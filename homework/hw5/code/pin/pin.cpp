#include "pin.h"
#include <algorithm>
#include <chrono>
#include <thread>

Pin::Pin(double curvature, double sharpness, size_t id) {
    curvature_ = curvature;
    sharpness_ = sharpness;
    id_ = id;
}

void Pin::Sharpen() {
    sharpness_ = std::min(10.0, sharpness_ * 1.5);
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

double Pin::GetQuality() const {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return sharpness_ * curvature_;
}

bool Pin::CheckCurvature() const {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return curvature_ >= 0.3;
}

std::string Pin::to_string() const {
    return "Pin #" + std::to_string(id_) + ": curvature = " +
    std::to_string(curvature_) + "; sharpness = " + std::to_string(sharpness_);

}
