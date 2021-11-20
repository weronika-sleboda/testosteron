#include "client_test.h"
#include "client.cpp"
#include "client_manager.cpp"

namespace testosteron
{

	ClientTest::ClientTest() :

		clientManager { new blue_pearl_bank::ClientManager { } }

	{}

	blue_pearl_bank::ClientManager* ClientTest::getClientManager()
	{

		return clientManager;

	}

	void ClientTest::cleanUp()
	{

		delete clientManager;

	}

}