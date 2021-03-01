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
    PPM(const char *path);
    int *ptr;
    _Color GetPixel(int x, int y);
    void ShowDetails(bool show_content);
    int GetStride();
};

#endif
