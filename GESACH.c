/* Sujet : Gestion d'un panier (GESACH) - TP de programmation en langage C */
/* ESIEA - 2A - Groupe 24 : Lucas MONTEGUT, Gautier THIERRY) */
/* Version du fichier : 24/11/2020 */

#include "gesach.h"

int main()
{
  
  char ChoixSaisi;
  char ConfirmationSai;
  int iErrCode;
  int ArtAjout;

  //stock
  char tcStoArtNom[DebNbMaxArtListe][DefArtCarTaiMax];             

  //variables des articles

  do {

     iErrCode = OpOK;

    //en tête
      printf ("\n\t ___________________________________________________");
      printf ("\n\n%s \n%s - %s \n%s \n%s %s \n\n\n\n%s\n%s\n\n", tcComNom, tcComNumTel, tcComEMail, tcComNumNomVoie, tcComCP, tcComCommune, tcLibTxt[LibAuteur], tcLibTxt[LibMail]);

    //Affichage du titre de la page d'accueil
      printf ("\n\n\t\t\t%s", tcLibTxt[LibLogiciel]);
      printf ("\n\n\t\t\t%s", tcLibTxt[LibMAccTitre]);
      printf ("\n\n");

    //Affichage du menu
      printf ("\n\t\t%s", tcLibTxt [LibMaccQuitter]);
      printf ("\n\t\t%s", tcLibTxt [LibMAccCatalog]);
      printf ("\n\t\t%s", tcLibTxt [LibMAccAjout]);
      printf ("\n\t\t%s", tcLibTxt [LibMAccPanier]);
      printf ("\n\t\t%s", tcLibTxt [LibMAccRetirer]);
      printf ("\n");

    //Saisie du choix de l'opération (numéro de rubrique)
      printf ("\n\n");
      printf ("\n\t\t%s", tcLibTxt [LibMAccChoixSai]);


    ChoixSaisi = getchar();

  switch (ChoixSaisi) {

    case '0' :        // quitter
    continue;

    case '1' :        // Catalogue

      if((getchar())==0){
        break;
      }
      else{
      printf ("\n\n\n\n");
      printf ("\n\t _____________________________");
      printf ("\n\n");
      printf ("\n\t\t  %s", tcLibTxt [LibCatal]);
      printf ("\n\n");
      printf ("\n\t\t%s\n", tcLibTxt [LibArt1]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt2]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt3]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt4]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt5]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt6]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt7]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt8]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt9]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt10]);
      printf ("\n");
      break;
      }
      
    case '2' :        // ajout d'un article

      if((getchar())==0){
        break;
      }
      
      else{
      printf ("\n\n\n\n");
      printf ("\n\t _____________________________");
      printf ("\n\n");
      printf ("\n\t  %s", tcLibTxt [LibEAjoutArt]);
      printf ("\n\n");
      printf ("\n\t\t%s\n", tcLibTxt [LibArt1]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt2]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt3]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt4]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt5]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt6]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt7]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt8]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt9]);
      printf ("\n\t\t%s\n", tcLibTxt [LibArt10]);
      printf ("\n");

      printf ("\n\n");
      printf ("\n\t\t%s", tcLibTxt [LibEAjoutChoix]);
      scanf("%d", &ArtAjout);
      strcpy(ArtAjout, tcStoArtNom[DebNbMaxArtListe][DefArtCarTaiMax]);          // à développer 

      //confirmation de la saisie 
      do{
        printf ("\n\n\t\t%s", tcMsgTxt[OpConfirmationSai]);
        scanf (" %c", &ConfirmationSai); //l'espace permet de passer outre les caractères qui seraient déjà présentes dans le buffer du clavier
        ConfirmationSai = toupper(ConfirmationSai); //'o' sera converti en 'O'
        if (ConfirmationSai != DefOui && ConfirmationSai != DefNon)
         {
          iErrCode = ErrSaiON; 
          printf ("\n\n\t\t%s", tcMsgTxt[iErrCode]);
          }

        else {
          iErrCode = OpOK;
        }
      }while(iErrCode == ErrSaiON);

      //Abandonner l'opération 
        if (ConfirmationSai == DefNon)
          {
            iErrCode = OpABANDON; 
            break;
          }
       
      printf ("\n\n%s%d", tcMsgTxt [OpAjoutPanier], ArtAjout);
      }


   }

      printf("\n\n\t%s", tcMsgTxt[OpRetourAuMenuAcc]);          // retour accueil
      getchar();  // caractère correspondant à la touche Entrée du clavier
      printf("\n\n");

  } while (ChoixSaisi != '0');

}