#pragma once
#include <vector>
#include "Genus.h"
using namespace std;

//this is a tree in data structure.
//This class is responsible for managing the entire tree(run, Information exchange, etc.)
class PaleoTree {
public:
	static void initialization();
	static Genus& getGenus(int id);
	static void nextEpoch();
	static void createNewGenus(int parent, int diePro);
	static int getSumGenera();
	static int getSumSpecies();
	static int getEpoch();
private:
	static vector<Genus> genera;
	static int sumGenera;
	static int sumSpecies;
	static int epoch;
};