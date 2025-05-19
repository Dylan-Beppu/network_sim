#include "application.h"


void application::sendData(std::string& data) {
	std::cout << "[Application layer] Sending: " << data << std::endl;
	data = "APP_HDR|" + data;
}

void application::receiveData(std::string &data) {
	
	std::cout << "[Application layer] Receiving: " << data << std::endl;
	
	//TODO: strip headers from data
	const std::string header = "APP_HDR|";
	if (data.find(header) == 0) {
        data.erase(0, header.length());
    }
}
