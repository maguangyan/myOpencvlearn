#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
void Canny_Demo(int, void*);
Mat src, dst, gray_src;
int ti_value = 50;
int max_value = 255;
int main(int argc, char** argv) {
	src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/2.jpg", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片
	namedWindow("edge_image", CV_WINDOW_AUTOSIZE);

	//转换成灰度
	cvtColor(src, gray_src,	CV_BGR2GRAY);
	//创建trackbar
	createTrackbar("threhold:", "edge_image", &ti_value, max_value, Canny_Demo,&gray_src);

	waitKey(0);
	return 0;
}

void Canny_Demo(int pos,void*userdata){
	Mat img = *(Mat*)(userdata);
	Mat edge_img; 
	blur(img, img, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
	Canny(img, edge_img, pos, pos*2.0, 3, false);
	imshow("edge_image", ~edge_img);
}