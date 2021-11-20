#ifndef TEST_H
#define TEST_H

#include <vector>
#include <string>
#include "test_object.h"
#include "account.h"

namespace testosteron
{

	class ClientTest;
	class ServerTest;

	class Test
	{

	public:

		Test();
		~Test();

	public:
	
		std::vector<TestObject>& singleTest();
		std::vector<TestObject>& clientTest();
		std::vector<TestObject>& serverTest();
		std::vector<TestObject>& fullTest();

		bool hasPassed();
		std::string singleTestOutput(unsigned int testIndex);
		std::string specializedTestOutput
		(std::vector<TestObject>& collection, std::string testName);

		std::string& getFailedFunctionName(unsigned int index);
		std::string& getFailedFunctionResult(unsigned int index);;

	private:

		ClientTest* client;
		ServerTest* server;
		blue_pearl_bank_admin::Account account;

	private:

		bool passed;

		std::vector<TestObject> singleTestCollection;
		std::vector<TestObject> clientTestCollection;
		std::vector<TestObject> serverTestCollection;
		std::vector<TestObject> fullTestCollection;

		std::vector<std::string> failedFunctionsNames;
		std::vector<std::string> failedFunctionsResults;

	};

}

#endif
