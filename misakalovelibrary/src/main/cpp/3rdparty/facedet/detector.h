///*
// * detector.h using google-style
// *
// *  Created on: May 24, 2016
// *      Author: Tzutalin
// *
// *  Copyright (c) 2016 Tzutalin. All rights reserved.
// */
//
//#pragma once
//
//#include <dlib/image_loader/load_image.h>
//#include <dlib/image_processing.h>
//#include <dlib/image_processing/frontal_face_detector.h>
//#include <dlib/image_processing/render_face_detections.h>
//#include <dlib/opencv/cv_image.h>
//#include <dlib/image_loader/load_image.h>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/opencv.hpp>
//#include <jni.h>
//#include <memory>
//#include <stdio.h>
//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <jni_utils/jni_utils.h>
//
//using namespace jniutils;
//
//#define LOG_TAG "DLibHOGDetector"
//
//class DLibHOGDetector {
//private:
//    typedef dlib::scan_fhog_pyramid<dlib::pyramid_down<6>> image_scanner_type;
//    dlib::object_detector<image_scanner_type> mObjectDetector;
//
//    inline void init() {
//        LOGI("Model Path: %s", mModelPath.c_str());
//        if (jniutils::fileExists(mModelPath)) {
//            dlib::deserialize(mModelPath) >> mObjectDetector;
//        } else {
//            LOGI("Not exist : %s", mModelPath.c_str());
//        }
//    }
//
//public:
//    DLibHOGDetector(const std::string &modelPath = "/sdcard/person.svm")
//            : mModelPath(modelPath) {
//        init();
//    }
//
//    virtual inline int det(const std::string &path) {
//        using namespace jniutils;
//        if (!fileExists(mModelPath) || !fileExists(path)) {
//            LOGW("No modle path or input file path");
//            return 0;
//        }
//        cv::Mat src_img = cv::imread(path, CV_LOAD_IMAGE_COLOR);
//        if (src_img.empty())
//            return 0;
//        int img_width = src_img.cols;
//        int img_height = src_img.rows;
//        int im_size_min = MIN(img_width, img_height);
//        int im_size_max = MAX(img_width, img_height);
//
//        float scale = float(INPUT_IMG_MIN_SIZE) / float(im_size_min);
//        if (scale * im_size_max > INPUT_IMG_MAX_SIZE) {
//            scale = (float) INPUT_IMG_MAX_SIZE / (float) im_size_max;
//        }
//
//        if (scale != 1.0) {
//            cv::Mat outputMat;
//            cv::resize(src_img, outputMat,
//                       cv::Size(img_width * scale, img_height * scale));
//            src_img = outputMat;
//        }
//
//         cv::resize(src_img, src_img, cv::Size(320, 240));
//        dlib::cv_image<dlib::bgr_pixel> cimg(src_img);
//
//        double thresh = 0.5;
//        mRets = mObjectDetector(cimg, thresh);
//        return mRets.size();
//    }
//
//    inline std::vector<dlib::rectangle> getResult() { return mRets; }
//
//    virtual ~DLibHOGDetector() {}
//
//protected:
//    std::vector<dlib::rectangle> mRets;
//    std::string mModelPath;
//    const int INPUT_IMG_MAX_SIZE = 800;
//    const int INPUT_IMG_MIN_SIZE = 600;
//};
//
///*
// * DLib face detect and face feature extractor
// */
//class DLibHOGFaceDetector : public DLibHOGDetector {
//private:
//    std::string mLandMarkModel;
//    dlib::shape_predictor msp;
//    std::unordered_map<int, dlib::full_object_detection> mFaceShapeMap;
//    dlib::frontal_face_detector mFaceDetector;
//
//    inline void init() {
//        LOGI( "Init mFaceDetector");
//        mFaceDetector = dlib::get_frontal_face_detector();
//    }
//
//public:
//    DLibHOGFaceDetector() { init(); }
//
//    DLibHOGFaceDetector(const std::string& landmarkmodel)
//            : mLandMarkModel(landmarkmodel) {
//        init();
//        if (!mLandMarkModel.empty() && jniutils::fileExists(mLandMarkModel)) {
//            long long curTime = getCurrentTime();
//            dlib::deserialize(mLandMarkModel) >> msp;
//            LOGI("读取pixel时间%lld ", getCurrentTime() - curTime);
//            LOGI("Load landmarkmodel from %s",mLandMarkModel.c_str() );
//        }
//    }
//
//    virtual inline int det(const std::string& path) {
//        LOGI("Read path from %s",path.c_str());
//        cv::Mat src_img = cv::imread(path, CV_LOAD_IMAGE_COLOR);
//        return det(src_img);
//    }
//
//    // The format of mat should be BGR or Gray
//    // If converting 4 channels to 3 channls because the format could be BGRA or
//    // ARGB
//    virtual inline int det(const cv::Mat& image) {
//        if (image.empty())
//            return 0;
//        LOGI("com_tzutalin_dlib_PeopleDet go to det(mat)");
//        if (image.channels() == 1) {
//            cv::cvtColor(image, image, CV_GRAY2BGR);
//        }
////        CHECK(image.channels() == 3);
//        // TODO : Convert to gray image to speed up detection
//        // It's unnecessary to use color image for face/landmark detection
//        dlib::cv_image<dlib::bgr_pixel> img(image);
//        mRets = mFaceDetector(img);
//        LOGI("Dlib HOG face det size : %d",mRets.size());
//        mFaceShapeMap.clear();
//        // Process shape
//        if (mRets.size() != 0 && mLandMarkModel.empty() == false) {
//            for (unsigned long j = 0; j < mRets.size(); ++j) {
//                dlib::full_object_detection shape = msp(img, mRets[j]);
//                LOGI("face index:%d number of parts: %d",j,shape.num_parts());
//                mFaceShapeMap[j] = shape;
//            }
//        }
//        return mRets.size();
//    }
//
//    std::unordered_map<int, dlib::full_object_detection>& getFaceShapeMap() {
//        return mFaceShapeMap;
//    }
//};
