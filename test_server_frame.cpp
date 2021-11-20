#include "test_server_frame.h"
#include "frame_controller.h"
#include <thread>

namespace testosteron
{

	TestServerFrame::TestServerFrame() :

		wxFrame
	{

		nullptr,
		wxID_ANY,
		"Testosteron",
		wxPoint { 10, 10 },
		wxSize { 500, 620 }

	},

		titleBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 20 },
		wxSize { 440, 60 }

	},

		titlePanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 23 },
		wxSize { 433, 53 }

	},

		title
	{

		this,
		wxID_ANY,
		">>TESTOSTERON<<",
		wxPoint { 55, 27 },
		wxSize { 300, 40 }

	},

		outputInfoBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 90 },
		wxSize { 440, 37 }

	},

		outputInfoPanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 93 },
		wxSize { 434, 31 }

	},

		outputInfo
	{

		this,
		wxID_ANY,
		"Output:",
		wxPoint { 40, 99 },
		wxSize { 410, 20 }

	},

		outputBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 133 },
		wxSize { 440, 67 }

	},

		outputPanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 136 },
		wxSize { 434, 61 }

	},

		output
	{

		this,
		wxID_ANY,
		"READY TO TEST. Testing server. "
		"\nClick on failed function for more information.",
		wxPoint { 40, 145 },
		wxSize { 400, 50 }

	},

		failedFunctionsInfoBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 220 },
		wxSize { 210, 37 }

	},

		failedFunctionsInfoPanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 223 },
		wxSize { 204, 31 }

	},

		failedFunctionsInfo
	{

		this,
		wxID_ANY,
		"Failed functions:",
		wxPoint { 40, 229 },
		wxSize { 187, 20 }

	},

		failedFunctionsListBox
	{

		this,
		wxID_ANY,
		wxPoint { 20, 265 },
		wxSize { 210, 180 }

	},

		testFunctionsInfoBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 240, 220 },
		wxSize { 220, 37 }

	},

		testFunctionsInfoPanel
	{

		this,
		wxID_ANY,
		wxPoint { 243, 223 },
		wxSize { 214, 31 }

	},

		testFunctionsInfo
	{

		this,
		wxID_ANY,
		"Test functions:",
		wxPoint { 260, 229 },
		wxSize { 190, 20 }

	},

		testFunctionsListBox
	{

		this,
		wxID_ANY,
		wxPoint { 240, 265 },
		wxSize { 220, 180 }

	},

		testButton
	{

		this,
		wxID_ANY,
		"TEST SERVER",
		wxPoint { 20, 460 },
		wxSize { 440, 30 }

	},

		exitButton
	{

		this,
		wxID_ANY,
		"EXIT",
		wxPoint { 20, 500 },
		wxSize { 440, 30 }

	},

		authorInfo
	{

		this,
		wxID_ANY,
		"2021 Weronika Sleboda",
		wxPoint { 35, 546 },
		wxSize { 440, 30 }

	}

		//*** Constructor Body

	{

		SetBackgroundColour(colour.gray);
		setupTitlePanel();
		setupOutputInfoPanel();
		setupFailedFunctionsInfoPanel();
		setupFailedFunctionsListBox();
		setupTestFunctionsInfoPanel();
		setupTestFunctionsListBox();
		setupButtons();
		setupAuthorInfo();
		activateButtons();
		activateFailedFunctionsListBox();

	}

	void TestServerFrame::setupTitlePanel()
	{

		wxFont font
		{

			28,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_ITALIC,
			wxFONTWEIGHT_HEAVY

		};

		titleBorderPanel.SetBackgroundColour(colour.darkGray);
		titlePanel.SetBackgroundColour(colour.superDarkGray);
		title.SetBackgroundColour(colour.superDarkGray);
		title.SetForegroundColour(colour.lightGray);
		title.SetFont(font);

	}

	void TestServerFrame::setupOutputInfoPanel()
	{

		wxFont infoFont
		{

			10,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_BOLD

		};

		wxFont outputFont
		{

			12,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_LIGHT

		};

		outputInfoBorderPanel.SetBackgroundColour
		(colour.superDarkGray);

		outputInfoPanel.SetBackgroundColour(colour.middleGray);
		outputInfo.SetBackgroundColour(colour.middleGray);
		outputInfo.SetForegroundColour(colour.superDarkGray);
		outputInfo.SetFont(infoFont);

		outputBorderPanel.SetBackgroundColour(colour.superDarkGray);
		outputPanel.SetBackgroundColour(colour.yellow);
		output.SetBackgroundColour(colour.yellow);
		output.SetForegroundColour(colour.superDarkGray);
		output.SetFont(outputFont);

	}


	void TestServerFrame::setupFailedFunctionsInfoPanel()
	{

		wxFont font
		{

			10,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_BOLD

		};

		failedFunctionsInfoBorderPanel.SetBackgroundColour
		(colour.superDarkGray);

		failedFunctionsInfoPanel.SetBackgroundColour(colour.middleGray);
		failedFunctionsInfo.SetBackgroundColour(colour.middleGray);
		failedFunctionsInfo.SetForegroundColour(colour.superDarkGray);
		failedFunctionsInfo.SetFont(font);

	}

	void TestServerFrame::setupFailedFunctionsListBox()
	{

		wxFont font
		{

			10,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_LIGHT

		};

		failedFunctionsListBox.SetBackgroundColour
		(colour.darkGray);

		failedFunctionsListBox.SetOwnForegroundColour
		(colour.lightGray);

		failedFunctionsListBox.SetFont(font);

	}

	void TestServerFrame::setupTestFunctionsInfoPanel()
	{

		wxFont font
		{

			10,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_BOLD

		};

		testFunctionsInfoBorderPanel.SetBackgroundColour
		(colour.superDarkGray);

		testFunctionsInfoPanel.SetBackgroundColour(colour.middleGray);
		testFunctionsInfo.SetBackgroundColour(colour.middleGray);
		testFunctionsInfo.SetForegroundColour(colour.superDarkGray);
		testFunctionsInfo.SetFont(font);

	}

	void TestServerFrame::setupTestFunctionsListBox()
	{
		
		wxFont font
		{

			10,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_LIGHT

		};

		testFunctionsListBox.Disable();
		testFunctionsListBox.SetBackgroundColour
		(colour.superDarkGray);

		testFunctionsListBox.SetOwnForegroundColour
		(colour.lightGray);

		testFunctionsListBox.SetFont(font);


		//*** Show Test Functions

		for (unsigned int index = 0; index < test.serverTest().size(); index++)
		{

			testFunctionsListBox.AppendString
			(test.serverTest().at(index).getFunctionName());

		}

	}

	void TestServerFrame::setupButtons()
	{

		wxFont font
		{

			12,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_HEAVY

		};

		testButton.SetBackgroundColour(colour.lightGray);
		testButton.SetForegroundColour(colour.superDarkGray);
		testButton.SetFont(font);

		exitButton.SetBackgroundColour(colour.lightGray);
		exitButton.SetForegroundColour(colour.superDarkGray);
		exitButton.SetFont(font);

	}

	void TestServerFrame::setupAuthorInfo()
	{

		wxFont font
		{

			10,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_ITALIC,
			wxFONTWEIGHT_LIGHT

		};

		authorInfo.SetForegroundColour(colour.darkGray);
		authorInfo.SetFont(font);

	}

	void TestServerFrame::activateButtons()
	{

		testButton.Bind
		(wxEVT_BUTTON, &TestServerFrame::onClickTest, this);

		exitButton.Bind
		(wxEVT_BUTTON, &TestServerFrame::onClickExit, this);

	}

	void TestServerFrame::onClickTest(wxCommandEvent& event)
	{

		//*** Show Failed Functions

		failedFunctionsListBox.Clear();

		for (unsigned int index = 0; index < test.serverTest().size(); index++)
		{

			if (!test.serverTest().at(index).hasPassed())
			{

				failedFunctionsListBox.AppendString
				(test.serverTest().at(index).getFunctionName());

			}

		}

		//*** Show Output

		output.SetLabel
		(test.specializedTestOutput(test.serverTest(), "Server"));

		if (test.hasPassed())
		{

			outputPanel.SetBackgroundColour(colour.green);
			output.SetBackgroundColour(colour.green);

		}

		else
		{

			outputPanel.SetBackgroundColour(colour.red);
			output.SetBackgroundColour(colour.red);

		}

		outputPanel.Refresh();
		output.Refresh();
		
		event.Skip();

	}

	void TestServerFrame::onClickExit(wxCommandEvent& event)
	{

		Hide();

				outputPanel.SetBackgroundColour(colour.yellow);
		output.SetBackgroundColour(colour.yellow);

		output.SetLabel
		(

			"READY TO TEST. Testing client. "
			"\nClick on failed function for more information."

		);

		failedFunctionsListBox.Clear();

		FrameController::frameController().showMainFrame();

		event.Skip();

	}

	void TestServerFrame::activateFailedFunctionsListBox()
	{

		failedFunctionsListBox.Bind
		(wxEVT_LISTBOX, &TestServerFrame::onClickShowInfo, this);

	}

	void TestServerFrame::onClickShowInfo
	(wxCommandEvent& event)
	{

		unsigned int selectedFunction = failedFunctionsListBox.GetSelection();

		std::string info = 

			test.getFailedFunctionName(selectedFunction) + "\n" +
			test.getFailedFunctionResult(selectedFunction);

		FrameController::frameController().showPopupFrame(info);

		failedFunctionsListBox.DeselectAll();

		event.Skip();

	}

}