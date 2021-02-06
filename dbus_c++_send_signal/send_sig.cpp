#include <stdio.h>
#include <dbus-cxx.h>
#include <string.h>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv){

	//First we have to init the dbus.
	DBus::init();
	//The dispatcher sends us information.  Make sure that it doesn't go out of scope or bad things will happen.
	DBus::Dispatcher::pointer dispatcher = DBus::Dispatcher::create();
	//Create a connection to the session bus
	DBus::Connection::pointer connection = dispatcher->create_connection( DBus::BUS_SESSION );
  	
  	DBus::signal<void, int, string, int>::pointer signal_send = connection->
        create_signal<void, int, string, int>("/", "com.rm5248.SignalInterface", "GenericSignal");
        
    signal_send->emit( 5, "Sending out signals is fun!", 17);
  	return 0;
}
