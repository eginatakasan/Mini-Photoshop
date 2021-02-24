#ifndef PPM_H
#define PPM_H

#include "./image.h"
#include "./color.h"
#include <string>
using std::istream;
using std::string;

class PPM : public Image
{
private:
    /* Variables */
    Color **content;

    /* Functions */
    void readP6Content(istream &fp);
    void readP3Content(istream &fp);
    void readContent(istream &fp);

public:
    /* Constructor */
    PPM(char *const path);
    Color GetPixel(int x, int y);
    void ShowDetails(bool show_content);
};

#endif
