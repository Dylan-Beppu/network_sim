# Internet Protocol Stack Simulation

This is a C++ program that models a basic version of the internet protocol stack, focusing on four main layers: Application, Transport, Network, and Link. It shows how data is wrapped with headers (encapsulation) when sent, and unwrapped (decapsulation) when received. As the message moves through each layer, the program prints updates in the terminal to clearly show how the data is processed step by step.

## File Overview

### Root Directory
- **main.cpp** – 
  Serves as the main driver of the program. It begins by prompting the user to enter a message, which is then passed through four protocol layers: **Application → Transport → Network → Link**.

  - During the **sending phase**, each layer adds its own header to simulate encapsulation.
  - During the **receiving phase**, the process is reversed: **Link → Network → Transport → Application**, and each layer removes its corresponding header to simulate decapsulation.

  Throughout both phases, the program prints terminal output to clearly show how the message is transformed as it moves through the stack.

### Layers


- **application.h / application.cpp** – Represents the Application layer; uses the `APP_HDR` header.
- **transport.h / transport.cpp** – Simulates the Transport layer with the `TRANS_HDR` header.
- **network.h / network.cpp** – Implements the Network layer, using the `NET_HDR` header.
- **link.h / link.cpp** – Models the Link layer, appending and removing the `LINK_HDR` header.




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

==== Sending ====
[Application Layer] Sending: Hello, Network!
[Transport Layer] Sending: APP_HDR|Hello, Network!
[Network Layer] Sending: TRANS_HDR|APP_HDR|Hello, Network!
[Link Layer] Sending: NET_HDR|TRANS_HDR|APP_HDR|Hello, Network!

==== Receiving ====
[Link Layer] Receiving: LINK_HDR|NET_HDR|TRANS_HDR|APP_HDR|Hello, Network!
[Network Layer] Receiving: NET_HDR|TRANS_HDR|APP_HDR|Hello, Network!
[Transport Layer] Receiving: TRANS_HDR|APP_HDR|Hello, Network!
[Application Layer] Receiving: APP_HDR|Hello, Network!

Final message received: Hello, Network!

```

## Contributors

- **Dylan Beppu** 


- **Jazmin Chavez** 

