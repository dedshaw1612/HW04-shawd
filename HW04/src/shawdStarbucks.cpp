#pragma once
#include <shawdStarbucks.h>
#include <math.h>

using namespace std;

int* computeHash(double d1, double d2) {
	int* hash = new int[2];

	hash[0] = (int)(floor(10*d1));
	hash[1] = (int)(floor(10*d1));

	return hash;

}
/*
void grow(Entry* arr,int sizeOf) {
	Entry* temp = new Entry[2*sizeOf];
	for(int i = 0;i<sizeOf;i++) {
		temp[i] = arr[i];
	}
	arr = temp;
	delete temp;

}
*/




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
	Entry* candidate;
	int candid = 0;
	double distance = this->grid[find[0]*(this->col) + find[1]].computeDistance(0,x,y);
	
	for(int i = 1;i < this->grid[find[0]*(this->col) + find[1]].entries;i++)
	{
		if(this->grid[find[0]*(this->col) + find[1]].computeDistance(i,x,y) < distance)
			candid = i;
		
	}

	return &(this->grid[find[0]*(this->col) + find[1]].locations[candid]);
	





	Entry* test = new Entry();
	return test;

}

