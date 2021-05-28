/* ZJW simple C++ code to write out a PPM file representing an ellipse(s) */

#include <iostream>
#include <fstream>
#include <vector>
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

enum style {
	UNIFORM,
	CLUSTER,
	RANDOM,
	LINEAR,
	ILINEAR
};



void makeScene(vector<shared_ptr<shape>>& theShapes, int sizeX, int sizeY, style theStyle ) {

	vec2 corner = vec2(0);

	//make a nice matrix of triangles (rows of blue mountains) and rects
	for (int x=0; x < 4; x++) {
		for (int y=0; y < 4; y++) {
			if (theStyle == UNIFORM) {
				corner.setX(x*(sizeX/4.0));
				corner.setY(y*(sizeY/4.0));
			} else if (theStyle == CLUSTER) {
				corner.setX(x*(sizeX/16.0));
				corner.setY(y*(sizeY/16.0));
			} else if (theStyle == RANDOM) {
				corner.setX(nicerRand(0, sizeX));
				corner.setY(nicerRand(0, sizeY));
			} else if (theStyle == LINEAR) {
				corner.setX(x*(sizeX/4.0));
				corner.setY(x*(sizeY/4.0));
			} else if (theStyle == ILINEAR) {
				corner.setX(x*(sizeX/4.0));
				corner.setY(sizeY - x*(sizeY/4.0));
			}
			vector<vec2> triVerts;
			triVerts.push_back(vec2(corner.x() + nicerRand(-10, 10), corner.y()+50+nicerRand(-10, 20)));
			triVerts.push_back(vec2(corner.x()+ 50+nicerRand(-10, 10), corner.y()+10+nicerRand(-20, 10)));
			triVerts.push_back(vec2(corner.x()+ 100+nicerRand(-10, 10), corner.y()+50+nicerRand(-10, 20)));

			theShapes.push_back(make_shared<Polygon>(triVerts, 1, color(nicerRand(0, 25), nicerRand(0, 55), nicerRand(0, 255) ) ) );

		}
	}
}


/*read command line arguments and write out new ascii file of given size */
int main(int argc, char *argv[]) {

	ofstream outFile;
	int sizeX, sizeY;
	color background(112, 134, 156);

	vector<shared_ptr<shape>> theShapes;

	string outFilename;
	if (argc < 4) {
		cerr << "Error format: a.out sizeX sizeY outfileName" << endl;
		exit(0);
	} 

	sizeX = stoi(argv[1]);
	sizeY = stoi(argv[2]);
	image theImage(sizeX, sizeY, background);




	//a triangle
	makeScene(theShapes, sizeX, sizeY, UNIFORM);
	
	for (int j=0; j < 5; j++) {
		theShapes.push_back(make_shared<ellipse>(nicerRand(100, 200), nicerRand(100, 200), 
								nicerRand(11, 30), nicerRand(11, 30), color(nicerRand(123, 250), 12, nicerRand(123, 250))));	
	}

	for (int i=0; i < 10; i++) {
		theShapes.push_back(make_shared<Rect>(vec2(nicerRand(0, 300), nicerRand(0, 300)), 
				nicerRand(18, 43), nicerRand(15, 36), color(nicerRand(123, 250), 12, 112), nicerRand(1, 20)));
	}

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
