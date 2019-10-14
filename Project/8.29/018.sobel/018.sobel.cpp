#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
Mat src, dst;
int main(int argc, char** argv) {
	src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/11.jpg", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片

	Mat gray_src;
	cvtColor(src, gray_src, COLOR_BGR2GRAY);
	namedWindow("gray", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("gray", gray_src);//在指定窗口显示指定图片
	
	//改进 schar
	Mat xgrad, ygrad;
	Scharr(gray_src, xgrad, CV_16S, 1, 0);
	Scharr(gray_src, ygrad, CV_16S, 0, 1);
	//Mat xgrad, ygrad;//利用solbe 计算x,y两个方向的梯度
	//Sobel(gray_src, xgrad, CV_16S, 1, 0, 3);
	//Sobel(gray_src, ygrad, CV_16S, 0, 1, 3);
	convertScaleAbs(xgrad, xgrad);//图像增强
	convertScaleAbs(ygrad, ygrad);
	imshow("xgrad", xgrad);
	imshow("ygrad", ygrad);

	Mat xygrad = Mat(xgrad.size(), xgrad.type());
	printf("type is:%d\n", xgrad.type());
	int width = xgrad.cols;
	int height = ygrad.rows;
	for (int row = 0; row < height; row++)
	{
		for (int  col = 0; col < width; col++)
		{
			int xg = xgrad.at<uchar>(row, col);//获取水平和垂直梯度的像素值   （单通道）
			int yg = ygrad.at<uchar>(row, col);
			int xy = xg + yg;//并相加
			xygrad.at<uchar>(row, col) = saturate_cast<uchar>(xy);//溢出检查
		}
	}
	imshow("xygrad", xygrad);



	waitKey(0);
	return 0;
}