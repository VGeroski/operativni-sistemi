/* Program demonstrita koriscenje fajl deskriptora, open i close funkcije. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void error(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    /* Ispisuju se vrednost konstanti za std ulaz, std izlaz i std gresku. */
    fprintf(stdout, "STDIN_FILENO = %d\n", STDIN_FILENO);
    fprintf(stdout, "STDOUT_FILENO = %d\n", STDOUT_FILENO);
    fprintf(stdout, "STDERR_FILENO = %d\n", STDERR_FILENO);

    /* pokusavamo da otvorimo fajl koji ne postoji. */
    int fd; /* fajl deskriptor */
    if ((fd = open("f1.txt", O_RDWR)) < 0)
        error("open()");
    else
        fprintf(stdout, "Fajl deskriptor je %d.\n", fd);

    /* Pokusavamo sa zatvaranjem fajl deskriptora  */
    if (close(fd) < 0)
        error("close()");

    /* pokusavamo da otvorimo fajl koji ne postoji uz O_CREAT flag. */
    if ((fd = open("f1.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH)) < 0)
        error("open()");
    else
        fprintf(stdout, "Uspesno je otvoren fajl, fajl deskriptor je %d\n", fd);

    /* Program se uspesno zavrsava */
    exit(EXIT_SUCCESS);
}
