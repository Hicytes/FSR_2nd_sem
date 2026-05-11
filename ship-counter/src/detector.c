#include "../include/detector.h"

int count_tanks(unsigned char *data, int width, int height, int threshold) {
    int count = 0;
    int y = 1;
    
    while (y < height) {
        int x = 1;
        while (x < width) {
            int idx = y * width + x;
            
            if (data[idx] > threshold) {
                 if (data[idx - 1] <= threshold && data[idx - width] <= threshold) {
                    count++;
                }
            }
            x++;
        }
        y++;
    }
    
    return count;
}
