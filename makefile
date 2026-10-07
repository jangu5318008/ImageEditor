CC = g++
CFLAGS = -c -g -Wall -std=c++17 -fpermissive
EXENAME = ImageEditor

default: main.o ImageEditor.o Picture.o lodepng.o
	$(CC) main.o ImageEditor.o Picture.o lodepng.o -o $(EXENAME)

main.o: main.cpp ImageEditor.h Picture.h lodepng.h
	$(CC) $(CFLAGS) main.cpp 

ImageEditor.o: ImageEditor.cpp ImageEditor.h
	$(CC) $(CFLAGS) ImageEditor.cpp

Picture.o: Picture.cpp Picture.h
	$(CC) $(CFLAGS) Picture.cpp

lodepng.o: lodepng.cpp lodepng.h
	$(CC) $(CFLAGS) lodepng.cpp

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)