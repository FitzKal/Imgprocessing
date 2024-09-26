#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {

	//szurkeskala CV_8UC1
	//szines CV_8UC3

	Mat img1 = imread("C:/Users/user/Desktop/fitz.png");
	imshow("kep", img1);
	int f = img1.type();
	cout << endl;
	cout << "FITZ" << " " << f << endl;
	/*if (f == CV_8UC3) {
		cout << "szines" << endl;
	}
	else
	{
		cout << "mas" << endl;
	}*/
	waitKey();

	Mat img2(100, 200, CV_8UC3);
	img2.setTo(Scalar(255, 0, 0));
	imshow("szines", img2);
	int t = img2.type();
	cout << "szines kep" << " " << t << endl;
	waitKey();


	Mat img3(50, 100, CV_8UC1);
	imshow("szurka", img3);
	int p = img3.type();
	cout << "szurke kep" << " " << p << endl;
	waitKey();


	Mat img4 = Mat::zeros(20, 40, CV_8UC1);
	imshow("fekete", img4);
	waitKey();

	Mat img5 = Mat::zeros(20, 40, CV_8UC1);
	img5.setTo(Scalar(255));
	imshow("feher", img5);
	waitKey();

	Mat img6(350, 350, CV_8UC3);
	img6.setTo(Scalar(0, 0, 255));
	imshow("img6", img6);
	waitKey();

	Mat img7(img6.size(), img6.type());
	img7.setTo(Scalar(152, 245, 203));
	imshow("kep7", img7);
	waitKey();
}
