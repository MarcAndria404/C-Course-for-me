1. La mémoire est une suite d’octets numérotés

Imagine la mémoire comme une très longue rangée de cases, d’un octet chacune, numérotées à partir de 0. Le numéro d’une case est son adresse. Ce sont des nombres, qu’on écrit en hexadécimal (base 16) parce que c’est plus court : 0x7ffc1a2b est simplement un nombre.

Une variable est un petit groupe de cases consécutives. Un int de 4 octets occupe 4 cases d’affilée. L’adresse de la variable est celle de sa première case.

2. Un pointeur est une variable qui contient une adresse

Un pointeur est une variable comme les autres, sauf que sa valeur est l’adresse d’une autre variable. Il y a trois éléments de syntaxe :

&x donne l’adresse de x.
int *p déclare un pointeur p qui contiendra l’adresse d’un int.
*p (dans une expression) désigne l’objet qui se trouve à l’adresse contenue dans p. On dit qu’on déréférence p.

Le même symbole \* a donc deux rôles : dans une déclaration, il dit « c’est un pointeur » ; dans une expression, il veut dire « va voir ce qu’il y a à cette adresse ». Un exemple avec un autre type que tes exercices :

c
char lettre = 'A';
char *p = &lettre; // p contient l'adresse de lettre
*p = 'B'; // modifie lettre en passant par p

À la fin, lettre vaut 'B', alors qu’on n’a jamais écrit lettre = 'B'. C’est la clé : par l’adresse, on peut modifier une variable depuis n’importe où.

3. Le type du pointeur dit comment lire l’adresse

Une adresse seule ne dit pas ce qu’il y a derrière : 1 octet ? 4 ? 8 ? C’est le type du pointeur qui le dit. int _ signifie « à cette adresse, lis 4 octets et interprète-les comme un entier » ; double _ signifie « lis 8 octets comme un nombre flottant ».

Conséquence : tous les pointeurs ont la même taille (une adresse, 8 octets sur ta machine 64 bits), mais ils ne pointent pas vers le même genre de chose. C’est ce que tu vérifieras avec sizeof(int _) contre sizeof(double _).

4. Pointeurs et tableaux : l’arithmétique d’adresses

Les éléments d’un tableau sont rangés les uns après les autres, sans trou. La formule à retenir est :

latex
\text{adresse}(t[i]) = \text{adresse}(t[0]) + i \times \text{sizeof(type)}

Pour un tableau d’int, la case t[3] est donc 12 octets après t[0]. Le C a une règle pratique : si p est un pointeur sur un élément, alors p + 1 désigne l’élément suivant, c’est-à-dire que l’adresse augmente de sizeof du type pointé, et non de 1. Le compilateur fait la multiplication pour toi.

C’est pour ça que t[i] et \*(t + i) signifient exactement la même chose : l’écriture t[i] est un raccourci.

Dernière règle : dans la plupart des expressions, le nom d’un tableau est converti en l’adresse de son premier élément. Il y a quelques exceptions, et c’est ce que l’exercice 8 te fait explorer avec &t et sizeof.

5. Passer un pointeur à une fonction

Le C passe tout par valeur : une fonction reçoit une copie de chaque argument. Quand l’argument est un Vec2, elle copie tout le vecteur ; quand c’est une adresse, elle copie l’adresse, qui reste valable. La fonction peut alors modifier l’original en déréférençant sa copie de l’adresse.

C’est ce qui explique deux choses que tu as déjà observées :

doubler(c) ne modifiait pas c (copie du vecteur), mais doubler(&c) oui (copie de l’adresse).
fillPlayerNumbers(tab, 5) modifiait ton tableau : le nom du tableau est devenu l’adresse du premier élément (règle du point 4). Les valeurs dans la fonction étaient donc les mêmes cases mémoire. 6. Les dangers (et pourquoi la cybersécurité s’en occupe)

Un pointeur ne vérifie rien : le C te laisse pointer n’importe où. Trois cas classiques :

Pointeur non initialisé : il contient une adresse quelconque. Écrire à travers lui, c’est écrire au hasard dans la mémoire.
Pointeur nul : NULL (adresse 0) signifie « ne pointe sur rien ». Le déréférencer fait planter le programme.
Pointeur vers une variable disparue : une variable locale n’existe plus après la fin de sa fonction. Si tu gardes son adresse, tu pointes sur une case qui sera réutilisée. C’est exactement la raison pour laquelle on ne peut pas renvoyer un tableau local (souviens-toi du return playerNumbers[] de ton loto).

Beaucoup de failles réelles viennent de ces trois cas, plus de l’écriture hors des bornes d’un tableau.

7. const et pointeurs

const Vec2 \*v veut dire : « je promets de ne pas modifier ce qui est pointé par v ». Le compilateur refuse alors toute écriture à travers v. C’est une protection que tu mets dans le prototype pour qu’on sache, en lisant, que la fonction ne touche pas à l’original.
