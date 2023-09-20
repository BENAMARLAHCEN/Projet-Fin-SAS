#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu();
void afichage();
void ajout();
typedef struct {
  int jour;
  int mois;
  int annee;
} deadline;
typedef struct {
  int id;
  char titre[100];
  char description[100];
  deadline dline;
  char statut[100];
} taches;
int main() {
  taches *tache, t1;
  int n, idt = 0, b, t = 0;

  menu();
  do {
    tache = &t1;
    tache = (taches *)malloc((t + 1) * sizeof(taches));
    printf("Entrez votre choix :");
    scanf("%d", &n);
    switch (n) {
    case 1:
      tache = &t1 + t;
      ajout(tache, idt);
      t++;
      idt++;
      break;

    case 2:
      for (tache = &t1; tache < &t1 + t; tache++) {
        afichage(tache);
      }
      break;

    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    case 0:
      break;
    default:
      printf("Erreur \n");
      break;
    }
  } while (n != 0);
  return 0;
}
void menu() {
  printf("1- Ajouter une nouvelle tâche \n");
  printf("2- Afficher la liste de toutes les tâches (Identifiant, Titre, "
         "Description, Deadline, Statut) : \n");
  printf("3- Trier les tâches par ordre alphabétique. \n");
  printf("4- Trier les tâches par deadline. \n");
  printf(
      "5- Afficher les tâches dont le deadline est dans 3 jours ou moins. \n");
  printf("6- Modifier une tâche: \n");
  printf("7- suprimer une tâche par identifiant. \n");
  printf("8- Rechercher les Tâches : \n");
  printf("9- Statistiques : \n");
  printf("10- Quitter \n");
}
void afichage(taches *tache) {
  printf("Identifiant : %d \n", tache->id);
  printf("Titre : %s \n", tache->titre);
  printf("Description : %s \n", tache->description);
  printf("Deadline : %d/%d/%d \n", tache->dline.jour, tache->dline.mois,
         tache->dline.annee);
  printf("Statut : %s \n", tache->statut);
  printf("\n");
}
void ajout(taches *tache, int idt) {
  tache->id = idt;
  printf("Entrer le titre de la tache : ");
  scanf(" %[^\n]s", tache->titre);
  printf("Entrer la description de la tache : ");
  scanf(" %[^\n]s", tache->description);
  printf("Entrez le jour de la tâche : ");
  scanf("%d", &tache->dline.jour);
  printf("Entrez le mois de la tâche : ");
  scanf("%d", &tache->dline.mois);
  printf("Entrez l'année de la tâche : ");
  scanf("%d", &tache->dline.annee);
  printf("Entrez le statut de la tâche : ");
  int b;
  printf("1-à réaliser\n2-en cours de réalisation\n3-finalisée\n");
  scanf("%d", &b);
  switch (b) {
  case 1:
    strcpy(tache->statut, "realiser");
    break;
  case 2:
    strcpy(tache->statut, "en cours de réalisation");
    break;
  case 3:
    strcpy(tache->statut, "finalisée");
    break;
  }
}