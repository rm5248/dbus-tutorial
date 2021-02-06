package com.rm5248;

import org.freedesktop.*;
import org.freedesktop.dbus.*;
import org.freedesktop.dbus.exceptions.*;

public class JavaReceive implements ReceiveInterface{
	

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			DBusConnection conn = DBusConnection.getConnection(DBusConnection.SESSION);
			conn.requestBusName("com.rm5248");
			conn.exportObject("/", new JavaReceive());
		} catch (DBusException e) {
			e.printStackTrace();
		}
		//Note that while the main thread will exit here, the D-Bus will keep the program 
		//waiting.  You do not have to make an infinite loop.

	}

	//This is the first method implemented.  It simply echos the string to System.out
	//and returns 0.
	public int echoMessage(String str) {
		System.out.println(str);
		return 0;
	}

	//this method is defined by DBusInterface.  Always return false
	public boolean isRemote() {
		return false;
	}

	//This is the second method implemented.  It will print out the string, and return
	//the addition of the two ints.
	public int echoAndAdd(String str, int a, int b) {
		System.out.println(str);
		return a+b;
	}

}
