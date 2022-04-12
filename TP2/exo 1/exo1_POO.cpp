#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>


using namespace std;


class rm{

     private:
        int n;
        float condition1 = 0.0;
        float condition2;
        float A[1][6];
        float B[1][6];


     public :
        rm(){

           cout << " Rate Monotonic Algorithm (RM) " << endl;
           cout << " ****************** " << endl;

           cout << " number of task => ";
           cin >> n;// I ask to the user the number of task needed to be scheduled
           cout << " ****************** " << endl;

           float A[n][6];

        }

        void takeData(){
             float compteur = 0;
             // I take every parameters of all tasks
             for( int i = 0; i < n ; i++ ){
                A[i][0] = compteur;
                compteur++;
                cout << " prog n° " << i+1 << endl;
                cout << " ****************** " <<endl;
                cout << "   arrival time => ";
                cin >> A[i][1];
                cout << "   period => ";
                cin >> A[i][2];
                cout << "   deadline => ";
                cin >> A[i][3];
                cout << "   capacity => ";
                cin >> A[i][4];
                cout << " ****************** " << endl;
             }
         }

         void checkCondition(){
             // I calculate the acceptability test
             for(int i = 0; i < n ; i++){
                condition1 = condition1 + A[i][4]/A[i][2];
             }

             condition2 = n*( pow(2.0,1.0/n) - 1) ;
         }

         void findPriority(){
              // I check if the acceptability test is respected
              if ( condition1 <= condition2){

                 cout<< " Tous est bon, début du calcul des prioritées B" <<endl;
                 float maListe[n];

                 // I calculate the priority for every task
                 for( int i = 0; i < n ; i++){
                      A[i][5] = 1 / A[i][2];
                      maListe[i] = A[i][5];
                 }

                 float B[n][6];
                 // I sort my liste with all priority data
                 sort(maListe,maListe + n);

                 for(int i = 0; i < n ; i++){

                     int x = 0;

                     while( A[i][5] != maListe[x] ){
                          x++;
                     }

                     cout<< "la task n°" << i << " doit être exécuter en " << x << " postion. "<<endl;

                     B[x][1] = A[i][1];
                     B[x][2] = A[i][2];
                     B[x][3] = A[i][3];
                     B[x][4] = A[i][4];
                     B[x][5] = A[i][5];
                 }
              cout << B[0][1] << endl;
              }else{
                   cout << " Impossible d'éxecuter tous les programmes avec les contraintes imposées "<<endl;
              }


         }

         void makeGraph(){
           if(condition1 < condition2){
              cout<< " Légende: " << endl;
              cout<< "       - 1 : actif" << endl;
              cout<< "       - 0 : non actif" << endl;
              cout<< "       - D : deadline " << endl;
              cout<< "       - P : period " << endl;


              // Now I will print the result on the terminal

              float graph[11];// first I generate my "graph"

              for( int x; x < 10; x++){
                   graph[x] = 0;// I add 0 for every value of my list
              }

cout << " ************* " << endl;

              for( int i = 0; i < n; i++){

                   int C = B[i][4];// I take the capacity of my task
cout << B[i][4] << endl; 
int P = B[i][2];// I take the period of my task
                   int position = 0;

                   while (position < C){
                         if (graph[position] == 1){
                             C = C + 1;
                         }else{
                             graph[position] = 1;
                         }
                         position++;
                   }

                   graph[P-1] = 1;// I write the deadline on the graph
               }

               cout << " ***************************" << endl;
               for(int truc = 0;  truc < 10; truc++){
                   cout << graph[truc];
               }
               cout <<" "<<endl;
           }

         }

};




int main (){

   rm requette;
   requette.takeData();
   requette.checkCondition();
   requette.findPriority();
   requette.makeGraph();
   cout<< "Fin du programme" << endl;
   return(0);

}
