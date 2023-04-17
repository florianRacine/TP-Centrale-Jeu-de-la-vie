# TP-Centrale-Jeu-de-la-vie

## Objectif : 

Créer en langage C un programme permettant de visualiser les évolutions d’un automate cellulaire, et plus précisément l’automate cellulaire créé par Conway et connu sous le nom de jeu de la vie :

## Regles du jeu de la vie :

* On dispose d’un tableau 2D de dimension N×M, chacune des cases comportant une cellule qui peut être
soit morte (valeur 0 dans le tableau) soit vivante (valeur 1).
* A partir de la configuration de ce tableau à l’étape numéro i, on peut déterminer la configuration du tableau à l’étape i + 1.

## Structure

* Le fichier [inp](./inp) contient les paramètres fournis par l’utilisateur.
* Le fichier [headers.h](./headers.h) contient les prototypes des fonctions crées pour ce projet.
* Le ficher [function.c](./function.c) contient les fonctions crées pour ce projet
* Le ficher [main.c](./main.c) contient le programme principal.
* Le fichier [makefile](./makefile) permet de compiler le projet.

## Fonctionnement

### Lecture des paramètres fournis par l’utilisateur

#### Dimensions et nombre de générations

Si les paramètres des dimensions et du nombre de générations du jeu de la vie ne sont pas entrer en argument.
Le programme va utiliser les paramètres du fichier [inp](./inp).

Le ficher [inp](./inp) doit pour cela être sous la forme :
* Les paramètres dans l'ordre suivant.
  * Hauteur
  * Largeur
  * Nombre d'itérations souhaitées

#### Initialiser la carte

Vous pouvez initialiser la carte avec un fichier texte dont le nom doit être fourni en 4 ème arguments de la ligne de commande.
Si il n'y a pas de nom de carte fourni dans la ligne de commande, la carte va être initialiser aléatoirement

#### Exemple de commande

Lancer le jeu de la vie avec un planeur :
```bash
./prg 13 14 10 planeur
```

```bash
Genération numéro : 1
+-------------+
|             |
|             |
|             |
|             |
|             |
|             |
|    o o      |
|     oo      |
|     o       |
|             |
|             |
|             |
|             |
|             |
+-------------+
Genération numéro : 2
+-------------+
|             |
|             |
|             |
|             |
|             |
|            |
|      o      |
|    o o      |
|     oo      |
|             |
|             |
|             |
|             |
|             |
+-------------+
Genération numéro : 3
+-------------+
|             |
|             |
|             |
|             |
|             |
|             |
|     o       |
|      oo     |
|     oo      |
|             |
|             |
|             |
|             |
|             |
+-------------+
Genération numéro : 4
+-------------+
|             |
|             |
|             |
|             |
|             |
|             |
|      o      |
|       o     |
|     ooo     |
|             |
|             |
|             |
|             |
|             |
+-------------+
Genération numéro : 5
+-------------+
|             |
|             |
|             |
|             |
|             |
|             |
|             |
|     o o     |
|      oo     |
|      o      |
|             |
|             |
|             |
|             |
+-------------+
Genération numéro : 6
+-------------+
|             |
|             |
|             |
|             |
|             |
|             |
|             |
|       o     |
|     o o     |
|      oo     |
|             |
|             |
|             |
|             |
+-------------+
Genération numéro : 7
+-------------+
|             |
|             |
|             |
|             |
|             |
|             |
|             |
|      o      |
|       oo    |
|      oo     |
|             |
|             |
|             |
|             |
+-------------+
Genération numéro : 8
+-------------+
|             |
|             |
|             |
|             |
|             |
|             |
|             |
|       o     |
|        o    |
|      ooo    |
|             |
|             |
|             |
|             |
+-------------+
Genération numéro : 9
+-------------+
|             |
|             |
|             |
|             |
|             |
|             |
|             |
|             |
|      o o    |
|       oo    |
|       o     |
|             |
|             |
|             |
+-------------+
Genération numéro : 10
+-------------+
|             |
|             |
|             |
|             |
|             |
|             |
|             |
|             |
|        o    |
|      o o    |
|       oo    |
|             |
|             |
|             |
+-------------+
```

Lancer le jeu de la vie avec une carte de 10*10 aléatoirement :
```bash
./prg 10 10 10
```

```bash
Genération numéro : 1
+----------+
|ooo o o o |
|         o|
|o o o    o|
|o     o   |
| o      o |
|          |
| o       o|
|    o     |
| o       o|
| oooooo o |
+----------+
Genération numéro : 2
+----------+
| o        |
|o o  o  oo|
| o        |
|o         |
|          |
|          |
|          |
|          |
| o        |
| ooooo    |
+----------+
Genération numéro : 3
+----------+
| o        |
|o o       |
|oo        |
|          |
|          |
|          |
|          |
|          |
| o oo     |
| oooo     |
+----------+
Genération numéro : 4
+----------+
| o        |
|o o       |
|oo        |
|          |
|          |
|          |
|          |
|          |
| o  o     |
| o  o     |
+----------+
Genération numéro : 5
+----------+
| o        |
|o o       |
|oo        |
|          |
|          |
|          |
|          |
|          |
|          |
|          |
+----------+
Genération numéro : 6
+----------+
| o        |
|o o       |
|oo        |
|          |
|          |
|          |
|          |
|          |
|          |
|          |
+----------+
Genération numéro : 7
+----------+
| o        |
|o o       |
|oo        |
|          |
|          |
|          |
|          |
|          |
|          |
|          |
+----------+
Genération numéro : 8
+----------+
| o        |
|o o       |
|oo        |
|          |
|          |
|          |
|          |
|          |
|          |
|          |
+----------+
Genération numéro : 9
+----------+
| o        |
|o o       |
|oo        |
|          |
|          |
|          |
|          |
|          |
|          |
|          |
+----------+
Genération numéro : 10
+----------+
| o        |
|o o       |
|oo        |
|          |
|          |
|          |
|          |
|          |
|          |
|          |
+----------+
```


Lancer le jeu de la vie avec les paramètres de [inp](./inp) :
```bash
./prg
```

## Installation

### Clone the repository

```bash
git clone https://github.com/florianRacine/TP-Centrale-Jeux-de-la-vie
```

### Build the project

```bash
make build
```
-> Cette commande permet de créer un ficher executable "prg"
