#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;
Mat src, dst, gray_src;
int main(int argc, char** argv) {
	src = imread("C:/Users/Admin/Desktop/opencv/Project/8.29/2.jpg", IMREAD_COLOR);//src 缩写为源文件 打开的文件名要加上格式 比如 jpg
	if (src.empty())
	{
		printf("could not load image....\n");
		return -1;//返回值为-1 表示异常
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	namedWindow("output", CV_WINDOW_AUTOSIZE);//创建一个窗口并命名
	imshow("input", src);//在指定窗口显示指定图片

	//分通道显示
	vector < Mat> bgr_planes;
	split(src, bgr_planes);//bgr_planes是一个数组 里面存放三个通道的图像
	//imshow("single channel demo", bgr_planes[0]);

	//计算直方图
	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRanges = { range };
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRanges, true, false);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRanges, true, false);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRanges, true, false);

	//归一化
	int hist_h = 400;
	int hist_w = 512;
	int bin_w = hist_w / histSize;
	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));
	normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX, -1, Mat());

	// 绘制直方图
	for (int i = 1; i < histSize; i++) {
		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point((i)* bin_w, hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, LINE_AA);

		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point((i)* bin_w, hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, LINE_AA);

		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point((i)* bin_w, hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, LINE_AA);
	}
	imshow("histImage" , histImage);
	waitKey(0);
	return 0;
}