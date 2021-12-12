#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int ukupno_slova = 0;

int prebroj(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            ukupno_slova++;
        }
    }
}

int main() {

    char* nizSlova = malloc(MAX * sizeof(char));
    char stop[] = "stop";

    do {
        // fgets je bolji od gets zato sto brine o ogranicenju i nece doci do overflow-a,
        // ali je isto tako gluplji zato sto kupi i znak enter ("\n") na kraju
        // zato se koristi strcspn da se taj enter "izbaci" sa kraja stringa
        printf("Unesite rec: ");
        fgets(nizSlova, MAX, stdin);
        nizSlova[strcspn(nizSlova, "\n")] = '\0';

        // scanf("%50s", nizSlova);
        // Ovo radi, ali ne prepoznaje enter. Ceka dok korisnik ne unese neki drugi znak
        // Mislim da ce ovo Dusica dozvoliti bez problema, ali nisam siguran

        prebroj(nizSlova);
        printf("Uneli ste %d slova\n", ukupno_slova);
        ukupno_slova = 0;
    } while (strcmp(nizSlova, stop));

    free(nizSlova);
    return 0;

}