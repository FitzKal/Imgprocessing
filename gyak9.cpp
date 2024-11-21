#include <iostream>
#include <string>
#include <algorithm>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {

    /*Mat img = imread("sajt.png", IMREAD_COLOR); // fa modell
    Mat gray, mask;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    threshold(gray, mask, 250, 255, THRESH_BINARY_INV);
    medianBlur(mask, mask, 3);
    imshow("mask",mask);

    vector<vector<Point>> conts;
    vector<Vec4i> hier;

    double hole = 0.0;
    double cheese = 0.0;
    findContours(mask, conts, hier,RETR_TREE, CHAIN_APPROX_NONE);
    cout << conts.size() << endl;
    for (int i = 0; i < conts.size(); ++i)
    {
        if (hier[i][3] == -1) {
            drawContours(img, conts, i, Scalar(255, 0, 0), 2);
            cheese += contourArea(conts[i]);
        }
        else {
            drawContours(img, conts, i, Scalar(0, 255, 0), 2);
            hole += contourArea(conts[i]);
        }
    }
    cout << hole / cheese * 100 << endl;
    imshow("img", img);
    waitKey();*/

    //sas
    /*VideoCapture cap;
    cap.open("sas.avi");

    if (!cap.isOpened()) {
        cout << "error" << endl;
        return -1;
    }

    Mat img, gray, mask, dest;
    while (1) {
        cap >> img;
        if (img.empty())
            break;

        cvtColor(img, gray, COLOR_BGR2GRAY);
        inRange(gray, 100, 155, mask);

        dest = img.clone();
        medianBlur(mask, mask, 5);
        erode(mask, mask, getStructuringElement(MORPH_ELLIPSE, Size(15, 15)));
        dest.setTo(0, mask);
        //invertalas: sas maszkja
        mask = 255 - mask;
        vector<vector<Point>> conts;

        findContours(mask, conts, RETR_EXTERNAL, CHAIN_APPROX_NONE);
        cout << conts.size() << endl;

        Rect r = boundingRect(conts[0]);


        imshow("src", img(r));
        imshow("dest", dest);
        waitKey(200);
    }*/
        
    //konvexburok 1
    /*Mat img = imread("objektumok.png", IMREAD_COLOR);
    Mat gray, mask;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    threshold(gray, mask, 250, 255, THRESH_BINARY);
    medianBlur(mask, mask, 3);
    imshow("mask", mask);

    vector<vector<Point>> conts;

    findContours(mask, conts, RETR_EXTERNAL, CHAIN_APPROX_NONE);
    drawContours(img, conts, -1, Scalar(0, 255, 0), 2);
    cout << conts.size() << endl;
    for (int i = 0; i < conts.size(); ++i)
    { 
        vector<Point> hull;
        convexHull(conts[i], hull, false, true);
        polylines(img, hull, true, (0, 255, 0));
        drawContours(img, conts, i, Scalar(255, 0, 0), 1);

        
    }
    imshow("img", img);
    waitKey();*/

     



        return 0;
    
}