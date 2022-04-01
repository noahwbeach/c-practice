#include <stdio.h>
#include <stdlib.h>

int test(int **list, int index) {
    if (list != NULL)
        return *list[index];
    else
        exit(1);
}

int main() {
    int *list = malloc(sizeof(int *) * 4);

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    list[3] = 4;

    for (int i = 0; i < 4; i++) {
        printf("%i\n", test(&list, i));
    }

    free(list);
}

