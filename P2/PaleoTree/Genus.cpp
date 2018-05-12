#include <stdlib.h>
#include "Genus.h"
#include "PaleoTree.h"

//Constructor
//Initialization function
//id: a special id for every Genus,and it starts from 1
//parent: the parent Genus. if it don't have parent,it will be 0
//epoch: the time of start
//diePro: The probability that a species becomes extinct during one epoch
Genus::Genus(int id, int parent, int epoch, int diePro) {
	this->id = id;
	this->parent = parent;
	this->diePro = diePro;
	created = epoch;
	extinct = 0;
	isExtinct = false;
	sumSpecies = 1;
}

//do a update in one epoch
//species have a chance to reduce by one
//species have a chance(18%) to add one
//Genus have a chance(2%) to have a Child Genus
//another case, it will do nothing
void Genus::update() {
	int p = rand() % 100;
	if (p < diePro) {//species reduce by one
		sumSpecies--;
		if (sumSpecies <= 0) {//Detect whether Genus is extinct
			isExtinct = true;
			extinct = PaleoTree::getEpoch();
		}
	}
	else if (p < diePro + 18) {//species add one
		sumSpecies++;
	}
	else if (p < diePro + 20) {//create a new Child Genus
		PaleoTree::createNewGenus(id, diePro);
	}
}