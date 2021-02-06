#include <stdio.h>
#include <dbus-cxx.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv){

	//The dispatcher sends us information.  Make sure that it doesn't go out of scope or bad things will happen.
	std::shared_ptr<DBus::Dispatcher> dispatcher = DBus::StandaloneDispatcher::create();
	//Create a connection to the session bus
	std::shared_ptr<DBus::Connection> connection = dispatcher->create_connection( DBus::BusType::SESSION );

	//Create a pointer to a remote object with the specified interface and path.
	std::shared_ptr<DBus::ObjectProxy> object = connection->create_object_proxy("com.rm5248", "/");

	//Make a method that returns an int and takes in a string
	DBus::MethodProxy<int(std::string)>& echoMessage = *(object->create_method<int(std::string)>("com.rm5248.ReceiveInterface", "echoMessage"));
	
	//Make a method that returns an int and takes in a string and two ints
	DBus::MethodProxy<int(std::string, int, int)>& echoAndAdd = *(object->create_method<int(std::string, int, int)>
		("com.rm5248.ReceiveInterface", "echoAndAdd"));
		
	//We can now call these methods as though they were defined in this file, or in an included file
	int firstResult = echoMessage("Hello Java from C++!");
	printf("%d\n", firstResult);
	
	int secondResult = echoAndAdd("Testing the addition", 42, 19);
	printf("%d\n", secondResult);

  	
  	return 0;
}
