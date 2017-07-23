#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdio.h>
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat M(600, 800, CV_8UC1);

	for (int i = 0; i < M.rows; ++i)
	{
		//specify a type when aquiring a ptr
		uchar* p = M.ptr<uchar>(i);
		for (int j = 0; j < M.cols; ++j)
		{
			double d1 = (double)((i + j) % 255);
			//need to specify a type when using at()
			M.at<uchar>(i, j) = d1;
			//should use at<uchar>() in the following line
			//or the running result would be uncorrect
			//without warning, d1!=d2
			double d2 = M.at<double>(i, j);
		}
	}

	/*//specify  the type of the matric elements during vardeclaration
	Mat_<uchar> M1 = (Mat_<uchar>&)M;
	for (int i = 0; i < M1.rows; ++i)
	{
		//no need for specifying a type for the elements
		uchar* p = M1.ptr(i);
		for (int j = 0; j < M1.cols; ++j)
		{
			double d1 = (double)((i + j) % 255);
			//reading matric element with matlab style
			M1(i, j) = d1;
			double d2 = M1(i, j);
		}
	}*/
	return 0;
}