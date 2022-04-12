/////////////////////////////////
//	 Cours IN 42 
//	 Systemes Temps réel
//	 TP1-EXERCICE1
/////////////////////////////////

#include <iostream>
#include <time.h>
using namespace std;

int main()
{

	time_t debut;	//Nb de secondes entre le 1er Janvier 1970 0:00 et la demande de saisie
	time_t fin;		//Nb de secondes entre le 1er Janvier 1970 0:00 et la saisie
	int temps;		//Nb de secondes d'ecart
	char texte[150]; //Chaine contenant le texte entre
	struct tm * temps_local; // Temps local
	clock_t temps_systeme; //Nombre de tops d'Horloge
	//////////////////////////////////////////////
	cout << "--- TP 1 EXO 1 ---" << endl;
	cout <<	"Entrez une chaine de caracteres:" << endl; //Demande de rentrer une chaine
	///////////////////////////////////////////////////////////////////////////////////
	time(&debut); //Enregistre le nb de secondes depuis le 1er Janvier 70 dans debut
	cin >> texte; //Saisie du texte
	time(&fin);   //Enregistre le nb de secondes depuis le 1er Janvier 70 dans fin
	temps=(int) (fin-debut); //Difference des nb de secondes + cast (conversions) vers Entier
	cout <<"Vous avez mis "<<temps<<" seconde(s)!"<<endl; //Affichage du temps de saisie
	/////////////////////////////////////////////////////////////////////////////////
	//acquisition et traitement de l'heure locale
	temps_local=localtime(&fin); //Conversion en temps local et affichages sur les prochaines lignes => il s'agit du temps local
	cout << "La date d'aujourd'hui est: " << temps_local->tm_mday << "/" << temps_local->tm_mon+1 << "/" << temps_local->tm_year+1900 << endl;
	cout << "L'heure locale est: " << temps_local->tm_hour << ":" << temps_local->tm_min << ":" << temps_local->tm_sec << endl;
	// Acquisition et visualisation du "temps système"	
	temps_systeme = clock(); //Fonction permettant de savoir cb de temps a dure le processus
	cout << "Le programme a dure " << temps_systeme/float(CLOCKS_PER_SEC) << " secondes!" << endl; //Affichage
	//  Attente de fin
	cout << "Entrez une touche pour quitter..." << endl;
	cin>>texte;
}
