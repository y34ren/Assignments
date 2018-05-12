#pragma once

//this class is a manager. It manages information throughout the tree, and the statistics collected.
//It also is responsible for implementing the entire simulation.
class Simulator {
public:
	Simulator(int epochs, float diePro);
	int getSumGenera();
	int getSumSpecies();
	float getLifespan();
	void run();
	void print();
private:
	int sumGenera;
	int sumSpecies;
	int totalEpochs;
};