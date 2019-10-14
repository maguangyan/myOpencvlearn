#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
int main(int argc, char** argv) {
	Mat src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/2.jpg", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片

	//上采样
	Mat dst;
	pyrUp(src, dst, Size(src.cols * 2, src.rows * 2));
	imshow("output_up", dst);//在指定窗口显示指定图片

	//下采样
	Mat dst_down;
	pyrDown(src, dst_down, Size(src.cols / 2, src.rows / 2));
	imshow("output_down", dst_down);//在指定窗口显示指定图片
	//DOG
	Mat gray_src, g1, g2, dogImg;
	cvtColor(src, gray_src, COLOR_BGR2GRAY);
	GaussianBlur(gray_src, g1, Size(5, 5), 0, 0);//高斯模糊1
	GaussianBlur(g1, g2, Size(5, 5), 0, 0);//高斯模糊2
	subtract(g1, g2, dogImg, Mat());//两次相减
	imshow("output_dog", dogImg);//在指定窗口显示指定图片
	//归一化显示
	normalize(dogImg, dogImg, 255, 0,NORM_MINMAX);
	imshow("output_normol", dogImg);//在指定窗口显示指定图片



	waitKey(0);
	return 0;
}