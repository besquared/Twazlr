#ifndef _twazlr_timelines_h_
#define _twazlr_timelines_h_

#include <Common/Common.h>

#include "BDB.h"
#include "Timeline.h"

using namespace std;

namespace Twazlr {
	class Timelines : public Twazlr::BDB {    
	public:		
		Timelines(const string& path);
		virtual bool Get(const string& key, Timeline& results);
  };
}

#endif