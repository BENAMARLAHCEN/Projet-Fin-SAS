#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu();
void afichage();
void supprimer();
void ajouterstatut();
void modifier();
// void tri();
int recherchedline();
void recherchedeadline();
void ajout();
void recherche();
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
  deadline dline2;
int ch;
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
      
      
      // tri(tache,t);
      
      
      
      
      break;

    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
       tache = &t1;
       modifier(&tache, t);
      break;
    case 7:
      tache = &t1;
      printf( "Entrer le jour de la tâche : ");
  scanf("%d", &dline2.jour);
  printf("Entrer le mois de la tâche : ");
  scanf("%d", &dline2.mois);
  printf("Entrer l'année de la tâche : ");
  scanf("%d", &dline2.annee);
  int b=recherchedline(tache,t,dline2);
  if(b==-1){
    printf("Aucune tâche n'a été trouvé.\n");
    
  }else{
    supprimer(tache,t,b);
    t--;
    }
      break;
    case 8:
      
      printf("[1]Rechercher une tâche par son Identifiant \n [2]Rechercher une tâche par son Titre\n");
      printf("Entre votre choix");
      scanf(" %d", &ch);
      if(ch==1){
        tache = &t1;
        recherchedeadline(tache, t);
      }
      else if(ch==2){
      tache = &t1;
      recherche(tache,t);}
      else{
        printf("tache ");
      }
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

void recherche(taches *tache,int t) {
  char titre[100];
  taches *tache1;
  tache1 = tache;
  printf("Entrer le titre de la tache : ");
  scanf(" %[^\n]s", titre);
  for(tache=tache1;tache<=tache1+t;tache++){
    if(strcmp(tache->titre,titre)==0){
      afichage(tache);
    } 
  }
}
int recherchedline(taches *tache,int t,deadline dline2) {
  int i=0;
  taches *tache1;
  tache1 = tache;
  for(tache=tache1;tache<=tache1+t;tache++){
    if(tache->dline.annee==dline2.annee && tache->dline.jour==dline2.jour && tache->dline.mois==dline2.mois){
      return i;
    }
    i++;
  }
  return -1;
} 

void recherchedeadline(taches *tache,int t) {
  deadline dline2;
  printf(
      "Entrer le jour de la tâche : ");
  scanf("%d", &dline2.jour);
  printf("Entrer le mois de la tâche : ");
  scanf("%d", &dline2.mois);
  printf("Entrer l'année de la tâche : ");
  scanf("%d", &dline2.annee);
  int b=recherchedline(tache,t,dline2);
  if(b==-1){
    printf("Aucune tâche n'a été trouvé.\n");
  }else{
    printf("Tâche trouvé : \n");
    tache = tache + b;
    afichage(tache);
  }
}
void supprimerdeadline(taches *tache,int t) {
  taches *tache1;
  tache1 = tache;
  tache1=(taches*)malloc(sizeof(taches)*(t+1));
  deadline dline2;
  printf(
      "Entrer le jour de la tâche : ");
  scanf("%d", &dline2.jour);
  printf("Entrer le mois de la tâche : ");
  scanf("%d", &dline2.mois);
  printf("Entrer l'année de la tâche : ");
  scanf("%d", &dline2.annee);
  int b=recherchedline(tache,t,dline2);
  if(b==-1){
    printf("Aucune tâche n'a été trouvé.\n");
    
  }else{
    for(tache=tache1;tache<=tache1+t;tache++){
    }}}    

void supprimer(taches *tache,int t,int b) {
  taches *tache1;
  tache1 = tache;
  for(tache=tache1+b;tache<=tache1+t;tache++){
    *tache=*(tache+1);

  }
  
}
void modifier(taches *tache,int t) {
  deadline dline2;
  taches tache1;
  int a,b;
  printf("entrer l'identifiant de la tache : ");
  scanf("%d",&b);
  if(b<0|| b>t){
    printf("Aucune tâche n'a été trouvé.\n");
    
  }else{
    tache = tache + b;
     printf("Entrer votre choix : \n");
     scanf("%d",&a);
    switch(a){
      case 1:
      printf("Entrer nouveau description : \n");
      scanf("%s",tache1.description);
      strcpy(tache->description,tache1.description);
      break;
      case 2:
      printf("Entrer nouvelle status : \n");
      ajouterstatut(tache);
      break;
      case 3:
      printf("Entrer nouvelle deadline : \n");
      printf("Entrez le jour de la tâche : ");
  scanf("%d", &tache->dline.jour);
  printf("Entrez le mois de la tâche : ");
  scanf("%d", &tache->dline.mois);
  printf("Entrez l'année de la tâche : ");
  scanf("%d", &tache->dline.annee);
      break;
       }
  }
}
void ajouterstatut(taches *tache) {
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
  }}