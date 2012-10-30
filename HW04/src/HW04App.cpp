#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <shawdStarbucks.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
};

void HW04App::setup()
{
	int z;
	int entry = 0;

	shawdStarbucks Grid;

	Entry* entriesArray = new Entry[7655];

	ifstream in("../resources/Starbucks_2006.csv");
	while(!(in.eof())) {
		getline(in,entriesArray[entry].identifier,',');
		in >> entriesArray[entry].x;

		//Consume the comma that follws the first double
		in.get();
		
		in >> entriesArray[entry].y;

		//Consume the comma that follows the second double, before the next string
		in.get();

		entry++;

	}

	Grid.build(entriesArray,entry-1);
	
	Entry* answer = Grid.getNearest(0.741801952,0.79441292);
	cout << answer->identifier;

	cin >> z;

}


void HW04App::update()
{
}

void HW04App::draw()
{

}

CINDER_APP_BASIC( HW04App, RendererGl )
