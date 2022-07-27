#include "MyLogger.h"
#include <vector>
#include <string>
#include "WriteLogInFile.h"
#include "WriteLogInterface.h"
#include "WriteLogInDb.h"
#include "WriteLogInConsole.h"

using namespace std;

int main()
{
	unique_ptr< WriteLogInterface> upLogInFile = make_unique< WriteLogInFile>();
	MyLogger::GetInstance().Log("test message", kDebugLog, upLogInFile);
	vector<string> items = { "test message 1", "test message 2" };
	MyLogger::GetInstance().Log(items, kLogLevelError, upLogInFile);

	// added for sample, if the interface is implemented it will work
	// till then below code will do nothing
	unique_ptr< WriteLogInterface> upLogInConsole = make_unique< WriteLogInConsole>();
	MyLogger::GetInstance().Log("test message console", kLogLevelInfo, upLogInConsole);
	items = { "test message console 1", "test message console2" };
	MyLogger::GetInstance().Log(items, kLogLevelError, upLogInFile);

	unique_ptr< WriteLogInterface> upLogInDb = make_unique< WriteLogInDb>();
	MyLogger::GetInstance().Log("test message DB", kLogLevelInfo, upLogInDb);
	items = { "test message DB 1", "test message DB 2" };
	MyLogger::GetInstance().Log(items, kLogLevelError, upLogInFile);

	return 0;
}