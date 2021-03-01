#include "ppm.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

PPM::PPM(const char *path) : PortableAnymaps(path)
{
    ifstream fp(path);
    string line;
    // skip header
    for (int i = 1; i <= 3; i++)
        getline(fp, line);
    readContent(fp);
    fp.close();
}

void PPM::readContent(istream &fp)
{
    this->content = new _Color *[height];
    for (int i = 0; i < this->height; i++)
    {
        content[i] = new _Color[width];
    }

    switch (this->magicNumber)
    {
    case 3:
        this->readP3Content(fp);
        break;
    case 6:
        this->readP6Content(fp);
        break;
    default:
        break;
    }
}

void PPM::readP3Content(istream &fp)
{
    int r, g, b;
    stringstream stream;
    stream << fp.rdbuf();
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            stream >> r;
            stream >> g;
            stream >> b;
            this->content[i][j] = _Color(r, g, b);
        };
    };
}

void PPM::readP6Content(istream &fp)
{
    int r, g, b;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            unsigned char* aux_r = new unsigned char[1];

            fp.read(reinterpret_cast<char*>(aux_r), sizeof(unsigned char));
            r = (int) *aux_r;
            fp.read(reinterpret_cast<char*>(aux_r), sizeof(unsigned char));
            g = (int) *aux_r;
            fp.read(reinterpret_cast<char*>(aux_r), sizeof(unsigned char));
            b = (int) *aux_r;
            this->content[i][j] = _Color(r, g, b);
        }
    }
}

void PPM::ShowDetails(bool show_content)
{
    cout << "magic number: " << this->magicNumber << "\n";
    cout << "width: " << this->width << "px \n";
    cout << "height: " << this->height << "px \n";
    cout << "max color value: " << this->maxVal << "\n";
    cout << "bit per pixel"
         << "\n";
    cout << "fileSize: " << this->fileSize << " B \n";
    if (show_content)
    {
        for (int i = 0; i < this->height; i++)
        {
            for (int j = 0; j < this->width; j++)
            {
                _Color pixel = this->content[i][j];
                cout << pixel.R << " " << pixel.G << " " << pixel.B << "  ";
            }
            cout << endl;
        }
    }
}

_Color PPM::GetPixel(int x, int y)
{
    return this->content[x][y];
}

int PPM::GetStride()
{
    int size = 0;
    int n = this->maxVal;
    while (n != 0)
    {
        n >> 8;
        size++;
    }
    return (n * 3 * this->width);
}