#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>
#include <fstream>
#include <sstream>
#include <unistd.h>


using namespace std;
using namespace cv;





int main() {


    string nazwa;
    cout << "Podaj nazwe pliku z foldeu images: ";
    cin >> nazwa;



    string pathF = "../images/"+nazwa;
    Mat img = imread(pathF);

    cvtColor(img, img, COLOR_BGR2GRAY);
    //    GaussianBlur(img2,img2, Size(7, 7), 7, 0);

    imshow("x",img);
    waitKey();


    string txtpathBig = "../results/"+nazwa+"_ASCII_BIG.txt";
    ofstream big(txtpathBig);
    for(int j=1; j+1<img.size().height; j+=2)
    {
        string text = "";
        for(int i=1; i+1<img.size().width; i+=2)
        {
            int sum = 0;

            sum+= (int)img.at<uchar>(j,i);
            sum+= (int)img.at<uchar>(j,i+1);
            sum+= (int)img.at<uchar>(j,i-1);

            sum+= (int)img.at<uchar>(j-1,i);
            sum+= (int)img.at<uchar>(j-1,i+1);
            sum+= (int)img.at<uchar>(j-1,i-1);

            sum+= (int)img.at<uchar>(j+1,i);
            sum+= (int)img.at<uchar>(j+1,i+1);
            sum+= (int)img.at<uchar>(j+1,i-1);
            sum/=9;


            if(sum>238) text+='@';
            else if(sum>221) text+='#';
            else if(sum>204) text+='&';
            else if(sum>187) text+='0';
            else if(sum>170) text+='O';
            else if(sum>153) text+='U';
            else if(sum>136) text+='*';
            else if(sum>119) text+='o';
            else if(sum>102) text+='+';
            else if(sum>85) text+='-';
            else if(sum>68) text+='"';
            else if(sum>51) text+="'";
            else if(sum>34) text+=',';
            else if(sum>17) text+='.';
            else text+=' ';
        }
        big << text << endl;


    }




    ofstream small("../results/"+nazwa+"_ascii_small.txt");

    for(int j=4; j+4<img.size().height; j+=8)
    {
        string text="";
        for(int i=4; i+4<img.size().width; i+=8)
        {
            int sum = 0;

            for(int k = -1; k<2 ; k++){
                for(int l=-1; l<2; l++)
                {
                    sum+= (int)img.at<uchar>(j+l*3,i+k*3);
                    sum+= (int)img.at<uchar>(j+l*3,i+1+k*3);
                    sum+= (int)img.at<uchar>(j+l*3,i-1+k*3);

                    sum+= (int)img.at<uchar>(j-1+l*3,i+k*3);
                    sum+= (int)img.at<uchar>(j-1+l*3,i+1+k*3);
                    sum+= (int)img.at<uchar>(j-1+l*3,i-1+k*3);

                    sum+= (int)img.at<uchar>(j+1+l*3,i+k*3);
                    sum+= (int)img.at<uchar>(j+1+l*3,i+1+k*3);
                    sum+= (int)img.at<uchar>(j+1+l*3,i-1+k*3);
                }

            }
            sum/=81;

            if(sum>238) text+='@';
            else if(sum>221) text+='#';
            else if(sum>204) text+='&';
            else if(sum>187) text+='0';
            else if(sum>170) text+='O';
            else if(sum>153) text+='U';
            else if(sum>136) text+='*';
            else if(sum>119) text+='o';
            else if(sum>102) text+='+';
            else if(sum>85) text+='-';
            else if(sum>68) text+='"';
            else if(sum>51) text+="'";
            else if(sum>34) text+=',';
            else if(sum>17) text+='.';
            else text+=' ';
        }
        small << text << endl;

    }
    return 0;

}

