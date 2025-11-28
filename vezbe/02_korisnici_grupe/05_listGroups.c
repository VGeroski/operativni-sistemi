/**
 * Program treba da ispise sve informacije o svim grupama na sistemu
 */

#define _XOPEN_SOURCE 700
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

void print_group(struct group *groupInfo)
{
    printf("---------------------------------------\n");
    printf("Group name: %s\n", groupInfo->gr_name);
    printf("Group password: %s\n", groupInfo->gr_passwd);
    printf("Group ID: %d\n", (int)groupInfo->gr_gid);
    for (int i = 0; groupInfo->gr_mem[i] != NULL; i++)
        printf("\t%s\n", groupInfo->gr_mem[i]);
}

int main(int argc, char **argv)
{
    checkError(argc == 1, "args");

    setgrent();

    struct group *currentGroup = NULL;
    while ((currentGroup = getgrent()) != NULL)
        print_group(currentGroup);

    endgrent();

    exit(EXIT_SUCCESS);
}