#include "test.h"
#include "client_test.h"
#include "server_test.h"
#include "account.cpp"
#include "database.cpp"

using namespace blue_pearl_bank_admin;

namespace testosteron
{

	Test::Test() : 

		account 
	{

		"First Name",
		"Last Name",
		"Email Address",
		"Password"
	
	},

		singleTestCollection
	{

			TestObject
		{

			"TestObject::justTesting()",
			false,
			"Just Testing is false",
			"Just Testing is true"

		},

			TestObject
		{

			"Account::getFirstName()",
			account.getFirstName().length() > 0,
			"First name is not empty",
			"First name is empty"

		},

			TestObject
		{

			"Account::getLastName()",
			account.getLastName().length() > 0,
			"Last name is not empty",
			"Last name is empty"

		},

			TestObject
		{

			"Account::getEmail()",
			account.getEmailAddress().length() > 0,
			"Email address is not empty",
			"Email address is empty"

		},

			TestObject
		{

			"Account::getPassword()",
			account.getPassword().length() > 0,
			"Password is not empty",
			"Password is empty"

		},


			TestObject
		{

			"Account::getFunds()",
			account.getFunds().length() > 0,
			"Funds string is not empty",
			"Funds string is not empty"

		},

			TestObject
		{

			"Database::createDatabase()",
			Database::createDatabase(),
			"Database has been created",
			"Unable to create database"

		},

			TestObject
		{

			"Database::addAccount()",
			Database::addAccount(account),
			"Account has been added to the database",
			"Unable to add an account to the database"

		},

					TestObject
		{

			"Database::updateFunds(givenEmail, amount)",
			Database::updateFunds("Email Address", "200"),
			"The funds has been updated",
			"Couldn't update the funds"

		},
			
			TestObject
		{

			"Database::getCovetedInfo()",
			Database::getCovetedInfo().length() > 0,
			"Coveted info has been received",
			"Coveted info has not been received"

		},

	},

		clientTestCollection 
	{

			TestObject
		{

			"ClientManager::getIpAddress()",
			client->getClientManager()->getIpAddress() == "127.0.0.1",
			"Ip address is a string '127.0.0.1'",
			"Ip address is not a string '127.0.0.1'"

		},


			TestObject
		{

			"ClientManager::getPortNumber()",
			client->getClientManager()->getPortNumber() == 3333,
			"Port number is 3333",
			"Port number is not 3333"

		},

			TestObject
		{

			"ClientManager::openSocket()",
			client->getClientManager()->openSocket(),
			"Client has opened the socket",
			"Client couldn't open the socket"

		},

			TestObject
		{

			"ClientManager::connectSocket()",
			client->getClientManager()->connectSocket(),
			"Client has been connected to server",
			"Client couldn't connect to server"

		},

			TestObject
		{

			"ClientManager::sendData()",
			client->getClientManager()->sendData("Test Data"),
			"Client has sent data to the server",
			"Client couldn't send data to the server"

		}

	},

		serverTestCollection
	{

			TestObject
		{

			"ServerManager::getPortNumber()",
			server->getServerManager()->getPortNumber() == 3333,
			"Port number is 3333",
			"Port number is not 3333"

		},

			TestObject
		{

			"ServerManager::listenToClient()",
			server->getServerManager()->listenToClient(),
			"Server is listening to the client",
			"Server couldn't listen to the client"

		},

	},
				
		fullTestCollection
	{

			TestObject
		{

			"Account::getFirstName()",
			account.getFirstName().length() > 0,
			"First name is not empty",
			"First name is empty"

		},

			TestObject
		{

			"Account::getLastName()",
			account.getLastName().length() > 0,
			"Last name is not empty",
			"Last name is empty"

		},

			TestObject
		{

			"Account::getEmail()",
			account.getEmailAddress().length() > 0,
			"Email address is not empty",
			"Email address is empty"

		},

			TestObject
		{

			"Account::getPassword()",
			account.getPassword().length() > 0,
			"Password is not empty",
			"Password is empty"

		},


			TestObject
		{

			"Account::getFunds()",
			account.getFunds().length() > 0,
			"Funds string is not empty",
			"Funds string is not empty"

		},

			TestObject
		{

			"Database::createDatabase()",
			Database::createDatabase(),
			"Database has been created",
			"Unable to create database"

		},

			TestObject
		{

			"Database::addAccount()",
			Database::addAccount(account),
			"Account has been added \nto the database",
			"Unable to add an account \nto the database"

		},

			TestObject
		{

			"Database::updateFunds(givenEmail, amount)",
			Database::updateFunds("Email Address", "200"),
			"The funds has been updated",
			"Couldn't update the funds"

		},

			TestObject
		{

			"Database::getCovetedInfo()",
			Database::getCovetedInfo().length() > 0,
			"Coveted info has been received",
			"Coveted info has not \nbeen received"

		},

	},

		client { new ClientTest { } },
		server { new ServerTest { } },
		passed { false }

	//*** Constructor Body

	{}

	Test::~Test()
	{

		client->cleanUp();
		delete client;

		server->cleanUp();
		delete server;

	}

	std::vector<TestObject>& Test::singleTest()
	{

		return singleTestCollection;

	}
	
	std::string Test::singleTestOutput(unsigned int testIndex)
	{

		std::string details = 
			
			singleTestCollection.at(testIndex).getFunctionName() + '\n' +
			singleTestCollection.at(testIndex).getOutputDescription();

		if (singleTestCollection.at(testIndex).hasPassed())
		{

			return "[PASSED] " + details;	
			
		}

		else
		{

			return "[FAILED] " + details;

		}

	}

	std::vector<TestObject>& Test::clientTest()
	{

		return clientTestCollection;

	}

	std::vector<TestObject>& Test::serverTest()
	{

		return serverTestCollection;

	}

	std::vector<TestObject>& Test::fullTest()
	{

		return fullTestCollection;

	}

	std::string Test::specializedTestOutput
	(std::vector<TestObject>& collection, std::string testName)
	{

		failedFunctionsNames.clear();
		failedFunctionsResults.clear();

		int passedTestNumber { 0 };

		for (auto& test : collection)
		{

			if (test.hasPassed())
			{

				passedTestNumber++;

			}

			else
			{

				failedFunctionsNames.push_back
				(test.getFunctionName());

				failedFunctionsResults.push_back
				(test.getOutputDescription());

			}

		}

		if (passedTestNumber == collection.size())
		{

			passed = true;
			return "[PASSED] " + testName + " has been accepted.";

		}

		else 
		{
		
			passed = false;
			return "[FAILED] " + testName + " has been rejected.";
		
		}

	}

	bool Test::hasPassed()
	{

		return passed;

	}

	std::string& Test::getFailedFunctionName(unsigned int index)
	{

		return failedFunctionsNames.at(index);

	}

	std::string& Test::getFailedFunctionResult(unsigned int index)
	{

		return failedFunctionsResults.at(index);

	}
}