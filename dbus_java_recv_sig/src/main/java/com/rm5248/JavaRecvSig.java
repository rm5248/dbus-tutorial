package com.rm5248;

import org.freedesktop.dbus.connections.impl.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;
import org.freedesktop.dbus.interfaces.DBusSigHandler;


public class JavaRecvSig {

    public static void main(String[] args) {
        try {
            DBusConnection conn = DBusConnection.getConnection(DBusConnection.DBusBusType.SESSION);
            conn.requestBusName("com.rm5248");
            //Anonymous inner class, because I don't feel like making a new class which implements DBusSigHandler
            conn.addSigHandler(SignalInterface.GenericSignal.class, new DBusSigHandler<SignalInterface.GenericSignal>() {

                @Override
                public void handle(SignalInterface.GenericSignal sig) {
                    //We do the same thing that we did in the C++ program, make sure that the parameters are valid
                    //and then print out the characters at those locations.
                    if (sig.a < sig.str.length()) {
                        System.out.println(sig.str.charAt(sig.a));
                    }

                    if (sig.b < sig.str.length()) {
                        System.out.println(sig.str.charAt(sig.b));
                    }

                    System.out.println("Entire string passed in: " + sig.str);

                }

            });
        } catch (DBusException e) {
            e.printStackTrace();
        }
    }
}
