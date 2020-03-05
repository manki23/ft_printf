# ft_printf

*Résumé: Vous en avez assez de faire vos affichages en alternant ft_putstr et ft_putnbr ?
Vous n’avez pas le droit d’utiliser printf ? Recodez le votre !
Ce sera l’occasion de découvrir une feature du C __les fonctions variadiques__
et de vous entrainer à la gestion fine des options d’affichage.
Vous aurez ensuite le droit d’utiliser votre ft_printf dans tous vos projets ultérieurs.*

## Sujet
La versatilité de la fonction printf en C représente pour nous un excellent exercice
de programmation. Ce projet va vous permettre de découvrir
les fonctions variadiques en C dans un contexte particulièrement adapté, et de voir un
excellent exemple d’un “dispatcher” rudimentaire implémenté en C à l’aide d’un tableau
de pointeurs sur fonctions.

Vous avez le droit d’utiliser les fonctions suivantes :
- *__write__*
- *__malloc__*
- *__free__*
- *__exit__*
- *__les fonctions du man 3 stdarg__*

Vous devez recoder la fonction printf de la libc
- Votre fonction s’appelera __ft_printf__ et sera prototypée de la même façon que
printf
- Vous __ne ferez pas__ la gestion de buffer présente dans la fonction printf de la libc.
- Vous devez gérer les conversions suivantes : ```csp```
- Vous devez gérer les conversions suivantes : ```diouxX``` avec les flags ```hh```, ```h```, ```l```, ```ll```
- Vous devez gérer la conversion suivante : ```f``` avec les flags ```l``` et ```L```
- Vous devez gérer le ```%%```
- Vous devez gérer les flags ```#0-+``` et ```espace```
- Vous devez gérer la taille minimum du champ
- Vous devez gérer la précision

## Téléchargement
```
git clone https://github.com/manki23/ft_printf.git ; cd ft_printf ; make
```

## Utilisation
```
gcc maincsp.c -I inc/ -L ./ -lftprintf ; ./a.out
```
