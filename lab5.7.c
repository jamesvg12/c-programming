// Write a program that accepts IPv4 32-bit addresses in octet form (e.g., 192.168.23.24) and then prints them out both in 
// octet form as well as a whole address value in hex. Make use of unions.

#include <stdio.h>
#include <stdint.h>

typedef union {
    uint32_t address;
    uint8_t octets[4];
} IPv4Address;

int main() {
    IPv4Address ip;

    printf("Enter an IPv4 address (e.g., 192.168.23.24): ");

    int octet1, octet2, octet3, octet4;
    if (scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4) != 4) {
        printf("Invalid input format.\n");
        return 1;
    }

    if (octet1 < 0 || octet1 > 255 || octet2 < 0 || octet2 > 255 || 
        octet3 < 0 || octet3 > 255 || octet4 < 0 || octet4 > 255) {
        printf("Each octet must be between 0 and 255.\n");
        return 1;
    }

    ip.octets[0] = octet1;
    ip.octets[1] = octet2;
    ip.octets[2] = octet3;
    ip.octets[3] = octet4;

    printf("IPv4 Address in octet form: %d.%d.%d.%d\n", 
            ip.octets[0], ip.octets[1], ip.octets[2], ip.octets[3]);

    printf("IPv4 Address in hexadecimal form: 0x%08X\n", ip.address);

    return 0;
}
