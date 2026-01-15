# RTT Measurement using TCP Sockets in C

This repository contains a TCP client–server implementation in C to measure Round Trip Time (RTT) between a client and a server using socket programming.

The client sends multiple messages to the server, the server echoes each message back, and the client measures the time taken for each round trip.

## Overview
- Implements TCP socket communication using IPv4
- Measures RTT (Round Trip Time) for multiple messages
- Uses `gettimeofday()` for high-resolution time measurement
- Demonstrates basic client–server architecture in C

## Files
| File       | Description                                                                 |
|------------|-----------------------------------------------------------------------------|
| `server.c` | TCP server that listens on a fixed port, accepts connections, receives messages, and echoes them back |
| `client.c` | TCP client that connects to the server, sends multiple messages, and measures RTT for each |

### Requirements
- Linux / Unix-based OS
- GCC compiler
- Basic knowledge of socket programming

## Compilation
Open two terminals.
**Compile the Server:**
```bash
gcc server.c -o server
```

**Compile the Client:**
```bash
gcc client.c -o client
```

## Execution
**Step 1: Run the Server**
```bash
./server
```
*Output:*
```
Server listening on port 8080...
```

**Step 2: Run the Client (in a new terminal)**
```bash
./client
```
The client will:
- Send 10 messages to the server
- Receive echoed responses
- Print RTT for each message in milliseconds

## Sample Output

**Client Side:**
```
Connected to server. Measuring RTT for 10 messages...
Sent: Message 1: Hello from client
Received echo: Message 1: Hello from client
RTT for message 1: 0.245 ms
```

**Server Side:**
```
Received: Message 1: Hello from client
Echoed message back to client
```

## RTT Measurement Logic
1. Client records the timestamp before sending a message
2. Server echoes the message back immediately
3. Client records the timestamp after receiving the echo
4. RTT is calculated as:

   **RTT = (End Time – Start Time) × 1000 ms**

## Learning Outcomes
- Understanding TCP socket lifecycle (`socket`, `bind`, `listen`, `accept`, `connect`)
- Measuring network latency using system timers
- Client–server synchronization
- Practical experience with low-level networking in C

## Use Cases
- Computer Networks / OS lab experiments
- Learning TCP socket programming
- Understanding latency and RTT concepts
- Academic or portfolio demonstration project

## Author
**Name:** Nithyasree K  
**Registration Number:** 3122235001092
