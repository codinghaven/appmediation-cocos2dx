#include "AMSDK.h"
#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

void AMSDK::init(const std::string& key) {
    cocos2d::JniMethodInfo mi;

    bool method_exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMSDK_CLASS, "init", "(Landroid/app/Activity;Ljava/lang/String;)V");
    if(method_exists) {
        CCLOG("method exists!");
    } else {
        CCLOG("method no exist!");
        return;
    }

    jstring str = mi.env->NewStringUTF(key.c_str());

    mi.env->CallStaticVoidMethod( mi.classID, mi.methodID, cocos2d::JniHelper::getActivity(),str);

    mi.env->DeleteLocalRef(str);
}

void AMSDK::setAutoLoad(AdType ad) { 
    cocos2d::JniMethodInfo mi;

    bool method_exists = cocos2d::JniHelper::getStaticMethodInfo(
            mi, AMSDK_CLASS, "setAutoLoad", "(Lcom/appmediation/sdk/models/AdType;Z)V");
    if(method_exists) {
        CCLOG("method exists!");
    } else {
        CCLOG("method no exist!");
        return;
    }

    std::string ad_type = "";
    switch(ad) {
        case BANNER:
            ad_type = "BANNER";
            break;
        case INTERSTITIAL:
            ad_type = "INTERSTITIAL";
            break;
        case REWARDED_VIDEO:
            ad_type = "REWARDED_VIDEO";
            break;
    }

    auto env = JniHelper::getEnv();
    jclass ad_type_enum = env->FindClass("com/appmediation/sdk/models/AdType");

    jfieldID  ad_type_field = env->GetStaticFieldID(ad_type_enum, ad_type.c_str(), "Lcom/appmediation/sdk/models/AdType;");
    jobject ad_type_j = env->GetStaticObjectField(ad_type_enum, ad_type_field);

    env->CallStaticVoidMethod(mi.classID, mi.methodID, ad_type_j, (jboolean)true);
}

void AMSDK::setAutoLoad(AdType ad_a, AdType ad_b) { 
    setAutoLoad(ad_a);
    setAutoLoad(ad_b);
}

void AMSDK::setAutoLoad(AdType ad_a, AdType ad_b, AdType ad_c) { 
    setAutoLoad(ad_a);
    setAutoLoad(ad_b);
    setAutoLoad(ad_c);
}

void AMSDK::showConsentAutomatically(bool cond) {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
            mi, AMSDK_CLASS, "showConsentAutomatically", "(Z)V");
    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, (jboolean)cond);
}

void AMSDK::setTestMode(bool cond) {
    cocos2d::JniMethodInfo mi;

    bool method_exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMSDK_CLASS, "setTestMode", "(Z)V");
    if(method_exists) {
        CCLOG("method exists!");
    } else {
        CCLOG("method no exist!");
        return;
    }

    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, (jboolean)cond);
}

void AMSDK::setUserIdentifier(const std::string& uid) {

}
