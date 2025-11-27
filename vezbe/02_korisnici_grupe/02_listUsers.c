/**
 * Program treba da ispise informacije o svim korisnicama na sistemu.
 */
#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool os_print_user_info(const struct passwd *userInfo, FILE *outStream)
{
    /* Ispis informacija koje postoje u passwd fajlu o korisniku */
    fprintf(outStream, "------------------------------------\n");
    fprintf(outStream, "User name: %s\n", userInfo->pw_name);
    fprintf(outStream, "Numerical user id: %d\n", (int)userInfo->pw_uid);
    fprintf(outStream, "Numerical group id: %d\n", (int)userInfo->pw_gid);
    fprintf(outStream, "Comment: %s\n", userInfo->pw_gecos);
    fprintf(outStream, "Home directory: %s\n", userInfo->pw_dir);
    fprintf(outStream, "Shell: %s\n", userInfo->pw_shell);
    fprintf(outStream, "--------------- END ---------------\n");

    return true;
}

/* Funkcija lista passwd fajl */
void os_list_all_users(FILE *outStream)
{
    struct passwd *currentUser;

    /* Prilikom citanja sadrzaja passwd fajla,
       neophodno je na pocetku premotati ceo fajl na pocetak */
    setpwent();

    /* passwd fajl se iterativno cita liniju po linuju */
    while ((currentUser = getpwent()) != NULL)
        checkError(os_print_user_info(currentUser, outStream), "Printing user failed");

    /* Nakon sto se zavrsi, passwd mora da se pravilno zatvori! */
    endpwent();
}

int main(int argc, char **argv)
{
    os_list_all_users(stdout);

    exit(EXIT_SUCCESS);
}
