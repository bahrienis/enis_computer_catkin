#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std; 
using namespace cv;

/* INTERNAL CAM TEST CODE */
/* REF: https://www.youtube.com/watch?v=HqNJbx0uAv0 */

class cam_test{
  public:
    cam_test()
    {
      VideoCapture cap(CV_CAP_ANY); // OPENT THE VIDEO CAMERO NO. 0

	if(!cap.isOpened()) //if not success, exit program
	{
		cout<<"Cannot open the video cam" << endl;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of te video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	
	
	
	
	
	double dFrame = cap.get(CV_CAP_PROP_FPS);
	cout << "FPS value is " << dFrame << endl;
	
	
	

	cout << "Frame size: " << dWidth << " x " << dHeight << endl;
	
	
	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while(1)
	{
		Mat frame;
		bool bSuccess = cap.read(frame); // read a new frame from video
	
		if(!bSuccess) // if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		
		
		
		
		
		
		
		
		
		
		
		
	//	Mat grey;
  //   cvtColor(frame, grey, CV_BGR2GRAY);
     
     
     
     
     
     
     
Vec3b intensity = frame.at<Vec3b>(20, 20);
uchar blue = intensity.val[0];
uchar green = intensity.val[1];
uchar red = intensity.val[2];
     
     
        
  cout << "Blue value at 50,50 is " << blue/1 <<endl;   
     
     
    if(blue > 100) 
    {
		cout << "Mavi 100 degerinin üstüne çıktı" << endl; 
	}
     
     

		imshow("My video", frame);

		if (waitKey(30) == 27) // wait for 'esc' key press form 30 ms
		{
			cout << "ESC key pressed by user"<< endl;
			break;
		}
	}
    }

    ~cam_test()
    {
	cvDestroyWindow("Camera_Output"); // Destroy Window
    }
};

int main(int argc, char **argv)
{
  //SetUP ROS.
  ros::init(argc, argv, "opencv_tutorial");
  cam_test cam_object;

  ROS_INFO("Cam Tested!");
}


































/*

#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{
     Mat img(500, 1000, CV_8UC3, Scalar(100,10, 220)); //create an image ( 3 channels, 8 bit image depth, 500 high, 1000 wide, (0, 0, 100) assigned for Blue, Green and Red plane respectively. )

     if (img.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          //system("pause"); //wait for a key press
          return -1;
     }
     
     
     
     
     
     
     
     Mat grey;
     cvtColor(img, grey, CV_BGR2GRAY);
     
     
     
     

     namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
     imshow("MyWindow", grey); //display the image which is stored in the 'img' in the "MyWindow" window

     waitKey(0);  //wait infinite time for a keypress

     destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

     return 0;
}
*/
