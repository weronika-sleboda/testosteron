#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>
#include "colour_palette.h"
#include "test.h"

namespace testosteron
{

	class FrameController;

	class MainFrame : public wxFrame
	{

	public:

		MainFrame();

	private:

		void setupTitlePanel();
		void setupListBox();
		void setupFunctionInfoPanel();
		void setupOutputInfoPanel();
		void setupButtons();
		void setupAuthorInfo();
		void activateButtons();

		//*** Button Actions

		void onClickTest(wxCommandEvent& event);
		void onClickTestClient(wxCommandEvent& event);
		void onClickTestServer(wxCommandEvent& event);
		void onClickTestAll(wxCommandEvent& event);

	private:

		ColourPalette colour;
		Test test;

	private:

		//*** Ttitle Panel

		wxPanel titleBorderPanel;
		wxPanel titlePanel;
		wxStaticText title;

		//*** Output Info Panel

		wxPanel outputInfoBorderPanel;
		wxPanel outputInfoPanel;
		wxStaticText outputInfo;

		//*** Output Panel

		wxPanel outputBorderPanel;
		wxPanel outputPanel;
		wxStaticText output;

		//*** Function Info Panel

		wxPanel functionInfoBorderPanel;
		wxPanel functionInfoPanel;
		wxStaticText functionInfo;

		//*** List Box

		wxListBox listBox;

		//*** Buttons

		wxButton testButton;
		wxButton testClientButton;
		wxButton testServerButton;
		wxButton testAllButton;

		//*** Author info

		wxStaticText authorInfo;

	};

}

#endif