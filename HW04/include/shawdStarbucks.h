//David Shaw
//CSE 274 HW4 Phase 3
/*
For this assignement, I inherited the Entry class from the original Starbucks.h class, and called it Node.
The idea was to have some extra variables that would be used to draw circles representing the starbucks locations.
The bigger the circle drawn, the more the average population density was between 2000 and 2010. The brighter shade of red
or green the circle was, the less or more people visted that starbucks. For some reason, the drawSolidCircle won't even draw
a circle with the most simplest call. For now I will just explain the rest of my ideas that I was attempting.

I created a separte array of Nodes, that would later be sorted based on radius size, so that all the bigger circles would
not be drawn over the smaller ones (sorted array code not implemented). The problem with this idea is I had to use a different
data structure to use getNearest because figuring out a way to sort all of the nodes inside each grid square seemed too dawnting
so I just created something simpler in hopes of working.
*/

#pragma once
#include <string>
#include <starbucks.h>
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace std;

#define OFST 0.00001

class Node : public Entry {
public:
	int pop_Prev;
	int pop_Next;
	//This will be determined by the population density of the starbucks, the bigger the circle, the bigger the population.
	float radius;
	//This is required in order to use cinder's drawSolidCircle method
	cinder::Vec2<float>* center;
	//if there has been an increase in population, we will color it green, if not, red.
	bool increase;
	 

};

class Square {
public:
	//all the starbucks in a grid square, which is an array of type Entry
	Node* locations;
	//keep track of the number of entries in the grid square, and the current size of the array
	int entries,sizeOf;
	//hashkeys for x & y directions
	int key1,key2;
	//borders of each square, made code for, but could not implement.
	double top,bottom,left,right;
	//grow function to adjust to the size of entries
	void grow();
	//a method to checkBorders
	int* checkBorders(Entry* c, double distance);
	//a function used to compute the hashkey of given coordinates.
	int* computeHash(double d1, double d2);
	//a function to determine whether to grow a square
	bool isFull();
	//adds starbucks locations to a square
	void add(Node c);
	//computes the distance between a location in a square, and given coordinates
	double computeDistance(int loc, double d1, double d2);
	

};


class shawdStarbucks : public Starbucks {
public:
	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y);
	void getNearest(double x, double y, int population, bool pop);
	//actual data structure 
	Square* grid;
	//array of nodes that will be used for drawing
	Node* locArray;
	//Separate computeDistance function for the Node Array
	double computeDistance(int loc, double d1, double d2);
	int col;
	//Number of squares across and up.
	void initialize(int squareX, int squareY);
	
};

