#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
int main(int argc, char** argv) {

	Mat src1 = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/1.jpg", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	Mat src2 = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/2.jpg", IMREAD_COLOR);
	Mat dst;
	if (!src1.data)
	{
		printf("could not load image1....\n");
		return -1;//返回值为-1 表示异常
	}
	if (!src2.data)
	{
		printf("could not load image2....\n");
		return -1;//返回值为-1 表示异常
	}
	double alpha = 0.5;
	if (src1.rows==src2.rows&&src1.cols==src2.cols&&src1.type()==src2.type())
	{
		addWeighted(src1, alpha, src2, (1.0 - alpha), 0.0, dst);
	}
	else
	{
		printf("could not blend image ,the size of image is not same");
		return -1;
	}
	namedWindow("output", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("output", dst);//在指定窗口显示指定图片
	namedWindow("src1", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("src1", src1);//在指定窗口显示指定图片
	namedWindow("src2", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("src2", src2);//在指定窗口显示指定图片





	waitKey(0);
	return 0;
}