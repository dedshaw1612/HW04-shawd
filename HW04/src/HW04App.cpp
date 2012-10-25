#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <shawdStarbucks.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void HW04App::setup()
{
	string ident;
	double d1;
	double d2;
	int entry = 0;

	Entry* entriesArray = new Entry[7001];

	ifstream in(".../resources/Starbucks_2006.csv");
	while(!(in.eof())) {
		getline(in,ident,',');
		entriesArray[entry].identifier = ident;

		in >> d1;
		entriesArray[entry].x = d1;

		//Consume the comma that follws the first double
		in.get();

		in >> d2;
		entriesArray[entry].y = d2;

		//Consume the comma that follows the second double, before the next string
		in.get();

		entry++;


	}
}

void HW04App::mouseDown( MouseEvent event )
{
}

void HW04App::update()
{
}

void HW04App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04App, RendererGl )
