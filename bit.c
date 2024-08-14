#include <stdio.h>
#include <stdint.h>

// Assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int __ashrsi3(int a, int b) {
    int result = a;

    for (int i = 0; i < b; i++)
    {
        result = result / 2;
    }

    return result;
}

int main() {
    int8_t a = -12;
    int8_t b = 2;
    
    int16_t result = a >> b;
    printf("Result: %d\n", result);

    int16_t result2 = __ashrsi3(a, b);
    printf("Result2: %d\n", result2);

    printf("------------- \n");

    printBits(sizeof(a), &a);
    printBits(sizeof(b), &b);
    printBits(sizeof(result), &result);
    printBits(sizeof(result2), &result2);

    return 0;
}
