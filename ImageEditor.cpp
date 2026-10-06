#include <iostream>
#include "ImageEditor.h"
using namespace std;

struct Color
{
	int r, g, b;
};



	ImageEditor::ImageEditor(string inFileName) : pic(inFileName) {
      //  pic(inFileName);
       // pic(inFileName) = placeHolder;

    }
	void ImageEditor::save(string outFileName) {
        pic.save(outFileName);

    }

	ImageEditor& ImageEditor::operator-() {
/////////For a given pixel {r,g,b}, its inverted pixel is {255 - r, 255 - g, 255 - b}//////
        int red, blue, green;

        //// X == I == WIDTH///////// J == I == HEIGHT/////////
        for (int x = 0; x < pic.width(); x++) {
            for (int y = 0; y < pic.height(); y++) {
                red = 255 - pic.red(x, y);
                green = 255 - pic.green(x, y);
                blue = 255 - pic.blue(x, y); 
                pic.set(x, y, red, green, blue);
            }


        }
        return *this;


    //pic.set(x, y, r, g, b);


        
    } //Invert all colors and return *this (image negative)


	ImageEditor& ImageEditor::operator-=(const Color& c) {


    } //subract c from all pixels


	ImageEditor& ImageEditor::operator+=(const Color& c) {


    } //add c to all pixels


	bool ImageEditor::operator==(const ImageEditor& ie) const {


    }  //compare to another image


	bool ImageEditor::operator!=(const ImageEditor& ie) const {


    }  //compare to another image


	ImageEditor& ImageEditor::operator*=(unsigned int n) {


    } //expand by factor of n by n
