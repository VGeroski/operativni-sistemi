#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s;

    char t[50];

    t[0] = 'a';
    t[1] = 'b';
    t[2] = 'c';
    // t[3] = '\0';

    /*
     * U ovom trenutku vrednost pokazivaca s je nesto sto je u meoriji u trenutku
     * pokretanja programa. scanf moze da upise na nesto u deo memorije koje je
     * bitno za normalno funkcionisanje programa. */
    // scanf("%s", s);

    /*
     * Niska t nema terminalni karakter, pa potencijalno moze nesto da se nadje
     * u ispisu i nakon karaktera 'c' (zavisno gde je sledeca terminirajuca nula). */

    printf("%s\n", t);

    exit(EXIT_SUCCESS);
}
