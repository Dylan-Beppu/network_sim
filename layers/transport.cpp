#include "transport.h"


void transport::sendData(std::string& data) {
	std::cout << "[Transport layer] Sending: " << data << std::endl;
	data = "TRANS_HDR|" + data;
}

void transport::receiveData(std::string &data) {
	
	std::cout << "[Transport layer] Receiving: " << data << std::endl;
	
	//TODO: strip headers from data
	const std::string header = "TRANS_HDR|";
	if (data.find(header) == 0) {
        data.erase(0, header.length());
    }
}
