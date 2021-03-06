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







#include "IPM.h"
#include "IPM.cpp"










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
		  
		  
		  
		  
			  clock_t begin = clock();    
         
		  
		
		  
		  
		  
     //  cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
       
       //namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo" 
       //Mat inputImg;
       Mat inputImgGray;
		Mat outputImg;
       
       
       
  
                                       
  //    cv::Mat inputImg= cv_bridge::toCvShare(msg, "bgr8")->image;              
                             
                             
   Mat inputImg = imread("/home/enis/Schreibtisch/deneme2/frame25.jpg", CV_LOAD_IMAGE_COLOR);



      cv::imshow("MyVideo", inputImg);
  
     
       
       
       
        
         
       
       
       
		
	

       
       
       
       
       
       
    
       
       
       
     
       printf("FRAME #%6d \n", frameNum);
		fflush(stdout);
		frameNum++;
  

  
       
       
       		 
       
     
      
      
		 
		
		 
		 
		 
		 
		 // View		
		
		 
		 
		 
		 
		  imshow("Input", inputImg);
		


























	
		 
//Sobel Operator defined		
	
	 
Mat grad;
int scale = 1;
int delta = 0;
int ddepth = CV_16S;		 
		 
GaussianBlur( inputImg, inputImg, Size(9,9), 0, 0, BORDER_DEFAULT );	//GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );		 
		 
//cvtColor( outputImg, inputImgGray, CV_BGR2GRAY );		 // Bunu sil
		 
		 
Mat grad_x, grad_y;
Mat abs_grad_x, abs_grad_y;

/// Gradient X
Sobel( inputImg, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );   //inputImgGray i src ile değiştir
/// Gradient Y
Sobel( inputImg, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );	//inputImgGray i src ile değiştir
		 
		 
convertScaleAbs( grad_x, abs_grad_x );
convertScaleAbs( grad_y, abs_grad_y );		 
		 
addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );		 
		 
imshow( "Sobel", grad );		 
		 
		 
		 




		 
	

 double x[10000],y[10000];
  int thebiggestvaluex = 0;
   int thebiggestvaluey = 0;
   int thewindowx = 30;
   int thewindowy = 20;






Mat cdst,dst;
Canny(grad, dst, 50, 200, 3);
cvtColor(dst, cdst, CV_GRAY2BGR);
 
 
 
 
 
  
  
  
  
  
  
  
  
    vector<Vec2f> lines;
  HoughLines(dst, lines, 1, CV_PI, 5, 0, 0 );

  for( size_t i = 0; i < lines.size(); i++ )
  {
     float rho = lines[i][0], theta = lines[i][1];
     Point pt1, pt2;
     double a = cos(theta), b = sin(theta);
     double x0 = a*rho, y0 = b*rho;
     pt1.x = cvRound(x0 + 1000*(-b));
     pt1.y = cvRound(y0 + 1000*(a));
     pt2.x = cvRound(x0 - 1000*(-b));
     pt2.y = cvRound(y0 - 1000*(a));
     line( cdst, pt1, pt2, Scalar(0,0,255), 3, CV_AA);
  }
   
  /*
				
  vector<Vec4i> lines;
  HoughLinesP(dst, lines, 1, CV_PI/180, 10, 10, 100 );
  for( size_t i = 0; i < lines.size(); i++ )
  

  
  {
    Vec4i l = lines[i];

    line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
   
   
   circle( cdst, Point(l[0], l[1]), 1, Scalar(0,0,255), 1, CV_AA, 0);
   circle( cdst, Point(l[2], l[3]), 1, Scalar(0,0,255), 1, CV_AA, 0);
   
   
   
   
   
   

   
      x[i]=l[0];
    y[i]=l[1];
   
   
   
   
   
   if(l[1] >440)
   {
	     if(l[0]>=thebiggestvaluex)
	     {
			 thebiggestvaluex = l[0];
			 thebiggestvaluey = l[1];
	   //cout << "x degeri : " << l[0] << " ve y değeri : " << l[1] << endl; 
   }
   }
 
  
  
  
  
  

   
  }  
  
  */
  
  
 cout << "en büyük değer x : " << thebiggestvaluex << " ve en büyük değer y : " <<  thebiggestvaluey << endl;
 //imshow("Sobel+Canny+Hough Trasformation", cdst);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   int i,j,k,n,N;
   cout.precision(4);  						//set precision
   cout.setf(ios::fixed);
   N = lines.size();
/*   double x[N],y[N];
   for(i=0;i<N;i++)
   x[i]=l[0];
    for(i=0;i<N;i++)
    y[i]=l[1];   */
    n = 2;   								//polinomun derecesi
    double X[2*n+1];
    for(i=0;i<2*n+1;i++)
    {
		X[i]=0;
		for(j=0;j<N;j++)
		X[i]=X[i]+pow(x[j],i);
	}
	double B[n+1][n+2],a[n+1];
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		B[i][j]=X[i+j];
	double Y[n+1];
	for(i=0;i<n+1;i++)
	{
		Y[i]=0;
		for(j=0;j<N;j++)
		Y[i]=Y[i]+pow(x[j],i)*y[j];
	}
	for(i=0;i<=n;i++)
	B[i][n+1]=Y[i];
	n=n+1;
/*	cout<<"\nThe Normal (Augmented Matrix) is as follows:\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		cout<<B[i][j]<<setw(16);
		cout<<"\n";
	}
*/	for(i=0;i<n;i++)
	for(k=i+1;k<n;k++)
	if(B[i][i]<B[k][i])
	for(j=0;j<=n;j++)
	{
		double temp=B[i][j];
		B[i][j]=B[k][j];
		B[k][j]=temp;
	}
	for(i=0;i<n-1;i++)
	for(k=i+1;k<n;k++)
	{
		double t=B[k][i]/B[i][i];
		for(j=0;j<=n;j++)
		B[k][j]=B[k][j]-t*B[i][j];
	}
	for(i=n-1;i>=0;i--)
	{
		a[i]=B[i][n];
		for(j=0;j<n;j++)
		if(j!=i)
		a[i]=a[i]-B[i][j]*a[j];
		a[i]=a[i]/B[i][i];
	}
	cout<<"\nThe values of the cofficients are as follows:\n";
	for(i=0;i<n;i++)
	cout << "x´"<<i<<"="<<a[i]<<endl;
	cout<<"\nHence the fitted Polynomial is given by:\ny=";
	for(i=0;i<n;i++)
	cout<<" + ("<<a[i]<<")"<<"x´"<<i;
	cout<<"\n";

	
		
   
   
   
   
   
   
   
  
   
   int p,r;
   for(p=0;p<480;p++)
   {
	   r=a[0] + a[1] * p + a[2] * p * p;
	   if(r>=0 && r<=640)
	  // cout<<p<< " degeri " <<r<<endl;
	   circle( cdst, Point(p, r), 1, Scalar(0,255,0), 1, CV_AA, 0);
	   }
   
   
  
   
   
   
   
   
   imshow("Sobel+Canny+Hough Trasformation", cdst);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   





	
		 waitKey(1);
		 










clock_t end = clock();


 
		 double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		 printf("%.2f   (ms)\r", 1000*elapsed_secs);
		 cout << 1000*elapsed_secs <<endl;






	
	
		 
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





