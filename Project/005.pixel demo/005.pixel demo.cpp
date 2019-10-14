#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
int main(int argc, char** argv) {
	Mat src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/11.jpg", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片
	

	Mat gray_src;
	cvtColor(src, gray_src, CV_BGR2GRAY);//由三通道的bgr转为单通道的gray


	int rows = gray_src.rows;
	int cols = gray_src.cols;
	//单通道
	for (int row = 0;  row< rows;row ++)
	{
		for (int col = 0; col < cols; col++)
		{
			int gray = gray_src.at<uchar>(row, col);//读取第row行第col列的像素值、

			gray_src.at<uchar>(row, col) = 255 - gray;//修改该点的像素值，达到反色效果
		}
	}
	//三通道
	int nc = src.channels();
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (nc==1)
			{
				int gray = gray_src.at<uchar>(row, col);//读取第row行第col列的像素值、

				gray_src.at<uchar>(row, col) = 255 - gray;//修改该点的像素值，达到反色效果
			}
			else if (nc==3)
			{
				int b = src.at<Vec3b>(row, col)(0);
				int g = src.at<Vec3b>(row, col)(1);
				int r = src.at<Vec3b>(row, col)(2);
				src.at<Vec3b>(row, col)(0) = 255 - b;
				src.at<Vec3b>(row, col)(1) = 255 - g;
				src.at<Vec3b>(row, col)(2) = 255 - r;
			}
		}
	}
	
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", gray_src);
	bitwise_not(src, gray_src);
	namedWindow("output2", CV_WINDOW_AUTOSIZE);
	imshow("output2",gray_src);
	
	waitKey(0);
	return 0;
}