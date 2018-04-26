#include <stdio.h>
#include <main.h>
#include <utilities.h>

int main() {

    // read a binary data
    unsigned char buffer[10];
    FILE *ptr;

    ptr = fopen("data_80x40.raw", "rb");
    fread(buffer, sizeof(buffer), 1, ptr);

    for (int i = 0; i < 10; i++)
        printf("%u ", buffer[i]);

    return(0);
}

