#include "popup_frame.h"

namespace testosteron
{

	PopupFrame::PopupFrame() :

		wxFrame
	{

		nullptr,
		wxID_ANY,
		"INFO",
		wxPoint { 120, 240 },
		wxSize { 320, 200 }

	},

		infoPanel
	{

		this,
		wxID_ANY,
		wxPoint { 10, 10 },
		wxSize { 285, 140 }

	},

		info
	{

		this,
		wxID_ANY,
		"",
		wxPoint { 20, 60 },
		wxSize { 100, 60 }

	}

	//*** Constructor Body

	{
	
		SetBackgroundColour(colour.darkGray);
		setupInfoPanel();
	
	}

	void PopupFrame::setupInfoPanel()
	{

		wxFont font
		{

			12,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_LIGHT

		};

		infoPanel.SetBackgroundColour(colour.red);

		info.SetFont(font);
		info.SetBackgroundColour(colour.red);
		info.SetForegroundColour(colour.superDarkGray);

	}

	void PopupFrame::changeInfo(std::string theInfo)
	{

		info.SetLabel(theInfo);

	}
}