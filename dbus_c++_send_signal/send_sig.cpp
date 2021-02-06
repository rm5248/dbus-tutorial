#include <stdio.h>
#include <dbus-cxx.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv){

	//The dispatcher sends us information.  Make sure that it doesn't go out of scope or bad things will happen.
	std::shared_ptr<DBus::Dispatcher> dispatcher = DBus::StandaloneDispatcher::create();
	//Create a connection to the session bus
	std::shared_ptr<DBus::Connection> connection = dispatcher->create_connection( DBus::BusType::SESSION );
  	
  	std::shared_ptr<DBus::Signal<void(int,std::string,int)>> signal_send = connection->
        create_free_signal<void(int,std::string,int)>("/", "com.rm5248.SignalInterface", "GenericSignal");
        
    signal_send->emit( 5, "Sending out signals is fun!", 17);
  	return 0;
}
