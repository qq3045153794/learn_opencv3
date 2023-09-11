#include <iostream>
#include <opencv2/opencv.hpp>

int main (int argc, char** argv) {
  cv::namedWindow("ex2_11", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("log_polar", cv::WINDOW_AUTOSIZE);

  cv::VideoCapture capture(argv[1]);

  double fps = capture.get(cv::CAP_PROP_FPS);

  cv::Size size(
    capture.get(cv::CAP_PROP_FRAME_WIDTH),
    capture.get(cv::CAP_PROP_FRAME_HEIGHT)
  );

  cv::VideoWriter writer;
  writer.open(argv[2], cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

  cv::Mat logpolar_frame, bgr_frame;
  for(;;) {
    capture >> bgr_frame;
    if(bgr_frame.empty()) {
      break;
    }
    cv::imshow("ex2_11", bgr_frame);
    cv::logPolar(
      bgr_frame,
      logpolar_frame,
      cv::Point2f(bgr_frame.cols / 2, bgr_frame.rows / 2),
      40,
      cv::WARP_FILL_OUTLIERS);
    cv::imshow("log_polar", logpolar_frame);
    writer << logpolar_frame;
    char c = cv::waitKey(10);
    if (c == 27) {
      break;
    }
  }
  capture.release();
}
