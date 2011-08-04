/*
 * Copyright (C) 2009-2011 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 */

using Gee;

namespace FsoGsm
{
    public FsoGsm.Modem theModem;
    public const string CONFIG_SECTION = "fsogsm";
    internal const string PPPD_DEFAULT_COMMAND = "/usr/sbin/pppd";

    // This is used the let the plugins define the services dependencies.
    public GLib.List<string> theServiceDependencies = new GLib.List<string>();
}

/**
 * @class PhonebookParams
 *
 * Helper class for a set of phonebook parameters
 **/
public class FsoGsm.PhonebookParams
{
    public int min;
    public int max;

    public PhonebookParams( int min, int max )
    {
        this.min = min;
        this.max = max;
    }
}

public class FsoGsm.ContextParams
{
    public string apn;
    public string username;
    public string password;

    public ContextParams( string apn, string username, string password )
    {
        this.apn = apn;
        this.username = username;
        this.password = password;
    }
}

public class FsoGsm.NetworkTimeReport
{
    public int time;
    public int zone;
    public int timestamp;
    public int zonestamp;

    public NetworkTimeReport()
    {
        time = 0;
        zone = 10000;
        timestamp = 0;
        zonestamp = 0;
    }

    public void setTime( int time )
    {
        this.time = time;
        this.timestamp = (int) TimeVal().tv_sec;
        sendUpdateSignal();
    }

    public void setZone( int zone )
    {
        this.zone = zone;
        this.zonestamp = (int) TimeVal().tv_sec;
        sendUpdateSignal();
    }

    public void setTimeAndZone( int time, int zone )
    {
        this.time = time;
        this.zone = zone;
        this.timestamp = (int) TimeVal().tv_sec;
        this.zonestamp = (int) TimeVal().tv_sec;
        sendUpdateSignal();
    }

    private void sendUpdateSignal()
    {
        var obj = theModem.theDevice<FreeSmartphone.GSM.Network>();
        obj.time_report( time, zone );
    }
}

public abstract interface FsoGsm.Modem : FsoFramework.AbstractObject
{
    public class Data : GLib.Object
    {
        public int alarmCleared;

        public bool simHasReadySignal;
        public uint simReadyTimeout;

        public int speakerVolumeMinimum;
        public int speakerVolumeMaximum;

        public FreeSmartphone.GSM.SIMAuthStatus simAuthStatus;
        public bool simBuffersSms;
        public HashMap<string,PhonebookParams> simPhonebooks;
        public string charset;
        public HashMap<string,AtCommandSequence> cmdSequences;

        public string functionality;
        public string simPin;
        public bool keepRegistration;

        // Device Capabilities
        public bool supportsGSM;
        public bool supportsCDMA;
        public bool supportsVoice;
        public bool supportsCSD;
        public string supportsPDP;
        public string supportsFAX;

        // Contents of SIM elementary files
        public GLib.HashTable<string,string> simOperatorbook;
        public string simIssuer;

        // PDP
        public string pppCommand;
        public string pppPort;
        public string[] pppOptions;
        public ContextParams contextParams;

        // Common AT extensions
        public string? atCommandCancelOutgoing;
        public string? atCommandRejectIncoming;

        // Network Information
        public NetworkTimeReport networkTimeReport;
    }

    public const int DEFAULT_RETRIES = 3;

    //TODO: Think about exposing a global modem state through DBus -- possibly
    //      reusing this as internal status as well -- rather than double bookkeeping

