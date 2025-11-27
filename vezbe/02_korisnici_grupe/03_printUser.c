/**
 * Program treba da ispise informacije o korisniku cije je ime 'username'
 * pri cemu se informacije dobijaju iz passwd fajla.
 *
 * Primer poziva programa:
 *     ./a.out -n username
 *     ./a.out -u user_id (1000)
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Neophodno zaglavlje kada radimo sa funkcijama koji citaju passwd fajl. */
#include <pwd.h>

#define checkError(expr, userMsg) \
    do                            \
    {                             \
        if (!(expr))              \
        {                         \
            perror(userMsg);      \
            exit(EXIT_FAILURE);   \
        }                         \
    } while (0)

/* Funkcija ispisuje informaciju o korisniku iz passwd fajla */
void print_user(const struct passwd *userInfo)
{
    /* Ispis informacija koje postoje u passwd fajlu o korisniku */
    printf("User name: %s\n", userInfo->pw_name);
    printf("Numerical user id: %d\n", (int)userInfo->pw_uid);
    printf("Numerical group id: %d\n", (int)userInfo->pw_gid);
    printf("Comment: %s\n", userInfo->pw_gecos);
    printf("Home directory: %s\n", userInfo->pw_dir);
    printf("Shell: %s\n", userInfo->pw_shell);
}

int main(int argc, char **argv)
{
    checkError(argc == 3, "args");

    if (strcmp(argv[1], "-u") == 0)
    {
        /* napomena: ako ne prosledimo broj, atoi dace 0, pa ce da se iscita root */
        int id = atoi(argv[2]);
        struct passwd *pwd = getpwuid((uid_t)id);

        print_user(pwd);
    }
    else if (strcmp(argv[1], "-n") == 0)
    {
        struct passwd *pwd = getpwnam(argv[2]);

        print_user(pwd);
    }
    else
    {
        checkError(0, "opt -u|-n");
    }

    exit(EXIT_SUCCESS);
}
