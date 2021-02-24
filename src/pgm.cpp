#include "pgm.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

PGM::PGM(char *const path) : Image(path)
{
    ifstream fp(path);
    string line;
    // skip header
    for (int i = 1; i <= 3; i++)
        getline(fp, line);
    readContent(fp);
    fp.close();
}

void PGM::readContent(istream &fp)
{
    this->content = new int *[this->height];
    for (int i = 0; i < this->height; i++)
    {
        content[i] = new int[this->width];
    }

    switch (this->magicNumber)
    {
    case 2:
        this->readP2Content(fp);
        break;
    case 5:
        this->readP5Content(fp);
        break;
    default:
        break;
    }
}

void PGM::readP2Content(istream &fp)
{
    int value;
    stringstream stream;
    stream << fp.rdbuf();
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            stream >> value;
            this->content[i][j] = value;
        };
    };
}

void PGM::readP5Content(istream &fp)
{
    int value;
    unsigned char *aux;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fp.read(reinterpret_cast<char *>(aux), 1);
            value = *aux;
            this->content[i][j] = value;
        }
    }
}

void PGM::ShowDetails(bool show_content)
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
                int pixel = this->content[i][j];
                cout << pixel << " ";
            }
            cout << endl;
        }
    }
}