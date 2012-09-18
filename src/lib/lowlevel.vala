/**
 * Copyright (C) 2009-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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

namespace FsoGsm {

public interface LowLevel : FsoFramework.AbstractObject
{
    /**
     * Power the device and prepare for AT mode
     **/
    public abstract bool poweron();
    /**
     * Power off the device
     **/
    public abstract bool poweroff();
    /**
     * Prepare device for suspend
     **/
    public abstract bool suspend();
    /**
     * Recover from suspend
     **/
    public abstract bool resume();
}

public class NullLowLevel : LowLevel, FsoFramework.AbstractObject
{
    public override string repr()
    {
        return "";
    }

    public bool poweron()
    {
        logger.warning( "NullLowlevel::poweron() - this is probably not what you want" );
        return true;
    }

    public bool poweroff()
    {
        logger.warning( "NullLowlevel::poweroff() - this is probably not what you want" );
        return true;
    }

    public bool suspend()
    {
        logger.warning( "NullLowlevel::suspend() - this is probably not what you want" );
        return true;
    }

    public bool resume()
    {
        logger.warning( "NullLowlevel::resume() - this is probably not what you want" );
        return true;
    }
}

}

// vim:ts=4:sw=4:expandtab
