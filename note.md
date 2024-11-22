Le tri **Radix** est une méthode efficace pour trier une pile dans le cadre de projets comme **push_swap**, notamment pour des piles avec un grand nombre d'éléments. Voici un plan détaillé pour implémenter un **Radix Sort** avec une pile.

---

## **Principe du Tri Radix avec Piles**
Le tri Radix fonctionne en triant les éléments bit par bit (des moins significatifs aux plus significatifs).  

- À chaque itération (par bit), les nombres sont répartis dans deux piles selon la valeur du bit traité.
  - Si le bit est `0`, l'élément reste dans la pile A.
  - Si le bit est `1`, l'élément est déplacé dans la pile B.
- Une fois toutes les valeurs triées pour un bit, les éléments sont rassemblés dans la pile A.
- On répète cette opération pour chaque bit.

---

## **Étapes du Radix Sort**

### 1. **Trouver le Nombre Maximal**
On commence par trouver la valeur maximale dans la pile pour déterminer le nombre de bits nécessaires au tri.

```c
int find_max(t_stack *stack) {
    int max = stack->value;

    while (stack) {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}
```

---

### 2. **Calculer le Nombre de Bits**
Pour savoir combien d'itérations effectuer, on calcule le nombre de bits nécessaires pour représenter le nombre maximal.

```c
int get_max_bits(int max) {
    int bits = 0;
    while (max > 0) {
        max >>= 1; // Décale les bits vers la droite
        bits++;
    }
    return bits;
}
```

---

### 3. **Tri Radix Principal**
Le cœur de l'algorithme consiste à effectuer un tri bit par bit.

```c
void radix_sort(t_stack **stack_a, t_stack **stack_b) {
    int max = find_max(*stack_a);
    int max_bits = get_max_bits(max);
    int size = stack_size(*stack_a); // Nombre total d'éléments

    for (int i = 0; i < max_bits; i++) {
        for (int j = 0; j < size; j++) {
            int num = (*stack_a)->value;

            // Vérifier le bit actuel
            if ((num >> i) & 1) {
                ra(stack_a); // Si le bit est 1, faire une rotation
            } else {
                pb(stack_a, stack_b); // Si le bit est 0, pousser dans B
            }
        }

        // Rassembler tous les éléments de B dans A
        while (*stack_b) {
            pa(stack_b, stack_a);
        }
    }
}
```

---

## **Fonctions Utilisées**

### 1. **Fonctions pour les Opérations de Pile**
Les opérations classiques utilisées sont :
- `ra`: Effectue une rotation sur la pile A.
- `pb`: Pousse le sommet de la pile A vers la pile B.
- `pa`: Pousse le sommet de la pile B vers la pile A.

---

## **Exemple d’Utilisation**

### **Programme Principal**
Voici comment intégrer le tri Radix dans ton programme principal :

```c
int main(int argc, char **argv) {
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    if (argc < 2)
        return 0;

    // Initialisation de la pile A
    for (int i = 1; i < argc; i++) {
        push(&stack_a, ft_atoi(argv[i])); // Ajouter les éléments à la pile
    }

    // Exécuter le tri Radix
    radix_sort(&stack_a, &stack_b);

    // Afficher la pile triée
    print_stack(stack_a);

    // Libérer la mémoire
    free_stack(&stack_a);
    return 0;
}
```

---

## **Optimisation**

1. **Normalisation des Indices :**  
   Si les nombres de la pile ne sont pas dans un intervalle consécutif (comme `0–n`), il est conseillé de les **normaliser** en assignant à chaque nombre son rang. Par exemple :
   - Pour une pile `[50, 10, 30]`, transformer en `[2, 0, 1]`.

   ```c
   void normalize_stack(t_stack *stack) {
       t_stack *sorted = copy_stack(stack); // Créer une copie triée
       sort_stack(sorted);                 // Trier la copie
       
       while (stack) {
           stack->value = get_index(sorted, stack->value); // Obtenir l'indice
           stack = stack->next;
       }
       free_stack(&sorted); // Libérer la copie triée
   }
   ```

2. **Utiliser un Masque de Bits :**  
   Les opérations bit à bit peuvent être optimisées avec des masques pour réduire les calculs.

---

## **Complexité**

- **Temps :** \(O(n \times \log(n))\), où \(n\) est la taille de la pile et \(\log(n)\) est le nombre de bits nécessaires pour représenter les nombres.
