#include "image.h"

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

Image::Image(char* const path) {
    FILE * fp;
	bool isRead = false;

	fp = fopen(path, "rb");
	if(fp == NULL){
		cerr<<"File tidak dapat ditemukan";
		exit;
	} else {
		cout << "Reading file..." << "\n";
        //read
        cout << "File read successfully" << "\n";
	}
}

int Image::getHeight() { return height; }
int Image::getWidth() { return width; }
int Image::getBitPerPixel() { return bitperpixel; }
long Image::getFileSize() { return filesize; }