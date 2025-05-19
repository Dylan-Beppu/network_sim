#include <iostream>
#include <string>

#include "./layers/application.h"
#include "./layers/transport.h"
#include "./layers/network.h"
#include "./layers/link.h"



void sendData(std::string& data) {
	
	std::cout << "==== Sending ====" << std::endl;

	application::sendData(data);
	transport::sendData(data);
	network::sendData(data);
	link::sendData(data);
}


void receiveData(std::string& data) {

	std::cout << "==== Receiving ====" << std::endl;

	link::receiveData(data);
	network::receiveData(data);
	transport::receiveData(data);
	application::receiveData(data);
	
}


int main() {

	std::string data;

	std::cout << "Message to send: ";
	std::getline(std::cin, data);
	std::cout << std::endl;


	std::cout << "Message sent: " << data << std::endl << std::endl;
	
	
	// Send data
	sendData(data);
	
	std::cout << std::endl;

	// Receive data
	receiveData(data);

	std::cout << std::endl;

	std::cout << "Final message received: " << data << std::endl;
	
	return 0;
}
