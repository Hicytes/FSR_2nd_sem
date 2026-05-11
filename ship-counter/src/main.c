#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#define STBI_ONLY_JPEG
#include "../include/stb_image.h"
#include "../include/detector.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file> [threshold]\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    int threshold = (argc > 2) ? atoi(argv[2]) : 252;

    int width, height, channels;
    unsigned char *data = stbi_load(filename, &width, &height, &channels, 1);
    
    if (!data) {
        printf("Error: Can't read file %s\n", filename);
        return 1;
    }

    int result = count_tanks(data, width, height, threshold);
    
     printf("%d\n", result);

    stbi_image_free(data);
    return 0;
}
