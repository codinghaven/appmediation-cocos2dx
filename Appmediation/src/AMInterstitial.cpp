#include "AMInterstitial.h"
#include "cocos2d.h"
#include "Constants.h"
#include <iostream>

USING_NS_CC;

using namespace appmediation;

bool AMInterstitial::isReady() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMINTERSTITIAL_CLASS, "isReady", "()Z");

    if(!exists) {
        CCLOG("isReady() AMInterstitial doesn't exist");
        return false;
    }

    jboolean b_result = mi.env->CallStaticBooleanMethod(mi.classID, mi.methodID);
    bool return_val = (bool) b_result;

    return return_val;

}

bool AMInterstitial::isDisplaying() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMINTERSTITIAL_CLASS, "isDisplaying", "()Z");

    if(!exists) {
        CCLOG("isDisplaying() AMInterstitial doesn't exist");
        return false;
    }

    jboolean b_result = mi.env->CallStaticBooleanMethod(mi.classID, mi.methodID);
    bool return_val = (bool) b_result;

    return return_val;
}

bool AMInterstitial::isLoading() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMINTERSTITIAL_CLASS, "isLoading", "()Z");

    if(!exists) {
        CCLOG("isLoading() AMInterstitial doesn't exist");
        return false;
    }

    jboolean b_result = mi.env->CallStaticBooleanMethod(mi.classID, mi.methodID);
    bool return_val = (bool) b_result;

    return return_val;
}

bool AMInterstitial::isFailed() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMINTERSTITIAL_CLASS, "isFailed", "()Z");

    if(!exists) {
        CCLOG("isFailed() AMInterstitial doesn't exist");
        return false;
    }

    jboolean b_result = mi.env->CallStaticBooleanMethod(mi.classID, mi.methodID);
    bool return_val = (bool) b_result;

    return return_val;

}

void AMInterstitial::show() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMINTERSTITIAL_CLASS, "show", "(Landroid/app/Activity;)V");

    if(!exists) {
        CCLOG("show() AMInterstitial doesn't exist");
        return;
    }

    jobject activity = cocos2d::JniHelper::getActivity();
    CCLOG("before show call");
    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, activity);
    CCLOG("after show() call");
}

void AMInterstitial::load() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMINTERSTITIAL_CLASS, "load", "(Landroid/app/Activity;)V");

    if(!exists) {
        CCLOG("load() AMInterstitial doesn't exist");
        return;
    }

    jobject activity = cocos2d::JniHelper::getActivity();
    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, activity);
}
