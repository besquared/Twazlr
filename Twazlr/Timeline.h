#ifndef _twazlr_timeline_h_
#define _twazlr_timeline_h_

#include <Common/Common.h>

using namespace std;

namespace Twazlr {
	class Timeline : public vector<double> {
	public:
		Timeline();		
		Timeline operator&(Timeline& other);
		Timeline operator|(Timeline& other);
		string Inspect();
	};
}

#endif