    //TODO: SIM and NETWORK readyness are somewhat orthogonal; think about
    //      separating them
    public enum Status
    {
        /** For error cases **/
        UNKNOWN,
        /** Initial state, Transport is closed **/
        CLOSED,
        /** Transport open, initialization commands are being sent **/
        INITIALIZING,
        /** Initialized, SIM status unknown **/
        ALIVE_NO_SIM,
        /** Initialized, SIM is locked **/
        ALIVE_SIM_LOCKED,
        /** Initialized, SIM is unlocked **/
        ALIVE_SIM_UNLOCKED,
        /** Initialized, SIM is ready for access **/
        ALIVE_SIM_READY,
        /** Initialized, SIM is booked into the network and reachable **/
        ALIVE_REGISTERED,
        /** Suspend commands are being sent **/
        SUSPENDING,
        /** Suspended **/
        SUSPENDED,
        /** Resume commands are being sent **/
        RESUMING,
        /** Shutdown commands are being sent **/
        CLOSING,
    }

    // DBus Service API
    public abstract async bool open();
    public abstract async void close();
    public abstract async bool suspend();
    public abstract async bool resume();
    public abstract void injectResponse( string command, string channel ) throws FreeSmartphone.Error; // DEBUG ONLY
    public abstract async void setFunctionality( string level, bool autoregister, string pin ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error;
    public signal void hangup();

    // Channel API
    public abstract void registerChannel( string name, FsoGsm.Channel channel );
    public abstract void advanceToState( Modem.Status status, bool force = false );
    public abstract AtCommandSequence atCommandSequence( string channel, string purpose );
    public signal void signalStatusChanged( Modem.Status status );

    // Mediator API
    public abstract T createMediator<T>() throws FreeSmartphone.Error;
    public abstract T createAtCommand<T>( string command );
    public abstract T theDevice<T>();
    public abstract Object parent { get; set; } // the DBus object
    public abstract CallHandler callhandler { get; set; } // the Call handler
    public abstract SmsHandler smshandler { get; set; } // the Sms handler
    public abstract PhonebookHandler pbhandler { get; set; } // the Phonebook handler
    public abstract WatchDog watchdog { get; set; } // the WatchDog
    public abstract PdpHandler pdphandler { get; set; } // the Pdp handler

    // PDP API
    public abstract string allocateDataPort();
    public abstract void releaseDataPort();

    // Command Queue API
    public abstract async string[] processAtCommandAsync( AtCommand command, string request, int retries = DEFAULT_RETRIES );
    public abstract async string[] processAtPduCommandAsync( AtCommand command, string request, int retries = DEFAULT_RETRIES );

    public abstract FsoGsm.Channel? channel( string category );

    // Misc. Accessors
    public abstract Modem.Status status();
    public abstract FreeSmartphone.GSM.DeviceStatus externalStatus();
    public abstract FsoGsm.Modem.Data data();
    public abstract void registerAtCommandSequence( string channel, string purpose, AtCommandSequence sequence );
}

/**
 * @class FsoGsm.AbstractModem
 **/
public abstract class FsoGsm.AbstractModem : FsoGsm.Modem, FsoFramework.AbstractObject
{
    //FIXME: Encapsulate as transport spec
    public string modem_type;
    public string modem_transport;
    public string modem_port;
    public int modem_speed;

    //FIXME: Encapsulate as transport spec
    public string data_type;
    public string data_transport;
    public string data_port;
    public int data_speed;

    protected FsoGsm.Modem.Status modem_status;
    protected FsoGsm.Modem.Data modem_data;

    protected HashMap<string,FsoGsm.Channel> channels;
    protected HashMap<string,FsoGsm.AtCommand> commands;
    protected HashMap<Type,Type> mediators;

    protected UnsolicitedResponseHandler urc;

    public Object parent { get; set; } // the DBus object
    public CallHandler callhandler { get; set; } // the Call handler
    public SmsHandler smshandler { get; set; } // the SMS handler
    public PhonebookHandler pbhandler { get; set; } // the Phonebook handler
    public WatchDog watchdog { get; set; } // the WatchDog
    public PdpHandler pdphandler { get; set; } // the Pdp handler

    protected FsoGsm.LowLevel lowlevel;

    protected FsoGsm.Modem.Status modem_status_before_suspend;

    protected uint modemSimTimeoutWatch;

