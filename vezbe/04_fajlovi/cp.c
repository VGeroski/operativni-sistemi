/* Prgram kopira tekst sa standardnog ulaza na standardni izlaz
   uz pomoc sistemskih poziva read i write */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 4096

void error(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

int main()
{
    int n;                 /* Broj ucitanih odnosno poslatih bajtova */
    char buf[BUFFER_SIZE]; /* Bafer za razmenu poruka */

    while ((n = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0)
        /* ucitane bajtove samo prosledimo na standardni izlaz */
        /* Napomena: kada stampamo, prosledjujemo stavrno ucitane bajtove, ne buf size */
        if (write(STDOUT_FILENO, buf, n) != n)
            error("Write");

    exit(EXIT_SUCCESS);
}