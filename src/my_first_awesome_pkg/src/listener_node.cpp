// Autor : Bahri Enis Demirtel


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

