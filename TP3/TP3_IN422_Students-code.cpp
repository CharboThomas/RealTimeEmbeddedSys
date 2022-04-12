#include <iostream>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <unistd.h>

using namespace std;


// Declare you variables, structures, forks, etc.

int forks[6];


// **********************************************************
//                   Création des fonctions
// **********************************************************


void Think(int i) {
   cout<< "I am the Philosopher number" << i << " and I am thinking " <<endl;
   sleep(5);
};



void PickupForks(int i) {

  // the mission of this procedure is to take the fork when you have access

  int stateLeft = i - 1;// this is the index of the left fork

  if( (i - 1) < 0 ){// if the index of the left fork is inferrior to 0, I update it
      stateLeft = 6 - i - 1;
  }

  int leftFork = ::forks[stateLeft];// I take the state of the left fork
  int rightFork = ::forks[i];// I take the state of the right fork

  cout << "   Take => PNJ : " << i << " state => " << leftFork << " | " << rightFork << " index : " << stateLeft << " | " << i << endl;


  while (leftFork != 1 or rightFork != 1){// while i don't have access to the left and the right fork, the thread wait
      sleep(2);// I wait 1 second
      cout << "  ReTake => PNG : " << i << " etat => " << leftFork << " | " << rightFork << endl;
  }

  ::forks[stateLeft] = 0;// With this action, I take the left fork
  ::forks[i] = 0;// with this action, I take the roght fork
  cout<<"I am the Philosopher number " <<  i << " and I am PickingupForks "<<endl;

};



void Eat(int i) {
    cout<<"I am the Philosopher number " <<  i << " and I am Eating "<<endl;
    sleep(2);
};



void PutForks(int i) {

  // the mission of this procedure is to return the fork after the previous procedure

  cout<<"I am the Philosopher number "  << i << " and I am Putting the forks "<<endl;

  int stateLeft = i - 1;// this is the index of the left fork

  if( (i - 1) < 0 ){// if the index is < to 0, i need to update it
      stateLeft = 6 - i - 1;
  }

  ::forks[stateLeft] = 1;// I return the left fork
  ::forks[i] = 1;// I return the right fork
   cout << "   PUT =>  PNJ : " << i << " state => " << ::forks[stateLeft] << " | " << ::forks[i] << " index : " << stateLeft << " | " << i << endl;

};





// **********************************************************
//                  Création du Thread
// **********************************************************

void* philoprocess(void* threadarg){

    int i = *(int*)threadarg;
    cout<<"I am the Philosopher N° "<< i <<endl;

    //Functions inside a thread
    Think(i);//Call the function Think();
    PickupForks(i);//Call the function PickupForks();
    Eat(i);//Call the function Eat();
    PutForks(i);//Call the function PutForks();

    pthread_exit(NULL);
}





// **********************************************************
//                     Boucle Main
// **********************************************************


int main() {

    cout<<"Info: "<<endl;
    cout<<"Philosophers and forks are numbered, in counter-clockwise direction. The fork to the right of a philosopher 'i' is also 'i', and the left 'i-1' (with the exeption of the first philosopher, whose left fork is n'."<<endl<<endl;

    //Initialize your forks
    for (int f = 0; f <= 6; f++){
        ::forks[f]=1;
        cout<<"Création de la 'forks' N° "<< ::forks[f] <<endl;
    }

    while(true){

 	//Création des philiossophe sous format de thread
    	pthread_t tphilo[6];

    	for(int i = 0; i < 6; i++){

        	int rc;

        	rc = pthread_create(&tphilo[i], NULL, philoprocess, &i);// création d'un thread
                sleep(3);
		// Attention, le thread que l'on vient de créer est  en cours d'éxecution

		// si la création du thread réussit : retourne 0 (zero) et l'identifiant du thread nouvellement crée est stockée l'adresse fournie en premier argument.
        	if (rc){
            		cout << "Error:unable to create thread for philosopher " << i << endl;
        	}
    	};

        //Check if all the threads are finished before ending the execution
        for(int i = 0; i < 6; i++){
            pthread_join(tphilo[i],NULL);// le système attend que le thread i se termine
        }
    };

    return 0;

}
