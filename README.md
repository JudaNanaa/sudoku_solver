# Sudoku Solver

Ce projet est un solveur de Sudoku écrit en C. Il utilise un Makefile pour faciliter la compilation et l'exécution.

## Table des matières

- [Description](#description)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Exemples](#exemples)

## Description

Ce solveur de Sudoku prend en entrée une grille de Sudoku partiellement remplie et tente de la résoudre en utilisant un algorithme de backtracking. Si la grille est résolvable, le programme affiche la solution complète. Sinon, il indique que la grille ne peut pas être résolue.

## Installation

1. Clonez ce dépôt sur votre machine locale :
    ```sh
    git clone https://github.com/JudaNanaa/sudoku_solver.git
    cd sudoku_solver
    ```

2. Compilez le programme en utilisant le Makefile :
    ```sh
    make
    ```

## Utilisation

Après avoir compilé le programme, vous pouvez l'exécuter en utilisant la commande suivante :

```sh
./sudoku_solver maps/1.txt
```
où 1.txt est un fichier contenant la grille de Sudoku à résoudre. Le fichier doit être formaté de la manière suivante :

Chaque ligne représente une ligne de la grille de Sudoku.
Utilisez le chiffre 0 pour représenter les cases vides.
Exemple de fichier 1.txt 

```
000000000
030050040
006207100
920000078
560040023
000000000
000608000
400502007
080000090
```
## Exemples
Pour exécuter le programme avec un fichier d'entrée :

```
./sudoku_solver examples/example1.txt
```
Vous devriez voir la solution de la grille s'afficher sur la sortie standard.

