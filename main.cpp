#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <thread>
#include <string>

using namespace cv;
using namespace std;

void workerThread(VideoCapture* capture,string* nameWindow)
{
    cv::Mat img;
	for(;;)
    {
        capture->read(img);
        cv::namedWindow( *nameWindow, 1 );
        cv::imshow( *nameWindow, img );
        if(cv::waitKey(30) >= 0) break;
    }
}
   int main(int argc, char** argv)
{
    string nameWindow1("Thread 1");
    string nameWindow2("Thread 2");

    VideoCapture capture1(1);
    VideoCapture capture2(2);

    thread tWorker1(&workerThread,&capture1,&nameWindow1);
    thread tWorker2(&workerThread,&capture2,&nameWindow2);

    cout << "Main thread is waiting for worker thread 1 & thread 2!!!"<<endl;

    tWorker1.join();
    tWorker2.join();

    cout << "Thread 1 and Thread 2 finished their work!!!"<<endl;

    return 0;
}
