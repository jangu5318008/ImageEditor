#include <iostream>
#include "picture.h"
#include "ImageEditor.h"

using namespace std;

int main() {

    Picture pic("pikachu.png");
    cout << "Width: " << pic.width() << endl;
    cout << "Height: " << pic.height() << endl;

    cout << "Red value at 142, 135: " << pic.red(142, 135) << endl;
    for (int y = 0; y < pic.height(); y++) {
        for (int x = 0; x < pic.width(); x++) {
            //249, 82, 45
            if (pic.red(x, y) == 249 && pic.green(x, y) == 82 && pic.blue(x, y) == 45) {
                pic.set(x, y, 6, 255 - 82, 255 - 45); 
            }
        }
    }
    for (int y = pic.height () / 2; y < pic.height(); y++) {

        for (int x = width() / 2 - 25; x < pic.width() / 2 + 25; x++) {
            pic.set(x, y, 0, 0, 255);
        }
    }

    pic.save("Pikachu2.png"); 

    return 0;
}
/*add tolerance to get more pixels close to desired RGB value.
aka more of pikachu's red cheek is colored instead of weird
tweaker patches*/