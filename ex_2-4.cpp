#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>

static int g_slider_position = 0;
static int g_run = 1;
static int g_dontset = 0;
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void*) {
  g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
  if (!g_dontset) {
    g_run = 1;
  }
  g_dontset = 0;
}

int main(int argc, char** argv) {
  cv::namedWindow("ex2_4", cv::WINDOW_AUTOSIZE);
  g_cap.open(std::string(argv[1]));
  int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
  int tmpw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
  int tmph = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
  std::cout << "video has" << frames << " frames of dimensitions(" << tmpw << " " << tmph << ")." << std::endl;
  cv::createTrackbar("Position", "ex2_4", &g_slider_position, frames, onTrackbarSlide);
  cv::Mat frame;
  for (;;) {
    if (g_run != 0) {
      g_cap >> frame;
      if (frame.empty()) {
        break;
      }
      int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
      g_dontset = 1;
      cv::setTrackbarPos("Position", "ex2_4", current_pos);
      cv::imshow("ex2_4", frame);
      g_run--;
    }
    char c = (char) cv::waitKey(10);
    if (c == 's') {
      g_run = 1;
      std::cout << "single step run = " << g_run << std::endl;
    }

    if (c == 'r') {
      g_run = -1;
      std::cout << "Run mode , run = " << g_run << std::endl;
    }

    if (c == 27) {
       break;
    }
  }
  return 0;
}
