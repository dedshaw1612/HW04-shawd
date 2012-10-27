#pragma once
#include <string>
#include <starbucks.h>
using namespace std;

#define OFST 0.00001

class Square {
public:
	//all the starbucks in a grid square, which is an array of type Entry
	Entry* locations;
	//keep track of the number of entries in the grid square
	int entries;
	//hashkeys for x & y directions
	int key1,key2;
	//borders of each square, may or may not implement.
	double top,bottom,left,right;
	//grow function to adjust to the size of entries
	void grow(Entry* arr,int sizeOf);
	//a function used to compute the hashkey of given coordinates.
	int* computeHash(double d1, double d2);

};


class shawdStarbucks : public Starbucks {
public:
	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y);
	Square* grid;
	//Number of squares across and up.
	void initialize(int squareX, int squareY);
};

