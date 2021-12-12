#include <stdio.h>
#include <stdlib.h>

void stampaj(int* niz, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", niz[i]);
    }
}

void swap(int* b1, int* b2) {
    int temp = *b1;
    *b1 = *b2;
    *b2 = temp;
}

void sort(int* niz, int n) {
    // Ja sam koristio ovde bubble zbog sopstvene vezbe, svejedno je koji se koristi
    // posto ce biti pomoc na kolokvijumu ukoliko bude sort
    // Dusica: "Sortiranja su više bila zbog vežbe, nije neophodno da ih znate.
    // Ukoliko bude neko sortiranje biće data pomoć ili pre ugrađene funkcije da radite."
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (niz[j] > niz[j+1]) {
                swap(&niz[j], &niz[j+1]);
            }
        }
    }
}

void ucitaj(int* niz, int n) {
    for (int i = 0; i < n; i++) {
        printf("Unesite %d. element: ", i);
        scanf("%d", niz + i);
    }
}

int main() {

    int n;
    printf("Unesite velicinu niza: ");
    scanf("%d", &n);

    int* niz = malloc(n * sizeof(int));

    ucitaj(niz, n);
    sort(niz, n);
    stampaj(niz, n);

    free(niz);
    return 0;

}