/* ZJW simple C++ code for lab08 - full tests  NOT FULL CODE!!! */

#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <memory>
#include "shape.h"
#include "color.h"
#include "rect.h"
#include "ellipse.h"
#include "polygon.h"
#include "util.h"
#include "image.h"
#include "createImage.h"

using namespace std;

/*write out PPM data, using the defined implicit equation 
  interior points write a differnt color then exterior points */

//TODO you must do this portion
//void createImage


/*read command line arguments and write output - covers all tests for lab08*/
int main(int argc, char *argv[]) {

	ofstream outFile;
	int sizeX, sizeY;
	color background(112, 134, 156);

	vector<shared_ptr<shape>> theShapes;

	/* four polygons - 2 concave */
	vector<vec2> Verts0;
	Verts0.push_back(vec2(50, 50));
	Verts0.push_back(vec2(75, 25));
	Verts0.push_back(vec2(100, 50));
	Verts0.push_back(vec2(100, 100));
	Verts0.push_back(vec2(50, 100));
	shared_ptr<Polygon> t2 = make_shared<Polygon>(Verts0, 5, color(250)) ;

	vector<vec2> Verts1;
	Verts1.push_back(vec2(200, 50));
	Verts1.push_back(vec2(225, 75));
	Verts1.push_back(vec2(250, 50));
	Verts1.push_back(vec2(250, 100));
	Verts1.push_back(vec2(200, 100));
	shared_ptr<Polygon> t3 = make_shared<Polygon>(Verts1, 5, color(250)) ;

	vector<vec2> Verts2;
	Verts2.push_back(vec2(50, 200));
	Verts2.push_back(vec2(100, 200));
	Verts2.push_back(vec2(100, 250));
	Verts2.push_back(vec2(50, 250));
	shared_ptr<Polygon> t4 = make_shared<Polygon>(Verts2, 5, color(250)) ;

	vector<vec2> Verts3;
	Verts3.push_back(vec2(200, 200));
	Verts3.push_back(vec2(210, 240));
	Verts3.push_back(vec2(250, 250));
	Verts3.push_back(vec2(200, 250));
	shared_ptr<Polygon> t5 = make_shared<Polygon>(Verts3, 5, color(250)) ;


	theShapes.push_back(t2);
	theShapes.push_back(t3);
	theShapes.push_back(t4);
	theShapes.push_back(t5);
	
	/*ellipse with zero divisor*/
	theShapes.push_back(make_shared<ellipse>(vec2(150, 150), 0.0, 14, color(250)));	
	
	//rect with reversed corners
	theShapes.push_back(make_shared<Rect>(vec2(170, 80), vec2(120, 60), color(250), 8));

	/*polygon out of bounds */
	vector<vec2> Verts4;
	Verts4.push_back(vec2(-10, 150));
	Verts4.push_back(vec2(10, 130));
	Verts4.push_back(vec2(10, 170));
	shared_ptr<Polygon> t6 = make_shared<Polygon>(Verts4, 5, color(250)) ;
	theShapes.push_back(t6);

	/*ellipse out of bounds*/
	theShapes.push_back(make_shared<ellipse>(vec2(150, -2), 4, 28, color(250)));	

	//rect out of bounds and inverted vertices */
	theShapes.push_back(make_shared<Rect>(vec2(10, 210), vec2(-10, 240), color(250), 4));

	/*ellipse out of bounds and zero radius! */
	theShapes.push_back(make_shared<ellipse>(vec2(-2, 50), 40, 0, color(250)));	

	/*polygon out of bounds  and concave!*/
	vector<vec2> Verts5;
	Verts5.push_back(vec2(-10, 250));
	Verts5.push_back(vec2(50, 290));
	Verts5.push_back(vec2(140, 300));
	Verts5.push_back(vec2(-10, 300));
	shared_ptr<Polygon> t7 = make_shared<Polygon>(Verts5, 5, color(250)) ;
	theShapes.push_back(t7);

	string outFilename;
	if (argc < 4) {
		cerr << "Error format: a.out sizeX sizeY outfileName" << endl;
		exit(0);
	} 

	sizeX = stoi(argv[1]);
	sizeY = stoi(argv[2]);
	image theImage(sizeX, sizeY, background);

	for (int i=0; i < 1; i++) {
		//code to write the files
		outFilename.append(argv[3]);
		if (i < 10)
		  	outFilename.append(to_string(0));
		outFilename.append(to_string(i));
		outFilename.append(".ppm");
		outFile.open(outFilename);

		//create the image
		createImage(theImage, theShapes, color(12));

		cout << "writing an image of size: " << sizeX << " " << sizeY << " to: " << argv[3] << endl;
		theImage.fullWriteOut(outFile);
		outFile.close();
		outFilename.erase();

	}//end animation loop
}
