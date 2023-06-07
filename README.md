# FTP Server Attack

This project is a simple FTP server attack program written in C. It establishes a connection with a specified FTP server and continuously attempts to connect to the server until the program is terminated.
Prerequisites

Before running this program, make sure you have the following:

- C compiler installed (e.g., GCC)
- Basic understanding of the FTP protocol

## Getting Started

To use this program, follow these steps:

1. Clone or download the source code files.
2. Compile the program using a C compiler. For example, using GCC, run the following command:
```sh
gcc ftp_attack.c -o ftp_attack
```
3. Run the program with the target FTP server's IP address as the command-line argument. For example:
```sh
./ftp_attack <target_ip>
```

## Description

The program establishes a TCP socket connection with the specified FTP server using the FTP default port (21). It continuously attempts to connect to the server in an infinite loop until the program is terminated manually.
Implementation Details

The program utilizes the following libraries and functions:

- <stdio.h> and <stdlib.h>: Standard input/output functions and memory allocation functions.
- <string.h>: String manipulation functions.
- <netdb.h>: Network database operations.
- <arpa/inet.h>: Definitions for internet operations.
- <sys/socket.h>: Definitions for socket operations.
- <unistd.h>: POSIX operating system API functions.

The connectToFTP function is responsible for establishing a connection with the FTP server. It creates a socket, converts the IP address to the required format, and connects to the server using the connect function. The function will display a message indicating a successful connection.

The main function validates the command-line arguments and calls the connectToFTP function with the specified IP address and FTP port (21).

## Disclaimer

The authors of this code are not responsible for any misuse or damages caused by running this program. Use it at your own risk and responsibility.