# Internet Protocol Stack Simulation

This is a C++ program that models a basic version of the internet protocol stack, focusing on four main layers: Application, Transport, Network, and Link. It shows how data is wrapped with headers (encapsulation) when sent, and unwrapped (decapsulation) when received. As the message moves through each layer, the program prints updates in the terminal to clearly show how the data is processed step by step. This simulation also includes extra features like checksum validation, ARP resolution, and randomized packet loss/corruption for realism.

## File Overview

### Root Directory
- **main.cpp** – 
  Serves as the main driver of the program. It begins by prompting the user to enter a message, which is then passed through four protocol layers: **Application → Transport → Network → Link**.

  - During the **sending phase**, each layer adds its own header to simulate encapsulation.
  - During the **receiving phase**, the process is reversed: **Link → Network → Transport → Application**, and each layer removes its corresponding header to simulate decapsulation.

  Throughout both phases, the program prints terminal output to clearly show how the message is transformed as it moves through the stack.

### Layers


- **application.h / application.cpp** – Represents the Application layer; uses the `APP_HDR` header.
- **transport.h / transport.cpp** – Simulates the Transport layer with the `TRANS_HDR` header and handles checksum functionality.
- **network.h / network.cpp** – Implements the Network layer, using the `NET_HDR` header and simulating corruption or drop.
- **link.h / link.cpp** – Models the Link layer, appending and removing the `LINK_HDR` header and resolving IP to MAC via ARP.

## Optional Extensions Implemented 

This program includes all three of the optional simulation enhancements:

1. **ARP Resolution at the Link Layer**
   - Simulates resolving an IP address to a MAC address via a hardcoded ARP table.
   - User selects a destination IP from a menu.
   - The Link layer prints the resolution before transmission.

2. **Checksums in the Transport Layer**
   - Calculates a simple checksum using ASCII values modulo 256.
   - Appends it in the header during send; validates it during receive.
   - If corruption occurs, a checksum mismatch warning is printed.

3. **Simulated Packet Corruption or Drop**
   - Network layer has a 10% chance to corrupt the packet and a 10% chance to drop it.
   - Drop skips transmission entirely.
   - Corruption modifies part of the message, triggering checksum errors or malformed headers.

   

## How to Build the Project



### Option 1: Build using VS Code (Recommended)
1. Open the project in Visual Studio Code.
2. Press `Ctrl+Shift+B` to run the build task (defined in `.vscode/tasks.json`).
3. This compiles the project using `g++` and produces an executable named `main`.

### Option 2: Build manually using terminal
```bash
g++ main.cpp layers/*.cpp -o main
```

##  Development Environment

- **Editor:** Visual Studio Code
- **Platform Target:** Windows (WSL or native build)
- **Build Tool:** g++ via terminal or VS Code tasks


## Sample Output

```python

Message to send: Hello, Network!

Select destination IP:
  1. 192.168.0.10
  2. 192.168.0.11
Enter choice (1 or 2): 1
Message sent: Hello, Network!

==== Sending ====
[Application layer] Sending: Hello, Network!
[Transport layer] Sending: APP_HDR|Hello, Network! (Checksum: 229)
[Network layer] Sending: TRANS_HDR:CHKSUM_229|APP_HDR|Hello, Network!
[Link layer] ARP resolved: 192.168.0.10 -> AA:BB:CC:DD:EE:01
[Link layer] Sending: NET_HDR|TRANS_HDR:CHKSUM_229|APP_HDR|Hello, Network!

==== Receiving ====
[Link layer] Receiving: LINK_HDR|NET_HDR|TRANS_HDR:CHKSUM_229|APP_HDR|Hello, Network!
[Network layer] Receiving: NET_HDR|TRANS_HDR:CHKSUM_229|APP_HDR|Hello, Network!
[Transport layer] Receiving: TRANS_HDR:CHKSUM_229|APP_HDR|Hello, Network!
[Application layer] Receiving: APP_HDR|Hello, Network!

Final message received: Hello, Network!

```

## Contributors

- **Dylan Beppu** 


- **Jazmin Chavez** 


- **Jacob Miller**