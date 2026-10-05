#include "ImageEditor.h"
#include <fstream>

bool matchImage(string name1, string name2);

int main()
{
    int score = 0;

    
    /*
    ///Generate Test Images
    ImageEditor im2Invert("pikachu.png");
    im2Invert = -im2Invert;
    im2Invert.save("pikachuInverted.png");

    ImageEditor im2x("pikachu.png");
    im2x *= 2;
    im2x.save("pikachu2x.png");

    ImageEditor im3x("pikachu.png");
    im3x *= 3;
    im3x.save("pikachu3x.png");

    ImageEditor im4x("pikachu.png");
    im4x *= 4;
    im4x.save("pikachu4x.png");

    ImageEditor imSubtract("pikachu.png");
    imSubtract -= Color{ 30, 70, 110 };
    imSubtract.save("pikachuSubtract.png");

    ImageEditor imAdd("pikachu.png");
    imAdd += Color{ 50, 90, 130 };
    imAdd.save("pikachuAdd.png");
    */
    

    cout << "Testing inversion (-) operator..." << endl;
    ImageEditor im1("pikachu.png");
    im1 = -im1;
    im1.save("pikachu1.png");
   
    if (matchImage("pikachu1.png", "pikachuInverted.png"))
    {
        score += 2;
        cout << "inversion (-) operator passed! +2 points" << endl;
    }
    else
    {
        cout << "inversion (-) operator failed." << endl;
    }

    cout << "Testing subtraction (-=) operator..." << endl;
    ImageEditor im2("pikachu.png");
    im2 -= Color{ 30, 70, 110 };
    im2.save("pikachu2.png");

    if (matchImage("pikachu2.png", "pikachuSubtract.png"))
    {
        score += 2;
        cout << "subtraction (-=) operator passed! +2 points" << endl;
    }
    else
    {
        cout << "subtraction (-=)  operator failed." << endl;
    }

    cout << "Testing addition (+=) operator..." << endl;
    ImageEditor im3("pikachu.png");
    im3 += Color{ 50, 90, 130 };
    im3.save("pikachu3.png");

    if (matchImage("pikachu3.png", "pikachuAdd.png"))
    {
        score += 2;
        cout << "addition (+=) operator passed! +2 points" << endl;
    }
    else
    {
        cout << "addition (+=) operator failed." << endl;
    }

    cout << "Testing equality (==) operator..." << endl;
    ImageEditor im4("pikachu.png");
    ImageEditor im5("pikachuInverted.png");
    ImageEditor im6("pikachu2x.png");
    if (im4 == im4 && !(im4 == im5) && !(im4 == im6))
    {
        score += 2;
        cout << "equality (==) operator passed! +2 points" << endl;
    }
    else
    {
        cout << "equality (==) operator failed!" << endl;
    }

    cout << "Testing equality (!) operator..." << endl;
    if (!(im4 != im4) && (im4 != im5) && (im4 != im6))
    {
        score += 2;
        cout << "inequality (!=) operator passed! +2 points" << endl;
    }
    else
    {
        cout << "inequality (!=) operator failed!" << endl;
    }


    cout << "Testing expansion (*=) operator..." << endl;
    ImageEditor im7("pikachu.png");
    ImageEditor im8("pikachu.png");
    ImageEditor im9("pikachu.png");
    im7 *= 2;
    im8 *= 3;
    im9 *= 4;

    im7.save("pikachu7.png");
    im8.save("pikachu8.png");
    im9.save("pikachu9.png");

    bool caught1 = false, caught2 = false;
    cout << "Checking for boundary exceptions..." << endl;
    try
    {
        im7 *= 0;
    }
    catch(runtime_error& e)
    {
        cout << "Exception caught: " << e.what() << endl;
        caught1 = true;
    }
    try
    {
        im7 *= 11;
    }
    catch (runtime_error& e)
    {
        cout << "Exception caught: " << e.what() << endl;
        caught2 = true;
    }

    if (!caught1 || !caught2) cout << "Failed to throw boundary exception" << endl;
    else
    {
        if (matchImage("pikachu7.png", "pikachu2x.png") && matchImage("pikachu8.png", "pikachu3x.png") && matchImage("pikachu9.png", "pikachu4x.png"))
        {
            score += 6;
            cout << "expansion (*=) operator passed! +6 points" << endl;
        }
        else
        {
            cout << "expansion (*=) operator failed." << endl;
        }
    }

    cout << "Final score: " << score << "/16" << endl;
    ofstream ofs("score.txt");
    ofs << score << endl;
    ofs.close();

    return 0;
}

bool matchImage(string name1, string name2)
{
    Picture p1(name1);
    Picture p2(name2);

    if (p1.height() != p2.height())
    {
        cout << "Image height mismatch" << endl;
        return false;
    }
    if (p1.width() != p2.width())
    {
        cout << "Image width mismatch" << endl;
        return false;
    }
    for (int x = 0; x < p1.width(); x++)
    {
        for (int y = 0; y < p1.height(); y++)
        {
            if (p1.red(x, y) != p2.red(x, y) || p1.green(x, y) != p2.green(x, y) || p1.blue(x, y) != p2.blue(x, y))
            {
                cout << "Pixel color mismatch at " << x << "," << y << endl;
                return false;
            }
        }
    }
    return true;
}