#include "pbm.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <bitset>

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
    string s;
    int i = 0, j = 0;
    int stringIdx = 0;
    getline(fp, s);
    int lineLength = s.length();

    while (stringIdx < lineLength)
    {
        string binary = bitset<8>(s[stringIdx]).to_string();
        for (int k = 0; k < 8; k++)
        {
            if (j > this->width)
            {
                j = 0;
                k = 0;
                i++;
            }
            const char *c = binary.c_str();
            this->content[i][j] = c[k];
            j++;
        }
        stringIdx++;
    };
}

unsigned char PBM::getPixel(int x, int y)
{
    return this->content[x][y];
}

void PBM::ShowDetails(bool show_content)
{
    cout << "magic number: " << this->magicNumber << "\n";
    cout << "width: " << this->width << "px \n";
    cout << "height: " << this->height << "px \n";
    cout << "max color value: " << 1 << "\n";
    cout << "bit per pixel"
         << "\n";
    cout << "fileSize: " << this->fileSize << " B \n";
    if (show_content)
    {
        for (int i = 0; i < this->height; i++)
        {
            for (int j = 0; j < this->width; j++)
            {
                cout << this->content[i][j] << " ";
            }
            cout << endl;
        }
    }
}