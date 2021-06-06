/* getasn.c: reads a PHP file from isprangefinder.toolforge.org and converts it to raw list of IP addresses */
/* Steven Sweet
 * 10/5/2020 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_IP_LEN 19

/* Convert: accepts a row number as if ip were never converted
 * to a multidemensional array. Returns a pointer to a string*/
void check_line(void);

int main(void) {
    check_line();
    return 0;
}

/* This function prints each IP address to stdout */
void check_line(void) {
    int ch, i = 0, j = 0;
    bool isIP = false;
    char ip[MAX_IP_LEN] = {0};
    while((ch = getchar()) != EOF) {
        if((char)ch == ':' && ip[i-1] >= '0' && ip[i-1] <= '9')  {// We're only looking for IPv4 addresses
            break;
        }
        /* Selects a digit (which has a chance of not being in an IP,) a '.', and a '/' */
        if(((char)ch >= '0' && (char)ch <= '9') || (((char)ch == '.') &&
             (ip[i-1] >= '0') && (ip[i-1] <= '9')) || ((char)ch == '/' && ip[i-1] >= '0' && ip[i-1]
                <= '9')) { // Check to see if the character being read is part of an IP address
            /* Assume it is, and store it into the IP */
            ip[i++] = ch;
        } 
        /* Something has been stored into the IP array, and now the program is receiving irrelevant characters */        
        else if(i > 0) {
            /* See if an IP has been stored or a trailing digit */
            for(j = 0; j < i; j++) {
                // The string contained is an IP if it has a '.'
                if(ip[j] == '.') {
                    isIP = true;
                }
            }   
            if(isIP) {
                ip[i] = 0;
                i = 0;
                puts(ip);
                isIP = false;
            } else {
                i = 0;
            }
        }
    }
}

