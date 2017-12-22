/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                          License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring>



using namespace std;
using namespace cv;

int main(){

	VideoCapture left(0);
	VideoCapture right(1);
	left.set(CAP_PROP_FRAME_WIDTH,320);
	left.set(CAP_PROP_FRAME_HEIGHT,240);
	right.set(CAP_PROP_FRAME_WIDTH,320);
	right.set(CAP_PROP_FRAME_HEIGHT,240);
	char *leftname[14] = {"left01.jpg","left02.jpg","left03.jpg","left04.jpg","left05.jpg","left06.jpg","left07.jpg","left08.jpg","left09.jpg","left10.jpg","left11.jpg","left12.jpg","left13.jpg","left14.jpg"};
	char *rightname[14] = {"right01.jpg","right02.jpg","right03.jpg","right04.jpg","right05.jpg","right06.jpg","right07.jpg","right08.jpg","right09.jpg","right10.jpg","right11.jpg","right12.jpg","right13.jpg","right14.jpg"};
	if (!left.isOpened() || !right.isOpened()) {
		printf("cant open camera!\n");
	} else {
		int imageserial = 0;
		for(;;){
		Mat leftframe,rightframe;
		left >> leftframe;
		right >> rightframe;
		imshow("left",leftframe);
		imshow("right",rightframe);
		char cmd = waitKey(1);
		if(cmd=='c'){
			if(imageserial>=14)break;
			imwrite(leftname[imageserial],leftframe);
			imwrite(rightname[imageserial],rightframe);
			imageserial++;
		}
		if(cmd=='b'){break;}
		}
	}
	return 0;
}
		



