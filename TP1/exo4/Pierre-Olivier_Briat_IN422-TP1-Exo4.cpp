#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string.h>

using namespace std;

#define NUM_THREADS  3


void *Verif(void *threadid)
{
    time_t debut;
	time_t fin;
    do
    {
        time(&debut);
        time(&fin);
        while (fin - debut < 5)
        {
            time(&fin);
        }
        cout<<"\nEcrit plus vite stp"<<endl;
    }while(1);
    pthread_exit(NULL);
}

void *Saisie(void *msg)
{
    char * value = (char *) msg;
	pthread_t TH;
    int rc;
    cout<<"Ecrit bg :D"<<endl;
    rc = pthread_create(&TH, NULL, Verif, NULL);
    cin>>value;
    pthread_cancel(TH);
    cout<<"Message ecrit : "<<value<<endl;
    cout<<"Message situation : "<<msg<<endl;
    pthread_exit(NULL);
}

void *PrintSentence(void *msg)
{
    char * value = (char *) msg;
    cout<<"La chaine transmise est : "<<value<<endl;
	pthread_exit(NULL);
}

void *Reverse(void *msg)
{
    char * value = (char *) msg;
    int p = strlen(value);
    char invalue[p];
    for(int i = p-1 ; i >= 0; i--)
    {
        invalue[p-i-1] = value[i];
    }
    cout<<"La chaine inverse est : "<<invalue<<endl;
    cout<<"La longueur de la chaine inverse est : "<<strlen(invalue)<<endl;
    cout<<"La longueur de la chaine d'origine est : "<<p<<endl;
	pthread_exit(NULL);
}

int main ()
{  
    char * msg;
    pthread_t TH1;
    int rc1;
    pthread_t TH2;
    int rc2;
    pthread_t TH3;
    int rc3;
    
    rc1 = pthread_create(&TH1, NULL, Saisie, &msg);
    pthread_join(TH1, NULL);
    rc2 = pthread_create(&TH2, NULL, PrintSentence, &msg);
    pthread_join(TH2, NULL);
    rc3 = pthread_create(&TH3, NULL, Reverse, &msg);
    pthread_join(TH3, NULL);

    cout<<"\nFin du programme \nsaisir une lettre pour fermer\n";
    pthread_exit(NULL);
    return 1;
}
