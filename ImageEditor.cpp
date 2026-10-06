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


    } //Invert all colors and return *this (image negative)


	ImageEditor& ImageEditor::operator-=(const Color& c) {
       
       ////////////////USING COLOR STRUCT NOW////////////////////
       
        int red, green, blue; 
        
        
        for (int x = 0; x < pic.width(); x++) {
            for (int y = 0; y < pic.height(); y++) {
                red = pic.red(x, y) - c.r;
                if (red < 0) {
                    red = 0;
                }
                green = pic.green(x, y) - c.g;
                if (green < 0) {
                    green = 0;
                }
                blue = pic.blue(x, y) - c.b;
                if (blue < 0) {
                    blue = 0;
                } 

                pic.set(x, y, red, green, blue);
            }


        }


        return *this;

    } //subract c from all pixels


	ImageEditor& ImageEditor::operator+=(const Color& c) {
        int red, green, blue; 
        
        
        for (int x = 0; x < pic.width(); x++) {
            for (int y = 0; y < pic.height(); y++) {
                red = pic.red(x, y) + c.r;
                if (red > 255) {
                    red = 255;
                }
                green = pic.green(x, y) + c.g;
                if (green > 255) {
                    green = 255;
                }
                blue = pic.blue(x, y) + c.b;
                if (blue > 255) {
                    blue = 255;
                } 

                pic.set(x, y, red, green, blue);
            }


        }


        return *this;
        

    } //add c to all pixels


	bool ImageEditor::operator==(const ImageEditor& ie) const {
        

    }  //compare to another image


	bool ImageEditor::operator!=(const ImageEditor& ie) const {


    }  //compare to another image


	ImageEditor& ImageEditor::operator*=(unsigned int n) {


    } //expand by factor of n by n
