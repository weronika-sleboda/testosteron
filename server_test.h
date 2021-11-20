#ifndef SERVER_TEST_H
#define SERVER_TEST_H

#include "server_test.h"
#include "server_manager.h"

namespace testosteron
{

	class ServerTest
	{

	public:

		ServerTest();

		blue_pearl_bank_admin::ServerManager* getServerManager();
		void cleanUp();

	private:

		blue_pearl_bank_admin::ServerManager* serverManager;

	};

}

#endif