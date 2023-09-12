#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
int g_switch_value = 1;
void swtich_off() {
  std::cout << "pause" << std::endl;
}
void switch_on() {
  std::cout << "run" << std::endl;
}
void swtich_callback(int position, void*) {
  if (position == 0) {
    swtich_off();
  } else {
    switch_on();
  }
}
int main(int argc, char** argv) {
  cv::Mat frame;
  cv::VideoCapture cap;
  if (argc < 2 || !cap.open(argv[1])) {
    std::cerr << "argv or oepn faild" << std::endl;
  }

  cv::namedWindow("ex", cv::WINDOW_AUTOSIZE);

  // 滑块在窗口上方
  // param 1 : 滑块名
  // param 2 : 窗口名
  // 滑块值
  // 滑块最大值
  // 当滑块变化时的回调函数
  cv::createTrackbar("swtich", "ex", &g_switch_value, 1, swtich_callback);

  for (;;) {
    if (g_switch_value) {
      cap >> frame;
      if (frame.empty()) {
        break;
      }
      cv::imshow("ex", frame);
    }
    if (cv::waitKey(10) == 27) {
      break;
    }
  }
}
