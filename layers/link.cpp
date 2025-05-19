#include "link.h"


void link::sendData(std::string& data) {
	std::cout << "[Link layer] Sending: " << data << std::endl;
	data = "LINK_HDR|" + data;
}

void link::receiveData(std::string &data) {
	
	std::cout << "[Link layer] Receiving: " << data << std::endl;
	
	//TODO: strip headers from data
	const std::string header = "LINK_HDR|";
	if (data.find(header) == 0) {
        data.erase(0, header.length());
    }
}
