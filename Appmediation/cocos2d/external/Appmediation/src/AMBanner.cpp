#include "AMBanner.h"
#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

void AMBanner::load(AMBannerSize size, Gravity gravity) {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
            mi,
            AMBANNER_CLASS,
            "load",
            "(Landroid/app/Activity;Lcom/appmediation/sdk/AMBannerSize;I)V");

    if(!exists) {
        CCLOG("method load(size, gravity) no exists");
        return;
    }

    std::string ad_size = "";
    switch(size) {
        case FULL_WIDTH:
            ad_size = "FULL_WIDTH";
            break;
        case LARGE:
            ad_size = "LARGE";
            break;
        case STANDARD:
            ad_size = "STANDARD";
            break;
    }

    auto env = cocos2d::JniHelper::getEnv();
    jclass ad_banner_size = env->FindClass("com/appmediation/sdk/AMBannerSize");
    jfieldID size_id = env->GetStaticFieldID(ad_banner_size, ad_size.c_str(), "Lcom/appmediation/sdk/AMBannerSize;");
    jobject size_o = env->GetStaticObjectField(ad_banner_size, size_id);

    env->CallStaticVoidMethod(mi.classID,
            mi.methodID, cocos2d::JniHelper::getActivity(), size_o, gravity);
}

void AMBanner::show() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
            mi,
            AMBANNER_CLASS,
            "show",
            "(Landroid/app/Activity;)V");

    if (!exists) {
        CCLOG("method show() no exists");
        return;
    }

    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, cocos2d::JniHelper::getActivity());
}

void AMBanner::hide() {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
            mi,
            AMBANNER_CLASS,
            "hide",
            "(Landroid/app/Activity;)V");

    if (!exists) {
        CCLOG("method load(size, gravity) no exists");
        return;
    }

    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, cocos2d::JniHelper::getActivity());
}

void AMBanner::setAutoRefresh(bool cond) {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
            mi,
            AMBANNER_CLASS,
            "setAutoRefresh",
            "(Z)V");

    if (!exists) {
        CCLOG("method setAutoRefresh(bool) no exists");
        return;
    }

    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, (jboolean)cond);
}