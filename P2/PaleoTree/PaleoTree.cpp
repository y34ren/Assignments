#include <vector>
#include "PaleoTree.h"

vector<Genus> PaleoTree::genera;
int PaleoTree::sumGenera;
int PaleoTree::sumSpecies;
int PaleoTree::epoch;

//Initialization function
void PaleoTree::initialization() {
	sumGenera = 0;
	sumSpecies = 0;
	epoch = 0;
	genera.clear();
}

//get genus by id,and it returns a refrense of genus
Genus& PaleoTree::getGenus(int id) {
	for (vector<Genus>::size_type it = 0; it != genera.size(); ++it)//Traversal cycle
		if (genera[it].id == id)
			return genera[it];
}

//to execute next epoch
void PaleoTree::nextEpoch() {
	++epoch;
	for (vector<Genus>::size_type it = 0; it != genera.size(); ++it)//Traversal cycle
		if (!genera[it].isExtinct)//if it's live, execute update
			genera[it].update();
}

//to create new genus by parent.
//if it'a first genus, the parent is 0
void PaleoTree::createNewGenus(int parent, int diePro) {
	Genus newGenus(++sumGenera, parent, epoch, diePro);
	genera.push_back(newGenus);
}

//return the sum of Genera
int PaleoTree::getSumGenera(){
	return sumGenera;
}

//return the sum of Species
int PaleoTree::getSumSpecies(){
	sumSpecies = 0;
	for (vector<Genus>::size_type it = 0; it != genera.size(); ++it)//Traversal cycle
		if (!genera[it].isExtinct)
			sumSpecies += genera[it].sumSpecies;//to Calculate Species
	return sumSpecies;
}

//return epoch of now
int PaleoTree::getEpoch() {
	return epoch;
}
