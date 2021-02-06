package org.freedesktop;

import java.util.List;
import java.util.Map;
import org.freedesktop.dbus.interfaces.DBusInterface;
import org.freedesktop.dbus.types.UInt32;
import org.freedesktop.dbus.types.Variant;


public interface Notifications extends DBusInterface{
	public UInt32 Notify(String app_name, UInt32 id, String icon, String summary, String body, List<String> actions, Map<String,Variant> hints, int timeout);
}
