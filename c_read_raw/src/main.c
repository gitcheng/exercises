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
    printf("\n");

    unsigned *data = read_raw("data_80x40.raw", 80, 40, 2);
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 80; j++)
            printf("%d  ", data[i*80+j]);
        printf("\n");
    }
    return(0);
}

