#include "image.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Image::Image(char *const path)
{
    ifstream fp(path);
    bool isRead = false;
    streampos fsize = 0;

    if (!(fp && fp.is_open()))
    {
        cerr << "File not found";
        exit;
    }
    else
    {
        string line;
        cout << "Reading file..." << endl;

        //Get magic number
        if (getline(fp, line))
        {
            const int lineLength = line.length() + 1;
            char c_line[lineLength];
            strcpy(c_line, line.c_str());
            if (!isFormatValid(c_line))
            {
                cerr << "Image format is not suitable, only insert PGM, PPM, PBM, BMP or raw image";
                return;
            }
            this->magicNumber = c_line;
        }
        else
        {
            cerr << "File is not readable";
            return;
        }
        //Get comments
        if (getline(fp, line))
        {
        }
        //Get width and height
        if (getline(fp, line))
        {
            stringstream ss(line);
            ss >> this->width;
            ss >> this->height;
        }
        else
        {
            cerr << "File is not readable";
            return;
        }
        //Get max color value
        if (getline(fp, line))
        {
            stringstream ss(line);
            ss >> this->maxVal;
        }
        else
        {
            cerr << "File is not readable";
            return;
        }
        //Get image array
        stringstream stream;
        stream << fp.rdbuf();
        this->content = new int *[height];
        for (int i = 0; i < this->height; i++)
        {
            content[i] = new int[width];
        }
        for (int i = 0; i < this->height; i++)
        {
            for (int j = 0; j < this->width; j++)
            {
                stream >> this->content[i][j];
            };
        };

        fp.seekg(0, std::ios::end);
        fsize = fp.tellg() - fsize;
        this->filesize = fsize;

        cout << "File read successfully!"
             << "\n";
    }
}

void Image::Write(char *const path)
{
    FILE *fp;
    fp = fopen(path, "wb");
    if (fp == NULL)
    {
        cerr << "Error file cannot be saved at (" << path << ") \n";
        exit;
    }
    fprintf(fp, "%s\n%d %d\n%d\n", this->magicNumber, this->width, this->height, this->maxVal);
    fwrite(this->content, 1, this->pixels, fp);
    cout << "File saved successfully at " << path << "...\n";
}

void Image::ShowDetails()
{
    cout << "magic number: " << this->magicNumber << "\n";
    cout << "width: " << this->width << "px \n";
    cout << "height: " << this->height << "px \n";
    cout << "max color value: " << this->maxVal << "\n";
    cout << "bit per pixel"
         << "\n";
    cout << "filesize: " << this->filesize << "B \n";
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            cout << this->content[i][j] << " ";
        }
        cout << endl;
    }
}

int Image::GetHeight() { return this->height; }
int Image::GetWidth() { return this->width; }
int Image::GetBitPerPixel() { return this->bitperpixel; }
long Image::GetFileSize() { return this->filesize; }

bool Image::isFormatValid(char *magicNumber)
{
    return strcmp(magicNumber, "P1") || strcmp(magicNumber, "P4")     // PBM file
           || strcmp(magicNumber, "P2") || strcmp(magicNumber, "P5")  // PGM file
           || strcmp(magicNumber, "P3") || strcmp(magicNumber, "P6"); // PPM file
}