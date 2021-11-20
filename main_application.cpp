#include "main_application.h"
#include "frame_controller.h"

namespace testosteron
{

	wxIMPLEMENT_APP(MainApplication);

	bool MainApplication::OnInit()
	{

		FrameController::frameController().showMainFrame();

		return true;

	}

}

