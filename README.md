# Jeu de la Vie - Projet en Programmation Orientée Objet

## Table des matières
- Attendus
- Contexte
- Objectifs
- Documentation Utilisateur
- Documentation Technique
- Conclusion

---

## Attendus
### Conception
- **Diagrammes** :
  - Cas d'utilisation.
  - Classe.
  - Séquence.
  - Activité.
- Environnement de développement opérationnel.

### Solution informatique
- **Programme** : Application fonctionnelle (console et graphique) en C++ implémentant les principes de la POO.
- **Tests unitaires** : Vérification de la validité de la grille calculée à une itération donnée.
- **Oral** : Présentation complète du travail et maîtrise des concepts POO.
- **Évaluation par les pairs** : Validation du projet.

---

## Contexte
Le **jeu de la vie** est un automate cellulaire conçu par John Conway. Il modélise l'évolution d'une population de cellules sur une grille 2D selon des règles simples :
- Une **cellule morte** ayant exactement trois voisines vivantes devient vivante.
- Une **cellule vivante** ayant deux ou trois voisines vivantes reste vivante ; sinon, elle meurt.

Le programme consomme un fichier d'entrée décrivant la taille de la grille et l'état initial (vivant : `1`, mort : `0`) des cellules.

---

## Objectifs
Développer un programme pour jouer au jeu de la vie avec les fonctionnalités suivantes :
- Réalisation de diagrammes UML (cas d’utilisation, activité, classe, séquence).
- Implémentation de concepts avancés de la Programmation Orientée Objet (POO).
- Interface console et graphique (via SFML).
- Génération de fichiers contenant les états successifs de la grille.

---

## Documentation Utilisateur
### Diagrammes
- **Cas d’utilisation** : Montre les interactions possibles (simulation, tests, modes d’affichage console/graphique).
- **Activité** : Décrit les processus internes pour les différents modes d’interaction.
- **Classe** : Définit la structure statique des classes, leurs attributs, méthodes et relations.
- **Séquence** : Illustre les interactions temporelles entre les classes, selon le mode choisi.

### Fonctionnalités utilisateur
1. **Mode console** : 
   - Affiche la grille dans le terminal.
   - Génère des fichiers pour les itérations successives.
2. **Mode graphique** :
   - Utilise la bibliothèque SFML pour afficher la simulation dans une fenêtre.
3. **Mode testeur** : 
   - Valide les règles du jeu avec des grilles d’état initial et final.

---

## Documentation Technique
### Technologies utilisées
- **Langage** : C++
- **Bibliothèques** :
  - `std` : gestion des structures (vecteurs, chaînes de caractères, etc.).
  - `sfml` : création de l’interface graphique.

### Installation
1. Installer SFML :  
   ```bash
   sudo apt-get install libsfml-dev
   ```
2. Compiler le projet (exemple sous Linux) :
   ```bash
   g++ -o game main.cpp cell.cpp golrule.cpp grid.cpp gui.cpp console.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```
---

## Détails techniques

### class `Cell`

`Cell()` : Constructeur de cellule  
`get_state()` : Donne l'état de la cellule  
`set_state()` : Change l'état d'une cellule

---

### class `Console`

`Console()` : Constructeur de console  
`export_grid()` : Transforme un fichier comportant un état de grille en objet `Grid`  
`export_test()` : Transforme un fichier comportant un état de grille et un fichier d'état final en objet `UnitTest`  
`get_interface()` : Donne le mode de l'interface (1 : Graphique, 2 : Console)  
`get_iter_max()` : Donne le nombre d'itérations maximum donné par l'utilisateur  
`get_itertime()` : Donne l'intervalle de temps entre deux mises à jour de la grille en millisecondes  
`get_mode()` : Donne le mode d'utilisation (1 : Normal, 2 : Test)  
`select_interface()` : Demande à l'utilisateur le mode d'interface  
`select_iter_max()` : Demande à l'utilisateur le nombre maximum d'itérations  
`select_itertime()` : Demande à l'utilisateur le temps entre deux mises à jour de la grille  
`select_mode()` : Demande à l'utilisateur le mode d'utilisation (normal ou test)  
`select_path()` : Demande à l'utilisateur le chemin d'accès au fichier

---

### class `Grid`

`Grid()` : Constructeur de la grille  
`get_grid()` : Donne la grille sous la forme `vector<vector<Cell>>`  
`grid_arret()` : Renvoie la grille sous forme d'une chaîne de caractères, sert à l'arrêt si la grille n'évolue plus  
`load_file()` : Permet de charger un fichier dans la grille  
`operator==()` : Compare deux grilles  
`save_file()` : Sauvegarde l'état de la grille dans un fichier  
`show_grid()` : Affiche la grille dans la console  
`update()` : Met à jour la grille

---

### class `GUI`

`GUI()` : Constructeur de l'interface graphique  
`draw()` : Dessine l'état de la grille dans la fenêtre  
`get_window()` : Donne l'objet représentant la fenêtre

---

### class `Rule`

`apply_rule()` : Applique une règle sur une cellule en changeant son état selon ses voisins  
`get_tor_mode()` : Donne l'état d'activation du mode torique  
`switch_tor()` : Active/désactive le mode torique  
`tor_mode` : Représente l'activation du mode torique

---

### class `UnitTest`

`UnitTest()` : Constructeur du test unitaire  
`test()` : Teste le test unitaire stocké dans l'objet

---

### Modes de fonctionnement

- **Utilisateur** :
    - Interface console ou graphique.
    - Enregistre les états de la grille.
- **Testeur** :
    - Valide les règles sur des grilles de test.

---

## Dépendances

 - std : string, vector, map...
 - sfml : interface graphique

---

## Conclusion

Ce projet combine les principes de la programmation orientée objet avec une application pratique et interactive. Les diagrammes, la structure en classes et l’interface graphique démontrent une mise en œuvre robuste et évolutive. L’utilisation de tests unitaires garantit la fiabilité du programme.
