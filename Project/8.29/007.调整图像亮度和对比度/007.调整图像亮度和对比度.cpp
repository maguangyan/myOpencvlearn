#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
int main(int argc, char** argv) {
	Mat src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/1.jpg", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片
	//改变亮度和对比度
	int height = src.rows;
	int width = src.cols;
	Mat dst = Mat::zeros(src.size(), src.type());//创建一个和src一样的图形
	float alpha = 1.5;
	float beta = 10;

	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			if (src.channels()==3)
			{
				float b= src.at<Vec3b>(row, col)[0];
				float g = src.at<Vec3b>(row, col)[1];
				float r = src.at<Vec3b>(row, col)[2];

				dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * alpha + beta);
				dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * alpha + beta);
				dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * alpha + beta);
			}
			else if (src.channels()==1)
			{
				float v = src.at<uchar>(row, col);
				dst.at<uchar>(row, col) = saturate_cast<uchar>(v * alpha + beta);

			}
		}
	}


	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);



	waitKey(0);
	return 0;
}