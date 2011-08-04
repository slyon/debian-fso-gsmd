/**
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

/**
 * Encoders / Decoders etc.
 **/
namespace Codec {

public string hexToString( string hex, uint lowest = 0x20, uint highest = 0x7f, char? subst = null )
{
    var str = new GLib.StringBuilder();

    for ( int i = 0; i < hex.length / 2; ++i )
    {
        var hexbyte = "%c%c".printf( (int)hex[i*2+0], (int)hex[i*2+1] );
        int hexvalue;
        hexbyte.scanf( "%02X", out hexvalue );
        if ( hexvalue >= lowest && hexvalue <= highest )
        {
            str.append_c( (char)hexvalue );
        }
        else
        {
            if ( subst != null )
            {
                str.append_c( subst );
            }
        }
    }
    return str.str;
}

} /* namespace Codec */

// vim:ts=4:sw=4:expandtab
