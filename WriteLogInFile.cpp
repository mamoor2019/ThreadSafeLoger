#include "WriteLogInFile.h"

WriteLogInFile::WriteLogInFile()
{
	m_OutputStream.open(m_sFileName, ios_base::app);
	if (!m_OutputStream.good())
		throw runtime_error("Unable to initialize the File Logger!");
}
WriteLogInFile::~WriteLogInFile()
{
	m_OutputStream.close();
}
void WriteLogInFile::WriteLog(const std::vector<std::string>& vMessages, const string& sLogLevel)
{
	for (size_t i = 0; i < vMessages.size(); i++)
		WriteHelper(vMessages.at(i), sLogLevel);
}
void WriteLogInFile::WriteLog(const string& sMessage, const string& sLogLevel)
{
	WriteHelper(sMessage, sLogLevel);
}
void WriteLogInFile::WriteHelper(const string& sMessage, const string& sLogLevel)
{
	m_OutputStream << sLogLevel << ": " << sMessage << endl;
}
