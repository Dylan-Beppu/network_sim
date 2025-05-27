#include "link.h"

// static ARP table, IP to MAC
static std::unordered_map<std::string, std::string> arpTable = {
    {"192.168.0.10", "AA:BB:CC:DD:EE:01"},
    {"192.168.0.11", "AA:BB:CC:DD:EE:02"}
};

void link::sendData(std::string& data, const std::string& destIP) {
    // resolve, IP to MAC
    std::string macAddress;

    if (arpTable.find(destIP) != arpTable.end()) {
        macAddress = arpTable[destIP];
        std::cout << "[Link layer] ARP resolved: " << destIP << " -> " << macAddress << std::endl;
    } 
	else {
        // should not happen, handled encase it does
        macAddress = "??:??:??:??:??:??";
        std::cout << "[Link layer] ARP failed: Unknown IP " << destIP << std::endl;
    }

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
