#include "ImageEditor.h"

ImageEditor::ImageEditor (string inFileName) {
    pic = Picture(inFileName);
}
	ImageEditor(string inFileName) {

    }
	void ImageEditor::flipVertical() {

    }
	void ImageEditor::flipHorizontal() {

    }
	void ImageEditor::doubleSize() {

    }
	void ImageEditor::colorFilter(int redTarget, int greenTarget, int blueTarget, int tolerance, int newRed, int newGreen, int newBlue) {

    }
	void ImageEditor::save(string outFileName) {

    }

	void ImageEditor::swapPixels(int x1, int y1, int x2, int y2) {

    }
    void ImageEditor::blueSquare() {
        for (int y = pic.height() / 2 - 25; y < pic.height() / 2 + 25; y++) {
            for (int x = pic.width() / 2 - 25; x < pic.width() / 2 + 25; x++) {
                pic.set(x, y, 127, 0, 255);
            }
        }
    }
	Picture pic {
         
    }
