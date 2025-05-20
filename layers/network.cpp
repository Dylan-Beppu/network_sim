#include "network.h"


void network::sendData(std::string& data) {
	std::cout << "[Network layer] Sending: " << data << std::endl;
	data = "NET_HDR|" + data;
}

void network::receiveData(std::string &data) {
	
	std::cout << "[Network layer] Receiving: " << data << std::endl;
	
	//strip headers from data
	const std::string header = "NET_HDR|";
    size_t hPos = data.find(header);
    if (hPos != std::string::npos) {
        data.erase(hPos, header.length());
    }
}
