// additional includes $(OPENCV_DIR)\..\..\include
// linker / libs section $(OPENCV_DIR)\lib
// additional inputs in the linker section  $(OPENCV_DIR)\lib\opencv_world412d.lib $(OPENCV_DIR)\bin\opencv_world412d.dll
// xcopy /y /d "$(OPENCV_DIR)\bin\*.dll" "$(OutDir)"
//
// https://github.com/spmallick/learnopencv

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
	const auto filePath = R"(../playvideoTest/showerleak.mp4)"s;
	VideoCapture cap(filePath);
	
	if(!cap.isOpened())
	{
		return -1;
	}
	
	namedWindow("video",1);
	
	for(;;)
	{
		Mat frame;
		cap >> frame;
		if(frame.empty())
		{
			return 0;
		}
		imshow("video", frame);
		if(waitKey(30) >=0)
		{
			break;
		}
	}
	
	cap.release();
	return 0;
	
}
