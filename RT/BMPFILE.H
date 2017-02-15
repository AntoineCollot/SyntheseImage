#ifndef __BMPFILE_H
#define __BMPFILE_H

#include <string>

class BMPFile
{
    public:

        static void SaveBmp(std::string fileName,unsigned char *img,unsigned int w,unsigned int h);
};

#endif
