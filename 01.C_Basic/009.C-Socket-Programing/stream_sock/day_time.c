#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <time.h>

#define BUFFER_SIZE 128

int main() {
    int listenSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE];
    time_t currentTime;
    struct tm *localTime;

    // Create a TCP socket
    listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific address and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Accept connections from any IP
    serverAddr.sin_port = htons(13); // Daytime service port (port 13)
    if (bind(listenSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error binding");
        close(listenSocket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(listenSocket, 2) == -1) {
        perror("Error listening");
        close(listenSocket);
        exit(EXIT_FAILURE);
    }

    printf("TCP Daytime Server is listening on port 13...\n");

    while (1) {
        // Accept incoming connection
        clientSocket = accept(listenSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket == -1) {
            perror("Error accepting connection");
            continue;
        }

        // Get the current time
        currentTime = time(NULL);
        localTime = localtime(&currentTime);

        // Format the time string
        snprintf(buffer, BUFFER_SIZE, "Time: %02d:%02d:%02d\n",
                 localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

        // Send the time string to the client
        if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
            perror("Error sending data");
        }
        // Close the client socket
        close(clientSocket);
    }

    // Close the listening socket
    close(listenSocket);

    return 0;
}
