#ifndef COLOUR_PALETTE_H
#define COLOUR_PALETTE_H

#include <wx/wx.h>

namespace testosteron
{

	struct ColourPalette
	{

		const wxColour const lightGray;
		const wxColour const gray;
		const wxColour const middleGray;
		const wxColour const darkGray;
		const wxColour const superDarkGray;

		//*** Testing State Colours
		
		const wxColour const yellow;
		const wxColour const red;
		const wxColour const green;

		ColourPalette() :

			lightGray { 209, 209, 209 },
			gray { 145, 145, 145 },
			middleGray { 105, 105, 105 } ,
			darkGray { 56, 56, 56 } ,
			superDarkGray { 33, 33, 33} ,
			yellow { 255, 204, 64 } ,
			red { 255, 64, 64},
			green { 86, 255, 64 } 

		{}

	};

}

#endif