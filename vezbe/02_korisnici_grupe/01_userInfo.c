/**
 * Program treba da ispise informacije o korisniku cije je ime 'username'
 * pri cemu se informacije dobijaju iz passwd fajla.
 *
 * Primer poziva programa: ./a.out username
 */

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

static char *osUsage = "./userInfo username";

/* Funkcija ispisuje informaciju o korisniku iz passwd fajla */
bool os_get_user_info(const char *username, FILE *outStream)
{
    /**
     * Citamo informacije iz passwd fajla o korisniku sa korisnickim imenom username.
     * Funkcija getpwnam vraca pokazivac na staticki alociranu strukturu.
     * BITNO: Ovu struktur nikada ne smemo eksplicitno da
     */
    struct passwd *userInfo = getpwnam(username);
    /* U slucaju greske ili nepostojanja podataka, vraca se NULL */
    if (userInfo == NULL)
        return false;

    /* Ispis informacija koje postoje u passwd fajlu o korisniku */
    fprintf(outStream, "User name: %s\n", userInfo->pw_name);
    fprintf(outStream, "Numerical user id: %d\n", (int)userInfo->pw_uid);
    fprintf(outStream, "Numerical group id: %d\n", (int)userInfo->pw_gid);
    fprintf(outStream, "Comment: %s\n", userInfo->pw_gecos);
    fprintf(outStream, "Home directory: %s\n", userInfo->pw_dir);
    fprintf(outStream, "Shell: %s\n", userInfo->pw_shell);

    return true;
}

int main(int argc, char **argv)
{
    checkError(argc == 2, osUsage);
    checkError(os_get_user_info(argv[1], stdout), "get user info failed");

    exit(EXIT_SUCCESS);
}
