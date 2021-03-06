#include "pgm.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <bitset>
#include <climits>
#include <vector>
#include <iterator>

using namespace std;

PGM::PGM(const char *path) : PortableAnymaps(path)
{
    if (this->magicNumber == 2)
    {
        ifstream fp(path);
        readContent(fp);
        fp.close();
    }
    else if (this->magicNumber == 5)
    {
        ifstream fp(path, std::ios_base::binary);
        readContent(fp);
        fp.close();
    }
}

void PGM::readContent(istream &fp)
{
    string line;
    // skip header
    for (int i = 1; i <= 3; i++)
        getline(fp, line);

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
    std::vector<char> bytes(
        (std::istreambuf_iterator<char>(fp)),
        (std::istreambuf_iterator<char>()));

    int p;
    int i = 0, j = 0;
    for (auto k = bytes.begin(); k != bytes.end(); k++)
    {
        unsigned long long_p = bitset<8>(*k).to_ulong();
        p = long_p & INT_MAX;
        this->content[i][j] = p;
        j++;
        if (j >= this->width)
        {
            i++;
            j = 0;
        }
    }
}

int PGM::GetPixel(int x, int y)
{
    return this->content[x][y];
}

void PGM::Write(const char *path)
{
    ofstream fp(path);
    if (!fp)
    {
        cerr << "Error file cannot be saved at (" << path << ") \n";
        exit;
    }
    fp << "P" << this->magicNumber << endl;
    fp << this->width << " " << this->height << endl;
    fp << this->maxVal << endl;

    if (magicNumber == 2)
    {
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
    }
    else if (magicNumber == 5)
    {
        for (int i = 0; i < this->height; i++)
        {
            for (int j = 0; j < this->width; j++)
            {
                int pixel = this->content[i][j];

                char c = static_cast<char>(pixel);
                fp << c;
            };
        };
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

int PGM::GetStride()
{
    int size = 0;
    int n = this->maxVal;
    while (n != 0)
    {
        n >> 8;
        size++;
    }
    return (n * this->width);
}