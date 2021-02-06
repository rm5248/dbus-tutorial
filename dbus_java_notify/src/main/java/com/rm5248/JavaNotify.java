package com.rm5248;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

import org.freedesktop.Notifications;
import org.freedesktop.dbus.connections.impl.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;
import org.freedesktop.dbus.types.UInt32;
import org.freedesktop.dbus.types.Variant;

public class JavaNotify {

    /**
     * @param args
     */
    public static void main(String[] args) {
        try {
            DBusConnection conn = DBusConnection.getConnection(DBusConnection.DBusBusType.SESSION);
            Notifications notify = conn.getRemoteObject("org.freedesktop.Notifications", 
                    "/org/freedesktop/Notifications",
                    Notifications.class);
            Map<String, Variant> hints = new HashMap<String, Variant>();
            hints.put("urgency", new Variant<Byte>((byte) 2));
            notify.Notify("", new UInt32(0), "", "This is a test", "Again, this is only a test", new LinkedList<String>(), hints, -1);
        } catch (DBusException e) {
            e.printStackTrace();
        }

    }

}
