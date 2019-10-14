#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;
Mat src, dst,gray_src;
int main(int argc, char** argv) {
	src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/10.png", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片

	//中值滤波
	Mat moutput;
	medianBlur(src, moutput, 3);
	cvtColor(moutput, moutput, COLOR_BGR2GRAY);

	//霍夫圆检测
	vector<Vec3f> pcircles;
	HoughCircles(moutput, pcircles, CV_HOUGH_GRADIENT, 1, 10, 100, 30, 50);
	src.copyTo(dst);
	for (size_t i = 0; i < pcircles.size(); i++)
	{
		Vec3f cc = pcircles[i];
		circle(dst, Point(cc[0], cc[1]), cc[2], Scalar(0, 0, 255), 2, LINE_AA);
		circle(dst, Point(cc[0], cc[1]), 2, Scalar(198, 23, 155), 2, LINE_AA);


	}


	imshow("output", dst);

	waitKey(0);
	return 0;
}