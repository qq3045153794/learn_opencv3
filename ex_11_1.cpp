#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc_c.h>
int main (int argc, char** argv) {
  if (argc < 2) {
    std::cout << "err argc" << std::endl;
    return -1;
  }

  cv::Mat src = cv::imread(argv[1]);
  if (src.empty()) {
    std::cout << "faided open image" << std::endl;
    return -1;
  }

  cv::Point2f src_tri[] = {
    cv::Point2f(0.F, 0.F),
    cv::Point2f(src.cols - 1.F, 0.F),
    cv::Point2f(0.F, src.rows - 1.F)
  };

  cv::Point2f dst_tri[] = {
    cv::Point2f(src.cols * 0.F, src.rows * 0.33F),
    cv::Point2f(src.cols * 0.85F, src.rows * 0.25F),
    cv::Point2f(src.cols * 0.15F, src.rows * 0.7F)
  };

  cv::Mat warp_mat = cv::getAffineTransform(src_tri, dst_tri);
  cv::Mat dst, dst2;
  cv::warpAffine(src, dst, warp_mat, src.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar());
  for (int i = 0; i < 3; i++) {
    cv::circle(dst, dst_tri[i], 5, cv::Scalar(255, 0, 255), -1, CV_AA);
  }
  cv::imshow("affine", dst);
  cv::waitKey();
}
