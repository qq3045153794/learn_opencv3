#include <iostream>
#include <opencv2/opencv.hpp>

void example2_5(const cv::Mat& image) {
  cv::namedWindow("ex2_5-in", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("ex2_5-out", cv::WINDOW_AUTOSIZE);

  cv::imshow("ex2_5-in", image);

  cv::Mat out;
  cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
  cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);
  cv::imshow("ex2_5-out", out);

  cv::waitKey(0);
}

int main (int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "invalid arg" << std::endl;
    return -1;
  }

  auto img = cv::imread(argv[1], cv::IMREAD_COLOR);
  example2_5(img);
}
