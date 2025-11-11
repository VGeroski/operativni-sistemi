#include <stdio.h>
#include <stdlib.h>

/*
 * Makro kada se definise sa do while, se ponasa slicno kao funkcijski poziv,
 * pri cemu se ne kreira stek okvir kao u slucaju funkcijskih poziva.
 * Potrebno je dodatno ; na kraju */

#define proizvod(a, b)         \
    do                         \
    {                          \
        int rez = ((a) * (b)); \
        printf("%d\n", rez);   \
    } while (0)

#define proizvod_bez_while(a, b) \
    {                            \
        int rez = ((a) * (b));   \
        printf("%d\n", rez);     \
    }

int main()
{
    int x = 10;
    int y = 5;

    if (x > 5)
        proizvod(x, y);

    // U ovom primeru, ovako napisano, else deo bi 'visio'
    // if (x > 5)
    //     proizvod_bez_while(x, y);
    // else
    //     printf("Greska\n");

    exit(EXIT_SUCCESS);
}
