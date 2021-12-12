#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 50

void stampaj(char** knjige, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s", knjige[i]);
        printf("\n");
    }
}

void swap(char** k1, char** k2) {
    char* temp = *k1;
    *k1 = *k2;
    *k2 = temp;
}

void sortiraj(char** knjige, int n) {
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n - 1 - i; j ++) {
            if (strcmp(knjige[j], knjige[j+1]) > 0) {
                swap(&knjige[j], &knjige[j+1]);
            }
        }
    }
}

// Mnogo lakse, bez adresa i tih gluposti
void sortiraj2(char** knjige, int n) {
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n - 1 - i; j ++) {
            if (strcmp(knjige[j], knjige[j+1]) > 0) {
                char* temp = knjige[j];
                knjige[j] = knjige[j+1];
                knjige[j+1] = temp;
            }
        }
    }
}

void ucitaj_knjige(char** knjige, int n) {
    printf("Unesite naslove:\n");
    for(int i = 0; i < n; i++) {
        fgets(knjige[i], MAX, stdin);
        knjige[i][strcspn(knjige[i], "\n")] = '\0';
    }
}

void ucitaj_knjige2(char** knjige, int n) {
    printf("Unesite naslove:\n");
    for(int i = 0; i < n; i++) {
        scanf("%50s", knjige[i]); // Najjednostavniji nacin, nema cimanja sa fgets i getchar()
        // Kao u prethodnom zadatku, jedina mana sto ne prepoznaje kada se unese samo enter
        // Ali mislim da ovo Dusica dozvoljava na kolokvijumu, tako da se ne morate cimati
        // sa fgets() ako ne zelite (Ovo je moja pretpostavka, proverite sa Dusicom)
    }
}

int main() {

    int n;
    printf("Unesite broj knjiga: ");
    scanf("%d", &n);

    getchar(); // Jos jedan od razloga zasto "volim" fgets
    // scanf() ostavlja znak "\n" za sobom i kada se posle njega pozove fgets() on taj enter procita 
    // i sacuva ga kao string. Da se to ne bi desilo, ova funkcija se pozove kako bi "pojela" znak "\n"
    // i samim tim ostavila cist input za fgets(). Ovo se ne mora koristiti ako koristite ucitaj_knjige2

    char** knjige = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        knjige[i] = malloc(MAX * sizeof(char));
    }

    ucitaj_knjige(knjige, n);
    sortiraj(knjige, n);

    printf("Rezultat sortiranja:\n");
    stampaj(knjige, n);

    for (int i = 0; i < n; i++) {
        free(knjige[i]);
    }
    free(knjige);

    return 0;
}