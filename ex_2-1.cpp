// 显示图片
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "err argc" << std::endl;
    return -1;
  }

  // 更具文件名决定载入图像的格式，包括：BMP, JPG, PNG, JPEG等
  cv::Mat img = cv::imread(argv[1], -1);
  if (img.empty()) {
    std::cerr << "err img" << std::endl;
  }

  // 该函数右highgui模块提供 创建一个窗口
  cv::namedWindow("ex_2-1", cv::WINDOW_AUTOSIZE);

  // 显示图像， 如果窗口不存在 自动调用cv::namedWindow创建
  cv::imshow("ex_2-1", img);

  // 等待键盘响应，如果传入的值大零则为响应时间，否则无限响应下去
  cv::waitKey(0);

  // 销毁窗口防止内存泄漏
  cv::destroyWindow("ex_2-1");

  // cv::Mat类符合RAII 出作用域自动销毁
}
