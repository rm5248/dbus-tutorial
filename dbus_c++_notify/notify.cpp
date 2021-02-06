#include <stdio.h>
#include <dbus-cxx.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv){

	//The dispatcher sends us information.  Make sure that it doesn't go out of scope or bad things will happen.
	std::shared_ptr<DBus::Dispatcher> dispatcher = DBus::StandaloneDispatcher::create();
	//Create a connection to the session bus
	std::shared_ptr<DBus::Connection> connection = dispatcher->create_connection( DBus::BusType::SESSION );

	std::shared_ptr<DBus::ObjectProxy> object = connection->create_object_proxy("org.freedesktop.Notifications", "/org/freedesktop/Notifications");

	DBus::MethodProxy<uint32_t(std::string,uint32_t,std::string,std::string,std::string,std::vector<std::string>,std::map<std::string,DBus::Variant>,int32_t)>& notify = 
		*(object->create_method<uint32_t(std::string,uint32_t,std::string,std::string,std::string,std::vector<std::string>,std::map<std::string,DBus::Variant>,int32_t)>("org.freedesktop.Notifications", "Notify"));

	notify("", 0, "", "This is a test", "Again, this is only a test from C++", std::vector<std::string>(), std::map<std::string,DBus::Variant>(), -1 );
	
  	
  	return 0;
}
