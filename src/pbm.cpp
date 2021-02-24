#include "pbm.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

PBM::PBM(char *const path) : Image(path)
{
    ifstream fp(path);
    string line;
    // skip header
    for (int i = 1; i <= 2; i++)
        getline(fp, line);
    readContent(fp);
    fp.close();
}

void PBM::readContent(istream &fp)
{
    this->content = new unsigned char *[this->height];
    for (int i = 0; i < this->height; i++)
    {
        content[i] = new unsigned char[this->width];
    }

    switch (this->magicNumber)
    {
    case 1:
        this->readP1Content(fp);
        break;
    case 4:
        this->readP4Content(fp);
        break;
    default:
        break;
    }
}

void PBM::readP1Content(istream &fp)
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

void PBM::readP4Content(istream &fp)
{
    unsigned char *aux;
    unsigned char *b;
    int i = 0;
    int x = 0;
    while (!fp.eof())
    {
        fp.read(reinterpret_cast<char *>(b), sizeof(unsigned char));
        cout
            << *b << endl;
        for (int a = 0; a < 8; a++)
        {
            this->content[i][x] = (*b >> (7 - a)) & 0x1;
            cout << (*b >> (7 - a)) << endl;
            x++;
            if (x == this->width)
            {
                x = 0;
                a = 8;
                if (i == this->height - 1)
                {
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
    };
}

void PBM::ShowDetails(bool show_content)
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