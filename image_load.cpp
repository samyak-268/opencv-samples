/*
 * OpenCV program that reads an image from a file and displays it's
 * contents in a window.
 *
 */

#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    /* CV_LOAD_IMAGE_UNCHANGED: image-depth: 8 bits, channels: unchanged
     * CV_LOAD_IMAGE_GRAYSCALE: image-depth: 8 bits, channels: 1
     */
    Mat img = imread("/home/samyak/Pictures/architecture.png", 
            CV_LOAD_IMAGE_UNCHANGED);
    
    if(img.empty()) {
        cout << "Image can't be displayed!\n";
        return -1;
    }

    namedWindow("image_display", CV_WINDOW_NORMAL);
    // resizeWindow("image_display", 1500, 1500);
    imshow("image_display", img);

    waitKey(0);
    destroyWindow("image_display");
    
    return 0;
}
