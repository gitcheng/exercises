#include <stdio.h>
#include <stdlib.h>
#include <utilities.h>

void hello_tool(void) {
    printf("Hello my tool!\n");
    return;
}


unsigned *read_raw(const char *fname, unsigned width, unsigned height, unsigned bytes) {
    printf("%s  %d  %d\n", fname, width, height);

    unsigned char buffer[width*height*bytes];
    FILE *ptr = fopen(fname, "rb");
    fread(buffer, sizeof(buffer), 1, ptr);

    unsigned *retval;
    retval = malloc(width * height * sizeof(unsigned*));

    for (int i = 0; i < width*height; i++) {
        unsigned value = 0;
        for (int b = 0; b < bytes; b++) 
            value |= buffer[i*bytes+b] << 8*b;
        retval[i] = value;
    }

    return(retval);
}