    construct
    {
        // only one modem allowed per process
        assert( FsoGsm.theModem == null );
        FsoGsm.theModem = this;

        // channel map
        channels = new HashMap<string,FsoGsm.Channel>();

        // gather modem access parameters
        var modem_config = config.stringValue( CONFIG_SECTION, "modem_access", "invalid:invalid:-1" );
        if ( modem_config != "" )
        {
            var params = modem_config.split( ":" );
            if ( params.length == 3 )
            {
                var values = modem_config.split( ":" );
                modem_transport = values[0];
                modem_port = values[1];
                modem_speed = values[2].to_int();
            }
            else
            {
                logger.warning( @"Configuration string 'modem_access' invalid; expected 3 parameters, got $(params.length)" );
            }
        }
        else
        {
            logger.warning( @"Configuration string 'modem_access' missing. This might not be what you want." );
        }

        // gather modem data access parameters
        var data_config = config.stringValue( CONFIG_SECTION, "data_access", "" );
        if ( data_config != "" )
        {
            var params = data_config.split( ":" );
            if ( params.length == 3 )
            {
                var values = data_config.split( ":" );
                data_transport = values[0];
                data_port = values[1];
                data_speed = values[2].to_int();
            }
            else
            {
                logger.warning( @"Configuration string 'data_access' invalid; expected 3 parameters, got $(params.length)" );
            }
        }

        initLowlevel();
        initPdpHandler();
        initData();
        advanceToState( Modem.Status.CLOSED );
        registerHandlers();
        registerMediators();
        registerAtCommands();
        createChannels();

        var configuration = @"$modem_transport:$modem_port@$modem_speed";
        if ( data_config != "" )
        {
            configuration += @" / $data_transport:$data_port@$data_speed";
        }

        assert( logger.debug( @"Created; configured for $configuration" ) );
    }

    ~AbstractModem()
    {
        logger.debug( "Destroyed" );
    }

    private void initLowlevel()
    {
        // check preferred low level poweron/poweroff plugin and instanciate
        var lowleveltype = config.stringValue( CONFIG_SECTION, "lowlevel_type", "none" );
        string typename = "none";

        switch ( lowleveltype )
        {
            case "motorola_ezx":
                typename = "LowLevelMotorolaEZX";
                break;
            case "openmoko":
                typename = "LowLevelOpenmoko";
                break;
            case "palmpre":
                typename = "LowLevelPalmPre";
                break;
            case "nokia900":
                typename = "LowLevelNokia900";
                break;
            default:
                logger.warning( @"Invalid lowlevel_type $lowleveltype; vendor specifics will NOT be available" );
                lowlevel = new FsoGsm.NullLowLevel();
                return;
        }

        if ( lowleveltype != "none" )
        {
            var lowlevelclass = Type.from_name( typename );
            if ( lowlevelclass == Type.INVALID  )
            {
                logger.warning( @"Can't find plugin for lowlevel_type $lowleveltype; vendor specifics will NOT be available" );
                lowlevel = new FsoGsm.NullLowLevel();
                return;
            }

            lowlevel = Object.new( lowlevelclass ) as FsoGsm.LowLevel;
            logger.info( @"Ready. Using lowlevel plugin $lowleveltype to handle vendor specifics" );
        }
    }

    private void initPdpHandler()
    {
        // check preferred pdp handler plugin and instanciate
        var pdphandlertype = config.stringValue( CONFIG_SECTION, "pdp_type", "none" );
        string typename = "none";

        switch ( pdphandlertype )
        {
            case "ppp":
                typename = "PdpPpp";
                break;
            case "mux":
                typename = "PdpPppMux";
                break;
            case "qmi":
                typename = "PdpQmi";
                break;
            case "ippp":
                typename = "PdpPppInternal";
                break;
            case "nokia_isi":
                typename = "PdpNokiaIsi";
                break;
            default:
                logger.warning( @"Invalid pdp_type $pdphandlertype; data connectivity will NOT be available" );
                //pdphandler = new FsoGsm.Nullpdphandler();
                return;
        }

        if ( pdphandlertype != "none" )
        {
            var pdphandlerclass = Type.from_name( typename );
            if ( pdphandlerclass == Type.INVALID  )
            {
                logger.warning( @"Can't find plugin for pdp_type $pdphandlertype; data connectivity will NOT be available" );
                //pdphandler = new FsoGsm.Nullpdphandler();
                return;
            }

            pdphandler = Object.new( pdphandlerclass ) as FsoGsm.PdpHandler;
            logger.info( @"Ready. Using pdp plugin $pdphandlertype to handle data connectivity" );
        }
    }

