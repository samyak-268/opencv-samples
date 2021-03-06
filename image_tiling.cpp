/*
 * Author: Samyak Datta (datta[dot]samyak[at]gmail.com)
 *
 * Program to divide an image into tiles or blocks
 *
 */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <cstdio>

using namespace std;
using namespace cv;

void help();

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        help();
        return -1;
    }
    
    string input_image_path = argv[1];
    Mat image = imread(input_image_path, CV_LOAD_IMAGE_GRAYSCALE);
    if(image.empty())
    {
        cout << "Invalid image\n";
        return -1;
    }

    int block_rows = (image.rows / 2);
    int block_cols = (image.cols / 2);

    Mat block_1 = image(Rect(0, 0, block_cols, block_rows));
    Mat block_2 = image(Rect(block_cols, 0, block_cols, block_rows));
    Mat block_3 = image(Rect(0, block_rows, block_cols, block_rows));
    Mat block_4 = image(Rect(block_cols, block_rows, block_cols, block_rows));


    namedWindow("Image", WINDOW_AUTOSIZE);
    namedWindow("Block1", WINDOW_AUTOSIZE);
    namedWindow("Block2", WINDOW_AUTOSIZE);
    namedWindow("Block3", WINDOW_AUTOSIZE);
    namedWindow("Block4", WINDOW_AUTOSIZE);
    
    imshow("Image", image);
    imshow("Block1", block_1);
    imshow("Block2", block_2);
    imshow("Block3", block_3);
    imshow("Block4", block_4);

    imwrite("/home/samyak/Pictures/Samyak-1.jpg", block_1);
    imwrite("/home/samyak/Pictures/Samyak-2.jpg", block_2);
    imwrite("/home/samyak/Pictures/Samyak-3.jpg", block_3);
    imwrite("/home/samyak/Pictures/Samyak-4.jpg", block_4);
    
    waitKey(0);
    return 0;
}

void help()
{
    cout << "\nThis program splits up the given input image into 4 blocks using"
        " the Rect() function to extract ROI\n";

    cout << "\nUSAGE: ./image_tiling [IMAGE]\n"
        "IMAGE\n\tPath to image taken as input.\n";
}
