#include "Timeline.h"

using namespace Twazlr;

Timeline::Timeline() : vector<double>() {}

Timeline Timeline::operator&(Timeline& other) {
	Timeline results;
	results.reserve(min<size_t>(this->size(), other.size()));
	set_intersection(this->begin(), this->end(), other.begin(), other.end(), back_inserter(results));
	return results;
}

Timeline Timeline::operator|(Timeline& other) {
	Timeline results;
	results.reserve(this->size() + other.size());
	merge(this->begin(), this->end(), other.begin(), other.end(), back_inserter(results));
	return results;
}

// string Timeline::Inspect() {
//  string out;
//  
//  out += "[";
//  for(size_t i = 0; i < vector<double>::size(); i++) {
//    out += boost::lexical_cast<string>(vector<double>::at(i));
//    if(i < vector<double>::size() - 1) out += ", "; 
//  }
//  out += "]";
//  
//  return out;
// }