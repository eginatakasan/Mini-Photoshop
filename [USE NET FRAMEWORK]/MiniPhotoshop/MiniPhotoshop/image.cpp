#include "image.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

ImagePixel::ImagePixel(char* const path) {
    ifstream fp(path);
    bool isRead = false;
    streampos fsize = 0;

    if (!(fp && fp.is_open())) {
        cerr << "File not found"; exit;
    }
    else {
        string line;
        cout << "Reading file..." << endl;

        //Get magic number
        if (getline(fp, line)) {

            char* c_line = new char[line.length() + 1];
            strcpy(c_line, line.c_str());
            if (!isFormatValid(c_line)) {
                cerr << "ImagePixel format is not suitable, only insert PGM, PPM, PBM, BMP or raw image"; return;
            }
            this->magicNumber = c_line;
        }
        else {
            cerr << "File is not readable"; return;
        }
        //Get width and height
        if (getline(fp, line)) {
            stringstream ss(line);
            ss >> this->width;
            ss >> this->height;
        }
        else {
            cerr << "File is not readable"; return;
        }
        //Get max color value
        if (getline(fp, line)) {
            stringstream ss(line);
            ss >> this->maxVal;
        }
        else {
            cerr << "File is not readable"; return;
        }
        //Get image array
        stringstream stream;
        stream << fp.rdbuf();
        this->content = new int* [height];
        for (int i = 0; i < this->height; i++) {
            content[i] = new int[width];
        }
        for (int i = 0; i < this->height; i++) {
            for (int j = 0; j < this->width; j++) {
                stream >> this->content[i][j];
            };
        };

        fp.seekg(0, std::ios::end);
        fsize = fp.tellg() - fsize;
        this->filesize = fsize;

        cout << "File read successfully!" << "\n";
    }
}

void ImagePixel::write(char* const path) {
    FILE* fp;
    fp = fopen(path, "wb");
    if (fp == NULL) {
        cerr << "Error file cannot be saved at (" << path << ") \n";
        exit;
    }
    fprintf(fp, "%s\n%d %d\n%d\n", this->magicNumber, this->width, this->height, this->maxVal);
    fwrite(this->content, 1, this->pixels, fp);
    cout << "File saved successfully at " << path << "...\n";
}

void ImagePixel::showDetails() {
    cout << "magic number: " << this->magicNumber << "\n";
    cout << "width: " << this->width << "px \n";
    cout << "height: " << this->height << "px \n";
    cout << "max color value: " << this->maxVal << "\n";
    cout << "bit per pixel" << "\n";
    cout << "filesize: " << this->filesize << "B \n";
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            cout << this->content[i][j] << " ";
        }
        cout << endl;
    }
}

int ImagePixel::getHeight() { return this->height; }
int ImagePixel::getWidth() { return this->width; }
int ImagePixel::getBitPerPixel() { return this->bitperpixel; }
long ImagePixel::getFileSize() { return this->filesize; }

bool ImagePixel::isFormatValid(char* magicNumber) {
    return strcmp(magicNumber, "P1") || strcmp(magicNumber, "P4") // PBM file
        || strcmp(magicNumber, "P2") || strcmp(magicNumber, "P5") // PGM file
        || strcmp(magicNumber, "P3") || strcmp(magicNumber, "P6"); // PPM file
}