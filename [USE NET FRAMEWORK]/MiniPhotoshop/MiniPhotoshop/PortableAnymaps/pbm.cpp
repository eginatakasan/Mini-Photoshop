#include "pbm.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <bitset>
#include <vector>
#include <iterator>

using namespace std;

PBM::PBM(const char *path) : PortableAnymaps(path)
{
    if (this->magicNumber == 1)
    {
        ifstream fp(path);
        readContent(fp);
        fp.close();
    }
    else if (this->magicNumber == 4)
    {
        ifstream fp(path, std::ios_base::binary);
        readContent(fp);
        fp.close();
    }
}

void PBM::readContent(istream &fp)
{
    string line;
    // skip header
    for (int i = 1; i <= 2; i++)
        getline(fp, line);

    this->content = new int *[this->height];
    for (int i = 0; i < this->height; i++)
    {
        content[i] = new int[this->width];
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
    int x = 0, y = 0;

    std::vector<char> bytes(
        (std::istreambuf_iterator<char>(fp)),
        (std::istreambuf_iterator<char>()));

    for (auto i = bytes.begin(); i != bytes.end(); ++i)
    {
        string binary = bitset<8>(*i).to_string();
        for (int k = 0; k < 8; k++)
        {
            if (y > this->width)
            {
                y = 0;
                k = 0;
                x++;
            }
            this->content[x][y] = binary.at(k) - '0';
            y++;
        }
    }
}

int PBM::GetPixel(int x, int y)
{
    return this->content[x][y];
}

int PBM::GetStride()
{
    return this->width;
}

void PBM::Write(const char *path)
{
    ofstream fp(path);
    if (!fp)
    {
        cerr << "Error file cannot be saved at (" << path << ") \n";
        exit;
    }
    fp << "P" << this->magicNumber << endl;
    fp << this->width << " " << this->height << endl;

    if (magicNumber == 1)
    {
        for (int i = 0; i < this->height; i++)
        {
            for (int j = 0; j < this->width; j++)
            {
                fp << this->content[i][j];
                if (j != this->width - 1)
                {
                    fp << " ";
                }
            };
            if (i != this->height)
            {
                fp << endl;
            }
        };
    }
    else if (magicNumber == 4)
    {
        // cout
        int i = 0, j = 0, k = 0;
        while (k < this->totalPixels)
        {
            stringstream ss;
            for (int l = 0; l < 8; l++)
            {
                ss << this->content[i][j];
                j++;
                if (j >= this->width)
                {
                    j = 0;
                    i++;
                }
            }

            string s;
            ss >> s;
            char c1 = static_cast<char>(std::bitset<8>(s).to_ulong());

            cout << i << "," << j << " :" << s << endl;
            cout << c1 << endl;
            fp << c1;

            k += 8;
        }
    }
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