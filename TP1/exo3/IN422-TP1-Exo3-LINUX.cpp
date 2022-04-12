#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;
#define NUM_THREADS  3

void *PrintSentence(void *tt){

   char * value = (char*) tt;

   cout<<"La chaine transmise est : "<<value<<endl;
   pthread_exit(NULL);
}



int main (){
   pthread_t TH1;
   int rc;

   char TT[150]="BONJOUR";// Chaine de caractere

   rc = pthread_create(&TH1, NULL, PrintSentence, &TT);

   if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
   }

   cout<<"\nFin du programme \nsaisir une lettre pour fermer\n";
   pthread_exit(NULL);
   cin>>TT;
}
