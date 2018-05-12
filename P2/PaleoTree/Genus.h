#pragma once

//this class is a note for a tree. It is the smallest unit. it does everything that Each individual needs to be done.
class Genus {
public:
	Genus(int id, int parent, int epoch, int diePro = 15);
	int id;
	int parent;
	int created;
	int extinct;
	bool isExtinct;
	int sumSpecies;
	int diePro;
	void update();
};