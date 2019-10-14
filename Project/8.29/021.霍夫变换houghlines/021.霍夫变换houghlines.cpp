#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
Mat src, dst,gray_src;
int main(int argc, char** argv) {
	src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/9.png", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片

	//边缘检测
	Canny(src, gray_src, 150, 200, 3, false);
	cvtColor(gray_src, dst, CV_GRAY2BGR);
	imshow("edge image", gray_src);

	//vector<Vec2f> lines;
	//HoughLines(gray_src, lines, 1, CV_PI / 180, 150);
	//for (size_t i = 0; i < lines.size(); i++)
	//{
	//	float rho = lines[i][0];//极坐标中r的长度
	//	float theta = lines[i][1];//极坐标中的角度
	//	Point pt1, pt2;
	//	double a = cos(theta), b = sin(theta);
	//	double x0 = a * rho, y0 = b * rho;
	//	//转换为平面坐标系的四个点
	//	pt1.x = cvRound(x0 + 1000 * (-b));
	//	pt1.y = cvRound(y0 + 1000 * (a));
	//	pt2.x = cvRound(x0 - 1000 * (-b));
	//	pt2.y = cvRound(y0 - 1000 * (a));
	//	line(dst, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	//}
	
	vector<Vec4f> plines;//四维向量
	HoughLinesP(gray_src, plines, 1, CV_PI / 180.0, 10, 0, 10);
	Scalar color = Scalar(0, 0, 255);
	for (size_t i = 0; i < plines.size(); i++)
	{
		Vec4f hline = plines[i];
		line(dst, Point(hline[0], hline[1]), Point(hline[2], hline[3]), color, 1, LINE_AA);
	}




	imshow("dst", dst);
	waitKey(0);
	return 0;
}