// additional includes $(OPENCV_DIR)\..\..\include
// linker / libs section $(OPENCV_DIR)\lib
// additional inputs in the linker section  $(OPENCV_DIR)\lib\opencv_world412d.lib $(OPENCV_DIR)\bin\opencv_world412d.dll
// xcopy /y /d "$(OPENCV_DIR)\bin\*.dll" "$(OutDir)"

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0); // use the webcam

	if(!cap.isOpened())
	{
		cout << "failed to open web cam";
		return -1;
	}

	const auto frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	const auto frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
	const auto codec = cv::VideoWriter::fourcc('X', '2', '6', '4');
	const auto videoSize = Size(frame_width, frame_height);
	VideoWriter capWriter("home.mp4",codec, 25, videoSize, true);

	while(true)
	{
		Mat frame;
		cap >> frame;
		if(frame.empty())
		{
			break;
		}
		capWriter.write(frame);
		imshow("Frame", frame);

		auto keyPress = waitKey(5);
		if(keyPress == 27)
		{
			break;;
		}
	}

	cap.release();
	capWriter.release();
	destroyAllWindows();
	
}

