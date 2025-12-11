/* Program demonstrira rad sa errno vrednoscu. */
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
    fprintf(stdout, "Greska: %s\n", strerror(EACCES));

    errno = ENOENT;
    fprintf(stdout, "Greska: %s\n", strerror(errno));

    /* ispisace poslednju vrednost errno vrednosti */
    perror("Greksa");

    return 0;
}
