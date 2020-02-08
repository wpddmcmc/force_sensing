#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>

int main()
{
    cv::VideoCapture capture1(2);
    cv::VideoCapture capture2(4);

    capture1.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
    capture1.set(CV_CAP_PROP_FRAME_HEIGHT, 720);

    if (!capture1.isOpened())
        std::cout << "Camera1 Cannot Open" << std::endl;
    if (!capture2.isOpened())
        std::cout << "Camera2 Cannot Open" << std::endl;
    int init_loop = 0;

    std::vector<double> y_po_ini1, y_ne_ini1, x_po_ini1, x_ne_ini1, z_po_ini1,
        y_po_ini2, y_ne_ini2, x_po_ini2, x_ne_ini2, z_po_ini2,
        z_ini_s3, yp_ini_s3, xp_ini_s3, z_ini_s4, yn_ini_s4, xp_ini_s4,
        z_ini_s5, yp_ini_s5, xp_ini_s5, z_ini_s6, yn_ini_s6, xp_ini_s6, z_ini_s7, yp_ini_s7, xp_ini_s7;

    while (init_loop < 400)
    {
        cv::Mat src1, src2;
        cv::Mat gray1, gray2;

        capture1 >> src1; // two 3axis force sensors image
        capture2 >> src2; // five 3-axis force sensors image

        cv::cvtColor(src1, gray1, cv::COLOR_BGR2GRAY); // two 3axis force sensors image
        cv::cvtColor(src2, gray2, cv::COLOR_BGR2GRAY); // five 3-axis force sensors image
        y_po_ini1.push_back(cv::mean(gray1(cv::Rect(768, 286, 831 - 768, 339 - 286))).val[0]);
        y_ne_ini1.push_back(cv::mean(gray1(cv::Rect(962, 157, 1052 - 962, 231 - 157))).val[0]);
        x_po_ini1.push_back(cv::mean(gray1(cv::Rect(900, 297, 968 - 900, 369 - 297))).val[0]);
        x_ne_ini1.push_back(cv::mean(gray1(cv::Rect(805, 159, 876 - 805, 214 - 159))).val[0]);
        z_po_ini1.push_back(cv::mean(gray1(cv::Rect(864, 233, 933 - 864, 272 - 233))).val[0]);

        y_po_ini2.push_back(cv::mean(gray1(cv::Rect(269, 561, 358 - 269, 637 - 561))).val[0]);
        y_ne_ini2.push_back(cv::mean(gray1(cv::Rect(494, 450, 553 - 494, 502 - 450))).val[0]);
        x_po_ini2.push_back(cv::mean(gray1(cv::Rect(440, 589, 523 - 440, 683 - 589))).val[0]);
        x_ne_ini2.push_back(cv::mean(gray1(cv::Rect(353, 425, 422 - 353, 474 - 425))).val[0]);
        z_po_ini2.push_back(cv::mean(gray1(cv::Rect(393, 503, 456 - 393, 563 - 503))).val[0]);

        z_ini_s3.push_back(cv::mean(gray2(cv::Rect(312, 235, 337 - 312, 283 - 235))).val[0]);
        yp_ini_s3.push_back(cv::mean(gray2(cv::Rect(275, 289, 308 - 275, 327 - 289))).val[0]);
        xp_ini_s3.push_back(cv::mean(gray2(cv::Rect(266, 207, 300 - 266, 240 - 207))).val[0]);

        z_ini_s4.push_back(cv::mean(gray2(cv::Rect(434, 104, 448 - 434, 127 - 104))).val[0]);
        yn_ini_s4.push_back(cv::mean(gray2(cv::Rect(456, 62, 483 - 456, 83 - 62))).val[0]);
        xp_ini_s4.push_back(cv::mean(gray2(cv::Rect(389, 57, 420 - 389, 94 - 57))).val[0]);

        z_ini_s5.push_back(cv::mean(gray2(cv::Rect(186, 138, 198 - 186, 151 - 138))).val[0]);
        yp_ini_s5.push_back(cv::mean(gray2(cv::Rect(206, 92, 233 - 206, 115 - 92))).val[0]);
        xp_ini_s5.push_back(cv::mean(gray2(cv::Rect(215, 163, 239 - 215, 195 - 163))).val[0]);

        z_ini_s6.push_back(cv::mean(gray2(cv::Rect(211, 401, 225 - 211, 416 - 401))).val[0]);
        yn_ini_s6.push_back(cv::mean(gray2(cv::Rect(230, 367, 257 - 230, 388 - 367))).val[0]);
        xp_ini_s6.push_back(cv::mean(gray2(cv::Rect(238, 451, 281 - 238, 462 - 451))).val[0]);

        z_ini_s7.push_back(cv::mean(gray2(cv::Rect(480, 370, 489 - 480, 382 - 370))).val[0]);
        yp_ini_s7.push_back(cv::mean(gray2(cv::Rect(437, 409, 459 - 437, 426 - 409))).val[0]);
        xp_ini_s7.push_back(cv::mean(gray2(cv::Rect(519, 397, 531 - 519, 417 - 397))).val[0]);

        init_loop++;

        cv::Mat test,test2;
        src1.copyTo(test);
        src2.copyTo(test2);
        cv::rectangle(test, cv::Rect(768, 286, 831 - 768, 339 - 286), cv::Scalar(0, 0, 255),2);
        cv::rectangle(test,cv::Rect(962, 157, 1052 - 962, 231 - 157), cv::Scalar(0, 0, 255),2);
        cv::rectangle(test,cv::Rect(900, 297, 968 - 900, 369 - 297), cv::Scalar(0, 0, 255),2);
        cv::rectangle(test,cv::Rect(805, 159, 876 - 805, 214 - 159), cv::Scalar(0, 0, 255),2);
        cv::rectangle(test,cv::Rect(864, 233, 933 - 864, 272 - 233), cv::Scalar(0, 0, 255),2);

        cv::rectangle(test,cv::Rect(269, 561, 358 - 269, 637 - 561), cv::Scalar(128, 0, 255),2);
        cv::rectangle(test,cv::Rect(494, 450, 553 - 494, 502 - 450), cv::Scalar(128, 0, 255),2);
        cv::rectangle(test,cv::Rect(440, 589, 523 - 440, 683 - 589), cv::Scalar(128, 0, 255),2);
        cv::rectangle(test,cv::Rect(353, 425, 422 - 353, 474 - 425), cv::Scalar(128, 0, 255),2);
        cv::rectangle(test,cv::Rect(393, 503, 456 - 393, 563 - 503), cv::Scalar(128, 0, 255),2);
        cv::imshow("gray1", test);

        cv::rectangle(test2,cv::Rect(312, 235, 337 - 312, 283 - 235), cv::Scalar(0, 128, 255),2);
        cv::rectangle(test2,cv::Rect(275, 289, 308 - 275, 327 - 289), cv::Scalar(0, 128, 255),2);
        cv::rectangle(test2,cv::Rect(266, 207, 300 - 266, 240 - 207), cv::Scalar(0, 128, 255),2);
        cv::rectangle(test2,cv::Rect(434, 104, 448 - 434, 127 - 104), cv::Scalar(0, 0, 255),2);
        cv::rectangle(test2,cv::Rect(456, 62, 483 - 456, 83 - 62), cv::Scalar(0, 0, 255),2);
        cv::rectangle(test2,cv::Rect(389, 57, 420 - 389, 94 - 57), cv::Scalar(0, 0, 255),2);
        cv::rectangle(test2,cv::Rect(186, 138, 198 - 186, 151 - 138), cv::Scalar(255, 0, 0),2);
        cv::rectangle(test2,cv::Rect(206, 92, 233 - 206, 115 - 92), cv::Scalar(255, 0, 0),2);
        cv::rectangle(test2,cv::Rect(215, 163, 239 - 215, 195 - 163), cv::Scalar(255, 0, 0),2);
        cv::rectangle(test2,cv::Rect(211, 401, 225 - 211, 416 - 401), cv::Scalar(0, 255, 0),2);
        cv::rectangle(test2,cv::Rect(230, 367, 257 - 230, 388 - 367), cv::Scalar(0, 255, 0),2);
        cv::rectangle(test2,cv::Rect(238, 451, 281 - 238, 462 - 451), cv::Scalar(0, 255, 0),2);
        cv::rectangle(test2,cv::Rect(480, 370, 489 - 480, 382 - 370), cv::Scalar(128, 128, 128),2);
        cv::rectangle(test2,cv::Rect(437, 409, 459 - 437, 426 - 409), cv::Scalar(128, 128, 128),2);
        cv::rectangle(test2,cv::Rect(519, 397, 531 - 519, 417 - 397), cv::Scalar(128, 128, 128),2);
        cv::imshow("gray2", test2);

        char key = cv::waitKey(10);
        if(key=='q')
        {
            std::cout<<"Keyboard Exit!"<<std::endl;
            return -1;
        }
    }

    float initial_y_po1,initial_y_ne1,initial_x_po1,initial_x_ne1,initial_z1,initial_y_po2,
    initial_y_ne2,initial_x_po2,initial_x_ne2,initial_z2,z_s3_initial,y_s3_initial,x_s3_initial,
    z_s4_initial,y_s4_initial,x_s4_initial,z_s5_initial,y_s5_initial,x_s5_initial,z_s6_initial,
    y_s6_initial,x_s6_initial,z_s7_initial,y_s7_initial,x_s7_initial;

    initial_y_po1 = std::accumulate(y_po_ini1.begin()+100,y_po_ini1.end(),0)/y_po_ini1.size();
    initial_y_ne1 = std::accumulate(y_ne_ini1.begin()+100,y_ne_ini1.end(),0)/y_ne_ini1.size();
    initial_x_po1 = std::accumulate(x_po_ini1.begin()+100,x_po_ini1.end(),0)/x_po_ini1.size();
    initial_x_ne1 = std::accumulate(x_ne_ini1.begin()+100,x_ne_ini1.end(),0)/x_ne_ini1.size();
    initial_z1 = std::accumulate(z_po_ini1.begin()+100,z_po_ini1.end(),0)/z_po_ini1.size();

    initial_y_po2 = std::accumulate(y_po_ini2.begin()+100,y_po_ini2.end(),0)/y_po_ini2.size();
    initial_y_ne2 = std::accumulate(y_ne_ini2.begin()+100,y_ne_ini2.end(),0)/y_ne_ini2.size();
    initial_x_po2 = std::accumulate(x_po_ini2.begin()+100,x_po_ini2.end(),0)/x_po_ini2.size();
    initial_x_ne2= std::accumulate(x_ne_ini2.begin()+100,x_ne_ini2.end(),0)/x_ne_ini2.size();
    initial_z2= std::accumulate(z_po_ini2.begin()+100,z_po_ini2.end(),0)/z_po_ini2.size();

    z_s3_initial= std::accumulate(z_ini_s3.begin()+100,z_ini_s3.end(),0)/z_ini_s3.size();
    y_s3_initial= std::accumulate(yp_ini_s3.begin()+100,yp_ini_s3.end(),0)/yp_ini_s3.size();
    x_s3_initial= std::accumulate(xp_ini_s3.begin()+100,xp_ini_s3.end(),0)/xp_ini_s3.size();
    
    z_s4_initial= std::accumulate(z_ini_s4.begin()+100,z_ini_s4.end(),0)/z_ini_s4.size();
    y_s4_initial= std::accumulate(yn_ini_s4.begin()+100,yn_ini_s4.end(),0)/yn_ini_s4.size();
    x_s4_initial= std::accumulate(xp_ini_s4.begin()+100,xp_ini_s4.end(),0)/xp_ini_s4.size();
    
    z_s5_initial= std::accumulate(z_ini_s5.begin()+100,z_ini_s5.end(),0)/z_ini_s5.size();
    y_s5_initial= std::accumulate(yp_ini_s5.begin()+100,yp_ini_s5.end(),0)/yp_ini_s5.size();
    x_s5_initial= std::accumulate(xp_ini_s5.begin()+100,xp_ini_s5.end(),0)/xp_ini_s5.size();
    
    z_s6_initial= std::accumulate(z_ini_s6.begin()+100,z_ini_s6.end(),0)/z_ini_s6.size();
    y_s6_initial= std::accumulate(yn_ini_s6.begin()+100,yn_ini_s6.end(),0)/yn_ini_s6.size();
    x_s6_initial= std::accumulate(xp_ini_s6.begin()+100,xp_ini_s6.end(),0)/xp_ini_s6.size();
    
    z_s7_initial= std::accumulate(z_ini_s7.begin()+100,z_ini_s7.end(),0)/z_ini_s7.size();
    y_s7_initial= std::accumulate(yp_ini_s7.begin()+100,yp_ini_s7.end(),0)/yp_ini_s7.size();
    x_s7_initial= std::accumulate(xp_ini_s7.begin()+100,xp_ini_s7.end(),0)/xp_ini_s7.size();

    long int frame_num = 1;

    std::vector<float> y_po1,y_ne1,x_po1,x_ne1,z_po1,y_po2,y_ne2,x_po2,x_ne2,z_po2,
    z_li_s3,y_li_s3,x_li_s3,z_li_s4,y_li_s4,x_li_s4,z_li_s5,y_li_s5,x_li_s5,z_li_s6,
    y_li_s6,x_li_s6,z_li_s7,y_li_s7,x_li_s7;

    float liz_s1,lix_po_s1,lix_ne_s1,liy_po_s1,liy_ne_s1,liz_s2,lix_po_s2,lix_ne_s2,liy_po_s2,
    liy_ne_s2,liz_s3,lix_s3,liy_s3,liz_s4,lix_s4,liy_s4,liz_s5,lix_s5,liy_s5,liz_s6,
    lix_s6,liy_s6,liz_s7,lix_s7,liy_s7;

    std::vector<float> fz_s1f,fy_s1f,fx_s1f,fz_s2f,fy_s2f,fx_s2f,fz_s3f,fy_s3f,fx_s3f,
        fz_s4f,fy_s4f,fx_s4f,fz_s5f,fy_s5f,fx_s5f,fz_s6f,fy_s6f,fx_s6f,fz_s7f,
        fy_s7f,fx_s7f;
    std::vector<std::vector<float>> Force_res;
    std::vector<std::vector<float>> Force_xyz;
    while (1)
    {
        cv::Mat src1, src2;
        cv::Mat gray1, gray2;

        capture1 >> src1;
        capture2 >> src2;

        cv::imshow("Capture1", src1);
        cv::imshow("Capture2", src2);
        char key = cv::waitKey(10);
        if(key=='q')
        {
            std::cout<<"Keyboard Exit!"<<std::endl;
            return -1;
        }
        cv::cvtColor(src1, gray1, cv::COLOR_BGR2GRAY);
        cv::cvtColor(src1, gray2, cv::COLOR_BGR2GRAY);

        float fz_s1,fy_s1,fx_s1,fz_s2,fy_s2,fx_s2,fz_s3,fy_s3,fx_s3,
        fz_s4,fy_s4,fx_s4,fz_s5,fy_s5,fx_s5,fz_s6,fy_s6,fx_s6,fz_s7,
        fy_s7,fx_s7;

        y_po1.push_back(cv::mean(gray1(cv::Rect(768, 286, 831 - 768, 339 - 286))).val[0]);
        y_ne1.push_back(cv::mean(gray1(cv::Rect(962, 157, 1052 - 962, 231 - 157))).val[0]);
        x_po1.push_back(cv::mean(gray1(cv::Rect(900, 297, 968 - 900, 369 - 297))).val[0]);
        x_ne1.push_back(cv::mean(gray1(cv::Rect(805, 159, 876 - 805, 214 - 159))).val[0]);
        z_po1.push_back(cv::mean(gray1(cv::Rect(864, 233, 933 - 864, 272 - 233))).val[0]);

        y_po2.push_back(cv::mean(gray1(cv::Rect(269, 561, 358 - 269, 637 - 561))).val[0]);
        y_ne2.push_back(cv::mean(gray1(cv::Rect(494, 450, 553 - 494, 502 - 450))).val[0]);
        x_po2.push_back(cv::mean(gray1(cv::Rect(440, 589, 523 - 440, 683 - 589))).val[0]);
        x_ne2.push_back(cv::mean(gray1(cv::Rect(353, 425, 422 - 353, 474 - 425))).val[0]);
        z_po2.push_back(cv::mean(gray1(cv::Rect(393, 503, 456 - 393, 563 - 503))).val[0]);

        z_li_s3.push_back(cv::mean(gray2(cv::Rect(312, 235, 337 - 312, 283 - 235))).val[0]);
        y_li_s3.push_back(cv::mean(gray2(cv::Rect(275, 289, 308 - 275, 327 - 289))).val[0]);
        x_li_s3.push_back(cv::mean(gray2(cv::Rect(266, 207, 300 - 266, 240 - 207))).val[0]);

        z_li_s4.push_back(cv::mean(gray2(cv::Rect(434, 104, 448 - 434, 127 - 104))).val[0]);
        y_li_s4.push_back(cv::mean(gray2(cv::Rect(456, 62, 483 - 456, 83 - 62))).val[0]);
        x_li_s4.push_back(cv::mean(gray2(cv::Rect(389, 57, 420 - 389, 94 - 57))).val[0]);

        z_li_s5.push_back(cv::mean(gray2(cv::Rect(186, 138, 198 - 186, 151 - 138))).val[0]);
        y_li_s5.push_back(cv::mean(gray2(cv::Rect(206, 92, 233 - 206, 115 - 92))).val[0]);
        x_li_s5.push_back(cv::mean(gray2(cv::Rect(215, 163, 239 - 215, 195 - 163))).val[0]);

        z_li_s6.push_back(cv::mean(gray2(cv::Rect(211, 401, 225 - 211, 416 - 401))).val[0]);
        y_li_s6.push_back(cv::mean(gray2(cv::Rect(230, 367, 257 - 230, 388 - 367))).val[0]);
        x_li_s6.push_back(cv::mean(gray2(cv::Rect(238, 451, 281 - 238, 462 - 451))).val[0]);

        z_li_s7.push_back(cv::mean(gray2(cv::Rect(480, 370, 489 - 480, 382 - 370))).val[0]);
        y_li_s7.push_back(cv::mean(gray2(cv::Rect(437, 409, 459 - 437, 426 - 409))).val[0]);
        x_li_s7.push_back(cv::mean(gray2(cv::Rect(519, 397, 531 - 519, 417 - 397))).val[0]);
        
        if(frame_num>7 && frame_num<20)
        {
            liz_s1 = std::accumulate(z_po1.end()-5,z_po1.end(),0)/z_po1.size();
            lix_po_s1 = std::accumulate(x_po1.end()-5,x_po1.end(),0)/x_po1.size();
            lix_ne_s1 = std::accumulate(x_ne1.end()-5,x_ne1.end(),0)/x_ne1.size();
            liy_po_s1 = std::accumulate(y_po1.end()-5,y_po1.end(),0)/y_po1.size();
            liy_ne_s1 = std::accumulate(y_ne1.end()-5,y_ne1.end(),0)/y_ne1.size();
            
            liz_s2 = std::accumulate(z_po2.end()-5,z_po2.end(),0)/z_po2.size();
            lix_po_s2 = std::accumulate(x_po2.end()-5,x_po2.end(),0)/x_po2.size();
            lix_ne_s2 = std::accumulate(x_ne2.end()-5,x_ne2.end(),0)/x_ne2.size();
            liy_po_s2 = std::accumulate(y_po2.end()-5,y_po2.end(),0)/y_po2.size();
            liy_ne_s2 = std::accumulate(y_ne2.end()-5,y_ne2.end(),0)/y_ne2.size();

            liz_s3 = std::accumulate(z_li_s3.end()-5,z_li_s3.end(),0)/z_li_s3.size();
            lix_s3 = std::accumulate(x_li_s3.end()-5,x_li_s3.end(),0)/x_li_s3.size();
            liy_s3 = std::accumulate(y_li_s3.end()-5,y_li_s3.end(),0)/y_li_s3.size();
       
            liz_s4 = std::accumulate(z_li_s4.end()-5,z_li_s4.end(),0)/z_li_s4.size();
            lix_s4 = std::accumulate(x_li_s4.end()-5,x_li_s4.end(),0)/x_li_s4.size();
            liy_s4 = std::accumulate(y_li_s4.end()-5,y_li_s4.end(),0)/y_li_s4.size();
       
            liz_s5 = std::accumulate(z_li_s5.end()-5,z_li_s5.end(),0)/z_li_s5.size();
            lix_s5 = std::accumulate(x_li_s5.end()-5,x_li_s5.end(),0)/x_li_s5.size();
            liy_s5 = std::accumulate(y_li_s5.end()-5,y_li_s5.end(),0)/y_li_s5.size();
       
            liz_s6 = std::accumulate(z_li_s6.end()-5,z_li_s6.end(),0)/z_li_s6.size();
            lix_s6 = std::accumulate(x_li_s6.end()-5,x_li_s6.end(),0)/x_li_s6.size();
            liy_s6 = std::accumulate(y_li_s6.end()-5,y_li_s6.end(),0)/y_li_s6.size();
       
            liz_s7 = std::accumulate(z_li_s7.end()-5,z_li_s7.end(),0)/z_li_s7.size();
            lix_s7 = std::accumulate(x_li_s7.end()-5,x_li_s7.end(),0)/x_li_s7.size();
            liy_s7 = std::accumulate(y_li_s7.end()-5,y_li_s7.end(),0)/y_li_s7.size();
            
            float y_int1 = liy_po_s1- liy_ne_s1;
            float z_int1 = liz_s1;

            float x_int1;
            if (lix_ne_s1<0)
                x_int1 = lix_ne_s1;
            else
                x_int1 =  lix_po_s1;

            float y_int2 = liy_po_s2-liy_ne_s2;
            float x_int2 = lix_po_s2-lix_ne_s2;
            float z_int2 = liz_s2;
            //%%%% sensor 1 Final calibration 
            fz_s1f.push_back(0.0027052*pow(z_int1,4)-0.011676*pow(z_int1,3)-0.010948*pow(z_int1,2) +0.71242*z_int1 -0.004521);
            fy_s1f.push_back(0.095471*y_int1);
            fx_s1f.push_back( 0.26765*x_int1);

            //%%%% sensor 2 Final calibration
            fz_s2f.push_back(0.64248 * z_int2);
            fy_s2f.push_back(0.15159 * y_int2);
            fx_s2f.push_back(0.13342 * x_int2);

            //%%%% sensor 3 Final calibration
            fz_s3f.push_back(-0.011222 * pow(liz_s3, 3) + -0.043049 * pow(liz_s3, 2) - 0.93763 * liz_s3 + 0.0071904);
            fy_s3f.push_back(3.8712e-05 * pow(liy_s3, 3) + -0.0028025 * pow(liy_s3, 2) + 0.16335 * liy_s3 - 0.16775);
            fx_s3f.push_back(1.8035e-05 * pow(lix_s3, 3) - 0.0023924 * pow(lix_s3, 2) + 0.26868 * lix_s3 + 0.04158);

            //%%%% sensor4 Final calibration
            fz_s4f.push_back(-0.011222 * pow(liz_s4, 3) + -0.043049 * pow(liz_s4, 2) - 0.93763 * liz_s4 + 0.0071904);
            fy_s4f.push_back(-2.5286e-05 * pow(liy_s4, 4) + -0.0015057 * pow(liy_s4, 3) + -0.026599 * pow(liy_s4, 2) + 0.075347 * liy_s4 + 0.021047);
            fx_s4f.push_back(-0.00017878 * pow(lix_s4, 3) - 0.0079705 * pow(lix_s4, 2) - 0.3129 * lix_s4 - 0.67847);

            //%%%% sensor5 Final calibration
            fz_s5f.push_back(-0.0044725 * pow(liz_s5, 3) - 0.047633 * pow(liz_s5, 2) - 0.46121 * liz_s5 + 0.73707);
            fy_s5f.push_back(-1.0017e-12 * pow(liy_s5, 10) + 8.9623e-11 * pow(liy_s5, 9) + -1.9142e-09 * pow(liy_s5, 8) + -4.0429e-08 * pow(liy_s5, 7) + 1.8078e-06 * pow(liy_s5, 6) + -4.7217e-06 * pow(liy_s5, 5) + -0.00042256 * pow(liy_s5, 4) + 0.0030408 * pow(liy_s5, 3) + 0.043865 * pow(liy_s5, 2) + -0.7219 * liy_s5);
            fx_s5f.push_back(0.011346 * pow(lix_s5, 3) + 0.16438 * pow(lix_s5, 2) + 0.98549 * lix_s5 + 0.017546);

            //%%%% sensor6 Final calibration
            fz_s6f.push_back(0.00022378 * pow(liz_s6, 4) + -0.0061643 * pow(liz_s6, 3) + 0.034503 * pow(liz_s6, 2) + 0.48075 * liz_s6 + 0.048943);
            fy_s6f.push_back(5.0291e-05 * pow(liy_s6, 3) - 0.00078962 * pow(liy_s6, 2) + 0.15164 * liy_s6 + 0.0049077);
            fx_s6f.push_back(-2.3331e-06 * pow(lix_s6, 4) + -6.2271e-05 * pow(lix_s6, 3) + 0.0022352 * pow(lix_s6, 2) + 0.30789 * lix_s6 + 0.42283);

            //%%% sensor7 Final calibration
            fz_s7f.push_back(-0.0017082 * pow(liz_s7, 3) - 0.033597 * pow(liz_s7, 2) - 0.49547 * liz_s7 - 0.030753);
            fy_s7f.push_back(7.939e-07 * pow(liy_s7, 4) + -1.6693e-05 * pow(liy_s7, 3) - 0.0038142 * pow(liy_s7, 2) + -0.20008 * liy_s7 + 0.096795);
            fx_s7f.push_back(0.0006545 * pow(lix_s7, 3) - 0.026066 * pow(lix_s7, 2) + 0.52242 * lix_s7 + 0.032173);
        }
        
        else if(frame_num>=20)
        {
            liz_s1 = std::accumulate(z_po1.end()-5,z_po1.end(),0)/z_po1.size();
            lix_po_s1 = std::accumulate(x_po1.end()-5,x_po1.end(),0)/x_po1.size();
            lix_ne_s1 = std::accumulate(x_ne1.end()-5,x_ne1.end(),0)/x_ne1.size();
            liy_po_s1 = std::accumulate(y_po1.end()-5,y_po1.end(),0)/y_po1.size();
            liy_ne_s1 = std::accumulate(y_ne1.end()-5,y_ne1.end(),0)/y_ne1.size();
            
            liz_s2 = std::accumulate(z_po2.end()-5,z_po2.end(),0)/z_po2.size();
            lix_po_s2 = std::accumulate(x_po2.end()-5,x_po2.end(),0)/x_po2.size();
            lix_ne_s2 = std::accumulate(x_ne2.end()-5,x_ne2.end(),0)/x_ne2.size();
            liy_po_s2 = std::accumulate(y_po2.end()-5,y_po2.end(),0)/y_po2.size();
            liy_ne_s2 = std::accumulate(y_ne2.end()-5,y_ne2.end(),0)/y_ne2.size();

            liz_s3 = std::accumulate(z_li_s3.end()-5,z_li_s3.end(),0)/z_li_s3.size();
            lix_s3 = std::accumulate(x_li_s3.end()-5,x_li_s3.end(),0)/x_li_s3.size();
            liy_s3 = std::accumulate(y_li_s3.end()-5,y_li_s3.end(),0)/y_li_s3.size();
       
            liz_s4 = std::accumulate(z_li_s4.end()-5,z_li_s4.end(),0)/z_li_s4.size();
            lix_s4 = std::accumulate(x_li_s4.end()-5,x_li_s4.end(),0)/x_li_s4.size();
            liy_s4 = std::accumulate(y_li_s4.end()-5,y_li_s4.end(),0)/y_li_s4.size();
       
            liz_s5 = std::accumulate(z_li_s5.end()-5,z_li_s5.end(),0)/z_li_s5.size();
            lix_s5 = std::accumulate(x_li_s5.end()-5,x_li_s5.end(),0)/x_li_s5.size();
            liy_s5 = std::accumulate(y_li_s5.end()-5,y_li_s5.end(),0)/y_li_s5.size();
       
            liz_s6 = std::accumulate(z_li_s6.end()-5,z_li_s6.end(),0)/z_li_s6.size();
            lix_s6 = std::accumulate(x_li_s6.end()-5,x_li_s6.end(),0)/x_li_s6.size();
            liy_s6 = std::accumulate(y_li_s6.end()-5,y_li_s6.end(),0)/y_li_s6.size();
       
            liz_s7 = std::accumulate(z_li_s7.end()-5,z_li_s7.end(),0)/z_li_s7.size();
            lix_s7 = std::accumulate(x_li_s7.end()-5,x_li_s7.end(),0)/x_li_s7.size();
            liy_s7 = std::accumulate(y_li_s7.end()-5,y_li_s7.end(),0)/y_li_s7.size();
            
            float y_int1 = liy_po_s1- liy_ne_s1;
            float z_int1 = liz_s1;

            float x_int1;
            if (lix_ne_s1<0)
                x_int1 = lix_ne_s1;
            else
                x_int1 =  lix_po_s1;

            float y_int2 = liy_po_s2-liy_ne_s2;
            float x_int2 = lix_po_s2-lix_ne_s2;
            float z_int2 = liz_s2;
            
            //%%%% sensor 1 Final calibration 
            fz_s1 = 0.0027052*pow(z_int1,4)-0.011676*pow(z_int1,3)-0.010948*pow(z_int1,2) +0.71242*z_int1 -0.004521 - std::accumulate(fz_s1f.begin(),fz_s1f.end(),0)/fz_s1f.size();
            fy_s1 = 0.095471*y_int1- std::accumulate(fy_s1f.begin(),fy_s1f.end(),0)/fy_s1f.size();
            fx_s1 =  0.26765*x_int1- std::accumulate(fx_s1f.begin(),fx_s1f.end(),0)/fx_s1f.size();

            //%%%% sensor 2 Final calibration
            fz_s2 = 0.64248 * z_int2 - std::accumulate(fz_s2f.begin(),fz_s2f.end(),0)/fz_s2f.size();
            fy_s2 = 0.15159 * y_int2 - std::accumulate(fy_s2f.begin(),fy_s2f.end(),0)/fy_s2f.size();
            fx_s2 = 0.13342 * x_int2 - std::accumulate(fx_s2f.begin(),fx_s2f.end(),0)/fx_s2f.size();

            //%%%% sensor 3 Final calibration
            fz_s3 = -0.011222 * pow(liz_s3, 3) + -0.043049 * pow(liz_s3, 2) - 0.93763 * liz_s3 + 0.0071904 - std::accumulate(fz_s3f.begin(),fz_s3f.end(),0)/fz_s3f.size();
            fy_s3 = 3.8712e-05 * pow(liy_s3, 3) + -0.0028025 * pow(liy_s3, 2) + 0.16335 * liy_s3 - 0.16775- std::accumulate(fy_s3f.begin(),fy_s3f.end(),0)/fy_s3f.size();
            fx_s3 = 1.8035e-05 * pow(lix_s3, 3) - 0.0023924 * pow(lix_s3, 2) + 0.26868 * lix_s3 + 0.04158- std::accumulate(fx_s3f.begin(),fx_s3f.end(),0)/fx_s3f.size();

            //%%%% sensor4 Final calibration
            fz_s4 = -0.011222 * pow(liz_s4, 3) + -0.043049 * pow(liz_s4, 2) - 0.93763 * liz_s4 + 0.0071904 - std::accumulate(fz_s4f.begin(),fz_s4f.end(),0)/fz_s4f.size();
            fy_s4 = -2.5286e-05 * pow(liy_s4, 4) + -0.0015057 * pow(liy_s4, 3) + -0.026599 * pow(liy_s4, 2) + 0.075347 * liy_s4 + 0.021047- std::accumulate(fy_s4f.begin(),fy_s4f.end(),0)/fy_s4f.size();
            fx_s4 = -0.00017878 * pow(lix_s4, 3) - 0.0079705 * pow(lix_s4, 2) - 0.3129 * lix_s4 - 0.67847- std::accumulate(fx_s4f.begin(),fx_s4f.end(),0)/fx_s4f.size();

            //%%%% sensor5 Final calibration
            fz_s5 = -0.0044725 * pow(liz_s5, 3) - 0.047633 * pow(liz_s5, 2) - 0.46121 * liz_s5 + 0.73707- std::accumulate(fz_s5f.begin(),fz_s5f.end(),0)/fz_s5f.size();
            fy_s5 = -1.0017e-12 * pow(liy_s5, 10) + 8.9623e-11 * pow(liy_s5, 9) + -1.9142e-09 * pow(liy_s5, 8) + -4.0429e-08 * pow(liy_s5, 7) + 1.8078e-06 * pow(liy_s5, 6) + -4.7217e-06 * pow(liy_s5, 5) + -0.00042256 * pow(liy_s5, 4) + 0.0030408 * pow(liy_s5, 3) + 0.043865 * pow(liy_s5, 2) + -0.7219 * liy_s5- std::accumulate(fy_s5f.begin(),fy_s5f.end(),0)/fy_s5f.size();
            fx_s5 = 0.011346 * pow(lix_s5, 3) + 0.16438 * pow(lix_s5, 2) + 0.98549 * lix_s5 + 0.017546- std::accumulate(fx_s5f.begin(),fx_s5f.end(),0)/fx_s5f.size();

            //%%%% sensor6 Final calibration
            fz_s6 = 0.00022378 * pow(liz_s6, 4) + -0.0061643 * pow(liz_s6, 3) + 0.034503 * pow(liz_s6, 2) + 0.48075 * liz_s6 + 0.048943- std::accumulate(fz_s6f.begin(),fz_s6f.end(),0)/fz_s6f.size();
            fy_s6 = 5.0291e-05 * pow(liy_s6, 3) - 0.00078962 * pow(liy_s6, 2) + 0.15164 * liy_s6 + 0.0049077- std::accumulate(fy_s6f.begin(),fy_s6f.end(),0)/fy_s6f.size();
            fx_s6 = -2.3331e-06 * pow(lix_s6, 4) + -6.2271e-05 * pow(lix_s6, 3) + 0.0022352 * pow(lix_s6, 2) + 0.30789 * lix_s6 + 0.42283- std::accumulate(fx_s6f.begin(),fx_s6f.end(),0)/fx_s6f.size();

            //%%% sensor7 Final calibration
            fz_s7 = -0.0017082 * pow(liz_s7, 3) - 0.033597 * pow(liz_s7, 2) - 0.49547 * liz_s7 - 0.030753- std::accumulate(fz_s7f.begin(),fz_s7f.end(),0)/fz_s7f.size();
            fy_s7 = 7.939e-07 * pow(liy_s7, 4) + -1.6693e-05 * pow(liy_s7, 3) - 0.0038142 * pow(liy_s7, 2) + -0.20008 * liy_s7 + 0.096795- std::accumulate(fy_s7f.begin(),fy_s7f.end(),0)/fy_s7f.size();
            fx_s7 = 0.0006545 * pow(lix_s7, 3) - 0.026066 * pow(lix_s7, 2) + 0.52242 * lix_s7 + 0.032173- std::accumulate(fx_s7f.begin(),fx_s7f.end(),0)/fx_s7f.size();
        
        }
        
        if(frame_num<=21)
            frame_num++;

        if(frame_num==22)
        {   
            std::vector<float> f_xyz;
            f_xyz.push_back(fx_s1);
            f_xyz.push_back(fy_s1);
            f_xyz.push_back(fz_s1);
            f_xyz.push_back(fx_s2);
            f_xyz.push_back(fy_s2);
            f_xyz.push_back(fz_s2);
            f_xyz.push_back(fx_s3);
            f_xyz.push_back(fy_s3);
            f_xyz.push_back(fz_s3);
            f_xyz.push_back(fx_s4);
            f_xyz.push_back(fy_s4);
            f_xyz.push_back(fz_s4);
            f_xyz.push_back(fx_s5);
            f_xyz.push_back(fy_s5);
            f_xyz.push_back(fz_s5);
            f_xyz.push_back(fx_s6);
            f_xyz.push_back(fy_s6);
            f_xyz.push_back(fz_s6);
            f_xyz.push_back(fx_s7);
            f_xyz.push_back(fy_s7);
            f_xyz.push_back(fz_s7);
            Force_xyz.push_back(f_xyz);
            
            std::vector<float> f_res;
            float f_res_s1 = sqrt(pow(fx_s1,2) + pow(fy_s1,2) + pow(fz_s1,2));
            float f_res_s2 = sqrt(pow(fx_s2,2) + pow(fy_s2,2) + pow(fz_s2,2));
            float f_res_s3 = sqrt(pow(fx_s3,2) + pow(fy_s3,2) + pow(fz_s3,2));
            float f_res_s4 = sqrt(pow(fx_s4,2) + pow(fy_s4,2) + pow(fz_s4,2));
            float f_res_s5 = sqrt(pow(fx_s5,2) + pow(fy_s5,2) + pow(fz_s5,2));
            float f_res_s6 = sqrt(pow(fx_s6,2) + pow(fy_s6,2) + pow(fz_s6,2));
            float f_res_s7 = sqrt(pow(fx_s7,2) + pow(fy_s7,2) + pow(fz_s7,2));
            f_res.push_back(f_res_s1);
            f_res.push_back(f_res_s2);
            f_res.push_back(f_res_s3);
            f_res.push_back(f_res_s4);
            f_res.push_back(f_res_s5);
            f_res.push_back(f_res_s6);
            f_res.push_back(f_res_s7);
            Force_res.push_back(f_res);
            for(int n =0;n<Force_xyz.size();n++)
            {
                for(int j=0;j<Force_xyz[n].size();j++)
                std::cout<<"("<<n<<" "<<j<<")"<<Force_xyz[n][j]<<std::endl;
            }
        }
        
        if(y_po1.size()>5)
        {
            y_po1.erase(y_po1.begin());
            y_ne1.erase(y_ne1.begin());
            x_po1.erase(x_po1.begin());
            x_ne1.erase(x_ne1.begin());
            z_po1.erase(z_po1.begin());

            y_po2.erase(y_po2.begin());
            y_ne2.erase(y_ne2.begin());
            x_po2.erase(x_po2.begin());
            x_ne2.erase(x_ne2.begin());
            z_po2.erase(z_po2.begin());

            z_li_s3.erase(z_li_s3.begin());
            y_li_s3.erase(y_li_s3.begin());
            x_li_s3.erase(x_li_s3.begin());

            z_li_s4.erase(z_li_s4.begin());
            y_li_s4.erase(y_li_s4.begin());
            x_li_s4.erase(x_li_s4.begin());

            z_li_s5.erase(z_li_s5.begin());
            y_li_s5.erase(y_li_s5.begin());
            x_li_s5.erase(x_li_s5.begin());

            z_li_s6.erase(z_li_s6.begin());
            y_li_s6.erase(y_li_s6.begin());
            x_li_s6.erase(x_li_s6.begin());

            z_li_s7.erase(z_li_s7.begin());
            y_li_s7.erase(y_li_s7.begin());
            x_li_s7.erase(x_li_s7.begin());
        }
        if(Force_xyz.size()>50){
            Force_xyz.erase(Force_xyz.begin());
        }
        if(Force_res.size()>50){
            Force_res.erase(Force_res.begin());
        }
    }

    return 0;
}
