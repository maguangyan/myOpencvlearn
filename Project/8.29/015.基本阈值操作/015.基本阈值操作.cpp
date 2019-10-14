#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;

Mat src, gray_src, dst;
int threshold_value = 177;//初始值
int threshold_max = 255;//最大值
int type_value = 2;
int type_max = 4;
const char* output_title = "binary image";
void Threshold_Demo(int ,void*);

int main(int argc, char** argv) {
	src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/3.jpg", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片
	namedWindow(output_title, WINDOW_AUTOSIZE);

	createTrackbar("Threshold value:", output_title, &threshold_value, threshold_max, Threshold_Demo);
	createTrackbar("type value:", output_title, &type_value, type_max, Threshold_Demo);
	Threshold_Demo(0, 0);





	waitKey(0);
	return 0;
}
void Threshold_Demo(int pos, void* usrdata) {
	cvtColor(src, gray_src, COLOR_BGR2GRAY);
	threshold(gray_src, dst, pos,threshold_max, type_value);
	imshow(output_title, dst);
}