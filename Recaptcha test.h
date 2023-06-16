#pragma once
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;

/*----------------------------------------------Global Variables----------------------------------------------*/
bool buttonClicked = false;
bool Called = false;
bool b2 = false;
bool b1 = false;
/*----------------------------------------------Global Variables----------------------------------------------*/

/*----------------------------------------------MousePosition----------------------------------------------*/
void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        cv::Rect* buttonRect = static_cast<cv::Rect*>(userdata);
        if (buttonRect->contains(cv::Point(x, y)))
        {
            buttonClicked = true;
        }
    }
}
/*----------------------------------------------MousePosition----------------------------------------------*/

void buttonPressed()
{
    Called = true;
}

int recaptcha()
{
    double scale = 4.0;

    cv::CascadeClassifier faceCascade;
    faceCascade.load("haarcascade_frontalface_alt.xml");

    cv::VideoCapture cap(0);
    if (!cap.isOpened())
        return -1;

    /*----------------------------------------------WindowRender----------------------------------------------*/

    cv::namedWindow("Webcam frame", cv::WINDOW_NORMAL);

    /*----------------------------------------------WindowRender----------------------------------------------*/

    for (;;)
    {
        /*---------------------------------------------Capture Video----------------------------------------------*/

        cv::Mat frame;
        cap >> frame;

        /*---------------------------------------------Capture Video----------------------------------------------*/

        /*---------------------------------------------Convert to Black and White----------------------------------------------*/

        cv::Mat grayscale;
        cv::cvtColor(frame, grayscale, cv::COLOR_BGR2GRAY);
        cv::resize(grayscale, grayscale, cv::Size(grayscale.size().width / scale, grayscale.size().height / scale));

        /*---------------------------------------------Convert to Black and White----------------------------------------------*/

      /*--------------------------------------------Detect Faces----------------------------------------------*/
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, cv::Size(30, 30));

        /*--------------------------------------------Detect Faces----------------------------------------------*/

        /*--------------------------------------------Draw Rectangle----------------------------------------------*/
        for (cv::Rect area : faces)
        {
            cv::Scalar drawColor(255, 0, 0);
            cv::rectangle(frame, cv::Point(cvRound(area.x * scale), cvRound(area.y * scale)),
                cv::Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)), drawColor);

            int buttonWidth = area.width;
            int buttonHeight = 30;
            int buttonX = area.x;
            int buttonY = area.y + area.height + 10;
            cv::Rect buttonRect(buttonX, buttonY, buttonWidth, buttonHeight);
            cv::rectangle(frame, buttonRect, drawColor, cv::FILLED);
            cv::putText(frame, "Verified. Click Me", cv::Point(buttonX + 10, buttonY + 20), cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 255, 255), 2);

            cv::setMouseCallback("Webcam frame", onMouse, &buttonRect);
        }
        /*--------------------------------------------Draw Rectangle----------------------------------------------*/

        /*--------------------------------------------Show Video----------------------------------------------*/
        cv::imshow("Webcam frame", frame);

        if (buttonClicked)
        {
            buttonPressed();
            buttonClicked = false;
        }

        /*--------------------------------------------Show Video----------------------------------------------*/

        if (Called)
        {
            cv::destroyAllWindows();
            cap.release();
            break;
        }

        /*--------------------------------------------PressKey To Exitt----------------------------------------------*/
        if (cv::waitKey(30) >= 0)
            break;

        /*--------------------------------------------PressKey To Exitt----------------------------------------------*/
    }
    /*-------------------------------------------Conditions to call Functions----------------------------------------------*/
    if (b1)
    {
        b1 = false;
        admin();
    }

    if (b2)
    {
        b2 = false;
        FacSignup();
    }
    /*-------------------------------------------Conditions to call Functions----------------------------------------------*/
    return 0;
}