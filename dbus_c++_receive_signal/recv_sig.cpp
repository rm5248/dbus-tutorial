#include <stdio.h>
#include <dbus-cxx.h>
#include <string.h>
#include <unistd.h>

using namespace std;

//This is our signal handling method.
void getSignal(int a, string str, int b){
	char* cstr = (char*)str.c_str();
	
	if( a < strlen(cstr) ){
		printf( "%c\n", cstr[a]);
	}
	
	if( b < strlen(cstr) ){
		printf( "%c\n", cstr[b] );
	}
	
	printf("Entire string passed in: %s\n", cstr);
}

int main(int argc, char** argv){

	//First we have to init the dbus.
	DBus::init();
	//The dispatcher sends us information.  Make sure that it doesn't go out of scope or bad things will happen.
	DBus::Dispatcher::pointer dispatcher = DBus::Dispatcher::create();
	//Create a connection to the session bus
	DBus::Connection::pointer connection = dispatcher->create_connection( DBus::BUS_SESSION );
	
	//Request a unique name on the session bus, check for an error.
	int ret = connection->request_name( "com.rm5248", DBUS_NAME_FLAG_REPLACE_EXISTING );
  	if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != ret) return 1;

	//Make a signal proxy which takes in an int, a string, and another int.
	DBus::signal_proxy<void, int, string, int >::pointer signal = connection->
                create_signal_proxy<void, int, string, int >
                ("/", "com.rm5248.SignalInterface", "GenericSignal");
                
    signal->connect( sigc::ptr_fun(getSignal) );

	while( true ){
		sleep(300);
	}
  	
  	return 0;
}
