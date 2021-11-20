#ifndef POPUP_FRAME_H
#define POPUP_FRAME_H

#include <wx/wx.h>
#include <string>
#include "colour_palette.h"

namespace testosteron
{

	class PopupFrame : public wxFrame
	{

	public:

		PopupFrame();
		void setupInfoPanel();
		void changeInfo(std::string info);

	private:

		ColourPalette colour;
		wxPanel infoPanel;
		wxStaticText info;

	};
}

#endif