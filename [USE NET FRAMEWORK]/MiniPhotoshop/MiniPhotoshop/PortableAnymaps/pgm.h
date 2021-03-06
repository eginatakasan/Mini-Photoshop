#ifndef PGM_H
#define PGM_H

#include "./PortableAnymaps.h"
#include <string>
using std::istream;
using std::string;

class PGM : public PortableAnymaps
{
private:
    /* Variables */
    int **content;

    /* Functions */
    void readContent(istream &fp);
    void readP2Content(istream &fp);
    void readP5Content(istream &fp);

public:
    /* Constructor */
    PGM(const char *path);
    void ShowDetails(bool show_content);
    void Write(const char *path);
    int GetPixel(int x, int y);
    int GetStride();
};

#endif
