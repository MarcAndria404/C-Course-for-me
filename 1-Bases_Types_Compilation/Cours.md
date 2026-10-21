Concept. Un int n’est pas “un nombre magique” : c’est un bloc d’octets en mémoire, et sa taille dépend de la machine. En C, un tableau est un bloc contigu d’éléments du même type, et le C ne vérifie pas les bornes. Lire t[10] dans un tableau de 5 éléments compile sans erreur. Garde ça en tête : c’est la source de la moitié des failles de sécurité.

Maths. La moyenne d’un ensemble de $n$ valeurs est $\mu = \frac{1}{n}\sum_{i=0}^{n-1} x_i$, et la variance est $\sigma^2 = \frac{1}{n}\sum_{i=0}^{n-1}(x_i-\mu)^2$.
