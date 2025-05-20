#include "link.h"


void link::sendData(std::string& data) {
	std::cout << "[Link layer] Sending: " << data << std::endl;
	data = "LINK_HDR|" + data;
}

void link::receiveData(std::string &data) {
	
	std::cout << "[Link layer] Receiving: " << data << std::endl;
	
	//strip headers from data
	const std::string header = "LINK_HDR|";
	size_t hPos = data.find(header);
    if (hPos != std::string::npos) {
        data.erase(hPos, header.length());
    }
}
