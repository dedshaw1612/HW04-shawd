#pragma once
#include <shawdStarbucks.h>

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

	//virtual void 
void shawdStarbucks::build(Entry* c, int n) {

}

	//virtual Entry* 
Entry* shawdStarbucks::getNearest(double x, double y) {
		Entry* test = new Entry();
		return test;

}

