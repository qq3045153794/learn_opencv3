#include <iostream>
#include <opencv2/opencv.hpp>

int main (int argc, char** argv) {
  cv::namedWindow("ex2-8", cv::WINDOW_AUTOSIZE);

  cv::VideoCapture cap;
  if (argc ==1) {
    cap.open(0);
  } else {
    cap.open(argv[1]);
  }

  if (!cap.isOpened()) {
    std::cerr << "open faid" << std::endl;
    return -1;
  }

  cv::Mat frame;
  for (;;) {
    cap >> frame;
    cv::imshow("ex2-8", frame);
    if(cv::waitKey(40) > 0) {
      break;
    }
  }
}
