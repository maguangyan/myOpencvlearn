#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;
Mat src, dst, gray_src;
Mat map_x, map_y;
int index = 0;
void update_map(void);
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

	map_x.create(src.size(), CV_32FC1);
	map_y.create(src.size(), CV_32FC1);
	
	/*Mat map_1;
	map_1.create(3,3,CV_8UC1);
	cout << map_1 << endl;*/

	int c = 0;
	while (true)
	{
		c = waitKey(500);
		if ((char)c==27)
		{
			break;
		}
		index = c % 4;
		update_map();
		remap(src, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 122, 0));
		imshow("output", dst);
	}



	waitKey(0);
	return 0;
}
void update_map(void) {
	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			switch (index)
			{
			case 0:if (col > (src.cols * 0.25) && col <= (src.cols * 0.75) && row > (src.rows * 0.25) && row <= (src.rows * 0.75)) {
				map_x.at<float>(row, col) = 2 * (col - (src.cols * 0.25));
				map_y.at<float>(row, col) = 2 * (row - (src.rows * 0.25));
			}
				   else {
				map_x.at<float>(row, col) = 0;
				map_y.at<float>(row, col) = 0;
			}
				   break;
			case 1:
				map_x.at<float>(row, col) = (src.cols - col - 1);
				map_y.at<float>(row, col) = row;
				break;
			case 2:
				map_x.at<float>(row, col) = col;
				map_y.at<float>(row, col) = (src.rows - row - 1);
				break;
			case 3:
				map_x.at<float>(row, col) = (src.cols - col - 1);
				map_y.at<float>(row, col) = (src.rows - row - 1);
				break;
			default:
				break;
			}
		}
	}
}
