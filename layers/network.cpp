#include "network.h"


void network::sendData(std::string& data) {
	std::cout << "[Network layer] Sending: " << data << std::endl;
	data = "NET_HDR|" + data;
}

void network::receiveData(std::string &data) {
	
	std::cout << "[Network layer] Receiving: " << data << std::endl;
	
	//TODO: strip headers from data
	const std::string header = "NET_HDR|";
	if (data.find(header) == 0) {
        data.erase(0, header.length());
    }
}
