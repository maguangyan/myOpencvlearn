#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
int main(int argc, char** argv) {
	Mat src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/.png", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片
	Mat dst;

	Mat kernel = getStructuringElement(MORPH_RECT, Size(20, 20), Point(-1, -1));



	morphologyEx(src, dst,CV_MOP_CLOSE, kernel);



	namedWindow("output", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("output", dst);//在指定窗口显示指定图片





	waitKey(0);
	return 0;
}