    private void initData()
    {
        modem_data = new FsoGsm.Modem.Data();

        // set defaults
        modem_data.supportsGSM = true;
        modem_data.supportsCDMA = false;
        modem_data.supportsVoice = true;
        modem_data.supportsCSD = true;
        modem_data.supportsPDP = "B";
        modem_data.supportsFAX = "8";

        modem_data.charset = config.stringValue( CONFIG_SECTION, "modem_charset", "guess" ).up();
        modem_data.simHasReadySignal = false;
        modem_data.simReadyTimeout = 30; /* seconds */

        modem_data.speakerVolumeMinimum = -1;
        modem_data.speakerVolumeMaximum = -1;

        modem_data.alarmCleared = 946684800; // 00/01/01,00:00:00 (default for SIEMENS mc75i)
        modem_data.simAuthStatus = FreeSmartphone.GSM.SIMAuthStatus.UNKNOWN;
        modem_data.simBuffersSms = config.boolValue( CONFIG_SECTION, "sim_buffers_sms", true );

        modem_data.simPhonebooks = new HashMap<string,PhonebookParams>();

        modem_data.cmdSequences = new HashMap<string,AtCommandSequence>();

        modem_data.networkTimeReport = new NetworkTimeReport();

        modem_data.simPin = config.stringValue( CONFIG_SECTION, "auto_unlock", "" );
        modem_data.keepRegistration = config.boolValue( CONFIG_SECTION, "auto_register", false );

        modem_data.pppCommand = config.stringValue( CONFIG_SECTION, "ppp_command", PPPD_DEFAULT_COMMAND );
        modem_data.pppPort = data_port ?? config.stringValue( CONFIG_SECTION, "ppp_port", "/dev/null" );
        modem_data.pppOptions = config.stringListValue( CONFIG_SECTION, "ppp_options", {
            "115200",
            "nodetach",
            "modem",
            "crtscts",
            "nodefaultroute",
            "noreplacedefaultroute",
            "debug",
            "hide-password",
            //"ipcp-accept-local",
            "ktune",
            // "lcp-echo-failure", "10",
            // "lcp-echo-interval", "20",
            //"ipcp-max-configure", "4",
            // "noauth",
            "noccp",
            "noipdefault",
            "novj",
            "novjccomp",
            "proxyarp",
            //"silent",     /* Wait for the modem to send the first LCP packet */
            "usepeerdns" } );

        // add some basic init/exit/suspend/resume sequences
        var seq = modem_data.cmdSequences;

        seq["null"] = new AtCommandSequence( {} );

        var initsequence = new AtCommandSequence( {
            "E0Q0V1",       /* echo off, Q0, verbose on */
            "+CMEE=1",      /* report mobile equipment errors = numerical format */
            "+CRC=1",       /* extended cellular result codes = enable */
            "+CSNS=0",      /* single numbering scheme = voice */
            "+CMGF=0",      /* sms mode = PDU */
            "+CLIP=0",      /* calling line id present = disable */
            "+CLIR=0",      /* calling line id restrict = disable */
            "+COLP=0",      /* connected line id present = disable */
            "+CCWA=0",      /* call waiting = disable */
            "+CSMS=1"       /* gsm phase 2+ commands = enable */
        } );
        initsequence.append( config.stringListValue( CONFIG_SECTION, "modem_init", { } ) );
        registerAtCommandSequence( "MODEM", "init", initsequence );

        registerAtCommandSequence( "MODEM", "shutdown", new AtCommandSequence( {} ) );

        configureData();
    }

