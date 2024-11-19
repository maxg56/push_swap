
"Turk Algorithm"

swap.c
- Sa
- Sb 
- SS  
Push.c
- pA
- pB 
rotate.c
 - rA
 - RB 
 - rr
reverse_rotate.c
 - Rra
 - rrb
 -rrr

Algorithmes de tri spécifiques à push_swap : Pour le projet push_swap de l'Ecole 42, on utilise souvent des techniques de tri hybrides et optimisées pour un nombre limité d'opérations, comme :
- **Tri de petites piles** : pour les piles de taille ≤ 3 mai 6, il y a des solutions simples en 2-3 mouvements.
- **Tri par segments (Chunk Sort)** : Divise la pile en segments (chunks) et trie chaque segment indépendamment.
- **Tri par déplacement optimisé** : avec des opérations de swap, rotate, et reverse_rotate pour minimiser le nombre de coups.

Ces algorithmes sont adaptés en fonction des contraintes de mémoire et d'optimisation du nombre d'opérations, en particulier pour des projets avec des exigences spécifiques comme push_swap.
{
    "security.workspace.trust.untrustedFiles": "newWindow",
    "editor.insertSpaces": false,
    "editor.comments.insertSpace": false,
    "editor.tabCompletion": "on",
    "git.autofetch": true,
    "makefile.configureOnOpen": true,
    "git.confirmSync": false,
    "files.autoSave": "afterDelay",
    "workbench.colorTheme": "Moonlight Italic",
    "gitlens.advanced.messages": {
        "suppressLineUncommittedWarning": true
    },
    "workbench.iconTheme": "eq-material-theme-icons-deepforest",
    "[c]": {
        
        "editor.wordBasedSuggestions": "off",
        "editor.semanticHighlighting.enabled": true,
        "editor.stickyScroll.defaultModel": "foldingProviderModel",
        "editor.suggest.insertMode": "replace"
    }
}