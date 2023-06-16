#pragma once
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int FaceCap()
{
    double scale = 4.0;

    CascadeClassifier faceCascade;
    faceCascade.load("haarcascade_frontalface_alt.xml");

    VideoCapture cap(0);
    if (!cap.isOpened())
        return -1;

    //Delay 5 seconds to capture the frame
    cout << endl << "Waiting for 2 seconds..." << endl;
    waitKey(2000);

    Mat frame;
    cap >> frame;

    //Convert to black and white to detect face
    Mat grayscale;
    cvtColor(frame, grayscale, COLOR_BGR2GRAY);
    resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));

    //Detect faces
    std::vector<cv::Rect> faces; //ambiguity error ki wajah se cv:: and std::
    faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, Size(30, 30));

    //rectangle
    for (cv::Rect area : faces)
    {
        Scalar drawcolor = Scalar(255, 0, 0);
        rectangle(frame, Point(cvRound(area.x * scale), cvRound(area.y * scale)),
            Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)), drawcolor);
    }

    //Filestore
    std::time_t t = std::time(nullptr);
    std::tm now;
    localtime_s(&now, &t);
    char filename[100];
    std::strftime(filename, sizeof(filename), "%Y%m%d%H%M%S.jpg", &now);

    //Save Image
    std::string filepath = std::string(filename);
    imwrite(filepath, frame);

    //Show the saved file path
    cout << "Image saved: " << filepath << endl;

    return 0;
}