#include "PortableAnymaps.h"

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
PortableAnymaps::PortableAnymaps(int width, int height, int magicNumber, int maxVal)
{
    this->width = width;
    this->height = height;
    this->magicNumber = magicNumber;
    this->maxVal = maxVal;
    this->totalPixels = width * height;
}

PortableAnymaps::PortableAnymaps(const char *path)
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

PortableAnymaps::PortableAnymaps(PortableAnymaps *image)
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

void PortableAnymaps::readHeader(istream &fp)
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
        this->totalPixels = this->width * this->height;
    }
    else
    {
        cerr << "File is not readable" << endl;
        return;
    }
    //Get bit per pixels and max color value
    if (this->magicNumber == 1 || this->magicNumber == 4)
    {
        this->maxVal = 1;
        this->bitPerPixel = 1;
        return;
    }
    if (getline(fp, line))
    {
        stringstream ss(line);
        ss >> this->maxVal;

        //get bit per pixel
        int size = 0;
        int n = this->maxVal;
        while (n > 0)
        {
            n = n >> 1;
            size++;
        }

        if (this->magicNumber == 3 || this->magicNumber == 6)
        {
            this->bitPerPixel = size * 3;
        }
        else
        {
            this->bitPerPixel = size;
        }
    }
    else
    {
        cerr << "File is not readable" << endl;
        return;
    }
}

void PortableAnymaps::ShowDetails(bool show_content)
{
    cout << "magic number: " << this->magicNumber << "\n";
    cout << "width: " << this->width << "px \n";
    cout << "height: " << this->height << "px \n";
    cout << "max color value: " << this->maxVal << "\n";
    cout << "bit per pixel"
         << "\n";
    cout << "fileSize: " << this->fileSize << " B \n";
}

int PortableAnymaps::GetHeight() { return this->height; }
int PortableAnymaps::GetWidth() { return this->width; }
int PortableAnymaps::GetBitPerPixel() { return this->bitPerPixel; }
long PortableAnymaps::GetFileSize() { return this->fileSize; }
int PortableAnymaps::GetMagicNumber() { return this->magicNumber; }
bool PortableAnymaps::isMagicNumberValid(int magicNumber)
{
    return (magicNumber >= 1) && (magicNumber <= 6);
}
int PortableAnymaps::GetMaxVal() { return this->maxVal; }