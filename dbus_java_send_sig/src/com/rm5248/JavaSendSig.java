package com.rm5248;

import org.freedesktop.dbus.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;

public class JavaSendSig {

	public static void main(String[] args) {		
		try {
			DBusConnection conn = DBusConnection.getConnection(DBusConnection.SESSION);
			//First we construct a new signal
			SignalInterface.GenericSignal sig = new SignalInterface.GenericSignal("/", 6, "Hello there my friends, this is a test of the emergency broadcast system", 22);
			//Then we send it out
			conn.sendSignal(sig);
		} catch (DBusException e) {
			e.printStackTrace();
		}

	}

}
