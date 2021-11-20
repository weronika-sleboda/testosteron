#ifndef TEST_SERVER_FRAME_H
#define TEST_SERVER_FRAME_H

#include <wx/wx.h>
#include "colour_palette.h"
#include "test.h"

namespace testosteron
{

	class TestServerFrame : public wxFrame
	{

	public:

		TestServerFrame();

	private:

		ColourPalette colour;
		Test test;

	private:

		void setupTitlePanel();
		void setupFailedFunctionsInfoPanel();
		void setupFailedFunctionsListBox();
		void setupTestFunctionsInfoPanel();
		void setupTestFunctionsListBox();
		void setupOutputInfoPanel();
		void setupButtons();
		void setupAuthorInfo();
		void activateButtons();
		void activateFailedFunctionsListBox();

		//*** Button Actions

		void onClickTest(wxCommandEvent& event);
		void onClickExit(wxCommandEvent& event);

		//*** Failed Functions ListBox Action

		void onClickShowInfo(wxCommandEvent& event);

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

		//*** Failed Functions Info Panel

		wxPanel failedFunctionsInfoBorderPanel;
		wxPanel failedFunctionsInfoPanel;
		wxStaticText failedFunctionsInfo;

		//*** Failed Functions List Box

		wxListBox failedFunctionsListBox;

		//*** Test Functions Info Panel

		wxPanel testFunctionsInfoBorderPanel;
		wxPanel testFunctionsInfoPanel;
		wxStaticText testFunctionsInfo;

		//*** Test Function List Box

		wxListBox testFunctionsListBox;

		//*** Buttons

		wxButton testButton;
		wxButton exitButton;

		//*** Author info

		wxStaticText authorInfo;

	};

}

#endif