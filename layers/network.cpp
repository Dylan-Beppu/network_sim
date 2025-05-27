#include "network.h"

void network::sendData(std::string& data) {
    // simulate random behavior
    int chance = rand() % 100;

	// 10% chance to drop the packet
    if (chance < 10) {
        std::cout << "[Network layer] Packet dropped!" << std::endl;
		// clear data to simulate loss
        data = ""; 
        return;
    }

	// 10% chance to corrupt the packet
    if (chance < 20) {
        if (!data.empty()) {
			// corrupt first character
            data[0] = '#'; 
            std::cout << "[Network layer] Packet corrupted!" << std::endl;
        }
    }

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
