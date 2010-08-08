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

using FsoGsm;
using Gee;

public class CinterionMc75.UnsolicitedResponseHandler : FsoGsm.AtUnsolicitedResponseHandler
{
    public UnsolicitedResponseHandler()
    {
        registerUrc( "^SSIM READY", dachSSIM_READY );
        registerUrc( "^SIND", dachSIND );
    }

    public virtual void dachSSIM_READY( string prefix, string rhs )
    {
        theModem.logger.info( "mc75i sim ready" );
        theModem.advanceToState( FsoGsm.Modem.Status.ALIVE_SIM_READY );
    }

    public virtual void dachSIND( string prefix, string rhs )
    {
        // FIXME: Handle
    }

    public override void plusCIEV( string prefix, string rhs )
    {
        var ciev = theModem.createAtCommand<CinterionPlusCIEV>( "+CIEV" );
        if ( ciev.validateUrc( @"$prefix: $rhs" ) == Constants.AtResponse.VALID )
        {
            logger.warning( "Received unhandled +CIEV %s, %d".printf( ciev.value1, ciev.value2 ) );
        }
        else
        {
            logger.warning( @"Received invalid +CIEV message $rhs. Please report" );
        }
    }
}
