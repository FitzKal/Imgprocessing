#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
	/*Mat_<uchar> img = imread("graycat.jpg", IMREAD_GRAYSCALE);
	imshow("eredeti", img);

	Mat_<uchar> dest = Mat::zeros(img.size(), CV_8UC1);
	for (int i = 0; i < img.rows-1; ++i)
	{
		for (int j = 0; j < img.cols-1; ++j)
		{
			
			//G1 x,y = / (x, y) - / (x + 1, y + 1);
			//G2 x, y = / (x + 1, y) - / (x, y + 1);
			dest(i, j) = abs(img(i, j) - img(i + 1, j + 1)) + abs(img(i, j + 1) - img(i + 1, j));
		}
	}
	imshow("grad", dest);*/

	//sober idk
	/*Mat_<uchar> img = imread("graycat.jpg", IMREAD_GRAYSCALE);
	imshow("eredeti", img);

	Mat grad1, grad2;
	Sobel(img, grad1, CV_32F, 1, 0);
	Sobel(img, grad2, CV_32F, 0, 1);

	Mat grad = cv::abs(grad1) + cv::abs(grad2);

	Mat grad3;
	cv::sqrt(grad1.mul(grad1) + grad2.mul(grad2),grad3);

	Mat dest;
	convertScaleAbs(grad3, dest);

	imshow("grad1", grad1 * 255);
	imshow("grad2", grad2*255);
	imshow("grad3", grad3*255);
	imshow("gradpontos", dest);

	Mat dest2;
	threshold(dest, dest2, 50, 255, THRESH_BINARY);
	imshow("el", dest2);*/

	Mat_<uchar> img = imread("go2.png", IMREAD_GRAYSCALE);
	imshow("eredeti", img);
	
	//Mat dest;
	//Canny(img, dest, 50, 120);
	vector<Vec3f>circles; //cx, cy, r
	HoughCircles(img, circles, HOUGH_GRADIENT, 2, 10, 80, 50, 22, 28);
	
	Mat dest;
	cvtColor(img, dest, COLOR_GRAY2BGR);
	for (Vec3f c : circles) {
		if(img.at<uchar>(c[1], c[0]) > 128)
		circle(dest, Point(c[0], c[1]), c[2], Scalar(255, 0, 0), 2);
		else
		circle(dest, Point(c[0], c[1]), c[2], Scalar(0, 0, 255), 2);
	}
	cout << circles.size();
	imshow("korok", dest);
	waitKey();

}