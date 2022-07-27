//Definition of thread-safe logger class 
// Making it singelton so that uniuqe ownership is ensured


#ifndef __MyLoger_HeaderFile__
#define __MyLoger_HeaderFile__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <mutex>
#include <memory>
#include "WriteLogInterface.h"


using namespace std;

class MyLogger
{
public:

	// Returns a reference to the singleton Logger object
	static MyLogger& GetInstance();

	// Logs a single message at the given log level
	void Log(const string& sMessage, const std::string& sLogLevel, unique_ptr< WriteLogInterface>& upLogIntf);

	// Logs a vector of messages at the given log level
	void Log(const vector<std::string>& vMessages,const string& sLogLevel, unique_ptr< WriteLogInterface>& upLogIntf);

	// For singelton implementation making copy constructor and assignment operator non copyable.
	MyLogger(const MyLogger&) = delete;
	MyLogger& operator=(const MyLogger&) = delete;

protected:
	// Static variable for the one-and-only instance  
	static MyLogger* _m_pInstance;

	// Embedded class to make sure the single Logger
	// instance gets deleted on program shutdown.
	friend class Cleanup;
	class Cleanup
	{
	public:
		~Cleanup();
	};

	//// Logs message. The thread should own a lock on sMutex
	//// before calling this function.
	//void logHelper(const string& inMessage,
	//	const string& inLogLevel);

private:
	MyLogger() =default;
	virtual ~MyLogger() {};
	
	static mutex _m_Mutex;
};
#endif // __MyLoger_HeaderFile__