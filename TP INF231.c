#include <stdio.h>
#include <stdlib.h>

// 1. Somme de matrices
void sommeMatrices() {
    int lignes, colonnes;
    printf("Entrez le nombre de lignes et colonnes : ");
    scanf("%d %d", &lignes, &colonnes);
    
    int A[lignes][colonnes], B[lignes][colonnes], C[lignes][colonnes];
    
    printf("Matrice A :\n");
    for(int i = 0; i < lignes; i++)
        for(int j = 0; j < colonnes; j++)
            scanf("%d", &A[i][j]);
    
    printf("Matrice B :\n");
    for(int i = 0; i < lignes; i++)
        for(int j = 0; j < colonnes; j++)
            scanf("%d", &B[i][j]);
    
    printf("Resultat :\n");
    for(int i = 0; i < lignes; i++) {
        for(int j = 0; j < colonnes; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

// 2. Produit de matrices
void produitMatrices() {
    int l1, c1, l2, c2;
    printf("Dimensions de A (lignes colonnes) : ");
    scanf("%d %d", &l1, &c1);
    printf("Dimensions de B (lignes colonnes) : ");
    scanf("%d %d", &l2, &c2);
    
    if(c1 != l2) {
        printf("Dimensions incompatibles !\n");
        return;
    }
    
    int A[l1][c1], B[l2][c2], C[l1][c2];
    
    printf("Matrice A :\n");
    for(int i = 0; i < l1; i++)
        for(int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);
    
    printf("Matrice B :\n");
    for(int i = 0; i < l2; i++)
        for(int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);
    
    for(int i = 0; i < l1; i++) {
        for(int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for(int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    
    printf("Resultat :\n");
    for(int i = 0; i < l1; i++) {
        for(int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}

// 3. Recherche séquentielle
void rechercheSequentielle() {
    int n, val;
    printf("Taille du tableau : ");
    scanf("%d", &n);
    int tab[n];
    
    printf("Elements du tableau :\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &tab[i]);
    
    printf("Valeur a rechercher : ");
    scanf("%d", &val);
    
    for(int i = 0; i < n; i++) {
        if(tab[i] == val) {
            printf("%d trouve a l'indice %d\n", val, i);
            return;
        }
    }
    printf("%d non trouve\n", val);
}

// 4. Multiplication par additions
int multiplication(int a, int b) {
    int res = 0;
    for(int i = 0; i < b; i++)
        res += a;
    return res;
}

// 5. Vérification tableau trié
void estTrie() {
    int n;
    printf("Taille du tableau : ");
    scanf("%d", &n);
    int tab[n];
    
    printf("Elements du tableau :\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &tab[i]);
    
    for(int i = 0; i < n-1; i++) {
        if(tab[i] > tab[i+1]) {
            printf("Tableau non trie\n");
            return;
        }
    }
    printf("Tableau trie\n");
}

// 6. Médian (version simplifiée pour tableau trié)
void median() {
    int n;
    printf("Taille du tableau : ");
    scanf("%d", &n);
    int tab[n];
    
    printf("Elements du tableau :\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &tab[i]);
    
    // Tri bulle pour préparer le médian
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(tab[j] > tab[j+1]) {
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
    
    if(n % 2 == 1)
        printf("Median : %d\n", tab[n/2]);
    else
        printf("Median : %.2f\n", (tab[n/2-1] + tab[n/2]) / 2.0);
}

// 7. Inversion tableau
void inverserTableau() {
    int n;
    printf("Taille du tableau : ");
    scanf("%d", &n);
    int tab[n];
    
    printf("Elements du tableau :\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &tab[i]);
    
    for(int i = 0; i < n/2; i++) {
        int temp = tab[i];
        tab[i] = tab[n-1-i];
        tab[n-1-i] = temp;
    }
    
    printf("Tableau inverse :\n");
    for(int i = 0; i < n; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

// 8. Produit vectoriel (pour 3D)
void produitVectoriel() {
    int u[3], v[3], w[3];
    
    printf("Vecteur u (x y z) : ");
    scanf("%d %d %d", &u[0], &u[1], &u[2]);
    
    printf("Vecteur v (x y z) : ");
    scanf("%d %d %d", &v[0], &v[1], &v[2]);
    
    w[0] = u[1]*v[2] - u[2]*v[1];
    w[1] = u[2]*v[0] - u[0]*v[2];
    w[2] = u[0]*v[1] - u[1]*v[0];
    
    printf("u x v = (%d, %d, %d)\n", w[0], w[1], w[2]);
}

// 9. Produit vecteur × matrice
void produitVecteurMatrice() {
    int n, m;
    printf("Dimensions de la matrice (lignes colonnes) : ");
    scanf("%d %d", &n, &m);
    
    int vect[m], mat[n][m], res[n];
    
    printf("Vecteur (taille %d) :\n", m);
    for(int i = 0; i < m; i++)
        scanf("%d", &vect[i]);
    
    printf("Matrice %dx%d :\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
    
    for(int i = 0; i < n; i++) {
        res[i] = 0;
        for(int j = 0; j < m; j++)
            res[i] += vect[j] * mat[i][j];
    }
    
    printf("Resultat :\n");
    for(int i = 0; i < n; i++)
        printf("%d ", res[i]);
    printf("\n");
}

int main() {
    int choix;
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche sequentielle\n");
        printf("4. Multiplication a*b\n");
        printf("5. Test tableau trie\n");
        printf("6. Median\n");
        printf("7. Inverser tableau\n");
        printf("8. Produit vectoriel\n");
        printf("9. Produit vecteur*matrice\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        
        switch(choix) {
            case 1: sommeMatrices(); break;
            case 2: produitMatrices(); break;
            case 3: rechercheSequentielle(); break;
            case 4: {
                int a, b;
                printf("Entrez a et b : ");
                scanf("%d %d", &a, &b);
                printf("%d * %d = %d\n", a, b, multiplication(a, b));
                break;
            }
            case 5: estTrie(); break;
            case 6: median(); break;
            case 7: inverserTableau(); break;
            case 8: produitVectoriel(); break;
            case 9: produitVecteurMatrice(); break;
        }
    } while(choix != 0);
    
    return 0;
}