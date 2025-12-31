/* Program demonstrira pravljenje rupe u fajlu, tzv. "hole" */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 4096

void error(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

int main()
{
    char buffer1[] = "qwertyuiop"; /* Bafer za prvi sadrzaj koji se upisuje u fajl. */
    char buffer2[] = "QWERTYUIOP"; /* Bafer za drugi sadrzaj koji se upisuje u fajl. */
    int fd;                        /* Fajl deskriptor. */

    /* Otvara se fajl. Ako ne postoji, kreira se. */
    if ((fd = open("file.hole", O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH)) < 0)
        error("open()");

    /* Upisuje se u fajl sadrzaj prvog bafera. */
    if (write(fd, buffer1, 10) != 10)
        error("write()");

    /* Pomera se ofset za 1000 bajtova. */
    if (lseek(fd, 1000, SEEK_CUR) < 0)
        error("lseek()");

    /* Upisuje se u fajl sadrzaj drugog bafera. */
    if (write(fd, buffer2, 10) != 10)
        error("write()");

    /* komandom: 
       $ls -l -> mozemo da vidimo velicinu fajla (nece biti samo 20, nego ce imati i rupu) 
       $od -c file.hole -> mozemo da vidimo ceo fajl sa rupom, sa flagom -c tumaci sadrzaj kao karaktere */

    exit(fd);
    exit(EXIT_SUCCESS);
}