#include "ImageEditor.h"

///////////j = x = width ///////////////////////
///////////i = y = height///////////////////////

ImageEditor::ImageEditor (string inFileName) {
    pic = Picture(inFileName);
}
	void ImageEditor::flipVertical() {
	       ///////outer loop halved/////
	        for (int y = 0; y < pic.height() / 2; y++) {
	            for (int x = 0; x < pic.width(); x++) {
	               //current column, current row
	               //same column, opposite row
	                swapPixels(x, y, x, pic.height() - y - 1);
	            }
	        }

	    }
	void ImageEditor::flipHorizontal() {
	    ////inner loop halved/////
	        for (int y = 0; y < pic.height(); y++) {
	            for (int x = 0; x < pic.width() / 2; x++) {
	                swapPixels(x, y, pic.width() - x - 1, y);
	            }
	        }
    }
    void ImageEditor::doubleSize() {
        
        int xOut = 0;
        int yOut = 0;
        int r = pic.red(x, y);
        int g = pic.green(x, y);
        int b = pic.blue(x, y);

        Picture picOut(pic.width() * 2, pic.height() * 2);

        for (int y = 0; y < pic.height(); y++) {
            for (int x = 0; x < pic.width(); x++) {
                //5 items
                picOut.set(xOut, yOut, r, g, b);
                picOut.set(xOut + 1, yOut, r, g, b);
                picOut.set(xOut, yOut + 1, r, g, b);
                picOut.set(xOut + 1, yOut + 1, r, g, b);
                xOut += 2;
            }
            yOut += 2;
        }

    }
	void ImageEditor::colorFilter(int redTarget, int greenTarget, int blueTarget, int tolerance, int newRed, int newGreen, int newBlue) {

    }
	void ImageEditor::save(string outFileName) {

    }

	void ImageEditor::swapPixels(int x1, int y1, int x2, int y2) {
        int tempRed = pic.red(x1, y1);
        int tempGreen = pic.green(x1, y1);
        int tempBlue = pic.blue(x1, y1);
        pic.set(x1, y1, pic.red(x2, y2), pic.green(x2, y2), pic.blue(x2, y2));
        pic.set(x2, y2, tempRed, tempGreen, tempBlue);
    }
/* 
   void ImageEditor::blueSquare() {
        for (int y = pic.height() / 2 - 25; y < pic.height() / 2 + 25; y++) {
            for (int x = pic.width() / 2 - 25; x < pic.width() / 2 + 25; x++) {
                pic.set(x, y, 127, 0, 255);
            }
        }
    }
*/
