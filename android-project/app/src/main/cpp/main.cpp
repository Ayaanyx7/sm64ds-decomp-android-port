#include <android/log.h>

#define LOG_TAG "SM64DS"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" void sm64ds_android_main()
{
    LOGI("SM64DS Android native code reached");
}
