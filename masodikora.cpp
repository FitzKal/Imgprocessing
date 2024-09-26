#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;
void invertal(Mat img) {
	img = 255 - img;
}
void invertal2szines(Mat img, Mat& dest) { 
	dest = Scalar(255, 255, 255) - img;
}

void elotermasolo(const cv::Mat fg, cv::Mat& bg) {
	bool nincsKep = bg.empty();
	Vec3b c;
	Vec3b feher(255, 255, 255);
	for (int i = 0; i < fg.rows; ++i) {
		for (int j = 0; j < fg.cols; ++j) {
			c = fg.at<Vec3b>(i, j);
			if (c != feher) {
				bg.at<Vec3b>(i, j) = c;
			}
			else if (nincsKep) {
				bg.at<Vec3b>(i, j) = feher;
			}
		}
	}
}

int main() {

	/*Mat A(200, 50, CV_8UC1);
	imshow("A", A);
	waitKey();

	Mat B = A;
	B.setTo(255);
	imshow("A", A);
	waitKey();

	Mat C = A.clone();
	C.setTo(255);
	imshow("A", A);
	waitKey();*/

	
	/*Mat A(400, 600, CV_8UC3);
	A.setTo(Scalar(0, 0, 255));
	Rect r(0, 0, A.cols, A.rows / 2);
	A(r).setTo(Scalar(0, 255, 255));
	imshow("kiskep", A(r));
	imshow("alap", A);
	waitKey();*/

	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\kurama.jpg");
	int size = 250;
	//Rect r(size, size, img.cols - 2 * size, img.rows - 2 * size); //levag a kepbol 40 - 40 pixelt
	Mat smallImg;
	//imwrite("kiskurama.jpg", img(r));// ha mar letezik a mappaba egy kep ilyen nevvel, akkor felul fogja irni a mar letezo kepet
	resize(img, smallImg, Size(200, 200));
	Mat bg = imread("C:\\Users\\bleac\\Desktop\\uni\\background.jpg");
	Rect r2(100, 100, 100, 100);
	int x = img.cols ;
	Rect r(img.cols/2- smallImg.cols/2, img.rows/2 - smallImg.rows/2, smallImg.rows, smallImg.cols); //a kiskepet a nagykep kozepere masolja
	smallImg.copyTo(bg(r));
	//imshow("kep", img);
	imshow("small img", img(r));
	imshow("nagy kep", bg);*/

	
	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\kurama.jpg", IMREAD_GRAYSCALE);
	imshow("eredeti", img);
	Mat bg = imread("C:\\Users\\bleac\\Desktop\\uni\\background.jpg",IMREAD_GRAYSCALE);

	Mat Dest = img + 500; //vilagositas

	imshow("fakobb eloter", Dest);
	imshow("fakobb", bg);*/

	/*vilagositas es invertalas
	Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\kurama.jpg", IMREAD_GRAYSCALE);
	Mat alap = imread("C:\\Users\\bleac\\Desktop\\uni\\kurama.jpg");
	Mat bg = imread("C:\\Users\\bleac\\Desktop\\uni\\background.jpg", IMREAD_GRAYSCALE);
	if (img.empty()){
		cout << "Hopsz" << endl;
		return -1;
	}
	invertal(img);
	invertal2szines(alap, img);

	imshow("kep", img);
	imshow("alap", alap);*/


	//osszemosas
	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\kurama.jpg");
	if (img.empty()) {
		cout << "Hopsz" << endl;
		return -1;
	}
	Mat bg = imread("C:\\Users\\bleac\\Desktop\\uni\\background.jpg");
	resize(bg, bg, img.size());

	double alfa = 0.5; 
	Mat dest = alfa * img + alfa * bg; //csinalunk egy uj kepet, ami a beolvasott 2 kep osszemosttja lesz, a szinei pedig az alap kepek szineinek a 0.5 szerese
	imwrite("osszemosott.jpg", dest);
	imshow("dest.", dest);*/
	
	Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\kurama.jpg");
	Mat bg = imread("C:\\Users\\bleac\\Desktop\\uni\\background.jpg");
	resize(bg, bg, img.size());
	elotermasolo(img, bg);
	imshow("alap", bg);

	waitKey();



	