    private void registerHandlers()
    {
        urc = createUnsolicitedHandler();
        callhandler = createCallHandler();
        smshandler = createSmsHandler();
        pbhandler = createPhonebookHandler();
        watchdog = createWatchDog();
    }

    private void registerMediators()
    {
        mediators = new HashMap<Type,Type>();
        registerGenericAtMediators( mediators );
        registerCustomMediators( mediators );
    }

    private void registerAtCommands()
    {
        commands = new HashMap<string,FsoGsm.AtCommand>();
        registerGenericAtCommands( commands );
        registerCustomAtCommands( commands );
    }

    private void registerAtCommandSequence( string channel, string purpose, AtCommandSequence sequence )
    {
        assert( modem_data != null && modem_data.cmdSequences != null );
        modem_data.cmdSequences[ @"$channel-$purpose" ] = sequence;
    }

    private async void checkChannelsForHangup()
    {
        // we need to find out which channel has a hangup as we need to react
        // differently if it is the main channel or not
        var mainchannel = channels[ "main" ];
        if ( mainchannel.isActive() )
        {
            logger.error( "Detected main channel hangup; closing modem" );
            close();
            this.hangup();
        }
        else
        {
            // it was not the main channel which has a hangup so we restart the one
            // with the hangup
            foreach ( var cname in channels.keys )
            {
                if ( cname != "main" )
                {
                    var channel = channels[ cname ];
                    if ( !channel.isActive() )
                    {
                        logger.info( @"Detected $cname channel hangup; reopening channel ..." );

                        var ok = yield channel.open();
                        if ( !ok )
                        {
                            logger.error( @"Could not reopen channel '$cname' after hangup!!!" );
                        }
                    }
                }
            }
        }
    }

    private void onChannelHangup()
    {
        if ( modem_status == Modem.Status.CLOSING )
        {
            logger.warning( "Ignoring additional channel hangup while already closing the modem..." );
        }
        else
        {
            Idle.add( () => {
                checkChannelsForHangup();
                return false;
            } );
        }
    }

    //
    // protected API
    //
    /**
     * Override this to register additional mediators specific to your modem or
     * override generic mediators with modem-specific versions.
     **/
    protected virtual void registerCustomMediators( HashMap<Type,Type> mediators )
    {
    }

    /**
     * Override this to register additional AT commands specific to your modem or
     * override generic AT commands with modem-specific versions.
     **/
    protected virtual void registerCustomAtCommands( HashMap<string,FsoGsm.AtCommand> commands )
    {
    }

    /**
     * Override this to return a custom type of urc handler to be used for this modem.
     **/
    protected virtual UnsolicitedResponseHandler createUnsolicitedHandler()
    {
        return new AtUnsolicitedResponseHandler();
    }

    /**
     * Override this to return a custom type of Call handler to be used for this modem.
     **/
    protected virtual CallHandler createCallHandler()
    {
        return new GenericAtCallHandler();
    }

    /**
     * Override this to return a custom type of SMS handler to be used for this modem.
     **/
    protected virtual SmsHandler createSmsHandler()
    {
        return new AtSmsHandler();
    }

    /**
     * Override this to return a custom type of PB handler to be used for this modem.
     **/
    protected virtual PhonebookHandler createPhonebookHandler()
    {
        return new AtPhonebookHandler();
    }

    /**
     * Override this to return a custom type of Watch Dog to be used for this modem.
     **/
    protected virtual WatchDog createWatchDog()
    {
        return new GenericWatchDog();
    }

    /**
     * Override this to power on external components before the maintransport
     * will be opened
     **/
    protected virtual bool powerOn()
    {
        return true;
    }

