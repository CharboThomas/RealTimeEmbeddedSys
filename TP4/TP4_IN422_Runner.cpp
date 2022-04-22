#include <iostream>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <unistd.h>
#include <time.h>
#include <cstdlib>

using namespace std;

void* runner(void* threadarg){

	int i = *(int*)threadarg;// I take the ID number of the runner
	cout << "The Runner " << i << " begin the race " << endl;

	int timeOfRace = rand()%10+5;// I generate a random variable for the time run by the runner
	sleep(timeOfRace);// I stop my runner during a random time
	cout << "The Runner " << i << " finish the race " << endl;

	pthread_exit(NULL);

}

int main(){

	time_t debut;
	time_t fin1,fin2;

	int time1 = 0;
	int time2 = 0;

	pthread_t team1Runner[3];// It's the team One
	pthread_t team2Runner[3];// It's the team two

	// the goal of this for loop is to execute every round of the race for the 2 team
	for(int x = 0 ; x < 3; x++){

		cout << " ***************************************** " << endl;
		cout << "                   team 1                  " << endl;

		int rc;
		rc = pthread_create(&team1Runner[x], NULL, runner, &x);// I create the runner i of the team 1
		if (rc){
			cout << "Error:unable to create thread for runner " << x << endl;
		}else{

			time(&debut);// I take the time of the begining of the execution
			pthread_join(team1Runner[x],NULL);
			time(&fin1);// I take the time when the thread is over
			time1 += fin1 - debut;// I take the time of the execution of the thread
			cout << "Total time = " << time1 << endl;
		}



		cout << "                   team 2                  " << endl;

		rc = pthread_create(&team2Runner[x], NULL, runner, &x);// I do the same think for the team 2 
		if (rc){
			cout << "Error:unable to create thread for runner " << x << endl;
		}else{
			time(&debut);
			pthread_join(team2Runner[x],NULL);
			time(&fin2);
			time2 += fin2 - debut;
			cout << "Total time = " << time2 << endl;
		}



		cout <<  " ***************************************** " << endl;
		// the goal of this condition is to see who arrive first in this round
		if(time1 < time2){
			cout << "the runner " << x << " of the team 1 arrive first " << endl;
		}else{
			cout << "the runner " << x << " of the team 2 arrive first " << endl;
		}

	}

	cout << "Total time of the run for team 1: " << time1 << " s " << endl;
	cout << "Total time of the sum for team 2: " << time2 << " s " << endl;

	// the goal of this condition us to see who arrive first in this race
	if (time1 < time2){
		cout << "Team 1 win the race " << endl;
	}else{
		cout << "Team 2 win the race " << endl;
	}

	return 0;
}
