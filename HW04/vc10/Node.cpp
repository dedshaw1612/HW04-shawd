#include "cinder/app/AppBasic.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

//A constructor that sets the the center coordinate
Node::Node(float cen_X ,float cen_Y) {
	this->center = new Vec2<float>();
	this->center->x = cen_X;
	this->center->y = cen_Y;
	this->pop_Next = 0;
	this->pop_Prev = 0;
	
}