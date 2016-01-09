////////////////////////////////////////////////////////////////////////////////////
// Header: Image
// Built: Jeremy J Hartmann
// Date: 01-08-2016
////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include <fstream>

using namespace std;
typedef unsigned char uchar;

class Image
{
public:
    Image();
    Image(const char* in_filename);
    ~Image();

    // Transform a gray scale image into a B&W image with the
    // application of a threshold between 0-255. 
    // Everything that satisfies the threshold is 1, else -1;
    void threshold(float th);

    // Convert the image into a gray scale image.
    void grayScale();



private:
    // Vars
    ifstream *mInFile;
    ofstream *mOutFile;
    bool mIsBW;
    int *mImageData;
    int *mImageHeader;
    int mByteLen;
    int mHeaderLen;
    int mDataLen;

};


