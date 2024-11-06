#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include "histo.h"

using namespace cv;
using namespace std;
void createHisto(const Mat img, Mat& hiszto) {
	//a hiszto az eredmeny, float típusú elemeket tartalmaz majd
	vector<Mat> kepek;
	kepek.push_back(img); // egy képet használunk
	vector<int> csatornak;
	csatornak.push_back(0); //a képnek a 0. csatornáját használjuk
	vector<int> hiszto_meretek;
	hiszto_meretek.push_back(256); //szürkeárnyalatok száma
	vector<float> hiszto_tartomanyok;
	hiszto_tartomanyok.push_back(0.0f); //hol kezdődik a tartomány
	hiszto_tartomanyok.push_back(255.f); //meddig tart
	//accumlate: marad false (nullázza a hisztogrammot)
	calcHist(kepek, csatornak, noArray(), hiszto, hiszto_meretek,
		hiszto_tartomanyok, false);
}

int calcThreshold(const Mat img, float ratio = 0.1f) {
	Mat hist;
	Histo::calcHistoC1(img, hist);

	int numPixels = img.rows * img.cols * ratio;
	float s = 0;
	for (int th = 0; th <= 2500; ++th)
	{
		s += hist.at<int>(th);
		if (s >=numPixels)
		{
			return th;
		}
	}
	return -1;
}
int main() {

	//meg egy kis kuszoboles
	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\dog.jpg", IMREAD_GRAYSCALE);
	img = 255 - img;
	Mat dest;

	cout << threshold(img, dest, 0, 255, THRESH_OTSU | THRESH_BINARY_INV);

	imshow("mask", dest);
	*/

	/*
	Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\scanned3.png", IMREAD_GRAYSCALE);
	Mat dest;
	int th = calcThreshold(img, 0.1f);
	if (th != -1) {
		threshold(img, dest, th, 255, THRESH_BINARY_INV);
	}
	else
	{
		cout << "[0,1] tart-ban ad ratio-t" << endl;
	}
	imshow("mask", dest);
	*/

	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\zh.jpg", IMREAD_GRAYSCALE);
	Mat dest;
	imshow("img", img);
	int v;
	int c = 0;
	int s = 20;
	createTrackbar("c:", "img", &c, 100);
	createTrackbar("s:", "img", &s, 100);

	while (waitKey(1) != 'q') {
		int size(max(2 * s + 1, 3));
		adaptiveThreshold(img, dest, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, size,c);
		imshow("dest", dest);
	}
	*/


	//morfologia

	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\galaxy.jpg", IMREAD_GRAYSCALE);
	Mat se = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat dest;
	morphologyEx(img, dest, MORPH_TOPHAT, se);
	imshow("eredeti", img);
	imshow("eredmeny", dest);
	*/

	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\dog.jpg", IMREAD_GRAYSCALE);
	Mat se = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat mask;
	
	threshold(img, mask, 100, 255, THRESH_BINARY);
	imshow("kuszobolt", mask);
	
	Mat eroded;
	erode(mask, eroded, se);
	imshow("erodalt", eroded);

	Mat dest;
	dilate(eroded, dest, se);
	imshow("helyreallitott", dest);

	Mat dest2;
	morphologyEx(mask, dest2, MORPH_OPEN);*/

	
	//sajt 1
	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\sajt.png", IMREAD_GRAYSCALE);
	Mat se = getStructuringElement(MORPH_ELLIPSE, Size(15, 15));
	Mat mask, eroded, dest, dilated;

	threshold(img, mask, 250, 255, THRESH_BINARY);
	imshow("kuszobolt", mask);

	erode(mask, eroded, se);
	Mat edges = mask - eroded;
	imshow("korvonal", edges);

	dilate(mask, dilated, se);
	Mat edges2 = dilated - mask;
	imshow("korvonal2", edges2);

	imshow("kul", edges == edges2);*/

	//sajt2
	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\sajt.png", IMREAD_GRAYSCALE);
	Mat se = getStructuringElement(MORPH_ELLIPSE, Size(15, 15));
	Mat mask, eroded, dest, dilated;

	threshold(img, mask, 250, 255, THRESH_BINARY);
	medianBlur(mask, mask, 3);
	imshow("kuszobolt", mask);

	int size = 70;

	dilate(mask, dilated, se);
	imshow("dilated", dilated);

	erode(dilated, dest, se);
	imshow("eredmeny", dest);

	Mat dest2;
	morphologyEx(mask, dest2, MORPH_CLOSE, se ,cv::Point(-1, -1), 1, BORDER_CONSTANT, 0);

	imshow(" ", dest2);*/

/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\szitakoto.jpg", IMREAD_GRAYSCALE);
Mat se = getStructuringElement(MORPH_ELLIPSE, Size(5, 9));
Mat mask, eroded, dest, dilated;

threshold(img, mask, 120, 255, THRESH_BINARY_INV);
imshow("kuszobolt", mask);

Mat dest2;
morphologyEx(mask, dest2, MORPH_OPEN, se);
imshow("eredmeny2", dest2);

Rect r(img.cols / 3, 0,img.cols - img.cols / 3, img.rows);

Mat folt = dest2(r);
imshow("folt", folt);

cout << countNonZero(folt) << endl;*/


/*Mat img = imread("annotalt_sejt.png", IMREAD_COLOR);
vector<Mat> chs;
split(img, chs);
imshow("chs[2]", chs[2]);
Mat mask;
threshold(chs[2], mask, 254, 255, THRESH_BINARY);//kuszoboles

Mat se = getStructuringElement(MORPH_CROSS,Size(3,3));//kereszt alaku max
Mat dest;
morphologyEx(mask, dest, MORPH_HITMISS, se);

vector<Point> pts;
for (int i = 0; i < img.rows; ++i)
{
	for (int j = 0; j < img.cols; ++j) {
		if (dest.at<uchar>(i, j)) {
			pts.push_back(Point(j, i));
		}
	}
}
Mat img2 = img.clone();
for (auto p : pts) {
	drawMarker(img2, p, Scalar(0, 255, 0), MARKER_DIAMOND, 10, 2);
}
imshow("jelolok ", img2);
imshow("", dest);*/

/*Mat img = imread("graycat.jpg", IMREAD_COLOR);
imshow("eredeti kep", img);

Mat se = getStructuringElement(MORPH_ELLIPSE, Size(15, 15));
Mat img2;
erode(img, img2, se);
imshow("erozio", img2);

dilate(img, img2, se);
imshow("dilat", img2);*/
	waitKey();
}