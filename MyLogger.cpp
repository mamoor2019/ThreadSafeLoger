#include <stdexcept>
#include "MyLogger.h"

using namespace std;


MyLogger* MyLogger::_m_pInstance = nullptr;

mutex MyLogger::_m_Mutex;

MyLogger& MyLogger::GetInstance()
{
	static Cleanup cleanup;

	lock_guard<mutex> guard(_m_Mutex);
	if (_m_pInstance == nullptr)
		_m_pInstance = new MyLogger();
	return *_m_pInstance;
}

MyLogger::Cleanup::~Cleanup()
{
	lock_guard<mutex> guard(MyLogger::_m_Mutex);
	delete MyLogger::_m_pInstance;
	MyLogger::_m_pInstance = nullptr;
}

void MyLogger::Log(const string& sMessage, const std::string& sLogLevel, unique_ptr< WriteLogInterface>& upLogIntf)
{
	lock_guard<mutex> guard(_m_Mutex);
	upLogIntf->WriteLog(sMessage, sLogLevel);
}

void MyLogger::Log(const vector<std::string>& vMessages, const string& sLogLevel, unique_ptr< WriteLogInterface>& upLogIntf)
{
	lock_guard<mutex> guard(_m_Mutex);
	upLogIntf->WriteLog(vMessages, sLogLevel);
}