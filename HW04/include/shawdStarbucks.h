#pragma once
#include <string>
#include <starbucks.h>
using namespace std;

#define OFST 0.00001

class Square {
public:
	//all the starbucks in a grid square, which is an array of type Entry
	Entry* locations;
	//keep track of the number of entries in the grid square, and the current size of the array
	int entries,sizeOf;
	//hashkeys for x & y directions
	int key1,key2;
	//borders of each square, may or may not implement.
	double top,bottom,left,right;
	//grow function to adjust to the size of entries

	void grow(Entry* arr,int sizeOf) {
	Entry* temp = new Entry[2*sizeOf];
	for(int i = 0;i<sizeOf;i++) {
		temp[i] = arr[i];
	}
	arr = temp;
	delete temp;

}
	//a function used to compute the hashkey of given coordinates.
	int* computeHash(double d1, double d2);
	//a function to determine whether to grow
	bool isFull() {
		return (this->entries >= this->sizeOf);
	}

	void add(Entry c) {
		if(this->isFull()) {
			this->grow(this->locations,this->sizeOf);
		}
		this->locations[this->entries + 1] = c;
		this->entries++;
	}

	double computeDistance(int loc, double d1, double d2) {
		return sqrt(pow(abs(this->locations[loc].x - d1),2.0) + pow(abs(this->locations[loc].y - d2),2.0));
	}
	

};


class shawdStarbucks : public Starbucks {
public:
	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y);
	Square* grid;
	int col;
	//Number of squares across and up.
	void initialize(int squareX, int squareY);
};

