#include "ppm.h"

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

PPM::PPM(const char *path) : PortableAnymaps(path)
{
    if (this->magicNumber == 3)
    {
        ifstream fp(path);
        readContent(fp);
        fp.close();
    }
    else if (this->magicNumber == 6)
    {
        ifstream fp(path, std::ios_base::binary);
        readContent(fp);
        fp.close();
    }
}

void PPM::readContent(istream &fp)
{
    string line;
    // skip header
    for (int i = 1; i <= 3; i++)
        getline(fp, line);

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

    std::vector<char> bytes(
        (std::istreambuf_iterator<char>(fp)),
        (std::istreambuf_iterator<char>()));

    int r, g, b;
    int i = 0, j = 0;
    for (auto k = bytes.begin(); k != bytes.end(); k++)
    {
        unsigned long long_r = bitset<8>(*k).to_ulong();
        k++;
        unsigned long long_g = bitset<8>(*k).to_ulong();
        k++;
        unsigned long long_b = bitset<8>(*k).to_ulong();
        r = long_r & INT_MAX;
        g = long_g & INT_MAX;
        b = long_b & INT_MAX;
        this->content[i][j] = _Color(r, g, b);
        j++;
        if (j >= this->width)
        {
            i++;
            j = 0;
        }
    }
}

void PPM::Write(const char *path)
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

    if (magicNumber == 3)
    {
        for (int i = 0; i < this->height; i++)
        {
            for (int j = 0; j < this->width; j++)
            {
                _Color color = this->content[i][j];
                fp << color.R << " ";
                fp << color.G << " ";
                fp << color.B;
                if (j == this->width - 1)
                {
                    fp << " ";
                }
                else
                {
                    fp << endl;
                }
            };
        };
    }
    else if (magicNumber == 6)
    {
        for (int i = 0; i < this->height; i++)
        {
            for (int j = 0; j < this->width; j++)
            {
                _Color color = this->content[i][j];
                int int_r = color.R;
                int int_g = color.G;
                int int_b = color.B;

                char r = static_cast<char>(int_r);
                fp << r;
                char g = static_cast<char>(int_g);
                fp << g;
                char b = static_cast<char>(int_b);
                fp << b;
            };
        };
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
    return (size * 3 * this->width);
}