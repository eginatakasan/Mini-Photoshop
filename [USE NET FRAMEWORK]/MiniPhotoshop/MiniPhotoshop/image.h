#pragma once

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
using std::string;

class ImagePixel {
private:
    /* Variables */
    int** content;
    char* magicNumber; //buat nentuin format gambar 
    int maxVal; //maximum color value for a pixel
    char* path;

    int width; //lebar gambar
    int height; //tinggi gambar
    int pixels; //jumlah total pixels
    int bitperpixel; //jumlah bits untuk setiap pixel
    long filesize; //ukuran file gambar

    /* Functions */
    bool isFormatValid(char* magicNumber);

public:
    /* Constructor */
    ImagePixel(char* const path);

    /* Functions */
    void write(char* const path);
    void showDetails();

    /* Getter Functions */
    char* getPath();
    int getWidth();
    int getHeight();
    int getBitPerPixel();
    long getFileSize();
};

#endif
