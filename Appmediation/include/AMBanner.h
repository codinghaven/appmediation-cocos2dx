#ifndef AMBANNER_H_DEFINE
#define AMBANNER_H_DEFINE

#include "Gravity.h"
#include "AMBannerSize.h"
namespace appmediation {
	class AMBanner {
	public:
		static void load(AMBannerSize, Gravity);

		static void show();

		static void hide();

		static void setAutoRefresh(bool);
	};
}
#endif
