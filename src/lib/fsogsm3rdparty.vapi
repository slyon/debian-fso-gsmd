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

[CCode (cheader_filename = "conversions.h,util.h", cprefix = "", lower_case_cprefix = "")]
namespace Conversions
{
    string utf8_to_ucs2( string data );
    string utf8_to_gsm( string data );

    string ucs2_to_utf8( string data );
    string gsm_to_utf8( string data );

    string sim_string_to_utf8( string buffer, int length );


    void decode_hex_own_buf( string inbuffer,
                             long length,
                             out long items_written,
                             char terminator,
                             [CCode (array_length = false)] char[] outbuffer );

    void encode_hex_own_buf( [CCode (array_length = false)] char[] inbuffer,
                             long length,
                             char terminator,
                             [CCode (array_length = false)] char[] outbuffer );
}

[CCode (cheader_filename = "conversions.h,util.h,smsutil.h", cprefix = "SMS_", lower_case_cprefix = "sms_")]
namespace Sms
{
    public const int CBS_MAX_GSM_CHARS;

    [CCode (cname = "sms_language", cprefix = "SMS_TYPE_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum Type
    {
        DELIVER,
        DELIVER_REPORT_ACK,
        DELIVER_REPORT_ERROR,
        STATUS_REPORT,
        SUBMIT,
        SUBMIT_REPORT_ACK,
        SUBMIT_REPORT_ERROR,
        COMMAND
    }

    /* 23.040 Section 9.1.2.5 */
    [CCode (cname = "sms_number_type", cprefix = "SMS_NUMBER_TYPE_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum NumberType
    {
        UNKNOWN,
        INTERNATIONAL,
        NATIONAL,
        NETWORK_SPECIFIC,
        SUBSCRIBER,
        ALPHANUMERIC,
        ABBREVIATED,
        RESERVED
    }

    /* 23.040 Section 9.1.2.5 */
    [CCode (cname = "sms_numbering_plan", cprefix = "SMS_NUMBERING_PLAN_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum NumberingPlan
    {
        UNKNOWN,
        ISDN,
        DATA,
        TELEX,
        SC1,
        SC2,
        NATIONAL,
        PRIVATE,
        ERMES,
        RESERVED
    }

    [CCode (cname = "sms_validity_period_format", cprefix = "SMS_VALIDITY_PERIOD_FORMAT_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum ValidityPeriodFormat
    {
        ABSENT,
        ENHANCED,
        RELATIVE,
        ABSOLUTE,
    }

    [CCode (cname = "int", cprefix = "SMS_ST_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum Status
    {
        COMPLETED_RECEIVED,
        COMPLETED_UNABLE_TO_CONFIRM,
        COMPLETED_REPLACED,
        COMPLETED_LAST,
        TEMPORARY_CONGESTION,
        TEMPORARY_SME_BUSY,
        TEMPORARY_NO_RESPONSE,
        TEMPORARY_SERVICE_REJECTED,
        TEMPORARY_QOS_UNAVAILABLE,
        TEMPORARY_SME_ERROR,
        TEMPORARY_LAST,
        PERMANENT_RP_ERROR,
        PERMANENT_INVALID_DESTINATION,
        PERMANENT_CONNECTION_REJECTED,
        PERMANENT_NOT_OBTAINABLE,
        PERMANENT_QOS_UNAVAILABLE,
        PERMANENT_INTERWORKING_UNAVAILABLE,
        PERMANENT_VALIDITY_PERIOD_EXPIRED,
        PERMANENT_DELETED,
        PERMANENT_SC_ADMIN_DELETED,
        PERMANENT_SM_DOES_NOT_EXIST,
        PERMANENT_LAST,
        TEMPFINAL_CONGESTION,
        TEMPFINAL_SME_BUSY,
        TEMPFINAL_NO_RESPONSE,
        TEMPFINAL_SERVICE_REJECTED,
        TEMPFINAL_QOS_UNAVAILABLE,
        TEMPFINAL_SME_ERROR,
        TEMPFINAL_LAST
    }

    [CCode (cname = "sms_ct", cprefix = "SMS_CT_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum Ct
    {
        ENQUIRY,
        CANCEL_SRR,
        DELETE_SM,
        ENABLE_SRR
    }

    [CCode (cname = "sms_iei", cprefix = "SMS_IEI_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum Iei
    {
        CONCATENATED_8BIT,
        SPECIAL_MESSAGE_INDICATION,
        APPLICATION_ADDRESS_8BIT,
        APPLICATION_ADDRESS_16BIT,
        SMSC_CONTROL_PARAMETERS,
        UDH_SOURCE_INDICATOR,
        CONCATENATED_16BIT,
        WCMP,
        TEXT_FORMAT,
        PREDEFINED_SOUND,
        USER_DEFINED_SOUND,
        PREDEFINED_ANIMATION,
        LARGE_ANIMATION,
        SMALL_ANIMATION,
        LARGE_PICTURE,
        SMALL_PICTURE,
        VARIABLE_PICTURE,
        USER_PROMPT_INDICATOR,
        EXTENDED_OBJECT,
        REUSED_EXTENDED_OBJECT,
        COMPRESSION_CONTROL,
        OBJECT_DISTRIBUTION_INDICATOR,
        STANDARD_WVG_OBJECT,
        CHARACTER_SIZE_WVG_OBJECT,
        EXTENDED_OBJECT_DATA_REQUEST_COMMAND,
        RFC822_EMAIL_HEADER,
        HYPERLINK_ELEMENT,
        REPLY_ADDRESS_ELEMENT,
        ENHANCED_VOICE_MAIL_INFORMATION,
        NATIONAL_LANGUAGE_SINGLE_SHIFT,
        NATIONAL_LANGUAGE_LOCKING_SHIFT,
        INVALID
    }

    [CCode (cname = "enum sms_class", cprefix = "SMS_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum Class
    {
        CLASS_0,
        CLASS_1,
        CLASS_2,
        CLASS_3,
        CLASS_UNSPECIFIED,
    }

    [CCode (cname = "enum sms_charset", cprefix = "SMS_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum Charset
    {
        CHARSET_7BIT,
        CHARSET_8BIT,
        CHARSET_UCS2
    }

    [CCode (cname = "enum sms_mwi_type", cprefix = "SMS_MWI_TYPE_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum MwiType
    {
        VOICE,
        FAX,
        EMAIL,
        OTHER,
        VIDEO,
    }

    [CCode (cname = "enum sms_pid_type", cprefix = "SMS_PID_TYPE_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum PidType
    {
        SM_TYPE_0,
        REPLACE_SM_TYPE_1,
        REPLACE_SM_TYPE_2,
        REPLACE_SM_TYPE_3,
        REPLACE_SM_TYPE_4,
        REPLACE_SM_TYPE_5,
        REPLACE_SM_TYPE_6,
        REPLACE_SM_TYPE_7,
        ENHANCED_MESSAGE_SERVICE,
        RETURN_CALL,
        ANSI136,
        ME_DOWNLOAD,
        ME_DEPERSONALIZATION,
        USIM_DOWNLOAD,
    }

    [CCode (cname = "struct sms_address", cprefix = "sms_address_", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct Address
    {
        public unowned string to_string();
        public void from_string( string str );

        [CCode (cname = "sms_assembly_encode_address")]
        public bool encode( out unowned string straddr );

        public Sms.NumberType number_type;
        public Sms.NumberingPlan numbering_plan;
        public char[] address; /* Max 20 in semi-octet, 11 in alnum */
    }

    [CCode (cname = "struct sms_scts", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct Scts
    {
        public string to_string()
        {
            return "%02u/%02u/%02u,%02u:%02u:%02u%s".printf( year, month, day, hour, minute, second, timezone > 0 ? "+%02d".printf( timezone ) : "%02d".printf( timezone ) );
        }

        public uint to_epoch()
        {
            var t = GLib.Time() { year=year, month=month, day=day, hour=hour, minute=minute, second=second };
            return (uint)t.mktime();
        }

        public uint8 year;
        public uint8 month;
        public uint8 day;
        public uint8 hour;
        public uint8 minute;
        public uint8 second;
        public int8 timezone;
    }

    [CCode (cname = "struct sms_validity_period", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct ValidityPeriod
    {
        public uint8 relative;
        public Sms.Scts absolute;
        public uint8 enhanced;
    }

    [CCode (cname = "struct sms_deliver", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct Deliver
    {
        public void addProperties( GLib.HashTable<string,GLib.Value?> props )
        {
            props.insert( "mms", mms );
            props.insert( "sri", sri );
            props.insert( "udhi", udhi );
            props.insert( "rp", rp );
            props.insert( "pid", pid );
            props.insert( "dcs", dcs );
            props.insert( "udl", udl );
            if ( udhi )
            {
                props.insert( "udh", "%02X %02X %02X %04X %04X".printf( ud[0], ud[1], ud[2], ud[4] + (ud[3] << 8), ud[6] + (ud[5] << 8) ) );
            }
        }

        public bool mms;
        public bool sri;
        public bool udhi;
        public bool rp;
        public Sms.Address oaddr;
        public uint8 pid;
        public uint8 dcs;
        public Sms.Scts scts;
        public uint8 udl;
        public uint8 ud[];
    }

    [CCode (cname = "struct sms_deliver_err_report", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct DeliverErrorReport
    {
        public bool udhi;
        public uint8 fcs;
        public uint8 pi;
        public uint8 pid;
        public uint8 dcs;
        public uint8 udl;
        public uint8 ud[];
    }

    [CCode (cname = "struct sms_deliver_ack_report", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct DeliverAckReport
    {
        public bool udhi;
        public uint8 pi;
        public uint8 pid;
        public uint8 dcs;
        public uint8 udl;
        public uint8 ud[];
    }

    [CCode (cname = "struct sms_command", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct Command
    {
        public bool udhi;
        public bool srr;
        public uint8 mr;
        public uint8 pid;
        public Sms.Ct ct;
        public uint8 mn;
        public Sms.Address daddr;
        public uint8 cdl;
        public uint8 cd[];
    }

    [CCode (cname = "struct sms_status_report", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct StatusReport
    {
        public bool udhi;
        public bool mms;
        public bool srq;
        public uint8 mr;
        public Sms.Address raddr;
        public Sms.Scts scts;
        public Sms.Scts dt;
        public Sms.Status st;
        public uint8 pi;
        public uint8 pid;
        public uint8 dcs;
        public uint8 udl;
        public uint8 ud[];
    }

    [CCode (cname = "struct sms_submit", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct Submit
    {
        public bool rd;
        public Sms.ValidityPeriodFormat vpf;
        public bool rp;
        public bool udhi;
        public bool srr; // status report request
        public uint8 mr;
        public Sms.Address daddr;
        public uint8 pid;
        public uint8 dcs;
        public Sms.ValidityPeriod vp;
        public uint8 udl;
        public uint8 ud[];
    }

    [CCode (cname = "struct sms_submit_ack_report", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct SubmitAckReport
    {
        public bool udhi;
        public uint8 pi;
        public Sms.Scts scts;
        public uint8 pid;
        public uint8 dcs;
        public uint8 udl;
        public uint8 ud[];
    }

    [CCode (cname = "struct sms_submit_err_report", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct SubmitErrorReport
    {
        public bool udhi;
        public uint8 fcs;
        public uint8 pi;
        public Sms.Scts scts;
        public uint8 pid;
        public uint8 dcs;
        public uint8 udl;
        public uint8 ud[];
    }

    [Compact]
    [CCode (cname = "structsms", cprefix = "sms_", cheader_filename = "smsutil.h,conversions.h")]
    public class Message
    {
        public string to_string()
        {
            var list = new GLib.SList<unowned Sms.Message>();
            list.append( this );
            return Sms.decode_text( list );
        }

        public string number()
        {
            switch ( type )
            {
                case Sms.Type.DELIVER:
                    return deliver.oaddr.to_string();
                case Sms.Type.SUBMIT:
                    return submit.daddr.to_string();
                case Sms.Type.COMMAND:
                    return command.daddr.to_string();
                case Sms.Type.STATUS_REPORT:
                    return status_report.raddr.to_string();
                default:
                    return "unknown";
            }
        }

        /**
         * @returns a hashable string for the message that serves as a unique identifier
         * (considering the fragments of a concatenated message as being the same message)
         */
        public string hash()
        {
            // we only support deliver type messages for now
            GLib.assert( type == Sms.Type.DELIVER );

            uint16 ref_num;
            uint8 max_msgs;
            uint8 seq_num;

            var oaddr = number();

            if ( !extract_concatenation( out ref_num, out max_msgs, out seq_num ) )
            {
                // service center address, originating address, delivery timestamp
                return @"$(sc_addr)_$(oaddr)_$(deliver.scts.to_epoch())_1".replace( "+", "" );
            }
            else
            {
                // service center address, originating address, reference number, # of fragments
                //FIXME: This goes wrong (problem probably in sms_address_to_string)
                //return @"$(sc_addr)_$(deliver.oaddr)_$(ref_num)_$(max_msgs)";
                return @"$(sc_addr)_$(oaddr)_$(ref_num)_$(max_msgs)".replace( "+", "" );
            }
        }

        public string timestamp()
        {
            switch ( type )
            {
                case Sms.Type.DELIVER:
                    return deliver.scts.to_string();
                default:
                    return "none";
            }
        }

        public GLib.HashTable<string,GLib.Value?> properties()
        {
            var props = new GLib.HashTable<string,GLib.Value?>( GLib.str_hash, GLib.str_equal );

            int dst;
            int src;
            bool is8bit;
            var hasAppPort = extract_app_port( out dst, out src, out is8bit );
            if ( hasAppPort )
            {
                props.insert( "app-port-src", src );
                props.insert( "app-port-dst", dst );
                props.insert( "app-port-8bit", is8bit );
            }

            switch ( type )
            {
                case Sms.Type.DELIVER:
                    deliver.addProperties( props );
                    /*
                case Sms.Type.DELIVER_REPORT_ACK:
                    return deliver_ack_report.properties();
                case Sms.Type.DELIVER_REPORT_ERROR:
                    return deliver_err_report.properties();
                case Sms.Type.SUBMIT:
                    return submit.properties();
                case Sms.Type.SUBMIT_REPORT_ACK:
                    return submit_ack_report.properties();
                case Sms.Type.SUBMIT_REPORT_ERROR:
                    return submit_err_report.properties();
                case Sms.Type.COMMAND:
                    return command.properties();
                case Sms.Type.STATUS_REPORT:
                    return status_report.properties();
                    */
                default:
                    break;
            }
            return props;
        }

        public static Sms.Message? newFromHexPdu( string hexpdu, int tpdulen )
        {
            long items_written = -1;
            char[] binpdu = new char[1024];
            Conversions.decode_hex_own_buf( hexpdu, -1, out items_written, 0, binpdu );
            GLib.assert( items_written != -1 );

            var sms = new Sms.Message();
            var res = Sms.decode( binpdu, false, tpdulen, sms );

            if ( !res )
            {
                GLib.warning( @"Sms.Message::newFromHexPdu: could not decode message w/ tpdulen $(tpdulen) and hexpdu $(hexpdu)" );
                return null;
            }
            else
            {
                return sms;
            }
        }

        public string toHexPdu( out int tpdulen )
        {
            int binlen;
            char[] binpdu = new char[176];

            var res = Sms.encode( this, out binlen, out tpdulen, binpdu );
            if ( !res )
            {
                GLib.warning( @"Sms.Message::toHexPdu: could not encode message" );
                tpdulen = -1;
                return "";
            }
            char[] hexpdu = new char[1024];
            Conversions.encode_hex_own_buf( binpdu, binlen, 0, hexpdu );
            return "%s".printf( (string) hexpdu );
        }

        public bool is_concatenated()
        {
            return ( extract_concatenation( null, null, null ) );
        }

        /* Methods */
        public Message();
        public static long size();

        [CCode (array_length_type = "guint8", array_length_pos = 2.5)]
        public unowned uint8[] extract_common( out bool udhi, out uint8 dcs, out uint8 max );

        public bool extract_app_port( out int dst, out int src, out bool is_8bit );
        public bool extract_concatenation( out uint16 ref_num, out uint8 max_msgs, out uint8 seq_num );
        public bool extract_language_variant( out uint8 locking, out uint8 single );

        /* Members */
        public Sms.Address sc_addr;
        public Sms.Type type;
        /* <union> */
        public Sms.Deliver deliver;
        public Sms.DeliverAckReport deliver_ack_report;
        public Sms.DeliverErrorReport deliver_err_report;
        public Sms.Submit submit;
        public Sms.SubmitAckReport submit_ack_report;
        public Sms.SubmitErrorReport submit_err_report;
        public Sms.Command command;
        public Sms.StatusReport status_report;
        /* </union> */
    }

    //
    // Global methods
    //

    [CCode (cname = "sms_decode")]
    public bool decode( char[] binpdu, bool outgoing, int tpdu_len, Sms.Message message );

    [CCode (cname = "sms_encode")]
    public bool encode( Sms.Message message,
                        out int len,
                        out int tpdu_len,
                        [CCode (array_length = false)] char[] binpdu );

    [CCode (cname = "sms_decode_text")]
    public string decode_text( GLib.SList<Sms.Message> sms_list );

    [CCode (cname = "sms_text_prepare")]
    public GLib.SList<unowned Sms.Message> text_prepare( string utf8, uint16 reference, bool use_16bit, out int ref_offset );

#if USE_ASSEMBLY
    [CCode (cname = "struct sms_udh_iter", destroy_function = "")]
    public struct UserDataHeaderIter
    {
        public uint8 *data;
        public uint8 offset;
    }

    [CCode (cname = "struct sms_assembly_node", destroy_function = "")]
    public struct AssemblyNode
    {
        public Sms.Address addr;
        public time_t ts;
        public GLib.SList<Sms.Message*> fragment_list;
        public uint8 @ref;
        public uint8 max_fragments;
        public uint8 num_fragments;
        public uint bitmap[];
    }

    [CCode (cname = "struct sms_assembly")]
    [Compact]
    public class Assembly
    {
        [CCode (cname = "sms_assembly_new")]
        public Assembly( string imsi );

        public uint length()
        {
            return assembly_list.length();
        }

        public GLib.SList<Sms.Message*> add_fragment( Sms.Message sms, time_t ts, Sms.Address addr, uint16 uref, uint8 max, uint8 seq );

        public string imsi;
        private GLib.SList<AssemblyNode?> assembly_list;
    }
#endif
}

[CCode (cheader_filename = "conversions.h,util.h,smsutil.h", cprefix = "CB_", lower_case_cprefix = "cbs_")]
namespace Cb
{
    [CCode (cname = "enum cbs_language", cprefix = "CBS_LANGUAGE_", has_type_id = false, cheader_filename = "smsutil.h")]
    public enum Language
    {
        GERMAN,
        ENGLISH,
        ITALIAN,
        FRENCH,
        SPANISH,
        DUTCH,
        SWEDISH,
        DANISH,
        PORTUGESE,
        FINNISH,
        NORWEGIAN,
        GREEK,
        TURKISH,
        HUNGARIAN,
        POLISH,
        UNSPECIFIED,
        CZECH,
        HEBREW,
        ARABIC,
        RUSSIAN,
        ICELANDIC
    }

    public string language_to_string( Language lang )
    {
        switch ( lang )
        {
            case Language.GERMAN: return "de";
            case Language.ENGLISH: return "en";
            case Language.ITALIAN: return "it";
            case Language.FRENCH: return "fr";
            case Language.SPANISH: return "es";
            case Language.DUTCH: return "nl";
            case Language.SWEDISH: return "se";
            case Language.DANISH: return "dk";
            case Language.PORTUGESE: return "pg";
            case Language.FINNISH: return "fi";
            case Language.NORWEGIAN: return "no";
            case Language.GREEK: return "gr";
            case Language.TURKISH: return "tr";
            case Language.HUNGARIAN: return "hu";
            case Language.POLISH: return "pl";
            case Language.CZECH: return "cz";
            case Language.HEBREW: return "il";
            case Language.ARABIC: return "ae";
            case Language.RUSSIAN: return "ru";
            case Language.ICELANDIC: return "is";
            default:
                return "unspecified";
        }
    }

    [CCode (cname = "cbs_geo_scope", cprefix = "CBS_GEO_SCOPE_", cheader_filename = "smsutil.h")]
    public enum GeoScope
    {
        CELL_IMMEDIATE,
        PLMN,
        SERVICE_AREA,
        CELL_NORMAL
    }

    [Compact]
    [CCode (cname = "struct cbs", cprefix = "cbs_", cheader_filename = "smsutil.h")]
    public class Message
    {
        public Message();

        public GeoScope gs;
        public uint16 message_code;
        public uint8 update_number;
        public uint16 message_identifier;
        public uint8 dcs;
        public uint8 max_pages;
        public uint8 page;
        public uint8 ud[];

        public string to_string()
        {
            string language;
            return decode_all( out language );
        }

        public string decode_all( out string language )
        {
            bool udhi;
            Sms.Class cls;
            Sms.Charset charset;
            bool compressed;
            Cb.Language lang;
            bool iso639;

            if ( !dcs_decode( dcs, out udhi, out cls, out charset, out compressed, out lang, out iso639 ) )
            {
                GLib.warning( @"Cb.Message::to_string: could not decode dcs" );
                return "<unknown/invalid>";
            }

            /*
            var iso639_2 = new char[3];
            if ( !iso639_2_from_language( lang, iso639_2 ) )
            {
                GLib.warning( @"Cb.Message::to_string: iso639-2 charset unknown" );
                return "<unknown/invalid>";
            }
            *
            */

            var iso639_2 = new char[3];

            var list = new GLib.SList<unowned Cb.Message>();
            list.append( this );

            string text = Cb.decode_text( list, iso639_2 );

            language = iso639_2[0] != '\0' ? (string)iso639_2 : language_to_string( lang );

            return text;
        }

        public static Cb.Message? newFromHexPdu( string hexpdu, int tpdulen )
        {
            long items_written = -1;
            char[] binpdu = new char[1024];
            Conversions.decode_hex_own_buf( hexpdu, -1, out items_written, 0, binpdu );
            GLib.assert( items_written != -1 );

            var cb = new Cb.Message();
            var res = Cb.decode( binpdu, tpdulen, cb );

            if ( !res )
            {
                GLib.warning( @"Cb.Message::newFromHexPdu: could not decode message w/ tpdulen $(tpdulen) and hexpdu $(hexpdu)" );
                return null;
            }
            else
            {
                return cb;
            }
        }
    }
#if USE_ASSEMBLIES
    [CCode (cname = "cbs_assembly_node", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct AssemblyNode
    {
        uint32 serial;
        uint16 bitmap;
        GLib.SList<void*> pages;
    }

    [CCode (cname = "cbs_assembly", destroy_function = "cbs_assembly_free", cheader_filename = "smsutil.h")]
    public struct Assembly
    {
        GLib.SList<void*> assembly_list;
        GLib.SList<void*> recv_plmn;
        GLib.SList<void*> recv_loc;
        GLib.SList<void*> recv_cell;
    }

    [CCode (cname = "cbs_topic_range", destroy_function = "", cheader_filename = "smsutil.h")]
    public struct TopicRange
    {
        ushort min;
        ushort max;
    }
#endif
    //
    // Global methods
    //
    public static bool decode( [CCode (array_length = false)] char[] binpdu, int tpdulen, Cb.Message message );
    public static bool dcs_decode( uint8 dcs, out bool udhi, out Sms.Class cls, out Sms.Charset charset, out bool compressed, out Cb.Language lang, out bool iso639 );
    [CCode (cname = "iso639_2_from_language")]
    public static bool iso639_2_from_language( Cb.Language lang, [CCode (array_length = false)] char[] iso639 );

    public static string decode_text( GLib.SList<unowned Cb.Message> list, [CCode (array_length = false)] char[] iso639_lang );

    /*
    static inline bool is_bit_set(unsigned char oct, int bit)
    {
        int mask = 0x1 << bit;
        return oct & mask ? TRUE : FALSE;
    }

    static inline unsigned char bit_field(unsigned char oct, int start, int num)
    {
        unsigned char mask = (0x1 << num) - 1;

        return (oct >> start) & mask;
    }
    */
}
