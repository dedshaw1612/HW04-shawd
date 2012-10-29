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

void Square::grow() {
	Entry* temp = new Entry[2*this->sizeOf];
	for(int i = 0;i<this->sizeOf;i++) {
		temp[i] = this->locations[i];
	}
	this->locations = temp;
	this->sizeOf = 2 * sizeOf;

}

bool Square::isFull()
{
	return (this->entries >= this->sizeOf);
}

void Square::add(Entry c) {
	if(this->isFull()) {
		this->grow();
	}
	this->locations[this->entries] = c;
	this->entries = this->entries + 1;
}

double Square::computeDistance(int loc, double d1, double d2) {
	return sqrt(pow(abs(this->locations[loc].x - d1),2.0) + pow(abs(this->locations[loc].y - d2),2.0));
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
	this->col = col;

	this->grid = new Square[row*col];
	for(int i = 0; i < row; i++) {
		for(int j = 0;j < col; j++) {
			this->grid[i*col + j].key1 = j;
			this->grid[i*col + j].key2 = i;
			this->grid[i*col + j].locations = new Entry[1];
			this->grid[i*col + j].entries = 0;
			this->grid[i*col + j].sizeOf = 1;

		}
	}
}

	//virtual Entry* 
Entry* shawdStarbucks::getNearest(double x, double y) {
	int* find = computeHash(x,y);
	//Entry* candidate;
	int candid = 0;
	double distance = this->grid[find[0]*(this->col) + find[1]].computeDistance(candid,x,y);
	
	for(int i = 1;i < this->grid[find[0]*(this->col) + find[1]].entries;i++)
	{
		if(distance <= OFST) {
			return &(this->grid[find[0]*(this->col) + find[1]].locations[candid]);
		}

		if(this->grid[find[0]*(this->col) + find[1]].computeDistance(i,x,y) < distance) {
			candid = i;
		}

		if(i == 800)
			int meow = 5;

		
	}

	return &(this->grid[find[0]*(this->col) + find[1]].locations[candid]);


}

