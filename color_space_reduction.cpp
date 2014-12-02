/*
 * OpenCV program that takes a grayscale image and applies 
 * colorspace reduction.
 *
 */

#include "opencv2/highgui/highgui.hpp"
#include <iostream>

#define uchar unsigned char

using namespace std;
using namespace cv;

uchar table[256];
void GenerateLookupTable();
void PrintLookupTable(int);
void ReduceColorSpace(Mat&);
void ReduceColorSpace2(Mat&);


int main()
{
    double tick_1 = getTickCount();
    
    // Load a grayscale image
    Mat img = imread("/home/samyak/Pictures/OpenCV/Colaba.jpg", 
            CV_LOAD_IMAGE_GRAYSCALE);
    
    if(img.empty()) {
        cout << "Image could not be loaded!\n";
        return -1;
    }

    // Display image before color space reduction
    namedWindow("before", CV_WINDOW_NORMAL);
    imshow("before", img); 
    
    
    GenerateLookupTable();
    ReduceColorSpace(img);
    
    // Display image after color space reduction
    namedWindow("after", CV_WINDOW_NORMAL);
    imshow("after", img); 

    
    // Calculate time taken
    double tick_2 = getTickCount();
    double time_elapsed = (tick_2 - tick_1) / getTickFrequency();
    cout << "Time elapsed (in seconds): " << time_elapsed << "\n";

    waitKey(0);

    return 0;
}

void GenerateLookupTable() {
    for(int i = 0; i < 256; ++i)
        table[i] = (uchar)((i / 100) * 100);
}

void PrintLookupTable(int num) {
    for(int i = 0; i < num; ++i)
        cout << (int)table[i] << " ";
    cout << "\n";
}

void ReduceColorSpace(Mat& I) {
    MatIterator_<uchar> iter, end;
    end = I.end<uchar>();

    for(iter = I.begin<uchar>(); iter != end; ++iter)
        *iter = table[*iter];
}

void ReduceColorSpace2(Mat&);
