#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;

int main(){
 Mat image, roi;
 Rect crop;
 int rows = 40, columns = 40;
 image = imread("img.jpg");
 int sizeX = image.size().height; //tinggi image sing diload
 int sizeY = image.size().width; //lebar image sing diload
 
 for (int i = 0; i < rows; i++){
  for (int j = 0; j < columns; j++){
   crop.x = j*sizeX/columns;
   crop.y = i*sizeY/rows;
   crop.width = sizeX/columns;
   crop.height = sizeY/rows;
   roi = image(crop);
   std::stringstream printImage;
   printImage << "path/"<< i << "_" << j << "_.jpg";
   imwrite(printImage.str(), roi);
  }
 }
 return 0;
}
