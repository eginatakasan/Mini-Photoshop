#include "Raw.h"

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
Raw::Raw(int width, int height)
{
    this->width = width;
    this->height = height;
    this->content = new int* [this->height];
    for (int i = 0; i < this->height; i++)
    {
        content[i] = new int[this->width];
    }
}

Raw::Raw(const char *path)
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
    readContent(fp);

    //get file size
    fp.seekg(0, std::ios::end);
    fsize = fp.tellg() - fsize;
    this->fileSize = fsize;

    fp.close();
}

void Raw::readHeader(istream &fp)
{
    string line;

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
}

void Raw::readContent(istream &fp)
{
    this->content = new int *[this->height];
    for (int i = 0; i < this->height; i++)
    {
        content[i] = new int[this->width];
    }

    int value;
    stringstream stream;
    stream << fp.rdbuf();
    this->maxVal = 0;
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            stream >> value;
            this->content[i][j] = value;
            if (value > maxVal)
            {
                this->maxVal = value;
            }
        };
    };
}

void Raw::ShowDetails(bool show_content)
{
    cout << "width: " << this->width << "px \n";
    cout << "height: " << this->height << "px \n";
    cout << "max color value: " << this->maxVal << "\n";
    cout << "bit per pixel"
         << "\n";
    cout << "fileSize: " << this->fileSize << " B \n";
}

int Raw::GetHeight() { return this->height; }
int Raw::GetWidth() { return this->width; }
int Raw::GetBitPerPixel()
{
    //get bit per pixel
    int size = 0;
    int n = this->maxVal;
    while (n > 0)
    {
        n = n >> 1;
        size++;
    }
    return size;
}
long Raw::GetFileSize() { return this->fileSize; }
int Raw::GetMaxVal() { return this->maxVal; }
int Raw::GetPixel(int x, int y)
{
    return this->content[x][y];
}

void Raw::SetPixel(int x, int y, int pixel) {
    this->content[x][y] = pixel;
}

void Raw::Write(const char* path) {
    ofstream fp(path);
    if (!fp)
    {
        cerr << "Error file cannot be saved at (" << path << ") \n";
        exit;
    }
    fp << this->width << " " << this->height << endl;

    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            int pixel = this->content[i][j];
            fp << pixel;
            if (j == this->width - 1)
            {
                fp << endl;
            }
            else
            {
                fp << " ";
            }
        };
    };

    fp.close();
}