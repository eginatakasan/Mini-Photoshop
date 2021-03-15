#ifndef IMAGE_H
#define IMAGE_H

#include "./color.h"
#include <string>
using std::istream;
using std::string;

/*
Image class for PPM, PGM, PBM only.
PPM -> Magic Number 3 or 6, has R G B on one pixel (3 values per pixel)
PGM -> Magic Number 2 or 5, greyscale values only (1 value per pixel)
PBM -> Magic number 1 or 4, black and white only, 1 bit value every pixel (1 value per pixel)
*/
class Raw
{
protected:
    /* Constructor */
    Raw(int width, int height, int maxVal);
    Raw(const char* path);

    /* Variables */
    int** content;
    int maxVal; //maximum color value for a pixel
    char* path;
    int stride;

    int width;       //lebar gambar
    int height;      //tinggi gambar
    int totalPixels; //jumlah total pixels
    long fileSize;   //ukuran file gambar

    /* Functions */
    bool isMagicNumberValid(int magicNumber);
    void readHeader(istream& fp);
    void readContent(istream& fp);

public:
    /* Functions */
    void ShowDetails(bool show_content);

    /* Getter Functions */
    char* GetPath();
    int GetWidth();
    int GetHeight();
    int GetBitPerPixel();
    long GetFileSize();
    int GetMaxVal();

    /* Setter Functions */
    void SetPixel(int x, int y, int pixel);
};

#endif
