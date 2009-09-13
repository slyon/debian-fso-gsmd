/**
 * Copyright (C) 2009 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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

/**
 * This file contains Dbus/AT command mediators only using official 3GPP AT commands.
 *
 * Do _not_ add vendor-specific mediators here, instead add them to your modem plugin.
 **/

using Gee;

namespace FsoGsm
{

public class DeviceGetAntennaPower : AbstractMediator
{
    //TODO: needs to get the dbus reply handlers from the creator
    public DeviceGetAntennaPower()
    {
        debug( "DeviceGetAntennaPower()" );
        PlusCFUN cfun = theModem.atCommandFactory( "PlusCFUN" ) as PlusCFUN;
        enqueue( cfun, cfun.query(), onResponse );
    }

    public void onResponse( AtCommand command, string[] response )
    {
        debug( "DeviceGetAntennaPower.onResponse( '%s' )", response[0] );

        var cfun = command as PlusCFUN;
        cfun.parse( response[0] );
    }
}

public void registerGenericMediators( HashMap<string,Type> table )
{
    // register commands
    table[ "DeviceGetAntennaPower" ] = typeof( DeviceGetAntennaPower );
}

} // namespace FsoGsm