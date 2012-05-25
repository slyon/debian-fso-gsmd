/*
 * Copyright (C) 2011 Klaus 'mrmoku' Kurzmann   <mok@fluxnetz.de>
 *               2011 Lukas 'slyon' Märdian     <lukasmaerdian@gmail.com>
 *               2012 Simon Busch               <morphis@gravedo.de>
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

using FsoGsm;
using Gee;

namespace Gtm601
{

public class PlusCHUP : V250terCommand
{
    public PlusCHUP()
    {
        base( "+CHUP" );
    }
}

public class UnderscoreOWANCALL : V250terCommand
{
    public UnderscoreOWANCALL()
    {
        base( "_OWANCALL" );
    }

    public string issue( bool connect )
    {
        return connect ? "_OWANCALL=1,1,1" : "_OWANCALL=1,0,1";
    }
}

public class UnderscoreOWANDATA : AbstractAtCommand
{
    public bool connected;
    public string ip;
    public string gateway;
    public string dns1;
    public string dns2;
    public string nbns1;
    public string nbns2;
    public string speed;

    public UnderscoreOWANDATA()
    {
        // some modems strip the leading zero for one-digit chars
        var str = """_OWANDATA: "(?P<connected>[01]), (?P<ip>[0-9.]+), (?P<gw>[0-9.]+), (?P<dns1>[0-9.]+), (?P<dns2>[0-9.]+), (?P<nbns1>[0-9.]+), (?P<nbns2>[0-9.]+), (?P<speed>\d+)""";
        try
        {
            re = new Regex( str );
        }
        catch ( GLib.RegexError e )
        {
            assert_not_reached();
        }
        prefix = { "_OWANDATA: " };
    }

    public override void parse( string response ) throws AtCommandError
    {
        base.parse( response );

        connected = to_int( "connected" ) == 1;
        ip = to_string( "ip" );
        gateway = to_string( "gw" );
        dns1 = to_string( "dns1" );
        dns2 = to_string( "dns2" );
        nbns1 = to_string( "nbns1" );
        nbns2 = to_string( "nbns2" );
        speed = to_string( "speed" );
    }

    public string issue()
    {
        return "_OWANDATA?";
    }
}

public class ExtPlusCEER : FsoGsm.PlusCEER
{
    public ExtPlusCEER()
    {
        try
        {
            re = new Regex( """\+CEER: (?P<reason>[A-Z a-z]+)""" );
        }
        catch ( GLib.RegexError e )
        {
            assert_not_reached(); // fail here if Regex is broken
        }

        prefix = { "+CEER: " };
    }

    public override void parse( string response ) throws AtCommandError
    {
        base.parse( response );
        reason = to_string( "reason" );
    }
}

public class UnderscoreOSIGQ : AbstractAtCommand
{
    public int strength = 0;

    public UnderscoreOSIGQ()
    {
        try
        {
            re = new Regex( """_OSIGQ: (?P<strength>[0-9.]+),(?P<unknown>[0-9.]+)""" );
        }
        catch ( GLib.RegexError e )
        {
            assert_not_reached();
        }

        prefix = { "_OSIGQ: " };
    }

    public override void parse( string response ) throws AtCommandError
    {
        base.parse( response );
        strength = to_int( "strength" );
    }
}

public class UnderscoreOPSYS : AbstractAtCommand
{
    public enum RadioAccessMode
    {
        GSM = 0,
        UMTS = 1,
        ANY = 5,
    }

    public string issue( RadioAccessMode mode )
    {
        return "_OPSYS=%i,2".printf( (int) mode );
    }
}

/* register all custom at commands */
public void registerCustomAtCommands( HashMap<string,AtCommand> table )
{
    table[ "H" ] = new PlusCHUP();
    table[ "_OWANCALL" ] = new UnderscoreOWANCALL();
    table[ "_OWANDATA" ] = new UnderscoreOWANDATA();
    table[ "+CEER" ] = new ExtPlusCEER();
    table[ "_OSIGQ" ] = new UnderscoreOSIGQ();
    table[ "_OPSYS" ] = new UnderscoreOPSYS();
}

} // namespace Gtm601

// vim:ts=4:sw=4:expandtab
