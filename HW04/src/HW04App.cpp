#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <shawdStarbucks.h>
#include "Resources.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class HW04App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
private:
	Surface map;
};

	static const int kAppWidth=800;
	static const int kAppHeight=600;
	static const int kTextureSize=1024; 

void HW04App::setup()
{
	int z;
	int entry = 0;
	map = (loadImage(loadResource(RES_MAP)));
	shawdStarbucks Grid;

	Entry* entriesArray = new Entry[7655];

	ifstream places("../resources/Starbucks_2006.csv");
	ifstream census1("../resources/Census_2000.csv");
	ifstream census2("../resources/Census_2010.csv");
	while(!(places.eof())) {
		getline(places,entriesArray[entry].identifier,',');
		places >> entriesArray[entry].x;

		//Consume the comma that follws the first double
		places.get();
		
		places >> entriesArray[entry].y;

		//Consume the comma that follows the second double, before the next string
		places.get();

		entry++;

	}

	Grid.build(entriesArray,entry-1);

	while(!(census1.eof())) {
		int pop(0);
		double d1(0.0);
		double d2(0.0);
		int trash(0);
		//skips first 4 things to get to info
		for(int i=0;i<4;i++) {
			census1 >> trash;
			census1.get();
		}

		census1 >> pop;
		census1.get();
		census1 >> d1;
		census1.get();
		census1 >> d2;

		Grid.getNearest(d1,d2,pop,true);
			
		//Consume final comma before next entry
		places.get();
	
	}

	while(!(census2.eof())) {
		int pop(0);
		double d1(0.0);
		double d2(0.0);
		int trash(0);
		//skips first 4 things to get to info
		for(int i=0;i<4;i++) {
			census2 >> trash;
			census2.get();
		}

		census2 >> pop;
		census2.get();
		census2 >> d1;
		census2.get();
		census2 >> d2;

		Grid.getNearest(d1,d2,pop,false);
		//census1 >> Grid.locArray[entry].pop_Prev;
			
		//Consume final comma before next entry
		places.get();

	}

	for(int i = 0;i<7654;i++) {
		//Radius of the circles is dependent on an average of the population density over the l0 years
		Grid.locArray[i].radius = (float)((Grid.locArray[i].pop_Prev + Grid.locArray[i].pop_Next)/2)/10;
		
		if((Grid.locArray[i].pop_Prev - Grid.locArray[i].pop_Next) < 1) 
			gl::color(Color8u(0,255,0));
		else
			gl::color(Color8u(255,0,0));

		Grid.locArray[i].radius = 50.0;
		gl::drawSolidCircle(*(Grid.locArray[i].center),Grid.locArray[i].radius,10);



	}

	cinder::Vec2<float>* p = new cinder::Vec2<float>(0.0,0.0);
	gl::color(Color8u(0,255,0));
	gl::drawSolidCircle(*p,500.0,0);






	//End Program
	//cin >> z;
}


void HW04App::update()
{
}

void HW04App::draw()
{

}

CINDER_APP_BASIC( HW04App, RendererGl )
