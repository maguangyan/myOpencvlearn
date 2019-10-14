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

	Mat gray_src,edge_image;//高斯模糊
	GaussianBlur(src, dst, Size(3, 3), 0, 0);
	cvtColor(dst, gray_src, COLOR_BGR2GRAY);//灰度转换

	Laplacian(gray_src, edge_image, CV_16S, 3);//拉普拉斯提取边缘
	convertScaleAbs(edge_image, edge_image);//取绝对值
	
	//二值化
	threshold(edge_image, edge_image, 0, 255, THRESH_OTSU | THRESH_BINARY);//OTSU  可以自动找到一个
	//最恰当的阈值


	namedWindow("edge", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("edge", edge_image);//在指定窗口显示指定图片
	waitKey(0);
	return 0;
}