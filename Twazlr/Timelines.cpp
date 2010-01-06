#include "Timelines.h"

using namespace Twazlr;

Timelines::Timelines(const string& path) : BDB::BDB(path, "timelines") {}

bool Timelines::Get(const string& key, Timeline& results) {
	int size = (int)sizeof(double);
	void* records = tcbdbget(this->database, key.c_str(), key.size(), &size);
	
	if(records != NULL) {
		size_t count = size / sizeof(double);
		results.insert(results.end(), (double*)records, (double*)records + count);
		free(records);
		return true;
	} else {
		return false;
	}
}
