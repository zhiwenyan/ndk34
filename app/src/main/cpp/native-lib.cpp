#include <jni.h>
#include <string>
#include "LinkedList.hpp"
#include <android/log.h>

extern "C"
JNIEXPORT jstring


JNICALL
Java_com_steven_ndk34_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    std::string hello = "Hello from C++";


    LinkedList<int> linkedList;

    linkedList.push(0);
    linkedList.push(1);
    linkedList.push(2);
    linkedList.push(3);
    linkedList.push(4);
    linkedList.push(5);;
    linkedList.insert(2, 9);
    linkedList.insert(linkedList.size(), 0);
    linkedList.insert(0, 10);
    for (int i = 0; i < linkedList.size(); ++i) {
        __android_log_print(ANDROID_LOG_ERROR, "TAG", "%d", linkedList.get(i));
    }
    linkedList.remove(2);

    for (int i = 0; i < linkedList.size(); ++i) {
        __android_log_print(ANDROID_LOG_ERROR, "TAG", "%d", linkedList.get(i));
    }
//    delete(linkedList);

//    time_t start = clock();
//    for (int i = 0; i < 50000; ++i) {
//        linkedList.push(i);
//    }
//    time_t end = clock();
//
//    __android_log_print(ANDROID_LOG_ERROR, "TAG", "%d", (end - start) / CLOCKS_PER_SEC);
//    for (int i = 0; i < linkedList.size(); ++i) {
//        __android_log_print(ANDROID_LOG_ERROR, "TAG", "%d", linkedList.get(i));
//    }

    return env->NewStringUTF(hello.c_str());
}
