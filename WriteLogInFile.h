// Implementation of WriteLogInterface for writing in File

#ifndef __WriteLogInFile_HeaderFile__
#define __WriteLogInFile_HeaderFile__

#include "WriteLogInterface.h"
#include <fstream>

using namespace std;

class WriteLogInFile :	public WriteLogInterface
{
public:
	~WriteLogInFile();
	WriteLogInFile();
	void WriteLog(const vector<std::string>& vMessages, const string& sLogLevel) override;
	void WriteLog(const string& sMessage, const string& sLogLevel)override;
private:
	void WriteHelper(const string& sMessage, const string& sLogLevel);
private:
	// Data member for the output stream
	ofstream m_OutputStream;
	const string m_sFileName = "log.out";

};



#endif // __WriteLogInFile_HeaderFile__

