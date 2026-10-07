#ifndef PICTURE_H
#define PICTURE_H

#include "lodepng.h"
#include <string>
#include <vector>

using namespace std;

class Picture
{
 public:
   Picture();
   Picture(string filename);
   Picture(int width, int height, int red = 255, int green = 255, int blue = 255);
   Picture(const vector<vector<int> >& grays);
   int width() const { 
      return _width;
   }
   int height() const { 
      return _height; 
   }
   void save(string filename) const;
   int red(int x, int y) const;
   int green(int x, int y) const;
   int blue(int x, int y) const;
   void set(int x, int y, int red, int green, int blue);
   vector<vector<int> > grays() const;
   void add(const Picture& other, int x = 0, int y = 0);

 private:
   void ensure(int x, int y);
   
   vector<unsigned char> _values;
   int _width;
   int _height;   
};

#endif
