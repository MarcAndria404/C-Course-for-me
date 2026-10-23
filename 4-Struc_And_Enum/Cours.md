# Module 5 : struct et enum

Concept struct. Un struct regroupe plusieurs variables de types différents sous un seul nom : par exemple deux double x et y pour un point. Tes cinq tableaux de loto étaient en fait des morceaux d’une même idée (un tirage, un joueur) : un struct sert à ça.

Concept enum. Un enum donne des noms à des constantes entières : ETAT_ARRET, ETAT_MARCHE... au lieu de 0, 1. Le code se lit sans commentaire. En mémoire, ce n’est qu’un entier.

Deux faits à tester toi-même (ne me crois pas sur parole) :

Un struct passé à une fonction est copié, contrairement à un tableau. Tu verras la différence avec une expérience (exercice ci-dessous).
sizeof d’un struct peut être plus grand que la somme de ses champs. Le compilateur ajoute des octets de remplissage (padding) pour aligner les champs en mémoire. Ça te servira en cybersécurité, quand on lira des en-têtes de paquets réseau à la main.

Maths : vecteurs du plan. Un vecteur v = (x, y). Trois opérations :

somme : (a + b) = (a_x + b_x, a_y + b_y)
produit scalaire : a · b = a_x·b_x + a_y·b_y
norme : ‖v‖ = √(x² + y²)

Calcule sur papier pour a = (3, 4) et b = (1, 2) : a + b, a · b et ‖a‖. Tu auras trois valeurs de référence.
