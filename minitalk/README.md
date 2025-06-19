# minitalk

A simple client-server messaging system using UNIX signals in C. Developed as part of the 42 school curriculum.

## Features

- Sends and receives messages between processes using only `SIGUSR1` and `SIGUSR2`
- Supports string transmission from client to server
- Server displays the received message in real-time
- Handles multiple signals efficiently using signal handlers
- Clean and robust implementation with error checking

## Installation

Clone the repository and build:

```bash
git clone https://github.com/your_username/minitalk.git
cd minitalk
make
```

## Usage

1. Run the server:

```bash
./server
```

The server will print its PID.
For example:
Server PID: 12345

2. In another terminal, run the client with a message:

```bash
./client 12345 "Hello from client!"
```
Where 12345 is the server's PID, and the string is the message to send.



