package com.rm5248;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import org.freedesktop.Notifications;
import org.freedesktop.dbus.DBusConnection;
import org.freedesktop.dbus.UInt32;
import org.freedesktop.dbus.Variant;
import org.freedesktop.dbus.exceptions.DBusException;

public class JavaNotify {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			DBusConnection conn = DBusConnection.getConnection(DBusConnection.SESSION);
			Notifications notify = (Notifications)conn.getRemoteObject("org.freedesktop.Notifications", "/org/freedesktop/Notifications");
			Map<String,Variant<Byte>> hints = new HashMap<String, Variant<Byte>>();
			hints.put("urgency", new Variant<Byte>((byte)2));
			notify.Notify("", new UInt32(0), "", "This is a test", "Again, this is only a test", new LinkedList<String>(), hints, -1);
		} catch (DBusException e) {
			e.printStackTrace();
		}
		

	}

}
