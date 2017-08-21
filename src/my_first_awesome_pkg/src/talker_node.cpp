// Autor : Bahri Enis Demirtel


#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <ctime>



#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std; 
using namespace cv;



double dWidth;
double dHeight;




int main(int argc, char* argv[])
{
	ros::init(argc, argv, "image_publisher");
	ros::NodeHandle node_handle;
	
	ros::Rate loop_rate(1);
	ros::Publisher pub;
	pub = node_handle.advertise<sensor_msgs::Image>("camera/image",30);

	
	

	
	
	

	
	VideoCapture cap(CV_CAP_ANY ); // OPENT THE VIDEO CAMERO NO. 0
      cap.set(CV_CAP_PROP_FPS,30);		//change the frame value    
   
   
   
   
   
   
      
       dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of te video
	 dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
      
      if(!cap.isOpened()) //if not success, exit program
	{
		cout<<"Cannot open the video cam" << endl;	}
      
    Mat inputImg;  
      
	
	
	
	
	
	while(ros::ok())
	{
		bool bSuccess = cap.read(inputImg);
		
		
		
		cv_bridge::CvImage out_msg;
//out_msg.header   = in_msg->header; // Same timestamp and tf frame as input image



out_msg.encoding = sensor_msgs::image_encodings::BGR8; // Or whatever
//out_msg.encoding = sensor_msgs::image_encodings::BGR8;





out_msg.image    = inputImg; // Your cv::Mat

		
		
		//sensor_msgs::Image msg;
		//msg.data = "Hello World!";
		
		
		
		//imshow("Input", inputImg);
		//msg.data = inputImg;
		
		//pub.publish(msg);
		
		
		pub.publish(out_msg.toImageMsg());
		
		
		
		
		cv::waitKey();
	}
	return 0;
}












