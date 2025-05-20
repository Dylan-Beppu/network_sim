#include "transport.h"


void transport::sendData(std::string& data) {
	std::cout << "[Transport layer] Sending: " << data << std::endl;
	data = "TRANS_HDR|" + data;
}

void transport::receiveData(std::string &data) {
	
	std::cout << "[Transport layer] Receiving: " << data << std::endl;
	
	//strip headers from data
	const std::string header = "TRANS_HDR|";
    size_t hPos = data.find(header);
    if (hPos != std::string::npos) {
        data.erase(hPos, header.length());
    }
}