    /**
     * Override this to power off external components before the maintransport
     * will be closed
     **/
    protected virtual void powerOff()
    {
    }

    /**
     * Override this to create your channels and assorted transports.
     **/
    protected virtual void createChannels()
    {
    }

    /**
     * Override this to configure the data instance for your modem.
     **/
    protected virtual void configureData()
    {
    }

    /**
     * Implement this to create the command/channel-assignment function.
     **/
    protected abstract FsoGsm.Channel channelForCommand( FsoGsm.AtCommand command, string request );

    //
    // public API
    //
    public virtual async bool open()
    {
        assert( logger.debug( "Opening the modem device..." ) );

        if ( !lowlevel.poweron() )
        {
            return false;
        }

        if ( !powerOn() )
        {
            return false;
        }

        assert( logger.debug( @"Will open $(channels.size) channels..." ) );

        if ( ! ( "main" in channels.keys ) )
        {
            logger.error( "Can't open main channel; not found in channel list" );
            return false;
        }

        var mainchannel = channels["main"];

        var ok = yield mainchannel.open();
        if ( !ok )
        {
            logger.error( "Can't open main channel; open returned false" );
            return false;
        }

        foreach( var key in this.channels.keys )
        {
            if ( key != "main" )
            {
                var channel = channels[key];
                var open = yield channel.open();
                if ( !open )
                {
                    logger.error( @"Can't open $key channel; open returned false" );
                    lowlevel.poweroff();
                    return false;
                }
            }
        }

        advanceToState( Modem.Status.INITIALIZING );
        return true;
    }

    public virtual async void close()
    {
        if ( status() == Modem.Status.CLOSED )
        {
            return;
        }
        assert( logger.debug( "Closing the modem device..." ) );

        advanceToState( Modem.Status.CLOSING );

        // give channels a chance to perform their closing commands
        GLib.Timeout.add_seconds( 3, close.callback );
        yield;

        // close all channels
        var channels = this.channels.values;
        foreach( var channel in channels )
        {
            channel.close();
        }

        lowlevel.poweroff();

        powerOff();

        advanceToState( Modem.Status.CLOSED, true ); // force wraparound

        initData();
    }

    public virtual async bool suspend()
    {
        modem_status_before_suspend = modem_status;

        advanceToState( Modem.Status.SUSPENDING );

        // suspend all channels
        var channels = this.channels.values;
        foreach( var channel in channels )
        {
            yield channel.suspend();
        }

        lowlevel.suspend();

        advanceToState( Modem.Status.SUSPENDED );

        return true;
    }

    public virtual async bool resume()
    {
        lowlevel.resume();

        advanceToState( Modem.Status.RESUMING );

        // resume all channels
        var channels = this.channels.values;
        foreach( var channel in channels )
        {
            yield channel.resume();
        }

        advanceToState( modem_status_before_suspend, true ); // force
        return true;
    }

    public virtual void injectResponse( string command, string channel ) throws FreeSmartphone.Error
    {
        var chan = this.channels[channel];
        if ( chan == null )
        {
            throw new FreeSmartphone.Error.INVALID_PARAMETER( @"Channel $channel not found" );
        }
        chan.injectResponse( command );
    }

    public virtual async void setFunctionality( string level, bool autoregister, string pin ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        var m = createMediator<FsoGsm.DeviceSetFunctionality>();
        yield m.run( level, autoregister, pin );
        watchdog.check();
    }

    public T theDevice<T>()
    {
        assert( parent != null );
        return (T) parent;
    }

    public Modem.Status status()
    {
        return modem_status;
    }

    public FsoGsm.Modem.Data data()
    {
        return modem_data;
    }

    public virtual FsoGsm.Channel? channel( string category )
    {
        if ( channels.size == 0 )
        {
            return null;
        }

        if ( category == "" )
        {
            foreach ( var chan in channels.values )
            {
                return chan;
            }
        }
        else
        {
            return channels[category];
        }
        return null;
    }

