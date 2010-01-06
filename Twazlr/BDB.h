#ifndef _twazlr_bdb_h_
#define _twazlr_bdb_h_

#include <Common/Common.h>

using namespace std;

namespace Twazlr {
	class BDB {
	protected:
		string path;
		string name;
		TCBDB *database;
		pthread_mutex_t mutex;
    
	public:		
		BDB(const string& path, const string& name);
		virtual ~BDB();
		
		bool OpenReader();
		bool OpenWriter();
		bool Open(int mode);
		bool Close();
		bool Truncate();
		
		void Lock();
    void Unlock();
    
		virtual bool Get(const string& key, string& result);	
    virtual bool Get(const string& key, vector<string>& results);
		virtual bool Put(const string& key, const string& value);
		virtual bool PutDup(const string& key, const string& value);
		virtual bool Add(const string& key, const int value, int& result);
		virtual bool Out(const string& key);
    virtual int Count(const string& key);
    
    bool TransactionBegin();
    bool TransactionAbort();
    bool TransactionCommit();
  
		string Error();
		int ErrorCode();
		
		static bool Create(const string& path, const string& name);
		static string Path(const string& path, const string& name);
	};
}

#endif