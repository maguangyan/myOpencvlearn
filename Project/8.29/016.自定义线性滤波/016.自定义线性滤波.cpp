#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
Mat src, dst;
int main(int argc, char** argv) {
	src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/3.jpg", -1);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片

	//sobel x 方向
	Mat kernel_x = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	filter2D(src, dst, -1, kernel_x, Point(-1, -1), 0.0);

	//Sobel Y 方向
	 Mat yimg;
	 Mat kernel_y = (Mat_<int>(3, 3) << -1, -2, -1, 0,0,0, 1,2,1);
	 filter2D(src, yimg, -1, kernel_y, Point(-1, -1), 0.0);

	 //拉普拉斯算子
	 Mat lap;
	 Mat kernel_l = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	 filter2D(src, lap, -1, kernel_l, Point(-1, -1), 0.0);

	namedWindow("output_dst", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("output_dst", dst);//在指定窗口显示指定图片

	namedWindow("output_yimg", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("output_yimg", yimg);//在指定窗口显示指定图片

	namedWindow("output_lap", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("output_lap", lap);//在指定窗口显示指定图片
	waitKey(0);




	return 0;
}