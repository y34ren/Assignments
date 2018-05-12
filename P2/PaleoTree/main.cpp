/*
COSC 2947
Programming Project 2: PaleoTree
Created by Yifei Ren on 15/10/22.
Student ID: 0315812
*/

#include "Simulator.h"
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//gave a data type to store datas of each simulator
//it like a data structure
class Data {
public:
	float Genera;//sum genera of each simulator
	float Species;//sum Species of each simulator
	float Lifespan;//sum average Lifespan of each simulator
};

//to in put all value to variables
//simulations: The number of simulations to run
//length: The length of the simulations
//diePro: The probability that a species becomes extinct during one epoch
void input(int& simulations, int& length, float& diePro) {
	cout << "The number of simulations to run: ";
	cin >> simulations;
	cout << "The length of the simulations: ";
	cin >> length;
	cout << "The probability that a species becomes extinct during one epoch:";
	cin >> diePro;
}

//to output final data
//they include:
//	Averages of Genera
//	Averages of Species
//	Averages of Lifespan
//	Standard Deviation of Genera
//	Standard Deviation of Species
//	Standard Deviation of Lifespan
void output(vector<float> a) {
	cout << "Averages:" << '\n'
		<< "Genera:" << a[0] << '\t'
		<< "Species:" << a[1] << '\t'
		<< "Lifespan:" << a[2] << '\n';
	cout << "Standard Deviation:" << '\n'
		<< "Genera:" << a[3] << '\t'
		<< "Species:" << a[4] << '\t'
		<< "Lifespan:" << a[5] << '\n';
}

//this function has two part
//the first part is Calculating the average
//the second part is Calculating the Standard Deviation
vector<float> AverageAndSD(Data s[], float sum) {
	//Definition variables
	float advGenera;
	float advSpecies;
	float advLifespan;
	float sdGenera;
	float sdSpecies;
	float sdLifespan;
	//Calculating the average
	float sumGenera = 0;
	float sumSpecies = 0;
	float sumLifespan = 0;
	for (int i = 0; i < sum; ++i) {//Cumulative sum
		sumGenera += s[i].Genera;
		sumSpecies += s[i].Species;
		sumLifespan += s[i].Lifespan;
	}
	advGenera = sumGenera / sum;
	advSpecies = sumSpecies / sum;
	advLifespan = sumLifespan / sum;
	//Calculating the Standard Deviation
	sumGenera = 0;
	sumSpecies = 0;
	sumLifespan = 0;
	for (int i = 0; i < sum; ++i) {//The cumulative sum of the variance
		sumGenera += pow((s[i].Genera - advGenera), 2);
		sumSpecies += pow((s[i].Species - advSpecies), 2);
		sumLifespan += pow((s[i].Lifespan - advLifespan), 2);
	}
	sumGenera /= sum;
	sumSpecies /= sum;
	sumLifespan /= sum;
	sdGenera = sqrt(sumGenera);
	sdSpecies = sqrt(sumSpecies);
	sdLifespan = sqrt(sumLifespan);
	//save values in a vector
	vector<float> answer;
	answer.clear();
	answer.push_back(advGenera);
	answer.push_back(advSpecies);
	answer.push_back(advLifespan);
	answer.push_back(sdGenera);
	answer.push_back(sdSpecies);
	answer.push_back(sdLifespan);

	return answer;
}

int main() {
	//set random seed
	srand(time(NULL));
	//Definition variables
	int simulations;
	int length;
	float diePro;
	//give a storage
	Data d[5000];
	//input values
	input(simulations, length, diePro);
	cout << '\n';
	//Simulation cycle
	for (int i = 0; i < simulations; ++i) {
		Simulator s(length, diePro);
		s.run();
		s.print();
		//save data
		d[i].Genera = (float)s.getSumGenera();
		d[i].Species = (float)s.getSumSpecies();
		d[i].Lifespan = s.getLifespan();
	}
	//output
	output(AverageAndSD(d, (float)simulations));

	return 0;
}