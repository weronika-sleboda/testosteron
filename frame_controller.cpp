#include "frame_controller.h"
#include "main_frame.h"
#include "test_all_frame.h"
#include "test_client_frame.h"
#include "test_server_frame.h"
#include "popup_frame.h"

namespace testosteron
{

	FrameController::FrameController() :

		mainFrame { new MainFrame { } },
		testServerFrame { new TestServerFrame { } },
		testClientFrame { new TestClientFrame { } },
		testAllFrame { new TestAllFrame { } },
		popupFrame { nullptr }

	{}

	FrameController::~FrameController()
	{

		delete mainFrame;
		delete testServerFrame;
		delete testClientFrame;
		delete testAllFrame;
		delete popupFrame;

	}

	FrameController& FrameController::frameController()
	{

		static FrameController controller;
		return controller;

	}

	void FrameController::showMainFrame()
	{

		mainFrame->Show();

	}

	void FrameController::showTestServerFrame()
	{

		testServerFrame->Show();

	}

	void FrameController::showTestClientFrame()
	{

		testClientFrame->Show();

	}

	void FrameController::showTestAllFrame()
	{

		testAllFrame->Show();

	}

	void FrameController::showPopupFrame(std::string info)
	{

		popupFrame = new PopupFrame { };
		popupFrame->changeInfo(info);
		popupFrame->Show();

	}

}