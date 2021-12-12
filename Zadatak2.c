#include <stdlib.h>
#include <stdio.h>
#define PI 3.14

int duzinaNiza = 0;

void stampaj(float* niz, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f\t", niz[i]);
    }
}

void ucitaj(float* niz, int n) {
    for (int i = 0; i < n; i++) {
        printf("Unesite %d. element niza: ", i);
        scanf("%f", niz + i);
    }
}

float* izdvoj(float* niz, int n) {
    for (int i = 0; i < n; i++) {
        if (niz[i] > PI) {
            duzinaNiza++;
        }
    }

    float* nizVeci = malloc(duzinaNiza * sizeof(float));

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] > PI) {
            nizVeci[k] = niz[i];
            k++;
        }
    }

    return nizVeci;
}

int main() {

    int n;
    printf("Unesite velicinu niza: ");
    scanf("%d", &n);

    float* niz = malloc(n * sizeof(float));
    ucitaj(niz, n);

    float* nizIzdvojeni = izdvoj(niz, n);
    stampaj(nizIzdvojeni, duzinaNiza);

    free(niz);
    free(nizIzdvojeni);
    // U zadacima sa vezbi ovi nizovu iz funkcija nisu oslobadjani,
    // ali meni to nema smisla, pa sam ih ja oslobodio
    // https://stackoverflow.com/questions/48256539/how-to-free-an-allocated-array-in-a-function-in-c

    return 0;
    
}