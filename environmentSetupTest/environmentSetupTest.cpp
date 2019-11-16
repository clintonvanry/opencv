// environmentSetupTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



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
    std::cout << "Hello World!\n";
	auto filePath =  R"(../environmentSetupTest/clock.jpg)"s;
	auto img = imread(filePath, IMREAD_COLOR);

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
