////////////////////////////////////////////////////////////////////////////////////
// Header: Tools.h
// Built: Jeremy J Hartmann
// Date: 01-08-2016
////////////////////////////////////////////////////////////////////////////////////

#pragma once



class Tools
{
public:
    Tools();
    ~Tools();

    /////////////////////////////////////////////////
    // Static Helper methods
   
    // Function that takes in an image and convolves on with the other. 
    // Returns out_res which contains the the convolved result (NOT OWN)
    template <typename T>
    static void conv2(T &in_img1, T &in_img2, T &out_res);


    // A morphological function that processes a 2D image using erosion. 
    // Returns out_res, a 2D file that contains the eroded result
    template <typename T>
    static void morphE(T &img);

   

};


