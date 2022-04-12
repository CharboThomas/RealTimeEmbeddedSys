#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>


// RM method code

using namespace std;

int main (){

   float condition1 = 0;
   int n;

   cout << " Rate Monotonic Algorithm (RM) " << endl;
   cout << " ****************** " << endl;

   cout << " number of task => ";
   cin >> n;// I ask to the user the number of task needed to be scheduled
   cout << " ****************** " << endl;

   float A[n][6];

   // I take every parameters of all tasks
   for( int i = 0; i < n ; i++ ){
       cout << " task N° " << i+1 << endl;
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


   // I calculate the acceptability test
   for(int i = 0; i < n ; i++){
         condition1 = condition1 + A[i][4]/A[i][2];
   }

   float condition2 = n*( pow(2.0,1.0/n) - 1) ;

    cout << " Condition check : " << endl;
    cout << "     condition 1 = " << condition1 << endl;
    cout << "     condition 2 = " << condition2 << endl;

    cout << " condition 1 < condition 2 <=> " << condition1 << " < " << condition2 << endl; 
    cout << " ****************** " << endl;

   // I check if the acceptability test is respected
   if ( condition1 <= condition2){

      cout<< " Condtion check is OK, let's orgenized the task" <<endl;
      cout << " ****************** " << endl;
      float maListe[n];

      // I calculate the priority for every task
      for(int i = 0; i < n ; i++){
         A[i][5] = 1 / A[i][2];
         maListe[i] = A[i][5];
      }

      float B[n][6];// i will use this list in order to have the most priority task on the begining of the list
      // I sort my liste with all priority data
      sort(maListe,maListe + n);

      for(int i = 0; i < n ; i++){

          int x = 0;

          while( A[i][5] != maListe[x] ){
             x++;
          }

          cout<< " The task n°" << i << " need to be execute in " << n-x-1 << " postion. "<<endl;

          B[n-x-1][1] = A[i][1];
          B[n-x-1][2] = A[i][2];
          B[n-x-1][3] = A[i][3];
          B[n-x-1][4] = A[i][4];
          B[n-x-1][5] = A[i][5];

     }

     cout << " ****************** " << endl;
     cout << " Légende : " << endl;
     cout << "     - 1 = task is running " << endl;
     cout << "     - 0 = task is waiting " << endl;
     cout << "     - D = Deadline " << endl;
     cout << "     - P = Periode " << endl;
     cout << " ****************** " << endl;

     // Now I will print the result on the terminal

     char graph[11];// first I generate my "graph" for printing the evolution of the system (all tasks) on the time
     char graphTemp[11];// second, I generate this plot in order to print the evolution of one task on  the time

     for( int x; x < 10; x++){
         graph[x] ='0';// I add 0 for every value of my list
         graphTemp[x]='0';// I add 0 for every value of my list
     }

     for( int i = 0; i < n; i++){

       int C = B[i][4];// I take the capacity of my task
       int P = B[i][2];// I take the period of my task
       int position = 0;

       while (position < C){

         // if some position on the final plot is occupied by a task, the system can't write her
         // but also, if the begining time don't append, the system can't write her
         if (graph[position] == '1' or position < B[i][1]){
            C = C + 1;
            graphTemp[position] = '0';
         }else{
             // if the space is free, the systeme can whrite her
             graph[position] = '1';
             graphTemp[position] = '1';
         }
         position++;
       }

       if (B[i][4] == B[i][3]) {

       graph[P-1] = 'P';// I write the deadline on the graph
       graphTemp[P-1] = 'P';

       } else {

       // if the period and the deadline are différent, I add them to the graph
       int D = B[i][3];
       graphTemp[D-1] = 'D';// I add the deadline to the graph of the task

       graph[P-1] = 'P';// I write the deadline on the graph
       graphTemp[P-1] = 'P';
       }



       cout << " Task N° " << i << " : ";

       for(int truc = 0; truc < 10; truc++){
           cout << graphTemp[truc];
       }

       cout << " " << endl;

       graphTemp[P-1] = '0';
     }

     cout << " Our solution : ";
     for(int truc = 0;  truc < 10; truc++){
          cout << graph[truc];
      }
     cout <<" "<<endl;


   }else{
     cout << " Impossible d'éxecuter tous les programmes avec les contraintes imposées "<<endl;
   }

   return(0);

}
