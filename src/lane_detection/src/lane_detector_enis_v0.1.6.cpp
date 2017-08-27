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

#include "IPM.h"
#include "IPM.cpp"






#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


















using namespace std;
using namespace cv;












/* INTERNAL CAM TEST CODE */

/* REF: https://www.youtube.com/watch?v=HqNJbx0uAv0 */
























int main(int argc, char **argv) {





    int count = 0;

















    //SetUP ROS.
    ros::init(argc, argv, "lane_detector_enis");












    //Get and show an image	 



    //const char* filename = argc >= 2 ? argv[1] : "/home/enis/Schreibtisch/deneme2/frame" + std::to_string(count) + ".jpg";
    //const char* filename = argc >= 2 ? argv[1] : "/home/enis/Schreibtisch/deneme2/frame22.jpg";







    //imshow( "Display window", src );	



























    //CV_CAP_ANY == 0 yazınca 2. kamera açılır.

    VideoCapture cap(CV_CAP_ANY); // OPENT THE VIDEO CAMERO NO. 0


    cap.set(CV_CAP_PROP_FPS, 30); //change the frame value





    if (!cap.isOpened()) //if not success, exit program
    {
        cout << "Cannot open the video cam" << endl;
    }

    double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of te video
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);




    double dFrame = cap.get(CV_CAP_PROP_FPS);



    cout << "FPS value is " << dFrame << endl;








    cout << "Frame size: " << dWidth << " x " << dHeight << endl;


    namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"













    Mat inputImg;
    Mat inputImgGray;
    Mat outputImg;


    cv::VideoCapture video;





    int sayi = 0;


    // Main loop
    int frameNum = 0;
    for (;;) {


        clock_t begin = clock();










        /*

                if (sayi >= 84) {
                    sayi = 0;
                }

                std::string filename = "/home/enis/Schreibtisch/deneme2/frame" + std::to_string(sayi) + ".jpg";
                sayi++;

         */
        // std::string filename = "/home/enis/Schreibtisch/deneme2/frame12.jpg";
        std::string filename = "/home/enis/Schreibtisch/frame0058.jpg";


        inputImg = imread(filename, CV_LOAD_IMAGE_COLOR);
        if (inputImg.empty()) {
            cout << "can not open " << filename << endl;
            return -1;
        }














        printf("FRAME #%6d ", frameNum);
        fflush(stdout);
        frameNum++;

        //     bool bSuccess = cap.read(inputImg);








        Rect Rec1(0, 200, 640, 280);
        rectangle(inputImg, Rec1, Scalar(255), 1, 8, 0);


        Mat outputImg1 = inputImg(Rec1);



















        //Sobel Operator defined		
        Mat outputImg2;
        Mat cdst1;
        Mat grad;
        Mat outputImg3;
        int scale = 1;
        int delta = 0;
        int ddepth = CV_16S;

        GaussianBlur(outputImg1, outputImg2, Size(3, 3), 0, 0, BORDER_DEFAULT); //GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );		 

        cvtColor(outputImg2, outputImg3, CV_BGR2GRAY); // Bunu sil












        double minVal;
        double maxVal;
        Point minLoc;
        Point maxLoc;

        minMaxLoc(outputImg3, &minVal, &maxVal, &minLoc, &maxLoc);

        cout << "min val : " << minVal << endl;
        cout << "max val: " << maxVal << endl;














        threshold(outputImg3, cdst1, 0.6 * maxVal, 255, 1);





        Mat grad_x, grad_y;
        Mat abs_grad_x, abs_grad_y;

        /// Gradient X
        Sobel(cdst1, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT); //inputImgGray i src ile değiştir
        /// Gradient Y
        Sobel(cdst1, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT); //inputImgGray i src ile değiştir


        convertScaleAbs(grad_x, abs_grad_x);
        convertScaleAbs(grad_y, abs_grad_y);

        addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

        imshow("Sobel", grad);













        Mat cdst, dst;

        Mat outputImg4gray, outputImg5gray;


        Canny(grad, dst, 255, 255, 3);
        //       cvtColor(dst, cdst, CV_GRAY2BGR);







        Rect Rec4(0, 0, 640, 140);
        rectangle(dst, Rec4, Scalar(255), 1, 8, 0);


        Mat outputImg4 = dst(Rec4);
        cvtColor(outputImg4, outputImg4gray, CV_GRAY2BGR);








        /*
				
         vector<Vec4i> lines;
         HoughLinesP(dst, lines, 1, CV_PI/180, 10, 10, 80 );
         for( size_t i = 0; i < lines.size(); i++ )
         {
           Vec4i l = lines[i];

           line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
   
         }
  
         */

        vector<Vec2f> lines1;
        HoughLines(outputImg4, lines1, 4, CV_PI, 10, 0, 0);

        for (size_t i = 0; i < lines1.size(); i++) {
            float rho = lines1[i][0], theta = lines1[i][1];
            Point pt1, pt2;
            double a = cos(theta), b = sin(theta);
            double x0 = a*rho, y0 = b*rho;
            pt1.x = cvRound(x0 + 1000 * (-b));
            pt1.y = cvRound(y0 + 1000 * (a));
            pt2.x = cvRound(x0 - 1000 * (-b));
            pt2.y = cvRound(y0 - 1000 * (a));
            line(outputImg4gray, pt1, pt2, Scalar(0, 0, 150), 1, CV_AA);

        }



        int findredlinesarray1[640];
        int a1 = 0;

        for (int k = 639; k >= 0; k--) {

            Vec3b intensity1 = outputImg4gray.at<Vec3b>(10, k);
            uchar blue1 = intensity1.val[0];
            uchar green1 = intensity1.val[1];
            uchar red1 = intensity1.val[2];






            if (red1 >= 100 && red1 <= 200) {

                findredlinesarray1[a1] = k;
                a1++;
            }
        }


   /*     for (int i = 0; i < a1; i++) {


            cout << "x değerleri : " << findredlinesarray1[i] << endl;

        }

*/

        int thebiggestvalue1 = 0;
        int thebiggestvalue11 = 0;
        int thebiggestvalue12 = 0;
         int thebiggestvalue11position = 0;
          int thebiggestvalue12position = 0;
         
        int jj = 3;
        
        
        thebiggestvalue11 = findredlinesarray1[jj - 3] - findredlinesarray1[jj - 2];
            thebiggestvalue12 = findredlinesarray1[jj - 2] - findredlinesarray1[jj - 1];
            
            
            
            thebiggestvalue11position = findredlinesarray1[jj - 3];
             thebiggestvalue12position  = findredlinesarray1[jj - 2];     
                    
                    
                    
            
            
        for (jj = 3; jj < a1; jj++) {
            thebiggestvalue1 = findredlinesarray1[jj-1] - findredlinesarray1[jj];
            
            if (thebiggestvalue1 >= thebiggestvalue11 || thebiggestvalue1 >= thebiggestvalue12) {
                if(thebiggestvalue1 >= thebiggestvalue11){
                thebiggestvalue12 = thebiggestvalue11;
                thebiggestvalue11 = thebiggestvalue1;
                
                
                thebiggestvalue12position = thebiggestvalue11position;
                thebiggestvalue11position = findredlinesarray1[jj];
                
                }
                else{
                    thebiggestvalue12 = thebiggestvalue1;
                    
                    
                    thebiggestvalue12position = findredlinesarray1[jj];
                }
            }
        }

        cout << "thebiggestvalue1 : " << thebiggestvalue11 << " thebiggestvalue12 : " << thebiggestvalue12 << endl;
         cout << "the biggest poisiton : " << thebiggestvalue11position << "tsbp : " << thebiggestvalue12position << endl;


         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
  double x[10000],y[10000];       
         
           
				
  vector<Vec4i> lines;
  HoughLinesP(outputImg4, lines, 1, CV_PI/180, 10, 10, 10 );
  for( size_t i = 0; i < lines.size(); i++ )
  

  
  {
    Vec4i l = lines[i];

 //   line( outputImg4gray, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
   
   
   circle( outputImg4gray, Point(l[0], l[1]), 1, Scalar(0,0,255), 1, CV_AA, 0);
   circle( outputImg4gray, Point(l[2], l[3]), 1, Scalar(0,0,255), 1, CV_AA, 0);
   
   
   
   
   
   

   if(l[0]>=thebiggestvalue11position){
      x[i]=l[0];
      x[i+9] = l[2];
    y[i]=l[1];
    y[i+9] = l[3];
    cout << "x degeri : "<< x[i] << " y değeri : " << y[i] << endl;
   }
   
   
  /*
   
   if(l[1] >440)
   {
	     if(l[0]>=thebiggestvaluex)
	     {
			 thebiggestvaluex = l[0];
			 thebiggestvaluey = l[1];
	   //cout << "x degeri : " << l[0] << " ve y değeri : " << l[1] << endl; 
   }
   }
 
  
  
  
  
  
  */ 
   
  }  
  
  
  
  
 //cout << "en büyük değer x : " << thebiggestvaluex << " ve en büyük değer y : " <<  thebiggestvaluey << endl;
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
	   circle( outputImg4gray, Point(p, r), 1, Scalar(0,255,0), 1, CV_AA, 0);
	   }
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
        imshow("Sobel+Canny+Hough Trasformation1", outputImg4gray);




















        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        






        Rect Rec5(0, 140, 640, 140);
        rectangle(dst, Rec5, Scalar(255), 1, 8, 0);


        Mat outputImg5 = dst(Rec5);
        cvtColor(outputImg5, outputImg5gray, CV_GRAY2BGR);





        vector<Vec2f> lines2;
        HoughLines(outputImg5, lines2, 4, CV_PI, 10, 0, 0);

        for (size_t i = 0; i < lines2.size(); i++) {
            float rho = lines2[i][0], theta = lines1[i][1];
            Point pt1, pt2;
            double a = cos(theta), b = sin(theta);
            double x0 = a*rho, y0 = b*rho;
            pt1.x = cvRound(x0 + 1000 * (-b));
            pt1.y = cvRound(y0 + 1000 * (a));
            pt2.x = cvRound(x0 - 1000 * (-b));
            pt2.y = cvRound(y0 - 1000 * (a));
            line(outputImg5gray, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);




        }







        imshow("Sobel+Canny+Hough Trasformation2", outputImg5gray);







































        imshow("Input", inputImg);
        imshow("Output2", outputImg2);

        waitKey(1);







        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        printf("%.2f (ms)\r", 1000 * elapsed_secs);
        cout << 1000 * elapsed_secs << endl;





    }

    return 0;




}







