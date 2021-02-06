package com.rm5248;

import org.freedesktop.dbus.connections.impl.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;


public class JavaReceive implements ReceiveInterface {

    /**
     * @param args
     */
    public static void main(String[] args) {
        try {
            DBusConnection conn = DBusConnection.getConnection(DBusConnection.DBusBusType.SESSION);
            conn.requestBusName("com.rm5248");
            conn.exportObject("/", new JavaReceive());
        } catch (DBusException e) {
            e.printStackTrace();
        }
        //Note that while the main thread will exit here, the D-Bus will keep the program
        //waiting.  You do not have to make an infinite loop.

    }

    /**
     * Print a string out to stdout.
     */
    @Override
    public int echoMessage(String str) {
        System.out.println(str);
        return 0;
    }

    /**
     * Print a string, adds the two integers together and returns the result.
     */
    @Override
    public int echoAndAdd(String str, int a, int b) {
        System.out.println(str);
        return a + b;
    }

    /**
     * This method is used to determine if an object is local or remote.
     * Always return false.
     */
    @Override
    public boolean isRemote() {
        return false;
    }

    /**
     * This method lets you define an object path; it is not used in the
     * dbus-java library, so you may safely return null.
     */
    @Override
    public String getObjectPath() {
        return null;
    }

}
