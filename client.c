/*
 * Client Program for RTT Measurement
 * Name: [Your Name]
 * Reg. No: [Your Registration Number]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define NUM_MESSAGES 10

double get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[BUFFER_SIZE] = {0};
    double start_time, end_time, rtt;
    int message_count = 0;
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    printf("Connected to server. Measuring RTT for %d messages...\n", NUM_MESSAGES);
    
    // Send multiple messages and measure RTT
    for (int i = 0; i < NUM_MESSAGES; i++) {
        // Prepare message
        snprintf(buffer, BUFFER_SIZE, "Message %d: %s", i+1, hello);
        
        // Record start time
        start_time = get_current_time();
        
        // Send message
        send(sock, buffer, strlen(buffer), 0);
        printf("Sent: %s\n", buffer);
        
        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);
        
        // Receive echo from server
        read(sock, buffer, BUFFER_SIZE);
        
        // Record end time
        end_time = get_current_time();
        
        // Calculate RTT
        rtt = (end_time - start_time) * 1000; // Convert to milliseconds
        printf("Received echo: %s\n", buffer);
        printf("RTT for message %d: %.3f ms\n\n", i+1, rtt);
        
        // Small delay between messages
        sleep(1);
    }
    
    close(sock);
    
    return 0;
}
