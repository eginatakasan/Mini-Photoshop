#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
    private:
        /* Variables */
        char* path;
        int width; 
        int height;
        int bitperpixel;
        long filesize;

    public:
        /* Constructor */
        Image(char* const path);

        /* Functions */
        void write(char* const path);

        /* Getter Functions */
        char* getPath();
        int getWidth();
        int getHeight();
        int getBitPerPixel();
        long getFileSize();
};

#endif
