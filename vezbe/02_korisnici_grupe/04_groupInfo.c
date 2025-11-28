/**
 * Program treba da ispise informacije o grupi 'groupname'
 * pri cemu se informacije dobijaju iz group fajla.
 *
 * Primer poziva programa: ./a.out groupname
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

/* Neophodno zaglavlje kada radimo sa funkcijama koji citaju group fajl. */
#include <grp.h>

#define checkError(expr, userMsg) \
    do                            \
    {                             \
        if (!(expr))              \
        {                         \
            perror(userMsg);      \
            exit(EXIT_FAILURE);   \
        }                         \
    } while (0)

int main(int argc, char **argv)
{
    checkError(argc == 2, "args");

    struct group *groupInfo = getgrnam(argv[1]);
    checkError(groupInfo != NULL, "...");

    printf("Group name: %s\n", groupInfo->gr_name);
    printf("Group password: %s\n", groupInfo->gr_passwd);
    printf("Group ID: %d\n", (int)groupInfo->gr_gid);
    for (int i = 0; groupInfo->gr_mem[i] != NULL; i++)
        printf("\t%s\n", groupInfo->gr_mem[i]);

    exit(EXIT_SUCCESS);
}
