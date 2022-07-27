// Implementation of WriteLogInterface for writing in DB

#ifndef __WriteLogInDb_HeaderFile__
#define __WriteLogInDb_HeaderFile__

#include "WriteLogInterface.h"

class WriteLogInDb :public WriteLogInterface
{
public:
	~WriteLogInDb();
	WriteLogInDb();
	void WriteLog(const vector<std::string>& vMessages, const string& sLogLevel) override;
	void WriteLog(const string& sMessage, const string& sLogLevel)override;
private:
	// Data member for writing in DB
};

#endif // __WriteLogInDb_HeaderFile__

