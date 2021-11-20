#ifndef CLIENT_TEST_H
#define CLIENT_TEST_H

#include <client.h>
#include <client_manager.h>

namespace testosteron
{

	class ClientTest
	{

	public:

		ClientTest();

		blue_pearl_bank::ClientManager* getClientManager();
		void cleanUp();

	private:

		blue_pearl_bank::ClientManager* clientManager;

	};
}

#endif