#pragma once
#include <shawdStarbucks.h>
#include <math.h>

using namespace std;

/*
 * Note that the origin is in the LOWER LEFT corner, unlike in previous assignments.
 */
/*
 * This is an "abstract class" ... it contains a list of the public methods of the class, but
 *  they are all "pure virtual," which means they are not implemented anywhere in the code.
 *
 * An abstract class is used like an interface in Java: The only purpose of this class is to be the base
 *  class for your own data structure. You should make a .h and .cpp for you data structure ... in my
 *  case I made brinkmwjStarbucks.h and brinkmwjStarbucks.cpp, and my class was called "brinkmwjStarbucks"
 */
//class shawdStarbucks {// : public shawdStarbucks {
//public:

void grow(Entry* arr,int sizeOf) {
	Entry* temp = new Entry[2*sizeOf];
	for(int i = 0;i<sizeOf;i++) {
		temp[i] = arr[i];
	}
	arr = temp;
	delete temp;

}

int* computeHash(double d1, double d2) {
	int* hash = new int[2];

	hash[0] = (int)(floor(10*d1));
	hash[1] = (int)(floor(10*d1));

	return hash;

}


void shawdStarbucks::build(Entry* c, int n) {
	int* hashKey = new int[2];
	int numEntries;
	for(int i = 0; i < n; i++) {
		hashKey = computeHash(c[i].x,c[i].y);
		this->grid[hashKey[0]*(this->col) + hashKey[1]].add(c[i]);



	}
}



void shawdStarbucks::initialize(int row,int col) {
	this->grid = new Square[row*col];
	for(int i = 0; i < row; i++) {
		for(int j = 0;j < col; j++) {
			this->grid[i*col + j].key1 = j;
			this->grid[i*col + j].key2 = i;
		}
	}
}

	//virtual Entry* 
Entry* shawdStarbucks::getNearest(double x, double y) {
	int* find = computeHash(x,y);
	Entry* test = new Entry();
	return test;

}

