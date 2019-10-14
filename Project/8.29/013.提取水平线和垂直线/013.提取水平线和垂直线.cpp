#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
int main(int argc, char** argv) {
	Mat src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/9.png", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片
	//转换为灰度图像
	Mat gray_src;
	cvtColor(src, gray_src, COLOR_BGR2GRAY);

	namedWindow("gray image", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("gray image", gray_src);//在指定窗口显示指定图片
	//转换为二值图像
	Mat binImg;
	adaptiveThreshold(~gray_src, binImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	imshow("binary image", binImg);
	//进行提取
	//水平结构元素
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols / 16, 1), Point(-1, -1));
	//垂直结构元素
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 16), Point(-1, -1));
	//矩形结构
	Mat kernel = getStructuringElement(MORPH_RECT, Size(2, 2), Point(-1, -1));
	//进行open操作 
	Mat dst;
	morphologyEx(binImg, dst,CV_MOP_OPEN,kernel);

	imshow("final result", dst);



	waitKey(0);
	return 0;
}