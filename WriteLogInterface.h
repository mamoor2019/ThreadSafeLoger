// Interface to write the log information in different storages
// Different storages will implement this interface

#ifndef __WriteLogInterface_HeaderFile__
#define __WriteLogInterface_HeaderFile__

#include <vector>
#include <string>

using namespace std;


const string kDebugLog = "DEBUG";
const string kLogLevelInfo = "INFO";
const string kLogLevelError = "ERROR";

class WriteLogInterface
{
public:
	virtual ~WriteLogInterface(){}
	// For writing vector of strings
	virtual void WriteLog(const vector<std::string>& inMessages, const string& inLogLevel) = 0;
	//For writing string 
	virtual void WriteLog(const string& sMessage, const string& inLogLevel) = 0;
};


#endif // __WriteLogInterface_HeaderFile__
