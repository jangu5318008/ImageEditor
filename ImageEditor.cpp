#include "ImageEditor.h"

///////////j = x = width ///////////////////////
///////////i = y = height///////////////////////

ImageEditor::ImageEditor (string inFileName) {
    pic = Picture(inFileName);
}
	void ImageEditor::flipVertical() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < width() / 2; j++) {
                swapPixels(j, i, width() - j - 1, i);
            }
        }

    }
	void ImageEditor::flipHorizontal() {
        for (int i = 0; i < pic.height(); i++) {
            for (int j = 0; j < pic.width() / 2; j++) {
                swapPixels(j, i, pic.width() - j - 1, i);
            }
    }
	void ImageEditor::doubleSize() {
        Picture picOut(width() * 2, height() * 2);
        int xOut = 0;
        int yOut = 0;


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

