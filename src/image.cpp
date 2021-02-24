#include "image.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

/*
Image class for PPM, PGM, PBM only.
PPM -> Magic Number 3 or 6, has R G B on one pixel (3 values per pixel)
PGM -> Magic Number 2 or 5, greyscale values only (1 value per pixel)
PBM -> Magic number 1 or 4, black and white only, 1 bit value every pixel (1 value per pixel)
*/
Image::Image(char *const path)
{
    ifstream fp(path);
    bool isRead = false;
    streampos fsize = 0;

    if (!(fp && fp.is_open()))
    {
        cerr << "File not found" << endl;
        return;
    }
    cout << "Reading file..." << endl;
    readHeader(fp);

    //get file size
    fp.seekg(0, std::ios::end);
    fsize = fp.tellg() - fsize;
    this->fileSize = fsize;

    fp.close();
}

Image::Image(Image *image)
{
    this->width = image->width;
    this->height = image->height;
    this->magicNumber = image->magicNumber;
    this->maxVal = image->maxVal;
    this->path = image->path;
    this->numberOfBands = image->numberOfBands;
    this->totalPixels = image->totalPixels;
    this->bitPerPixel = image->bitPerPixel;
    this->fileSize = image->fileSize;
}

void Image::readHeader(istream &fp)
{
    string line;
    //Get magic number
    char c;
    fp.read(&c, 1);
    if (c != 'P')
    {
        cerr << "File is not readable" << endl;
        return;
    }
    fp.read(&c, 1);
    if (!isMagicNumberValid(c - '0'))
    {
        cerr << "File is not readable" << endl;
        return;
    }
    this->magicNumber = c - '0';
    getline(fp, line);

    //Get width and height
    if (getline(fp, line))
    {
        stringstream ss(line);
        ss >> this->width;
        ss >> this->height;
    }
    else
    {
        cerr << "File is not readable" << endl;
        return;
    }
    //Get max color value except for PBM
    if (this->magicNumber == 1 || this->magicNumber == 4)
    {
        return;
    }
    if (getline(fp, line))
    {
        stringstream ss(line);
        ss >> this->maxVal;
    }
    else
    {
        cerr << "File is not readable" << endl;
        return;
    }
}

// void Image::Write(char *const path)
// {
//     FILE *fp;
//     fp = fopen(path, "wb");
//     if (fp == NULL)
//     {
//         cerr << "Error file cannot be saved at (" << path << ") \n";
//         exit;
//     }
//     fprintf(fp, "%s\n%d %d\n%d\n", this->magicNumber, this->width, this->height, this->maxVal);
//     fwrite(this->content, 1, this->totalPixels, fp);
//     cout << "File saved successfully at " << path << "...\n";
// }

void Image::ShowDetails(bool show_content)
{
    cout << "magic number: " << this->magicNumber << "\n";
    cout << "width: " << this->width << "px \n";
    cout << "height: " << this->height << "px \n";
    cout << "max color value: " << this->maxVal << "\n";
    cout << "bit per pixel"
         << "\n";
    cout << "fileSize: " << this->fileSize << " B \n";
}

int Image::GetHeight() { return this->height; }
int Image::GetWidth() { return this->width; }
int Image::GetBitPerPixel() { return this->bitPerPixel; }
long Image::GetFileSize() { return this->fileSize; }
int Image::GetMagicNumber() { return this->magicNumber; }
bool Image::isMagicNumberValid(int magicNumber)
{
    return (magicNumber >= 1) && (magicNumber <= 6);
}