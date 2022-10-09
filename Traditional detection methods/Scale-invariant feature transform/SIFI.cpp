#include<opencv2/opencv.hpp>
#include<opencv2/xfeatures2d>
#include<math.h>
#include<iostream>

using namespace cv;
using namespace std;
using namespace cv::xfeatures2d;



Mat src, gray_src;
const char* output_title = "output_win";
int corners = 20;
int max_corners = 50;

void Tomasi_Demo(int, void*);
void SubPixel_Demo(int, void*);
int main(int argc, char** argv) {
	src = imread("C:/Users/18929/Desktop/博客项目/项目图片/18.jpg");
	if (src.empty()) {
		printf("could not load image");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input_img", src);

	int numFeatures = 400;
	Ptr<SIFT> detector = SIFT::create(numFeatures);
	vector<KeyPoint> keypoints;
	detector->detect(src, keypoints, Mat());
	printf("Total KeyPoints:%d\n", keypoints.size());

	Mat keypoint_img;
	drawKeypoints(src, keypoints, keypoint_img, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	namedWindow("SIFT KeyPoints", CV_WINDOW_AUTOSIZE);
	imshow("SIFT KeyPoints", keypoint_img);
	waitKey(0);
	return 0;
}
