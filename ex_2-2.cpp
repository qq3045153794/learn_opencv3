#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "err argc" << std::endl;
    return -1;
  }
  cv::namedWindow("ex2-2", cv::WINDOW_AUTOSIZE);
  cv::VideoCapture cp;
  cp.open(argv[1]);
  cv::Mat frame;
  for(;;) {
    cp >> frame;
    cv::imshow("ex2-2", frame);
    if (cv::waitKey(33) > 0) {
      break;
    }
  }
  cv::destroyWindow("ex2-2");
  return 0;
}