    public T createMediator<T>() throws FreeSmartphone.Error
    {
        var typ = mediators[typeof(T)];
        assert( typ != typeof(T) ); // we do NOT want the interface, else things will go havoc
        if ( typ == Type.INVALID )
        {
            logger.error( @"Requested mediator $(typeof(T).name()) not present for this modem" );
            throw new FreeSmartphone.Error.INTERNAL_ERROR( @"Not implemented (yet) for this modem (M:$(typeof(T).name()))" );
        }
        T obj = Object.new( typ );
        assert( obj != null );

        assert( logger.debug( @"Created mediator $(typeof(T).name())" ) );

        return obj;
    }

    public T createAtCommand<T>( string command )
    {
        AtCommand? cmd = commands[command];
        if (cmd == null )
        {
            logger.critical( @"Requested AT command $command unknown" );
            assert_not_reached();
        }
        return (T) cmd;
    }

    /**
     * Override this, if the data port is not static or if you need special initialization
     * before the data context is being opened.
     **/
    public virtual string allocateDataPort()
    {
        return data_port;
    }

    /**
     * Override this, if you need to clean up after the data context is being closed.
     **/
    public virtual void releaseDataPort()
    {
    }

    public async string[] processAtCommandAsync( AtCommand command, string request, int retries = DEFAULT_RETRIES )
    {
        AtChannel channel = channelForCommand( command, request ) as AtChannel;
        // FIXME: assert channel is really an At channel
        var response = yield channel.enqueueAsync( command, request, retries );
        return response;
    }

    public async string[] processAtPduCommandAsync( AtCommand command, string request, int retries = DEFAULT_RETRIES )
    {
        AtChannel channel = channelForCommand( command, request ) as AtChannel;
        // FIXME: assert channel is really an At channel
        var pdurequest = request.split( "\n" );
        // FIXME: don't assert
        assert( pdurequest.length == 2 );
        var continuation = yield channel.enqueueAsync( command, pdurequest[0], retries );
        // FIXME: don't assert
        assert( continuation.length == 1 && continuation[0] == "> " );
        var response = yield channel.enqueueAsync( command, pdurequest[1], retries );
        return response;
    }

    public void processUnsolicitedResponse( string prefix, string righthandside, string? pdu = null )
    {
        // lookup and forward to unsolicited object, if not found, handle on your own?
        assert( urc != null );
        if ( !urc.dispatch( prefix, righthandside, pdu ) )
        {
            logger.warning( @"No handler for URC $prefix w/ rhs $righthandside, please report to Mickey <smartphones-userland@linuxtogo.org>" );
        }
    }

    public Type mediatorFactory( Type mediator ) throws FreeSmartphone.Error
    {
        var typ = mediators[mediator];
        if ( typ == Type.INVALID )
        {
            throw new FreeSmartphone.Error.INTERNAL_ERROR( @"Requested mediator $(mediator.name()) unknown" );
        }
        return typ;
    }

    public AtCommand atCommandFactory( string command ) throws FreeSmartphone.Error
    {
        AtCommand? cmd = commands[command];
        if (cmd == null )
        {
            throw new FreeSmartphone.Error.INTERNAL_ERROR( @"Requested AT command $command unknown" );
        }
        return cmd;
    }

    public void registerChannel( string name, FsoGsm.Channel channel )
    {
        assert( channels != null );
        assert( channels[name] == null );
        channels[name] = channel;
        channel.hangup.connect( onChannelHangup );

        if ( channel is AtChannel )
        {
            channel.registerUnsolicitedHandler( this.processUnsolicitedResponse );
        }
    }

