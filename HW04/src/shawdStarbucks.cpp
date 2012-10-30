#pragma once
#include <shawdStarbucks.h>
#include <math.h>


using namespace std;

//given user coordinates, we give them the hashkeys of a square, and check the entries in it
int* computeHash(double d1, double d2) {
	int* hash = new int[2];

	if(d1 == 1) {
		hash[0] = 9;
	} else {
		hash[0] = (int)(floor(10*d1));
	}

	if(d2 == 1) {
		hash[1] = 9;
	} else {
		hash[1] = (int)(floor(10*d1));
	}


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
	this->initialize(10,10);

	int numEntries = 1;
	int* hashKey = new int[2];
	for(int i = 0; i < n; i++) {
		hashKey = computeHash(c[i].x,c[i].y);
		
		if(i==0)
			this->grid[hashKey[0]*(this->col) + hashKey[1]].add(c[i]);
		
		//check if two entries are the same to avoid adding it more than once
		if((abs(c[i].x - c[i-1].x) < OFST) && (abs(c[i].y - c[i-1].y) < OFST)) {
		} else {
			this->grid[hashKey[0]*(this->col) + hashKey[1]].add(c[i]);
			numEntries++;
		}
			
	}
}

//wasn't really sure how to use this method. getNearest can only be called by the actual shawdStarbucks class.
//it cannot be called within this class, unless it is static, which i thought would break the contract and 
//it couldn't be used by a client.Essentially we check all four borders of each square to see if the distance
//to them from the user coordinates is smaller than the given distance. Also because of this, the program won't be able
//to return a value of a user is in a square with no starbucks locations
int* Square::checkBorders(Entry* c, double distance) {
	int* borders = new int[2];
	int sizeEntries = 0;
	if(abs(this->top - c->y) < distance) {
		//if we are at the top square, we won't need to check above it
		if(this->key2 != 9) {
			borders[0] = 1;
		} else
			borders[0] = NULL;
	}

	if(abs(this->bottom - c->y) < distance) {
		//if we are at the bottom square, we won't need to check below it
		if(this->key2 != 0) {
			borders[0] = 2;
		}
	}

	if(abs(this->left - c->x) < distance) {
		//if we are at the left square, we won't need to check left of it
		if(this->key1 != 0) {
			borders[1] = 3;
		}else
			borders[1] = NULL;
	}

	if(abs(this->right - c->x) < distance) {
		//if we are at the right square, we won't need to check right of it
		if(this->key1 != 9) {
			borders[1] = 4;
		}
	}

	
	return borders;
	//because getNearest can't be called within this class, i needed a way to tell the caller to check the borders,
	//i chose an int* so that if certain values were in indexs of borders, the corresponding borders would be checked.
}


void shawdStarbucks::initialize(int row,int col) {
	this->col = col;
	//as for now this only works with the current data set. Not saying that it wouldn't compile with new data,
	//but this can be easily broken. All data in one square, or data compressed into a skinny line will make this 
	//method break. 
	this->grid = new Square[row*col];
	for(int i = 0; i < row; i++) {
		for(int j = 0;j < col; j++) {
			this->grid[i*col + j].key1 = j;
			this->grid[i*col + j].key2 = i;
			this->grid[i*col + j].locations = new Entry[1];
			this->grid[i*col + j].entries = 0;
			this->grid[i*col + j].sizeOf = 1;


			//used for initiating the borders of each square. 
			this->grid[i*col + j].top = (i+1.0)/10.0;
			this->grid[i*col + j].bottom = i/10.0;
			this->grid[i*col + j].left = j/10.0;
			this->grid[i*col + j].right = (j+1.0)/10.0;
			
			
			
		}
	}
}


Entry* shawdStarbucks::getNearest(double x, double y) {
	int* find = computeHash(x,y);
	double* borders = new double[4];

	
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

		
	}

	//this is where check borders would be called. I wasn't sure how to use getNearest recursivly, let alone if
	//getNearest could have been used in this method without breaking the Starbucks.h contract.
	return &(this->grid[find[0]*(this->col) + find[1]].locations[candid]);


}

