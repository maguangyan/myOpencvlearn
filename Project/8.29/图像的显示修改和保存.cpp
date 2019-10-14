#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
int main(int argc,char**argv) {
	Mat src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/11.jpg",IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("open setup demo", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("opencv setup demo", src);//在指定窗口显示指定图片
	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	Mat output_image;
	cvtColor(src, output_image, CV_BGR2GRAY);//修改图片 将原图片转化为灰度
	imshow("output window", output_image);//将修改后的图片输出
	imwrite("C:/Users/Admin/Desktop/opencv/Project/8.29/22.jpg", output_image);//保存图片
	waitKey(0);
	return 0;
}