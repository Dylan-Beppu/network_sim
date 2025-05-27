#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

#include "./layers/application.h"
#include "./layers/transport.h"
#include "./layers/network.h"
#include "./layers/link.h"



void sendData(std::string& data, const std::string& destIP) {
	
	std::cout << "==== Sending ====" << std::endl;

	application::sendData(data);
	transport::sendData(data);
	network::sendData(data);
	link::sendData(data, destIP);
}


void receiveData(std::string& data) {

	std::cout << "==== Receiving ====" << std::endl;

	link::receiveData(data);
	network::receiveData(data);
	transport::receiveData(data);
	application::receiveData(data);
	
}

int main() {

	// seed the random number generator at the start of the program
	srand(time(NULL));

	std::string data;
	std::string destIP;
	int choice = 0;

    std::unordered_map<int, std::string> ipChoices = {
        {1, "192.168.0.10"},
        {2, "192.168.0.11"}
    };

	std::cout << "Message to send: ";
	std::getline(std::cin, data);

	// prompt user for destination IP selection
    while (true) {
        std::cout << std::endl << "Select destination IP:" << std::endl;
		std::cout << "  1. " << ipChoices[1] << std::endl;
		std::cout << "  2. " << ipChoices[2] << std::endl;
		std::cout << "Enter choice (1 or 2): ";
        std::cin >> choice;
        std::cin.ignore(); 

        if (ipChoices.find(choice) != ipChoices.end()) {
            destIP = ipChoices[choice];
            break;
        } 
		else {
            std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
        }
    }

	std::cout << "Message sent: " << data << std::endl << std::endl;
	
	
	// Send data
	sendData(data, destIP);
	
	std::cout << std::endl;

	// Receive data
	receiveData(data);

	std::cout << std::endl;

	std::cout << "Final message received: " << data << std::endl;
	
	return 0;
}
