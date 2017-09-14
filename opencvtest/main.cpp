#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>
using namespace cv;
using namespace std;

const string videopath = "C:\\Users\\w\\Desktop\\视频拷贝检测\\数据集\\VCDB\\01\\core_dataset\\core_dataset\\baggio_penalty_1994\\3504e360accbaccb1580befbb441f1019664c2bb.mp4";
int main()
{
	VideoCapture capture(videopath);
	if (!capture.isOpened())
	{ 

		cout << "error opening file" << endl;
		return 1;
	}

	//获取帧率
	double rate = capture.get(CV_CAP_PROP_FPS);
	cout << rate << endl;

	//读取总帧数
	long totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
	cout << "整个视频共" << totalFrameNumber << "帧" << endl;

	Mat frame;
	int count = 1;
	char framesave[300];
	while (true)
	{
		if (!capture.read(frame))
		{
			break;
		}
		for (int i = 0; i < totalFrameNumber; i++){
			sprintf(framesave, "E:\\videoframe\\%d.jpg", i);   //格式化输出路径
			imwrite(framesave, frame);                         //保存视频帧
		}
		
	
	}

}