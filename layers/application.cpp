#include "application.h"


void application::sendData(std::string& data) {
	std::cout << "[Application layer] Sending: " << data << std::endl;
	data = "APP_HDR|" + data;
}

void application::receiveData(std::string &data) {
	
	std::cout << "[Application layer] Receiving: " << data << std::endl;
	
	//strip headers from data
	const std::string header = "APP_HDR|";
    size_t hPos = data.find(header);
    if (hPos != std::string::npos) {
        data.erase(hPos, header.length());
    }
}
