/*
 * Copyright (C) 2011-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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

using GLib;
using FsoGsm;
using GIsiComm;

namespace NokiaIsi
{

/**
 * @class IsiUnsolicited
 **/
public class IsiUnsolicitedHandler : FsoFramework.AbstractObject
{
    private FsoGsm.Modem modem;

    public IsiUnsolicitedHandler( FsoGsm.Modem modem )
    {
        this.modem = modem;

        NokiaIsi.isimodem.net.signalStrength.connect( onSignalStrengthUpdate );
        NokiaIsi.isimodem.net.registrationStatus.connect( onRegistrationStatusUpdate );
        NokiaIsi.isimodem.call.statusChanged.connect( onCallStatusUpdate );
    }

    public override string repr()
    {
        return "<>";
    }

    private void onSignalStrengthUpdate( uint8 rssi )
    {
        var obj = modem.theDevice<FreeSmartphone.GSM.Network>();
        obj.signal_strength( (int32) rssi );
    }

    private void onRegistrationStatusUpdate( Network.ISI_RegStatus istatus )
    {
        debug( @"on registration status update w/ isi status $(istatus.status)" );

        switch ( istatus.status )
        {
            case GIsiClient.Network.RegistrationStatus.HOME:
            case GIsiClient.Network.RegistrationStatus.ROAM:
            case GIsiClient.Network.RegistrationStatus.ROAM_BLINK:
                modem.advanceToState( FsoGsm.Modem.Status.ALIVE_REGISTERED );
                break;

            default:
                break;
        }

        var obj = modem.theDevice<FreeSmartphone.GSM.Network>();
        obj.status( isiRegStatusToFsoRegStatus( istatus ) );
    }

    private void onCallStatusUpdate( GIsiComm.Call.ISI_CallStatus istatus )
    {
        var callhandler = modem.callhandler as FsoGsm.IsiCallHandler;
        callhandler.handleStatusUpdate( istatus );
    }
}

} /* namespace NokiaIsi */

// vim:ts=4:sw=4:expandtab
