#ifndef PBM_H
#define PBM_H

#include "./image.h"
#include <string>
using std::istream;
using std::string;

class PBM : public Image
{
private:
    /* Variables */
    unsigned char **content;

    /* Functions */
    void readContent(istream &fp);
    void readP1Content(istream &fp);
    void readP4Content(istream &fp);

public:
    /* Constructor */
    PBM(char *const path);
    void ShowDetails(bool show_content);
};

#endif
