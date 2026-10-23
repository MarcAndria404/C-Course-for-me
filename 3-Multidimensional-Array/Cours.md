# Module 3: tableaux multidimensionnel

Concept. Un tableau int m[2][3] est une grille de 2 lignes et 3 colonnes. En mémoire, il n’existe pas de grille : les 6 entiers sont rangés les uns après les autres, ligne par ligne. Retiens cette phrase : on en reparlera au module 6 sur les pointeurs, et elle expliquera pourquoi, quand on passe un tableau 2D à une fonction, le compilateur exige de connaître le nombre de colonnes.

Maths. Une matrice A de m lignes et n colonnes est un tableau de nombres a(i,j), avec i pour la ligne et j pour la colonne. Le produit d’une matrice A (m×n) par une matrice B (n×p) donne une matrice C (m×p) dont chaque case est :

```c
c_{ij} = \sum_{k=0}^{n-1} a_{ik} \, b_{kj}
```

Exemple a faire a la main avant de coder:

```c
\begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix}
\begin{pmatrix} 5 & 6 \\ 7 & 8 \end{pmatrix}
```
