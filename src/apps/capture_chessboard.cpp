#include <features/features.h>
#include <features/orb_features.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace features;
using namespace cv;

std::string IMAGES_DIR = TEST_IMAGES_DIR;

int main(int argc, char* args[]) {
  cv::VideoCapture cam1(1);
  cam1.set(CV_CAP_PROP_FRAME_WIDTH, 640);
  cam1.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

  cv::VideoCapture cam2(2);
  cam2.set(CV_CAP_PROP_FRAME_WIDTH, 640);
  cam2.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
  for(int i = 0; i < 10; i++) {
    cv::Mat temp1, temp2;
    cam1 >> temp1;
    cam2 >> temp2;
  }

  for(int i = -5; i < 10; i++) {
    /*
    for(int t = 2; t >= 0; t--) {
      cout << t << "..." << std::flush;
      this_thread::sleep_for(chrono::milliseconds(500));
    }
    */
    cv::waitKey(1000);

    cv::Mat frame1;
    cv::Mat frame2;
    cam1 >> frame1;
    cam2 >> frame2;
    if(i < 0) continue;
    cv::imwrite(cv::format("left_%d.jpg", i), frame1);
    cv::imwrite(cv::format("right_%d.jpg", i), frame2);
    cout << "captured" << endl;
  }
}
