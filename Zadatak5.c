#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// U tekstu *funkcija vraca int, ali cete se sloziti da je to promasaj
// i da treba da pise float
float* novi_niz(float* niz, int duzina_niza, float (*funkcija)(float, float)) {
    // Procitao sam tekst 10 puta i ja sam na kraju funkciju ovako razumeo
    float* noviNiz = malloc((duzina_niza - 1) * sizeof(float));

    for (int i = 0; i < (duzina_niza - 1); i++) {
        noviNiz[i] = funkcija(niz[i], niz[i+1]);
    }

    return noviNiz;
}

float aritmeticka_sredina(float n, float m) {
    return (n + m) / 2;
}

float geometrijska_sredina(float n, float m) {
    return sqrt(n * m);
}

float* izdvoj_dijagonalu(float** matrica, int n) {
    float* niz = malloc(n * sizeof(float));
    
    for (int i = 0; i < n; i++) {
        niz[i] = matrica[i][i];
    }

    return niz;
}

void ispisNiza(float* niz, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f\t", niz[i]);
    }
    printf("\n");
}

void ispisMatrice(float** matrica, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f\t", matrica[i][j]);
        }
        printf("\n");
    }
}

void ucitaj_matricu(float** matrica, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Unesite el. matrice na poz. [%d][%d]: ", i, j);
            scanf("%f", &matrica[i][j]); // scanf("%f", *(matrica + i) + j);
        }
    }
}

int main() {

    int n;
    printf("Unesite dimenziju kvadratne matrice: ");
    scanf("%d", &n);

    float** matrica = malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        matrica[i] = malloc(n * sizeof(float));
    }

    ucitaj_matricu(matrica, n);
    ispisMatrice(matrica, n);

    float* nizDijagonala = izdvoj_dijagonalu(matrica, n);

    float* nizAritmeticke = novi_niz(nizDijagonala, n, aritmeticka_sredina);
    printf("Niz aritmetickih sredina:\n");
    ispisNiza(nizAritmeticke, n - 1);

    float* nizGeometrijske = novi_niz(nizDijagonala, n, geometrijska_sredina);
    printf("Niz geometrijskih sredina:\n");
    ispisNiza(nizGeometrijske, n - 1);

    for (int i = 0; i < n; i++) {
        free(matrica[i]);
    }
    free(matrica);
    
    free(nizDijagonala);
    free(nizAritmeticke);
    free(nizGeometrijske);

    return 0;

}