#ifndef PBM_H
#define PGM_H

#include "./image.h"
#include <string>
using std::istream;
using std::string;

class PGM : public Image
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
    PGM(char *const path);
    void ShowDetails(bool show_content);
};

#endif
