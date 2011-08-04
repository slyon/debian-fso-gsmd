/*
 * Copyright (C) 2010-2011 Simon Busch <morphis@gravedo.de>
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

private string networkRegistrationStatusToString( Msmcomm.NetworkRegistrationStatus reg_status )
{
    string result = "unknown";

    switch ( reg_status )
    {
        case Msmcomm.NetworkRegistrationStatus.NO_SERVICE:
            result = "unregistered";
            break;
        case Msmcomm.NetworkRegistrationStatus.HOME:
            result = "home";
            break;
        case Msmcomm.NetworkRegistrationStatus.ROAMING:
            result = "roaming";
            break;
        case Msmcomm.NetworkRegistrationStatus.DENIED:
            result = "denied";
            break;
        case Msmcomm.NetworkRegistrationStatus.SEARCHING:
            result = "busy";
            break;
    }

    return result;
}

public async void changeOperationMode( Msmcomm.OperationMode operation_mode ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
{
    var channel = theModem.channel( "main" ) as MsmChannel;

    if ( MsmData.operation_mode == operation_mode )
    {
        return;
    }

    try
    {
        yield channel.state_service.change_operation_mode( operation_mode );
        MsmData.operation_mode = operation_mode;

        // after we have send the power off command we have to wait until we get the final
        // information that our command was successful
        var info = ( yield channel.urc_handler.waitForUnsolicitedResponse( MsmUrcType.OPERATION_MODE ) ) as Msmcomm.StateInfo;
        if ( info.mode != operation_mode )
        {
            // reported mode after executed command is not the same as we want to have
            throw new FreeSmartphone.Error.INTERNAL_ERROR( "Could not switch operation mode successfully" );
        }
    }
    catch ( Msmcomm.Error err0 )
    {
    }
    catch ( Error err1 )
    {
    }
}

public class MsmNetworkRegister : NetworkRegister
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        yield changeOperationMode( Msmcomm.OperationMode.ONLINE );
    }
}

public class MsmNetworkUnregister : NetworkUnregister
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        yield changeOperationMode( Msmcomm.OperationMode.OFFLINE );
        MsmData.network_info.reset();

        // after we have unregistered from the network we have to authenticate again with
        // the sim card
        MsmData.sim_auth_status = FreeSmartphone.GSM.SIMAuthStatus.PIN_REQUIRED;
        yield gatherSimStatusAndUpdate();
    }
}
public class MsmNetworkGetSignalStrength : NetworkGetSignalStrength
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        signal = (int) MsmData.network_info.rssi;
    }
}

public class MsmNetworkGetStatus : NetworkGetStatus
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        status = new GLib.HashTable<string, Variant>( str_hash, str_equal );

        if ( MsmData.operation_mode == Msmcomm.OperationMode.ONLINE )
        {
            fillNetworkStatusInfo( status );
        }
        else
        {
            status.insert( "registration", "unregistered" );
        }
    }
}

public class MsmNetworkListProviders : NetworkListProviders
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.UNSUPPORTED( "Not yet implemented" );
    }
}

public class MsmNetworkSendUssdRequest : NetworkSendUssdRequest
{
    public override async void run( string request ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.UNSUPPORTED( "Not yet implemented" );
    }
}

public class MsmNetworkGetCallingId : NetworkGetCallingId
{
    public override async void run() throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.UNSUPPORTED( "Not yet implemented" );
    }
}

public class MsmNetworkSetCallingId : NetworkSetCallingId
{
    public override async void run( FreeSmartphone.GSM.CallingIdentificationStatus status ) throws FreeSmartphone.GSM.Error, FreeSmartphone.Error
    {
        throw new FreeSmartphone.Error.UNSUPPORTED( "Not yet implemented" );
    }
}

// vim:ts=4:sw=4:expandtab
