#include <stdio.h>

void calcul_moyenne(int nbr_edu, int nbr_matiere, float notes[50][20]) {
    float moyenne;
    for (int i = 0; i < nbr_edu; i++) {
        moyenne = 0;
        for (int j = 0; j < nbr_matiere; j++) {
            moyenne += notes[i][j];
        }
        printf("la moyenne de etudiant %d : %.2f \n", i + 1, moyenne / nbr_matiere);
    }
}

void calcul_min_max_matiere(int nbr_edu, int nbr_matiere, float notes[50][20], float *min, float *max) {

    for (int j = 0; j < nbr_matiere; j++) {
        *min = 20;
        *max = 0;
        printf("--------------------- pour la matiere %d :---------------------\n", j + 1);
        for (int i = 0; i < nbr_edu; i++) {
            if (*min > notes[i][j]) {
                *min = notes[i][j];
            }
            if (*max < notes[i][j]) {
                *max = notes[i][j];
            }
        }
        printf("le min est :%.2f \n", *min);
        printf("le max est :%.2f \n", *max);
    }
}

void calcul_min_max_edu(int nbr_edu, int nbr_matiere, float notes[50][20], float *min, float *max) {

    for (int i = 0; i < nbr_edu; i++) {
        *min = 20;
        *max = 0;
        printf("--------------------- pour l'etudiant %d :---------------------\n", i + 1);
        for (int j = 0; j < nbr_matiere; j++) {

            if (*min > notes[i][j]) {
                *min = notes[i][j];
            }

            if (*max < notes[i][j]) {
                *max = notes[i][j];
            }
        }
        printf("le min est :%.2f \n", *min);
        printf("le max est :%.2f \n", *max);
    }
}

void tris(int nbr_edu, int nbr_matiere, float notes[50][20]) {
    char choix;
    float T;
    printf("entrer le choix de trier : \n si vous voulez le trier croissante ecrire C si decroissant entrer D : ");
    scanf(" %c", &choix);
    for (int i = 0; i < nbr_edu; i++) {
        for (int j = 0; j < nbr_matiere - 1; j++) {
            for (int k = 0; k < nbr_matiere - j - 1; k++) {
                switch (choix) {
                    case 'C':
                        if (notes[i][k] > notes[i][k + 1]) {
                            T = notes[i][k];
                            notes[i][k] = notes[i][k + 1];
                            notes[i][k + 1] = T;
                        }
                        break;
                    case 'D':
                        if (notes[i][k] < notes[i][k + 1]) {
                            T = notes[i][k];
                            notes[i][k] = notes[i][k + 1];
                            notes[i][k + 1] = T;
                        }
                        break;
                    default:
                        printf("erreur de la saisie :\n");
                        printf("rentre C ou D :");
                        scanf(" %c", &choix);
                }
            }
        }
    }
}

void affichage_tris(int nbr_edu, int nbr_matiere, float notes[50][20]) {
    for (int i = 0; i < nbr_edu; i++) {
        printf("---------------------le trier d'etudiant %d:---------------------\n", i + 1);
        for (int j = 0; j < nbr_matiere; j++) {
            printf("%.2f\t", notes[i][j]);
        }
        printf("\n");
    }
}


int main() {

    float notes[50][20], min, max;
    int nbr_edu, nbr_matiere;

    do {
        printf("saisir le nombre total de matiere:");
        scanf("%d", &nbr_matiere);
    } while (nbr_matiere < 0 || nbr_matiere >= 20);

    do {
        printf("saisir le nombre total d'etudiant:");
        scanf("%d", &nbr_edu);
    } while (nbr_edu < 0 || nbr_edu >= 50);


    for (int i = 0; i < nbr_edu; i++) {
        printf("saisir pour etudiant %d:\n", i + 1);
        for (int j = 0; j < nbr_matiere; j++) {

            printf("la note de matiere %d:", j + 1);
            scanf("%f", &notes[i][j]);

            while (notes[i][j] > 20 || notes[i][j] < 0) {
                printf("resaisir la note entre 0 et 20 :");
                scanf("%f", &notes[i][j]);
            }

        }
    }

    calcul_moyenne(nbr_edu, nbr_matiere, notes);

    calcul_min_max_matiere(nbr_edu, nbr_matiere, notes, &min, &max);

    calcul_min_max_edu(nbr_edu, nbr_matiere, notes, &min, &max);

    tris(nbr_edu, nbr_matiere, notes);

    affichage_tris(nbr_edu, nbr_matiere, notes);


    return 0;
}