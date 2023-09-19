#include <iostream>
#include <opencv2/opencv.hpp>

void sum_rgb(const cv::Mat& src, cv::Mat& dst) {
  std::vector<cv::Mat> planes;

  cv::split(src, planes);

  cv::Mat b = planes[0], g = planes[1], r = planes[2], s;

  cv::addWeighted(r, 1.F / 3.F, g, 1.F / 3.F, 0.F, s);
  cv::addWeighted(s, 1.F, b, 1.F / 3.F, 0.F, s);
  cv::threshold(s, dst, 100, 100, cv::THRESH_TRUNC);
}

int main(int argc, char** argv) {
  if (argc < 2 ) {
    std::cout << "specify input image" << std::endl;
  }

  cv::Mat src = cv::imread(argv[1]), dst;

  if (src.empty()) {
    std::cerr << "open image faided" << std::endl;
  }

  sum_rgb(src, dst);
  cv::imshow(argv[1], dst);

  cv::waitKey(0);

  return 0;
}
