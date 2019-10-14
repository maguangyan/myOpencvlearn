#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

Mat src;
const char* drawdemo_win = "draw shapes and text demo";
void MyLines();
void MyRectangle();
void MyEllipse();
void MyPolygon();
void RandomLineDemo();


int main(int argc, char** argv) {
    src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/1.jpg", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片

	MyLines();
	MyRectangle();
	MyEllipse();
	MyPolygon();
	RandomLineDemo();
	namedWindow("output", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("output", src);//在指定窗口显示指定图片





	waitKey(0);
	return 0;
}
void MyLines() {
	Point p1 = Point(20, 30);//起点
	Point p2 = Point(400, 400);//始点
	Scalar color = Scalar(0, 0, 255);//颜色是一个标量 
	line(src, p1, p2, color, 1, LINE_AA);

}
void MyRectangle() {
	Rect rect = Rect(10, 10, 100, 100);//
	Scalar color = Scalar(0, 255, 0);
	rectangle(src, rect, color, 1);
}
void MyEllipse() {
	ellipse(src, Point(src.cols / 2, src.rows / 2), 
		Size(src.cols / 4, src.rows / 8), 90, 0, 360, (0, 0, 255), 2, LINE_8);
}

void MyPolygon() {
	Point pts[1][5];//一行五列
	pts[0][0] = Point(100, 100);
	pts[0][1] = Point(100, 200);
	pts[0][2] = Point(200, 200);
	pts[0][3] = Point(200, 100);
	pts[0][4] = Point(100, 100);//多边形的五个点

	const Point* ppts[] = { pts[0] };
	int npt[] = { 5 };
	Scalar color = Scalar(255, 12, 255);

	fillPoly(src, ppts, npt, 1, color, 8);


}
void RandomLineDemo() {
	RNG rng(12345); //构造方法设定一个具体值，表示下面代码每次生成的结果都是一样的
	Point pt1;
	Point pt2;
	Mat bg = Mat::zeros(src.size(), src.type());
	namedWindow("random line demo", CV_WINDOW_AUTOSIZE);
	for (int i = 0; i < 100000; i++) {
		pt1.x = rng.uniform(0, src.cols);
		pt2.x = rng.uniform(0, src.cols);
		pt1.y = rng.uniform(0, src.rows);
		pt2.y = rng.uniform(0, src.rows);//确保生成的随机数都在图像内
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		
		if (waitKey(50) > 0) {
			break;
		}//延时
		line(bg, pt1, pt2, color, 1, 8);
		imshow("random line demo", bg);
	}
}