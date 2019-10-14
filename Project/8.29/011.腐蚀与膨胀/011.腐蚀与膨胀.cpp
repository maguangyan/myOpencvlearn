#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;

Mat src, dst;
char OUTPUT_WIN[] = "output image";
int element_size = 3;
int max_size = 21;//
void CallBack_Demo(int ,void*);
int main(int argc, char**argv) {
	src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/6.png", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片

	namedWindow(OUTPUT_WIN, CV_WINDOW_AUTOSIZE);
	createTrackbar("Element Size:", OUTPUT_WIN, &element_size, max_size,CallBack_Demo);//创建一个可拖动的滑块
	CallBack_Demo(0, 0);

	waitKey(0);
	return 0;
}
void CallBack_Demo(int, void*) {
	int s = element_size * 2 + 1;
	Mat structureElement= getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));
	//dilate(src, dst, structureElement, Point(-1, -1), 1);//膨胀操作
	erode(src, dst, structureElement);//腐蚀操作


	imshow(OUTPUT_WIN, dst);
	return;
}