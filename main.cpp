#include <iostream>
#include "picture.h"
#include "ImageEditor.h"

using namespace std;

int main() {
   
   ////////TOLERANCE SLIDER//////////////////////////
    int tolerance; 
    cout << "Enter desired tolerance: "; 
    cin >> tolerance;

    ImageEditor editor("pikachu.png"); 

    editor.flipHorizontal();
    editor.flipVertical(); 
    editor.doubleSize();
    editor.colorFilter(249, 82, 45, tolerance, 6, 173, 210); 

    editor.save("Pikachu2.png"); 

    return 0;
}




  /*
  
   ///////DEBUG////// 
    cout << "Width: " << pic.width() << endl;
    cout << "Height: " << pic.height() << endl;
  ///////DEBUG///////

  */

/*
    for (int y = 0; y < pic.height(); y++) {
        for (int x = 0; x < pic.width(); x++) {
            //249, 82, 45
            // if (pic.red(x, y) == 249 && pic.green(x, y) == 82 && pic.blue(x, y) == 45) {
               // pic.set(x, y, 6, 255 - 82, 255 - 45); 
            



            }
        }
    } 
    */

/*
    for (int y = pic.height () / 2; y < pic.height(); y++) {

        for (int x = pic.width() / 2 - 25; x < pic.width() / 2 + 25; x++) {
            pic.set(x, y, 0, 0, 255);
        }
    }
    */
   
