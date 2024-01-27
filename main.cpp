#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>
#include <fstream>
#include <sstream>
#include <unistd.h>


using namespace std;
using namespace cv;





int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Użycie: " << argv[0] << " <nazwa_pliku.png>" << endl;
        return 1;
    }

//    char cwd[PATH_MAX];
//
//    if (getcwd(cwd, sizeof(cwd)) != NULL) {
//        std::cout << "Current working directory: " << cwd << std::endl;
//    } else {
//        perror("getcwd() error");
//        return 1;
//    }
//    return 0;




    string pathF = "/images/"+(string)argv[1];
    Mat img = imread(pathF);

    cvtColor(img, img, COLOR_BGR2GRAY);
    //    GaussianBlur(img2,img2, Size(7, 7), 7, 0);

    imshow("x",img);
    waitKey();


    string txtpathBig = "/Users/marcin/CLionProjects/IMG_to_ASCII/results/ASCII_BIG_"+(string)argv[1]+".txt";
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


            if(sum>241) text+='@';
            else if(sum>224) text+='#';
            else if(sum>207) text+='&';
            else if(sum>190) text+='0';
            else if(sum>173) text+='O';
            else if(sum>156) text+='U';
            else if(sum>139) text+='*';
            else if(sum>122) text+='o';
            else if(sum>105) text+='+';
            else if(sum>88) text+='-';
            else if(sum>71) text+='"';
            else if(sum>54) text+="'";
            else if(sum>37) text+=',';
            else if(sum>20) text+='.';
            else text+=' ';
        }
        big << text << endl;


    }




    ofstream small("/Users/marcin/CLionProjects/IMG_to_ASCII/results/ASCII_SMALL_"+(string)argv[1]+".txt");

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

            if(sum>241) text+='@';
            else if(sum>224) text+='#';
            else if(sum>207) text+='&';
            else if(sum>190) text+='0';
            else if(sum>173) text+='O';
            else if(sum>156) text+='U';
            else if(sum>139) text+='*';
            else if(sum>122) text+='o';
            else if(sum>105) text+='+';
            else if(sum>88) text+='-';
            else if(sum>71) text+='"';
            else if(sum>54) text+="'";
            else if(sum>37) text+=',';
            else if(sum>20) text+='.';
            else text+=' ';
        }
        small << text << endl;

    }
    return 0;

}

