#pragma once
#include <string>
#include <starbucks.h>
using namespace std;

#define OFST 0.00001

class Square {
public:
	Entry* locations;
	int key1,key2;
	double top,bottom,left,right;

};

class shawdStarbucks : public Starbucks {
public:
	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y);
	Square* grid;
	//Number of squares across and up.
	void initialize(int squareX, int squareY);
};