    /**
     * The only reason for this to be public is that the only authorized source to call this
     * is the command queues / channels and there are no friend classes in Vala. However,
     * it should _never_ be called by any other classes.
     **/
    public void advanceToState( Modem.Status next, bool force = false )
    {
        // do nothing, if we are already in the requested state
        if ( next == modem_status )
        {
            logger.debug( @"Already in status $next, not advancing" );
            return;
        }

        // unless forced, do nothing if we are beyond the requested state
        if ( !force && ( next < modem_status ) )
        {
            logger.debug( @"Already beyond status $next, not advancing" );
            return;
        }

        // kill timeout, if next one is closing
        if ( next == Modem.Status.CLOSING )
        {
            if ( modemSimTimeoutWatch > 0 )
            {
                GLib.Source.remove( modemSimTimeoutWatch );
            }
        }

        // if there is no SIM readyness signal, assume it's ready NOW
        if ( next == Modem.Status.ALIVE_SIM_UNLOCKED )
        {
            // if there is a SIM READY signal, launch a fallback timer, since these kinds of signals
            // are time criticle, i.e. there's a certain timeframe after
            // resetting the modem / unlocking the SIM when this signal is to arrive,
            // however, depending on how you are using this software, it may not have been
            // started yet, so we miss that signal.
            if ( modem_data.simHasReadySignal )
            {
                modemSimTimeoutWatch = GLib.Timeout.add_seconds( modem_data.simReadyTimeout, () => {
                    modemSimTimeoutWatch = 0;
                    advanceToState( Modem.Status.ALIVE_SIM_READY );
                    return false;
                } );
            }
            else
            {
                next = Modem.Status.ALIVE_SIM_READY;
            }
        }
        modem_status = next;

        // update for internal listeners
        signalStatusChanged( modem_status );
        // update for external listeners
        if ( parent != null )
        {
            var obj = parent as FreeSmartphone.GSM.Device;
            obj.device_status( externalStatus() );
        }
        logger.info( @"Modem Status changed to $modem_status" );
    }

    public AtCommandSequence atCommandSequence( string channel, string purpose )
    {
        var seq = modem_data.cmdSequences[ @"$channel-$purpose" ];
        return ( seq != null ) ? seq : modem_data.cmdSequences["null"];
    }

    // FIXME: Sync
    public FreeSmartphone.GSM.DeviceStatus externalStatus()
    {
        switch ( modem_status )
        {
            case Status.CLOSED:
                return FreeSmartphone.GSM.DeviceStatus.CLOSED;
            case Status.INITIALIZING:
                return FreeSmartphone.GSM.DeviceStatus.INITIALIZING;
            case Status.ALIVE_NO_SIM:
                return FreeSmartphone.GSM.DeviceStatus.ALIVE_NO_SIM;
            case Status.ALIVE_SIM_LOCKED:
                return FreeSmartphone.GSM.DeviceStatus.ALIVE_SIM_LOCKED;
            case Status.ALIVE_SIM_UNLOCKED:
                return FreeSmartphone.GSM.DeviceStatus.ALIVE_SIM_UNLOCKED;
            case Status.ALIVE_SIM_READY:
                return FreeSmartphone.GSM.DeviceStatus.ALIVE_SIM_READY;
            case Status.ALIVE_REGISTERED:
                return FreeSmartphone.GSM.DeviceStatus.ALIVE_REGISTERED;
            case Status.SUSPENDING:
                return FreeSmartphone.GSM.DeviceStatus.SUSPENDING;
            case Status.SUSPENDED:
                return FreeSmartphone.GSM.DeviceStatus.SUSPENDED;
            case Status.RESUMING:
                return FreeSmartphone.GSM.DeviceStatus.RESUMING;
            case Status.CLOSING:
                return FreeSmartphone.GSM.DeviceStatus.CLOSING;
            default:
                return FreeSmartphone.GSM.DeviceStatus.UNKNOWN;
        }
    }
}

public abstract class FsoGsm.AbstractGsmModem : FsoGsm.AbstractModem
{
}

public abstract class FsoGsm.AbstractCdmaModem : FsoGsm.AbstractModem
{
}

// vim:ts=4:sw=4:expandtab
