/* Sujet : Gestion d'un panier (GESACH) - TP de programmation en langage C */
/* ESIEA - 2A - Groupe 24 : Lucas MONTEGUT, Gautier THIERRY) */
/* Version du fichier : 24/11/2020 */

#include <stdio.h>
#include <string.h>            // bibliothèques
#include <ctype.h>

#define DefOui 'O' 
#define DefNon 'N'             // define
#define DebNbMaxArtListe 10 

// Valeurs relatives aux articles
#define DefMedListeNbMax  10  // Nombre maximum de médicaments dans la liste 
#define DefArtCarTaiMax  30  // Taille max de carac d'une caractéristique d'un médicament

// libellé variables
#define DefLibTMax  100  // Taille maximum d'un libellé
#define DefMsgTMax  100  // Taille maximum d'un message 

// libellés

//ecran 1
#define LibAuteur                    0
#define LibMail                      1
#define LibLogiciel                  2
#define LibMAccTitre                 3
#define LibMaccQuitter               4
#define LibMAccCatalog               5
#define LibMAccAjout                 6
#define LibMAccPanier                7
#define LibMAccRetirer               8
#define LibMAccChoixSai              9

#define LibCatal                     10

//Libellés des articles
#define LibArt1                      11
#define LibArt2                      12
#define LibArt3                      13
#define LibArt4                      14
#define LibArt5                      15
#define LibArt6                      16
#define LibArt7                      17
#define LibArt8                      18
#define LibArt9                      19   
#define LibArt10                     20

//écran 2

#define LibEAjoutArt                 21
#define LibEAjoutChoix               22


// code message 
#define OpRetourAuMenuAcc            0
#define OpAjoutPanier                1
#define OpConfirmationSai            2
#define OpRetPanier					 3
#define OpNonImplementee             4
#define OpOK                         5
#define OpABANDON                    6

#define ErrSaiON                     7

/* #define ErrStockSature               7
#define ErrStockVide                 8
#define ErrSaiOpInc                  9
#define ErrSaiON                     10
#define ErrSaiCIP                    11
#define ErrSaiMedNom                 12
#define ErrSaiMedFonction            13
#define ErrSaiCondLivr               14
#define ErrSaiMoisExp                15
#define ErrSaiAnneeExp               16
#define ErrRechBoiInexistante        17 */

// Coordonnées du commerce 
char tcComNom[] = "ESIEASHOP";
char tcComNumTel[] = "01 42 67 89 20"; 
char tcComEMail[] = "contact@esieaShop.com";
char tcComNumNomVoie[] = "74 bis, av. Maurice Thorez";
char tcComCP[] = "94200";
char tcComCommune[] = "Ivry-sur-Seine";
char tcComSite[] = "https://www.esiea/shop.fr/";
char tcComRCS[] = "517 403 572";

// Liste des articles
char tcArtNom[DebNbMaxArtListe][DefArtCarTaiMax] = { "T-shirt", "T-shirt uni", "Sweat à capuche", "Sweat à zip", "Polo blanc", "Polo noir", "Casquette", "Masque", "Sticker", "Stylo"};


char tcLibTxt[][DefLibTMax] = { 
	 "Logiciel réalisé par Lucas MONTEGUT et Gautier THIERRY", "contact: Lucas@mail.com , Gautier@mail.com", "GESACH",
	 "Accueil", "0 - Quitter", "1 - Afficher le catalogue", "2 - Ajouter un article au panier", "3 - Afficher le panier", "4 - Retirer un article du panier", "Opération choisie : ",
 	 "Catalogue :", " 1- T-shirt", " 2- T-shirt uni", " 3- Sweat à capuche", " 4- Sweat à zip", " 5- Polo blanc", " 6- Polo noir", " 7- Casquette", " 8- Masque", " 9- Sticker", "10- Stylo", 
 	 "Ajout d'un article au panier", "Article choisi :", 

 };


char tcMsgTxt[][DefMsgTMax] = { 
	"Retour à l'accueil (touche Entrée)", "Vous avez ajouté au panier l'article n°", "Confirmer la saisie (O/N) : ", "Vous avez retiré du panier l'article n°",
	"Opération non implémentée.", "Opération réussie.", "Opération abandonnée.",
	"Saisie erronée - Saisissez O pour Oui ou N pour Non.",
 };

