#include "main_frame.h"
#include "frame_controller.h"
#include <string>

namespace testosteron
{

	MainFrame::MainFrame() :

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
		"READY TO TEST.\nChoose a function from the list below.",
		wxPoint { 40, 145 },
		wxSize { 400, 50 }

	},

		functionInfoBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 220 },
		wxSize { 440, 37 }

	},

		functionInfoPanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 223 },
		wxSize { 434, 31 }

	},

		functionInfo
	{

		this,
		wxID_ANY,
		"Available functions:",
		wxPoint { 40, 229 },
		wxSize { 410, 20 }

	},

		listBox
	{

		this,
		wxID_ANY,
		wxPoint { 20, 265 },
		wxSize { 440, 180 }

	},
	
		testButton
	{

		this,
		wxID_ANY,
		"TEST",
		wxPoint { 20, 460 },
		wxSize { 440, 30 }

	},
		testClientButton
	{

		this,
		wxID_ANY,
		"TEST CLIENT",
		wxPoint { 20, 500 },
		wxSize { 140, 30 }

	},
		
		testServerButton
	{

		this,
		wxID_ANY,
		"TEST SERVER",
		wxPoint { 170, 500 },
		wxSize { 140, 30 }

	},
	
		testAllButton
	{

		this,
		wxID_ANY,
		"TEST ALL",
		wxPoint { 320, 500 },
		wxSize { 140, 30 }

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
		setupFunctionInfoPanel();
		setupListBox();
		setupButtons();
		setupAuthorInfo();
		activateButtons();
	
	}

	void MainFrame::setupTitlePanel()
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

	void MainFrame::setupOutputInfoPanel()
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


	void MainFrame::setupFunctionInfoPanel()
	{

		wxFont font
		{

			10,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_BOLD

		};

		functionInfoBorderPanel.SetBackgroundColour
		(colour.superDarkGray);

		functionInfoPanel.SetBackgroundColour(colour.middleGray);
		functionInfo.SetBackgroundColour(colour.middleGray);
		functionInfo.SetForegroundColour(colour.superDarkGray);
		functionInfo.SetFont(font);

	}

	void MainFrame::setupListBox()
	{

		wxFont font
		{

			12,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_LIGHT

		};

		listBox.SetBackgroundColour(colour.darkGray);
		listBox.SetForegroundColour(colour.lightGray);
		listBox.SetFont(font);

		for (unsigned int index = 0; index < test.singleTest().size(); index++)
		{

			listBox.AppendString
			(test.singleTest().at(index).getFunctionName());

		}

		listBox.SetSelection(0);

	}

	void MainFrame::setupButtons()
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

		testClientButton.SetBackgroundColour(colour.lightGray);
		testClientButton.SetForegroundColour(colour.superDarkGray);
		testClientButton.SetFont(font);

		testServerButton.SetBackgroundColour(colour.lightGray);
		testServerButton.SetForegroundColour(colour.superDarkGray);
		testServerButton.SetFont(font);

		testAllButton.SetBackgroundColour(colour.lightGray);
		testAllButton.SetForegroundColour(colour.superDarkGray);
		testAllButton.SetFont(font);

	}

	void MainFrame::setupAuthorInfo()
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

	void MainFrame::activateButtons()
	{

		testButton.Bind
		(wxEVT_BUTTON, &MainFrame::onClickTest, this);

		testClientButton.Bind
		(wxEVT_BUTTON, &MainFrame::onClickTestClient, this);

		testServerButton.Bind
		(wxEVT_BUTTON, &MainFrame::onClickTestServer, this);

		testAllButton.Bind
		(wxEVT_BUTTON, &MainFrame::onClickTestAll, this);

	}

	void MainFrame::onClickTest(wxCommandEvent& event)
	{

		unsigned int chosenTest = listBox.GetSelection();

		output.SetLabel(test.singleTestOutput(chosenTest));

		if (test.singleTest().at(chosenTest).hasPassed())
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

	void MainFrame::onClickTestClient(wxCommandEvent& event)
	{
		
		Hide();

		FrameController::frameController().showTestClientFrame();
		event.Skip();

	}

	void MainFrame::onClickTestServer(wxCommandEvent& event)
	{

		Hide();

		FrameController::frameController().showTestServerFrame();
		event.Skip();

	}

	void MainFrame::onClickTestAll(wxCommandEvent& event)
	{

		Hide();

		FrameController::frameController().showTestAllFrame();
		event.Skip();

	}

}