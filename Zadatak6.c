#include <stdlib.h>
#include <stdio.h>

float* izdvoj_vrstu(float** matrica, int n, int m, int i) {
    float* niz = malloc(n * sizeof(float));

    for (int k = 0; k < n; k++) {
        niz[k] = matrica[k][i];
    }

    return niz;
}

int najvise_sa_znakom(float** matrica, int n, int m, int (*funkcija)(float*, int)) {
    int indeks = m - 1;
    for (int i = 0; i < (m - 1); i++) {
        float* max = izdvoj_vrstu(matrica, n, m, indeks);
        float* trenutna = izdvoj_vrstu(matrica, n, m, i);

        if (funkcija(trenutna, n) > funkcija(max, n)) {
            indeks = i;
        }

        free(max);
        free(trenutna);
        // Mozda i ovo moze samo da se pozove na kraju petlje, ali mi deluje
        // da bi tako ostalo dosta nizova koji nisu oslobodjeni
    }
    return indeks;
}

int br_negativnih(float* niz, int duzina_niza) {
    int br = 0;
    for (int i = 0; i < duzina_niza; i++) {
        if (niz[i] < 0) {
            br++;
        }
    }
    return br;
}

int br_pozitivnih(float* niz, int duzina_niza) {
    int br = 0;
    for (int i = 0; i < duzina_niza; i++) {
        if (niz[i] > 0) {
            br++;
        }
    }
    return br;
}

void stampajNiz(float* niz, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f\t", niz[i]);
    }
}

void stampajMatricu(float** matrica, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%f\t", matrica[i][j]);
        }
        printf("\n");
    }
}

void ucitaj_matricu(float** matrica, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Unesite el. matrice na poz. [%d][%d]: ", i, j);
            scanf("%f", &matrica[i][j]);
        }
    }
}

int main() {

    int n, m;
    printf("Unesite prvu dimenziju matrice: ");
    scanf("%d", &n);
    printf("Unesite drugu dimenziju matrice: ");
    scanf("%d", &m);

    float** matrica = malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        matrica[i] = malloc(m * sizeof(float));
    }

    ucitaj_matricu(matrica, n, m);
    stampajMatricu(matrica, n, m);

    int vrstaNegativni = najvise_sa_znakom(matrica, n, m, br_negativnih);
    int vrstaPozitivni = najvise_sa_znakom(matrica, n, m, br_pozitivnih);

    printf("Indeks vrste sa najvise poz. br. je %d, ", vrstaPozitivni);
    printf("a za neg. br. je %d", vrstaNegativni);

    for (int i = 0; i < n; i++) {
        free(matrica[i]);
    }
    free(matrica);

    return 0;
}