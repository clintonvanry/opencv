// https://docs.opencv.org/4.1.2/d3/d52/tutorial_windows_install.html#tutorial_windows_install_path
// https://docs.opencv.org/4.1.2/dd/d6e/tutorial_windows_visual_studio_opencv.html
// setx -m OPENCV_DIR D:\OpenCV\Build\x64\vc15
// additional includes $(OPENCV_DIR)\..\..\include
// linker / libs section $(OPENCV_DIR)\lib
// additional inputs in the linker section  $(OPENCV_DIR)\lib\opencv_world412d.lib $(OPENCV_DIR)\bin\opencv_world412d.dll
// xcopy /y /d "$(OPENCV_DIR)\bin\*.dll" "$(ProjectDir)$(OutDir)"

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
    const auto filePath =  R"(../environmentSetupTest/clock.jpg)"s;
    const auto img = imread(filePath, IMREAD_COLOR);

	if(img.empty())
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", img);
	
	waitKey(0);
	return 0;
	
}
