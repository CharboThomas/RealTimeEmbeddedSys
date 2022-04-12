#include <iostream>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <unistd.h>

 

using namespace std;

 

// Declare you variables, structures, forks, etc.

 

 

// Function declaration
void Think(int i) {
   cout<< "I am the Philosopher number" << i << "and I am thinking " <<endl;

 

};

 

void PickupForks(int i) {
  cout<<"I am the Philosopher number i and I am PickingupForks "<<endl;

 

 };

 

void Eat(int i) {
    cout<<"I am the Philosopher number i and I am Eating "<<endl;
};

 

void PutForks(int i) {
   cout<<"I am the Philosopher number i and I am Putting the forks "<<endl;

 

};

 

//CREATE THE THREAD philosopher
void* philoprocess(int* threadarg)
{
    int i=*(int*)threadarg;
    cout<<"I am the Philosopher number i:"<<i<<endl;

 


    //Functions inside a thread
    Think(i);               //Call the function Think();
    PickupForks(i);         //Call the function PickupForks();
    Eat(i);                 //Call the function Eat();
    PutForks(i);            //Call the function PutForks();

 

    pthread_exit(NULL);
}

 


int main() {

 

    cout<<"Info: "<<endl;
    cout<<"Philosophers and forks are numbered, in counter-clockwise direction. The fork to the right of a philosopher 'i' is also 'i', and the left 'i-1' (with the exeption of the first philosopher, whose left fork is n'."<<endl<<endl;

 

    //Initialize your forks
    int forks[6];       // d�clare un tableau nomm� "forks" de 6 int
    for (int f=0; f<=6;f++)
    {
        forks[f]=1;
        cout<<forks[f]<<endl;
    }

 

    while(true)
    {

     //Create threads
    pthread_t tphilo[6];
    for(int i = 0; i<6; i++)
    {
        int rc;
        //cout<<"i="<<i<<endl;
        rc = pthread_create(tphilo[i], NULL, philoprocess, &i);    // création d'un thread et lancement du thread lors de l'exécution du 3ième argument
                                                                // si la création du thread réussit : retourne 0 (zero) et l'identifiant du thread nouvellement crée est stockée l'adresse fournie en premier argument.
        if (rc)
        {
            cout << "Error:unable to create thread for philosopher " << i << endl;

 

        }
    };

 

        //Check if all the threads are finished before ending the execution
       for(int i =0; i<6;i++) {

 

            pthread_join(tphilo[i],NULL);       // attendre que le thread i se termine
        }

 

    };

 

 

    return 0;
}

 
