// Implementation of WriteLogInterface for writing in Console

#ifndef __WriteLogInConsole_HeaderFile__
#define __WriteLogInConsole_HeaderFile__

#include "WriteLogInterface.h"
class WriteLogInConsole :	public WriteLogInterface
{
public:
	~WriteLogInConsole();
	WriteLogInConsole();
	void WriteLog(const vector<std::string>& vMessages, const string& sLogLevel) override;
	void WriteLog(const string& sMessage, const string& sLogLevel)override;
private:
	// Data member for writing in console
};

#endif // __WriteLogInConsole_HeaderFile__

