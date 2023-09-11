#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  cv::Mat img_rgb, img_gry, img_cny;

  img_rgb = cv::imread(argv[1]);

  cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
  cv::imshow("ex gray", img_gry);

  cv::Canny(img_gry, img_cny, 10, 100, 3, true);
  cv::imshow("ex canny", img_cny);

  cv::waitKey(0);

  return 0;
}
