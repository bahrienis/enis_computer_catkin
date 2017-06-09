#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <sys/ioctl.h> //ioctl() call definitions


using namespace std; 
using namespace cv;


/* INTERNAL CAM TEST CODE */
/* REF: https://www.youtube.com/watch?v=HqNJbx0uAv0 */


int n, x, y;
int fd; /* File descriptor for the port */
int RTS_flag;


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
	
	cout << "Frame size: " << dWidth << " x " << dHeight << endl;
	
	
	double dFrame = cap.get(CV_CAP_PROP_FPS);
	cout << "FPS value is " << dFrame << endl;
	
	
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
		
		imshow("My video", frame);

		if (waitKey(30) == 27) // wait for 'esc' key press form 30 ms
		{
			cout << "ESC key pressed by user"<< endl;
			break;
		}
	
    
	//	Mat grey;
	//  cvtColor(frame, grey, CV_BGR2GRAY);
    

	for(y=0; y<480; y++) 
	{
		for(x=0; x<640; x++)
		{
			Vec3b intensity = frame.at<Vec3b>(y, x);
			uchar blue = intensity.val[0];
			uchar green = intensity.val[1];
			uchar red = intensity.val[2];
			
			if(blue <= 3 && green <= 3 && red <= 3)
			{
				cout << "LED is on at pixels y = " << y << " and x = "<< x << endl;   
				n = write(fd, "ATZ\r", 4);
					if (n < 0)
					{
						fputs("write() of 4 bytes failed!\n", stderr);
						cout << "the value of n is " << n << endl;
						
						
						
						
						
						
						
						  
  
  
  RTS_flag = TIOCM_RTS;
  ioctl(fd,TIOCMBIS,&RTS_flag); //Set RTS pin
  getchar();
  ioctl(fd,TIOCMBIC,&RTS_flag); //Clear RTS pin
  close(fd);
  
  
  
  
  
  
  
	
					}			
				//	return (fd);
			}
		}
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

  ros::init(argc, argv, "opencv_tutorial");					//SetUP ROS.
  
  int fd; /* File descriptor for the port */

  fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
  

  
  
  
  
  if (fd == -1)
  {
   /* Could not open the port. */
    perror("open_port: Unable to open /dev/ttyS0 - ");  //Bu hatayı verirse "sudo chmod o+rw /dev/ttyS0" kodunu kullan.
  }
  else
  {
    fcntl(fd, F_SETFL, 0);
	cout << "Serial port is opened" << endl;
	
	
}

/*  n = write(fd, "ATZ\r", 4);
  if (n < 0)
  {
	fputs("write() of 4 bytes failed!\n", stderr);
	cout << "the value of n is " << n << endl;
	
}
 
 
   return (fd);
   
 */  
   
  cam_test cam_object;

  ROS_INFO("Cam Tested!");
  
  return (fd);
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
