/*
 * Copyright (C) 2009-2010 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 */

using Gee;
using FsoGsm;

/**
 * Public helpers
 **/
public void updateMsmSimAuthStatus( FreeSmartphone.GSM.SIMAuthStatus status )
{
    theModem.logger.info( @"SIM Auth status now $status" );
    // send the dbus signal
    var obj = theModem.theDevice<FreeSmartphone.GSM.SIM>();
    obj.auth_status( status );

    // check whether we need to advance the modem state
    var data = theModem.data();
    if ( status != data.simAuthStatus )
    {
        data.simAuthStatus = status;

        // advance global modem state
        var modemStatus = theModem.status();
        if ( modemStatus == Modem.Status.INITIALIZING )
        {
            if ( status == FreeSmartphone.GSM.SIMAuthStatus.READY )
            {
                theModem.advanceToState( Modem.Status.ALIVE_SIM_UNLOCKED );
            }
            else
            {
                theModem.advanceToState( Modem.Status.ALIVE_SIM_LOCKED );
            }
        }
    }
}

/**
 * Debug mediators
 **/

public class MsmDebugPing : DebugPing
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        var cmd = new Msmcomm.Command.TestAlive();
        var channel = theModem.channel( "main" ) as MsmChannel;
        yield channel.enqueueAsync( (owned) cmd );
    }
}

public class MsmDeviceGetFunctionality : DeviceGetFunctionality
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         var cfun = theModem.createAtCommand<PlusCFUN>( "+CFUN" );
//~         var response = yield theModem.processAtCommandAsync( cfun, cfun.query() );
//~         checkResponseValid( cfun, response );
//~         level = Constants.instance().deviceFunctionalityStatusToString( cfun.value );
//~         autoregister = theModem.data().keepRegistration;
//~         pin = theModem.data().simPin;
    }
}

public class MsmDeviceGetInformation : DeviceGetInformation
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        var channel = theModem.channel( "main" ) as MsmChannel;
        info = new GLib.HashTable<string,Value?>( str_hash, str_equal );

        info.insert( "model", "Palm Pre (Plus)" );
        info.insert( "manufacturer", "Palm, Inc." );

        var cmd = new Msmcomm.Command.GetFirmwareInfo();
        unowned Msmcomm.Reply.GetFirmwareInfo response = (Msmcomm.Reply.GetFirmwareInfo) ( yield channel.enqueueAsync( (owned) cmd ) );
        info.insert( "revision", response.info );

        var cmd2 = new Msmcomm.Command.GetImei();
        unowned Msmcomm.Reply.GetImei response2 = (Msmcomm.Reply.GetImei) ( yield channel.enqueueAsync( (owned) cmd2 ) );
        info.insert( "imei", response2.imei );
    }
}

public class MsmDeviceGetPowerStatus : DeviceGetPowerStatus
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         var cmd = theModem.createAtCommand<PlusCBC>( "+CBC" );
//~         var response = yield theModem.processAtCommandAsync( cmd, cmd.execute() );
//~
//~         checkResponseValid( cmd, response );
//~         status = cmd.status;
//~         level = cmd.level;
    }
}

public class MsmDeviceSetFunctionality : DeviceSetFunctionality
{
    public override async void run( string level, bool autoregister, string pin ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        var value = Constants.instance().deviceFunctionalityStringToStatus( level );

        if ( value == -1 )
        {
            throw new FreeSmartphone.Error.INVALID_PARAMETER( "Functionality needs to be one of \"minimal\", \"airplane\", or \"full\"." );
        }

        var cmd = new Msmcomm.Command.ChangeOperationMode();
        cmd.setOperationMode( Msmcomm.OperationMode.RESET );
        var channel = theModem.channel( "main" ) as MsmChannel;

        unowned Msmcomm.Message response = yield channel.enqueueAsync( (owned)cmd );


//~         var cmd = theModem.createAtCommand<PlusCFUN>( "+CFUN" );
//~         var response = yield theModem.processAtCommandAsync( cmd, cmd.issue( value ) );
//~         checkResponseExpected( cmd,
//~                          response,
//~                          { Constants.AtResponse.OK, Constants.AtResponse.CME_ERROR_011_SIM_PIN_REQUIRED } );
//~         var data = theModem.data();
//~         data.keepRegistration = autoregister;
//~         data.simPin = pin;
//~
//~         yield gatherSimStatusAndUpdate();
    }
}

/**
 * SIM Mediators
 **/
public class MsmSimGetAuthStatus : SimGetAuthStatus
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         var cmd = theModem.createAtCommand<PlusCPIN>( "+CPIN" );
//~         var response = yield theModem.processAtCommandAsync( cmd, cmd.query() );
//~         checkResponseValid( cmd, response );
//~         status = cmd.status;
    }
}

