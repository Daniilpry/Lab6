#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = malloc(5 * sizeof(int));

    if (array == NULL) {
        perror("malloc failed");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        array[i] = i * 10;
    }

    printf("Now writing out of bounds...\n");
    array[5] = 999;  // Write overflow

    for (int i = 0; i <= 5; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);
    return 0;
}
