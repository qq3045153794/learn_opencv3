#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "args err" << std::endl;
    std::cout << "example : ./ex <file>" << std::endl;
  }
  auto src = cv::imread(argv[1]);

  cv::Mat blur_dst, median_dst;

  cv::blur(src, blur_dst, cv::Size(5, 5));
  cv::medianBlur(src, median_dst, 5);

  cv::imshow("src", src);
  cv::imshow("blur", blur_dst);
  cv::imshow("median", median_dst);

  cv::waitKey(0);
  return 0;
}
