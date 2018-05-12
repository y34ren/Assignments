#include "Simulator.h"
#include "PaleoTree.h"
#include "Genus.h"
#include <iostream>
using namespace std;

//Constructor
//Initialization function
Simulator::Simulator(int epochs, float diePro) {
	totalEpochs = epochs;
	PaleoTree::initialization();
	PaleoTree::createNewGenus(0, (int)(diePro * 100));
}

//get the sum of Genera in this Simulator
int Simulator::getSumGenera() {
	sumGenera = PaleoTree::getSumGenera();
	return sumGenera;
}

//get the sum of Species in this Simulator
int Simulator::getSumSpecies() {
	sumSpecies = PaleoTree::getSumSpecies();
	return sumSpecies;
}

//get the average of Lifespan in this Simulator
float Simulator::getLifespan() {
	int Genera = getSumGenera();
	int sum = 0;//how many Genera
	int lifespan = 0;//sum of lifespan
	for (int i = 1; i <= Genera; ++i) {//Cumulative totals of lifespan
		Genus& g = PaleoTree::getGenus(i);
		if (g.isExtinct) {
			++sum;
			lifespan += g.extinct - g.created;//Calculate lifespan
		}
	}
	if (sum > 0)return (float)lifespan / (float)sum;//Calculate average
	else return 0;
}

//Execution epoch cycle
void Simulator::run() {
	for (int i = 0; i < totalEpochs; ++i)
		PaleoTree::nextEpoch();
}

//to print values after each Simulator down
//they include:
//sum of Genera
//sum of Species
//average of Lifespan
void Simulator::print() {
	cout << "The total number of genera: " << getSumGenera() << '\n';
	cout << "The total number of species: " << getSumSpecies() << '\n';
	cout << "The average lifespan: " << getLifespan() << '\n' << '\n';
}
