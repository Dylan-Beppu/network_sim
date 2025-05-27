#include "transport.h"

// computeChecksum to sum of all ASCII values mod 256
int computeChecksum(const std::string& payload) {
    int sum = 0;
    for (char c : payload) sum += c;
    return sum % 256;
}

void transport::sendData(std::string& data) {
    int checksum = computeChecksum(data);
    std::cout << "[Transport layer] Sending: " << data << " (Checksum: " << checksum << ")" << std::endl;
	// add header with checksum
    data = "TRANS_HDR:CHKSUM_" + std::to_string(checksum) + "|" + data;
}

void transport::receiveData(std::string &data) {
    std::cout << "[Transport layer] Receiving: " << data << std::endl;

    // extract and validate checksum from header
    std::regex headerPattern("^TRANS_HDR:CHKSUM_(\\d+)\\|");
    std::smatch match;

    if (std::regex_search(data, match, headerPattern)) {
        int expectedChecksum = std::stoi(match[1]);
		// substrings out the header in data
        data = data.substr(match[0].length()); 
        int actualChecksum = computeChecksum(data);

        if (actualChecksum != expectedChecksum) {
            std::cerr << "[Transport layer] WARNING: Checksum mismatch! Data may be corrupted." << std::endl;
        }
    } else {
        std::cerr << "[Transport layer] ERROR: Malformed transport header." << std::endl;
    }
}
