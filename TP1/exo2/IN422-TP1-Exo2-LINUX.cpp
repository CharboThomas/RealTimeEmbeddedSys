#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS  3

void *HelloWorld(void *threadid)
{
  
   cout<<"Je suis le TRAITEMENT 1."<<endl<<"Je suis actif...\n" ;
   pthread_exit(NULL);
}


int main (){

  pthread_t TH1;
  int rc;
  char TT;

  int MyThreadID;
   

  rc = pthread_create(&TH1,NULL,HelloWorld,NULL);
  // CREAT THE THREAD HERE

  cout<<"The thread ID is: "<< MyThreadID<<endl;


  if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
  }

  cout<<"\n Program END "<<endl<<"write a letter to end your program\n";

  //pthread_exit(NULL);
  cin>>TT;
  pthread_exit(NULL);

}
