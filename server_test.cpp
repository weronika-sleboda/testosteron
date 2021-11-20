#include "server_test.h"
#include "server.cpp"
#include "server_manager.cpp"

namespace testosteron
{

	ServerTest::ServerTest():

		serverManager { new blue_pearl_bank_admin::ServerManager { } }

	{}

	blue_pearl_bank_admin::ServerManager* ServerTest::getServerManager()
	{

		return serverManager;

	}

	void ServerTest::cleanUp()
	{

		delete serverManager;
		
	}

}