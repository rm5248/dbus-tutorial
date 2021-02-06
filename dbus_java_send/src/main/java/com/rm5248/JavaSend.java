package com.rm5248;

import org.freedesktop.dbus.connections.impl.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;

public class JavaSend {

    /**
     * @param args
     */
    public static void main(String[] args) {
        try {
            DBusConnection conn = DBusConnection.getConnection(DBusConnection.DBusBusType.SESSION);
            ReceiveInterface recvInterface = conn.getRemoteObject("com.rm5248",
                    "/",
                    ReceiveInterface.class);
            int returnValue = recvInterface.echoMessage("Hello C++ from Java!");
            System.out.println(returnValue);
        } catch (DBusException e) {
            e.printStackTrace();
        }
        //Note that while the main thread will exit here, the D-Bus will keep the program
        //waiting.  You do not have to make an infinite loop.

    }

}
