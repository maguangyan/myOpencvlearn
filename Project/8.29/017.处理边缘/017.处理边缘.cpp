#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
Mat src, dst;
int main(int argc, char** argv) {
	src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/2.jpg", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片
	namedWindow("output", CV_WINDOW_AUTOSIZE);


	//int top = (int)(0.1 * src.rows);
	//int bottom = (int)(0.1 * src.rows);
	//int left = (int)(0.1 * src.cols);
	//int right = (int)(0.1 * src.cols);
	//RNG rng(12345);
	//int borderType = BORDER_DEFAULT;//定义边界类型

	//int c = 0;
	//while (true)
	//{
	//	c = waitKey(500);//在500ms内读取并返回按下的按键值，如果没有按下则返回-1
	//	//ESC 的keycode为27
	//	if ((char)c == 27)
	//	{
	//		break;
	//	}
	//	if ((char)c == 'r')
	//	{
	//		borderType = BORDER_REPLICATE;//复制边界像素
	//	}
	//	else if ((char)c == 'w')
	//	{
	//		borderType = BORDER_WRAP;//用另一边像素填充
	//	}
	//	else if ((char)c == 'c')
	//	{
	//		borderType = BORDER_CONSTANT;//i 用指定像素i填充边界
	//	}
	//	Scalar  color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
	//	copyMakeBorder(src, dst, top, bottom, left, right, borderType, color);


	//	imshow("output", dst);
	//}

	GaussianBlur(src, dst, Size(5, 5), 0, 0);
	imshow("output", dst);

	waitKey(0);
	return 0;
}