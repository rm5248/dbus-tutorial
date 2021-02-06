package com.rm5248;


import org.freedesktop.dbus.exceptions.DBusException;
import org.freedesktop.dbus.interfaces.DBusInterface;
import org.freedesktop.dbus.messages.DBusSignal;

public interface SignalInterface extends DBusInterface {

    public class GenericSignal extends DBusSignal {

        public final int a;
        public final String str;
        public final int b;

        public GenericSignal(String path, int a, String str, int b) throws DBusException {
            super(path, a, str, b);
            this.a = a;
            this.str = str;
            this.b = b;
        }

    }
}
