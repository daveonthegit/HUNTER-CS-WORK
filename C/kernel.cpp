/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 8 G

Kernel filters an image
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

int sobel(int a, int b, int c, int g, int hx, int i){
    int sob = ((g+(2*hx))+i)-((a+(2*b))+c);
    if(sob>255){
        sob = 255;
    }else if (sob <0){
        sob = 0;
    }
    return sob;
}

int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
            int a, b, c,g,hx,i;
            if(row-1>-1&&col-1>-1)
                a = img[row-1][col-1];
            else 
                a = 0;
            if(row-1>-1)
                b = img[row-1][col];
            else
                b = 0;
            if(row-1>-1&&col+1<w)
                c = img[row-1][col+1];
            else   
                c = 0;
            if(row+1<h&&col-1>-1)
                g = img[row+1][col-1];
            else
                g= 0;
            if(row+1<h)
                hx = img[row+1][col];
            else
                hx = 0;
            if(row+1<h&&col+1<w)
                i = img[row+1][col+1];
            else
                i = 0;
            cout<<a<<" "<<b<<" "<<c<<" "<<g<<" "<<h<<" "<<i<<"("<<col<<","<<row<<")"<<endl;
            out[row][col]=sobel(a,b,c,g,hx,i);
		}
	}

	// and save this new image to file "outImage.pgm"
	writeImage(out, h, w);

}