public class MsmSimGetInformation : SimGetInformation
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         info = new GLib.HashTable<string,Value?>( str_hash, str_equal );
//~
//~         var value = Value( typeof(string) );
//~
//~         var cimi = theModem.createAtCommand<PlusCGMR>( "+CIMI" );
//~         var response = yield theModem.processAtCommandAsync( cimi, cimi.execute() );
//~         if ( cimi.validate( response ) == Constants.AtResponse.VALID )
//~         {
//~             value = (string) cimi.value;
//~             info.insert( "imsi", value );
//~         }
//~         else
//~         {
//~             info.insert( "imsi", "unknown" );
//~         }
//~
//~         var crsm = theModem.createAtCommand<PlusCRSM>( "+CRSM" );
//~         response = yield theModem.processAtCommandAsync( crsm, crsm.issue(
//~                 Constants.SimFilesystemCommand.READ_BINARY,
//~                 Constants.instance().simFilesystemEntryNameToCode( "EFspn" ), 0, 0, 17 ) );
//~         if ( crsm.validate( response ) == Constants.AtResponse.VALID )
//~         {
//~             var issuer = Codec.hexToString( crsm.payload );
//~             value = issuer != "" ? issuer : "unknown";
//~             info.insert( "issuer", value );
//~         }
//~         else
//~         {
//~             info.insert( "issuer", "unknown" );
//~         }
//~
//~         //FIXME: Add dial_prefix and country
    }
}

public class MsmSimGetAuthCodeRequired : SimGetAuthCodeRequired
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         var cmd = theModem.createAtCommand<PlusCLCK>( "+CLCK" );
//~         var response = yield theModem.processAtCommandAsync( cmd, cmd.query( "SC" ) );
//~         checkResponseValid( cmd, response );
//~         required = cmd.enabled;
    }
}

public class MsmSimSendAuthCode : SimSendAuthCode
{
    public override async void run( string pin ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        var cmd = new Msmcomm.Command.VerifyPin();
        cmd.pin = pin;
        var channel = theModem.channel( "main" ) as MsmChannel;
        unowned Msmcomm.Message response = yield channel.enqueueAsync( (owned) cmd );
        // FIXME: No way to find out whether the operation succeeded or not
    }
}


/**
 * SMS Mediators
 **/

/**
 * Network Mediators
 **/

public class MsmNetworkRegister : NetworkRegister
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        var cmd = new Msmcomm.Command.ChangeOperationMode();
        cmd.setOperationMode( Msmcomm.OperationMode.ONLINE );
        var channel = theModem.channel( "main" ) as MsmChannel;

        unowned Msmcomm.Message response = yield channel.enqueueAsync( (owned) cmd );
    }
}

/**
 * Call Mediators
 **/
public class MsmCallActivate : CallActivate
{
    public override async void run( int id ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         yield theModem.callhandler.activate( id );
    }
}

public class MsmCallHoldActive : CallHoldActive
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         yield theModem.callhandler.hold();
    }
}

public class MsmCallInitiate : CallInitiate
{
    public override async void run( string number, string ctype ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         validatePhoneNumber( number );
//~         id = yield theModem.callhandler.initiate( number, ctype );
    }
}

public class MsmCallListCalls : CallListCalls
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         var cmd = theModem.createAtCommand<PlusCLCC>( "+CLCC" );
//~         var response = yield theModem.processAtCommandAsync( cmd, cmd.execute() );
//~         checkMultiResponseValid( cmd, response );
//~         calls = cmd.calls;
    }
}

public class MsmCallSendDtmf : CallSendDtmf
{
    public override async void run( string tones ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         var cmd = theModem.createAtCommand<PlusVTS>( "+VTS" );
//~         var response = yield theModem.processAtCommandAsync( cmd, cmd.issue( tones ) );
//~         checkResponseOk( cmd, response );
    }
}

public class MsmCallRelease : CallRelease
{
    public override async void run( int id ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         yield theModem.callhandler.release( id );
    }
}

public class MsmCallReleaseAll : CallReleaseAll
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.INTERNAL_ERROR( "Not yet implemented on MSM" );
//~         yield theModem.callhandler.releaseAll();
    }
}

/**
 * PDP Mediators
 **/

/**
 * Register all mediators
 **/
public void registerMsmMediators( HashMap<Type,Type> table )
{
    table[ typeof(DebugPing) ]                    = typeof( MsmDebugPing );

    table[ typeof(DeviceGetInformation) ]         = typeof( MsmDeviceGetInformation );
    table[ typeof(DeviceGetFunctionality) ]       = typeof( MsmDeviceGetFunctionality );
    table[ typeof(DeviceGetPowerStatus) ]         = typeof( MsmDeviceGetPowerStatus );
    table[ typeof(DeviceSetFunctionality) ]       = typeof( MsmDeviceSetFunctionality );

    table[ typeof(SimGetAuthCodeRequired) ]       = typeof( MsmSimGetAuthCodeRequired );
    table[ typeof(SimGetAuthStatus) ]             = typeof( MsmSimGetAuthStatus );
    table[ typeof(SimGetInformation) ]            = typeof( MsmSimGetInformation );
    table[ typeof(SimSendAuthCode) ]              = typeof( MsmSimSendAuthCode );

    table[ typeof(NetworkRegister) ]              = typeof( MsmNetworkRegister );

    table[ typeof(CallActivate) ]                 = typeof( MsmCallActivate );
    table[ typeof(CallHoldActive) ]               = typeof( MsmCallHoldActive );
    table[ typeof(CallInitiate) ]                 = typeof( MsmCallInitiate );
    table[ typeof(CallListCalls) ]                = typeof( MsmCallListCalls );
    table[ typeof(CallReleaseAll) ]               = typeof( MsmCallReleaseAll );
    table[ typeof(CallRelease) ]                  = typeof( MsmCallRelease );
    table[ typeof(CallSendDtmf) ]                 = typeof( MsmCallSendDtmf );
}
