#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int x = 10;
    int y = 5;
    int *px = &x;

    swap(&x, &y);

    printf("*px: %d\n", *px);
    printf("px: %p\n", px);
    printf("%d, %d\n", x, y);

    exit(EXIT_SUCCESS);
}
