#ifndef PBM_H
#define PBM_H

#include "./PortableAnymaps.h"
#include <string>
using std::istream;
using std::string;

class PBM : public PortableAnymaps
{
private:
    /* Variables */
    int **content;

    /* Functions */
    void readContent(istream &fp);
    void readP1Content(istream &fp);
    void readP4Content(istream &fp);

public:
    /* Constructor */
    PBM(const char *path);
    void ShowDetails(bool show_content);
    int GetPixel(int x, int y);
    int GetStride();
};

#endif
