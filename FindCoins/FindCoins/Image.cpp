////////////////////////////////////////////////////////////////////////////////////
// Header: Image.cpp
// Built: Jeremy J Hartmann
// Date: 01-08-2016
////////////////////////////////////////////////////////////////////////////////////

#include "Image.h"

// Default Constructor
Image::Image()
{

}


Image::Image(const char* in_filename)
{

    // Open the image file
    mInFile = new ifstream(in_filename, ios::in | ios::binary);
    if (!mInFile->good()) return;

    // Get length of file
    mInFile->seekg(0, mInFile->end);
    mByteLen = mInFile->tellg();
    mInFile->seekg(0, mInFile->beg);
    

    // Get the header information
    bool found = false;
    int c;
    while (!mInFile->eof() && !found)
    {
        c = mInFile->get();
        if (c == 0xff)
        {
            c = mInFile->get();
            if (c == 0xda)
            {
                found = true;
            }
        }
    }

    mHeaderLen = mInFile->tellg();
    mDataLen = mByteLen - mHeaderLen;

    mImageHeader = new int[mHeaderLen];
    mImageData = new int[mDataLen];

    mInFile->read(reinterpret_cast<char*>(mImageHeader), mHeaderLen);
    mInFile->read(reinterpret_cast<char*>(mImageData), mDataLen);

    mInFile->close();
}


Image::~Image()
{
    delete[] mImageHeader;
    delete[] mImageData;

    delete mInFile;

    if (mOutFile)
        delete mOutFile;


}

void Image::threshold(float th)
{

}

void Image::grayScale()
{

}

