#include <stdio.h>
#include <dbus-cxx.h>
#include <string.h>
#include <unistd.h>

using namespace std;

//This is the first method implemented.  It simply echos the string to standard out
//and returns 0.
int echoMessage(string str) {
	printf("%s\n", str.c_str() );
	return 0;
}

//This is the second method implemented.  It will print out the string, and return
//the addition of the two ints.
int echoAndAdd(string str, int a, int b) {
	printf("%s\n", str.c_str());
	return a+b;
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

	//Create a path to export methods on
  	DBus::Object::pointer object = connection->create_object("/");

	//Create the first method
  	object->create_method<int, string>("com.rm5248.ReceiveInterface", "echoMessage", sigc::ptr_fun(echoMessage) );
  	
  	//Create the second method
  	object->create_method<int, string, int, int>("com.rm5248.ReceiveInterface", "echoAndAdd", sigc::ptr_fun(echoAndAdd) );
  	
  	while(true){
  		sleep(300);
  	}
  	
  	return 0;
}
