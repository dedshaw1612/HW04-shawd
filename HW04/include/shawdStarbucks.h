#pragma once
#include <string>
#include <starbucks.h>
using namespace std;

#define OFST 0.00001

class shawdStarbucks : public Starbucks {
public:
	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y);
};

class GridSquare {
public:
	Entry* locations;
	int key1,key2;
	double top,bottom,left,right;

};