#ifndef PPM_H
#define PPM_H

#include "./PortableAnymaps.h"
#include "./color.h"
#include <string>
using std::istream;
using std::string;

class PPM : public PortableAnymaps
{
private:
    /* Variables */
    _Color **content;

    /* Functions */
    void readP6Content(istream &fp);
    void readP3Content(istream &fp);
    void readContent(istream &fp);

public:
    /* Constructor */
    PPM(int width, int height, int magicNumber, int maxVal);
    PPM(const char *path);
    void Write(const char *path);
    int *ptr;
    _Color GetPixel(int x, int y);
    void SetPixel(int x, int y, _Color color);
    void ShowDetails(bool show_content);
    int GetStride();
};

#endif
