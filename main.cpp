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
    string fileName;
    cout << "Podaj nazwe pliku z folderu images:  ";
    cin >> fileName;

    string pathF = "../images/" + fileName;
    Mat img = imread(pathF);
//    resize(img, img, Size(),0.5,0.5);

    cvtColor(img, img, COLOR_BGR2GRAY);
    //    GaussianBlur(img2,img2, Size(7, 7), 7, 0);


//    imshow("x",img);
//    waitKey();


    string ASCII1 = " .,'\"-+o*UO0&#@"; //15 znakow
    string ASCII2 = " _.,-=+:;cba!?0123456789$W#@"; //28 znakow


    string file_path_ASCII_1_big = "../results/" + fileName + "_ASCII_BIG_1.txt";
    ofstream ASCII1big(file_path_ASCII_1_big);

    string file_path_ASCII_2_big = "../results/" + fileName + "_ASCII_BIG_2.txt";
    ofstream ASCII2big(file_path_ASCII_2_big);
    for(int j=1; j+1<img.size().height; j+=2)
    {
        string ASCII1text = "";
        string ASCII2text = "";
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

            ASCII1text+= ASCII1[(sum-5)/17];
            ASCII2text+= ASCII2[(sum-10)/9];

        }
        ASCII1big << ASCII1text << endl;
        ASCII2big << ASCII2text << endl;

    }




    string file_path_ASCII_1_small = "../results/" + fileName + "_ascii_small_1.txt";
    ofstream ASCII1small(file_path_ASCII_1_small);

    string file_path_ASCII_2_small = "../results/" + fileName + "_ascii_small_2.txt";
    ofstream ASCII2small(file_path_ASCII_2_small);

    for(int j=4; j+4<img.size().height; j+=8)
    {
        string ASCII1text = "";
        string ASCII2text = "";


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


            ASCII1text+= ASCII1[(sum-5)/17];
            ASCII2text+= ASCII2[(sum-10)/9];

        }
        ASCII1small << ASCII1text << endl;
        ASCII2small << ASCII2text << endl;

    }

    cout << "Twoje pliki znajdują się w folderze results." << endl;
    cout << "Polecam oddalić dla lepszego efektu!" << endl;

    return 0;
}

