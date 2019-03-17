#include "AMInterstitial.h"
#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

bool AMInterstitial::isReady() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMINTERSTITIAL_CLASS, "isReady", "()Z");

    if(!exists) {
        CCLOG("isReady() AMInterstitial doesn't exist");
        return false;
    }

    auto b_result = mi.env->CallStaticBooleanMethod(mi.classID, mi.methodID);

    return (bool)b_result;

}

void AMInterstitial::show() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMINTERSTITIAL_CLASS, "show", "(Landroid/app/Activity;)V");

    if(!exists) {
        CCLOG("show() AMInterstitial doesn't exist");
        return;
    }

    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, cocos2d::JniHelper::getActivity());
}

void AMInterstitial::load() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMINTERSTITIAL_CLASS, "load", "(Landroid/app/Activity;)V");

    if(!exists) {
        CCLOG("load() AMInterstitial doesn't exist");
        return;
    }

    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, cocos2d::JniHelper::getActivity());
}
