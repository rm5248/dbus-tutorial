#include <stdio.h>
#include <dbus-cxx.h>
#include <string.h>
#include <unistd.h>
#include <thread>

//This is the first method implemented.  It simply echos the string to standard out
//and returns 0.
int echoMessage(std::string str) {
	printf("%s\n", str.c_str() );
	return 0;
}

//This is the second method implemented.  It will print out the string, and return
//the addition of the two ints.
int echoAndAdd(std::string str, int a, int b) {
	printf("%s\n", str.c_str());
	return a+b;
}

int main(int argc, char** argv){

	//The dispatcher sends us information.  Make sure that it doesn't go out of scope or bad things will happen.
	std::shared_ptr<DBus::Dispatcher> dispatcher = DBus::StandaloneDispatcher::create();
	//Create a connection to the session bus
	std::shared_ptr<DBus::Connection> connection = dispatcher->create_connection( DBus::BusType::SESSION );

	//Request a unique name on the session bus, check for an error.
	DBus::RequestNameResponse ret = connection->request_name( "com.rm5248", DBUSCXX_NAME_FLAG_REPLACE_EXISTING );
  	if (DBus::RequestNameResponse::PrimaryOwner != ret) return 1;

	//Create a path to export methods on
  	std::shared_ptr<DBus::Object> object = connection->create_object("/");

	//Create the first method
  	object->create_method<int(std::string)>("com.rm5248.ReceiveInterface", "echoMessage", sigc::ptr_fun(echoMessage) );
  	
  	//Create the second method
  	object->create_method<int(std::string, int, int)>("com.rm5248.ReceiveInterface", "echoAndAdd", sigc::ptr_fun(echoAndAdd) );
  	
  	while(true){
		std::this_thread::sleep_for( std::chrono::seconds( 300 ) );
  	}
  	
  	return 0;
}
