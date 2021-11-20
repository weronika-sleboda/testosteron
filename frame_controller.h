#ifndef FRAME_CONTROLLER_H
#define FRAME_CONTROLLER_H

#include <string>

namespace testosteron
{

	class MainFrame;
	class TestServerFrame;
	class TestClientFrame;
	class TestAllFrame;
	class PopupFrame;

	class FrameController
	{

	public:

		static FrameController& frameController();

	public:

		~FrameController();

	public:

		void showMainFrame();
		void showTestServerFrame();
		void showTestClientFrame();
		void showTestAllFrame();
		void showPopupFrame(std::string info);

	private:

		FrameController();
		FrameController(FrameController&) = delete;
		FrameController(FrameController&&) = delete;
		FrameController& operator=(FrameController&) = delete;
		FrameController& operator=(FrameController&&) = delete;

	private:

		MainFrame* mainFrame;
		TestServerFrame* testServerFrame;
		TestClientFrame* testClientFrame;
		TestAllFrame* testAllFrame;
		PopupFrame* popupFrame;

	};

}

#endif