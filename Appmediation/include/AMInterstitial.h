#ifndef AMINTERSTITIAL_H_DEFINE
#define AMINTERSTITIAL_H_DEFINE

namespace appmediation {
class AMInterstitial {
public:
	static bool isReady();
	static bool isFailed();
	static bool isLoading();
	static bool isDisplaying();
	static void show();
	static void load();
};

}

#endif
