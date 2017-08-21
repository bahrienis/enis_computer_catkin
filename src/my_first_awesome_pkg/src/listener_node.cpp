/*


// Autor : Bahri Enis Demirtel


#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


#include <stdio.h>  
#include <string.h> 
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h> 
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









    void imageCallback(const sensor_msgs::ImageConstPtr& msg)
    {
      try
      {
     //  cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
       
       //namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo" 
       Mat inputImg;
      inputImg = cv_bridge::toCvShare(msg, "bgr8")->image;
      cv::imshow("view", inputImg);
      
   
       
       
       
       
       cv::waitKey(30);
     }
     catch (cv_bridge::Exception& e)
     {
       ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
     }
   }
   
   int main(int argc, char **argv)
   {
     ros::init(argc, argv, "image_listener");
     ros::NodeHandle node_handle;
    // cv::namedWindow("view");
     namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
  //  cv::startWindowThread();
     image_transport::ImageTransport it(node_handle);
     ros::Subscriber sub = node_handle.subscribe("camera/image", 1, imageCallback);
     ros::spin();
   //  cv::destroyWindow("view");
   }






*/

















#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


#include <stdio.h>  
#include <string.h> 
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h> 
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



int frameNum=0;	








    void imageCallback(const sensor_msgs::ImageConstPtr& msg)
    {
		

	
      try
      {
     //  cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
       
       //namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo" 
       Mat inputImg;
      inputImg = cv_bridge::toCvShare(msg, "bgr8")->image;
      cv::imshow("MyVideo", inputImg);
  
       cv::waitKey(30);
       
       
       
     
       printf("FRAME #%6d \n", frameNum);
		fflush(stdout);
		frameNum++;
  

  
       
       
       
       
       
       
     }
     catch (cv_bridge::Exception& e)
     {
       ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
     }
   }
   
   
   
   
   
   
   
   
   
   
   int main(int argc, char **argv)
   {
  
     
     
        ros::init(argc, argv, "image_listener");
  
     


     
       ros::NodeHandle node_handle;
    // cv::namedWindow("view");
     namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
  //  cv::startWindowThread();
     
image_transport::ImageTransport it(node_handle);



     ros::Subscriber sub = node_handle.subscribe("camera/image", 1, imageCallback);
     

     
     ros::spin();
     
    //} 
     
     
     
     
     
     
     
     
     
     
     
     
   //  cv::destroyWindow("view");
   }





