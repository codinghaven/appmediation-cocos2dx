#include "AMSDK.h"
#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

using namespace appmediation;

void AMSDK::init(const std::string& key) {
    cocos2d::JniMethodInfo mi;

    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMSDK_CLASS, "init", "(Landroid/app/Activity;Ljava/lang/String;)V");
    if(!exists) {
        CCLOG("method no exist!");
        return;
    }

    jstring str = mi.env->NewStringUTF(key.c_str());
    jobject activity = cocos2d::JniHelper::getActivity();

    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, activity, str);

    mi.env->DeleteLocalRef(str);
}

void AMSDK::setAutoLoad(std::vector<AdType>& ads) {
    if(ads.empty()) return;
    cocos2d::JniMethodInfo mi;

    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
            mi, AMSDK_CLASS, "setAutoLoad", "([Lcom/appmediation/sdk/models/AdType;)V");
    if(!exists) {
        CCLOG("method no exist!");
        return;
    }

    auto env = mi.env;
    auto initial_element = getJavaAdType(ads.front());
    jclass ad_type_class = env->FindClass("com/appmediation/sdk/models/AdType");
    jobjectArray ad_types = env->NewObjectArray(ads.size(), ad_type_class, initial_element);

    for(int i= 1; i < ads.size(); ++i) {
        auto ad_type = getJavaAdType(ads.at(i));
        env->SetObjectArrayElement(ad_types, i, ad_type);
        env->DeleteLocalRef(ad_type);
    }

    env->CallStaticVoidMethod(mi.classID, mi.methodID, ad_types);

    env->DeleteLocalRef(initial_element);
    env->DeleteLocalRef(ad_type_class);
    env->DeleteLocalRef(ad_types);
}

jobject AMSDK::getJavaAdType(AdType ad) {
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
    return env->GetStaticObjectField(ad_type_enum, ad_type_field);
}

void AMSDK::setAutoLoad(AdType ad_a) {
    std::vector<AdType> ads;
    ads.push_back(ad_a);
    setAutoLoad(ads);
}

void AMSDK::setAutoLoad(AdType ad_a, AdType ad_b) {
    std::vector<AdType> ads;
    ads.push_back(ad_a);
    ads.push_back(ad_b);
    setAutoLoad(ads);
}

void AMSDK::setAutoLoad(AdType ad_a, AdType ad_b, AdType ad_c) {
    std::vector<AdType> ads;
    ads.push_back(ad_a);
    ads.push_back(ad_b);
    ads.push_back(ad_c);
    setAutoLoad(ads);
}

void AMSDK::showConsentAutomatically(bool cond) {
    cocos2d::JniMethodInfo mi;
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
            mi, AMSDK_CLASS, "showConsentAutomatically", "(Z)V");
    if(!exists) {
        CCLOG("method in AMSDK showConsentAutomatically doesn't exist");
        return;
    }

    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, cond);
}

void AMSDK::setTestMode(bool cond) {
    cocos2d::JniMethodInfo mi;

    bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMSDK_CLASS, "setTestMode", "(Z)V");
    if(!exists) {
        CCLOG("method no exist!");
        return;
    }

    mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, cond);
}

void AMSDK::setUserIdentifier(const std::string& uid) {
    CCLOG("un implemented uid");
}