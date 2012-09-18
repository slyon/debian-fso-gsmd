/*
 * (C) 2011-2012 Simon Busch <morphis@gravedo.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

public interface IRemotePhoneControl : GLib.Object
{
    public abstract async void initiate_call( string number, bool hide ) throws RemotePhoneControlError;
    public abstract async void activate_incoming_call( int id ) throws RemotePhoneControlError;
    public abstract async void hangup_incoming_call( int id ) throws RemotePhoneControlError;
}

public errordomain RemotePhoneControlError
{
    FAILED,
}

// vim:ts=4:sw=4:expandtab
