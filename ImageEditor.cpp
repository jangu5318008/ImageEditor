#include <iostream>
#include <stdexcept>
#include "ImageEditor.h"
using namespace std;

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
        /////////PRACTICING TERNARY OPERATORS HERE//////////
        /////////shoutout prof tak////////////////
        bool r, g, b; 
        if (pic.height() != ie.pic.height() || pic.width() != ie.pic.width()) {
            return false; 
        }
        else {
            //rgb comparison
            for (int x = 0; x < pic.width(); x++) {
                for (int y = 0; y < pic.height(); y++) {
                    r = (pic.red(x, y) == ie.pic.red(x, y) ? true : false);
                        if (r == false) {
                            return false;

                        }
                    g = (pic.green(x, y) == ie.pic.green(x, y) ? true : false);
                        if (g == false) {
                            return false;

                        }
                    b = (pic.blue(x, y) == ie.pic.blue(x, y) ? true : false);
                        if (b == false) {
                             return false;
                        }          
                }
            } 
            return true;
        }
//return (r == false || g == false || b == false ? false : true);
    }  //compare to another image


	bool ImageEditor::operator!=(const ImageEditor& ie) const {
        return !(*this == ie);

    }  //compare to another image


	ImageEditor& ImageEditor::operator*=(unsigned int n) {
        int xOut = 0, yOut = 0; 


        if (n < 1 || n > 10) {
            throw runtime_error("Please Try Again. N cannot be smaller than 1 nor larger than 10 :3");
        }
        Picture picOut(pic.width() * n, pic.height() * n); 
   
        for (int x = 0; x < pic.width(); x++) {
            yOut = 0;
            for (int y = 0; y < pic.height(); y++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        picOut.set(xOut + i, yOut + j, pic.red(x, y), pic.green(x, y), pic.blue(x, y));
                    }
                }
                yOut += n;
            }
            xOut += n;
        }
        pic = picOut; 
        return *this;   
    } //expand by factor of n by n
