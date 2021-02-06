package com.rm5248;

import org.freedesktop.dbus.interfaces.DBusInterface;

public interface ReceiveInterface extends DBusInterface {
	
	public int echoMessage(String str);
	
	public int echoAndAdd(String str, int a, int b);

}
