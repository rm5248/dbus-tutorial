#include <stdio.h>
#include <dbus-cxx.h>
#include <string.h>
#include <unistd.h>

//This is our signal handling method.
void getSignal(int a, std::string str, int b){
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

	//The dispatcher sends us information.  Make sure that it doesn't go out of scope or bad things will happen.
	std::shared_ptr<DBus::Dispatcher> dispatcher = DBus::StandaloneDispatcher::create();
	//Create a connection to the session bus
	std::shared_ptr<DBus::Connection> connection = dispatcher->create_connection( DBus::BusType::SESSION );
	
	//Request a unique name on the session bus, check for an error.
	DBus::RequestNameResponse ret = connection->request_name( "com.rm5248", DBUSCXX_NAME_FLAG_REPLACE_EXISTING );
  	if (DBus::RequestNameResponse::PrimaryOwner != ret) return 1;

	//Make a signal proxy which takes in an int, a string, and another int.
	DBus::SignalMatchRule rule =
		DBus::MatchRuleBuilder::create()
		.set_path( "/" )
		.set_interface( "com.rm5248.SignalInterface" )
		.set_member( "GenericSignal" )
		.as_signal_match();
	std::shared_ptr<DBus::SignalProxy<void(int,std::string,int)>> signal = connection->
                create_free_signal_proxy<void(int,std::string,int)>(rule);
                
    signal->connect( sigc::ptr_fun(getSignal) );

	while( true ){
		std::this_thread::sleep_for( std::chrono::seconds( 300 ) );
	}
  	
  	return 0;
}
