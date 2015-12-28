﻿
/*
Copyright (c) 2015 Maximus5
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#pragma once

#include <windows.h>
#include "../common/RgnDetect.h"

//type

class CVConLine
{
public:
	CVConLine();
	~CVConLine();

public:
	// Methods
	void SetDialogs(int anDialogsCount, SMALL_RECT* apDialogs, DWORD* apnDialogFlags, DWORD anDialogAllFlags, const SMALL_RECT& arcUCharMap);
	void ParseLine(bool abForce, uint anTextWidth, wchar_t* apConCharLine, CharAttr* apConAttrLine, const wchar_t* const ConCharLine2, const CharAttr* const ConAttrLine2);

protected:
	// Methods

protected:
	// Members
	int mn_DialogsCount;
	const SMALL_RECT* mrc_Dialogs/*[MAX_DETECTED_DIALOGS]*/;
	const DWORD* mn_DialogFlags/*[MAX_DETECTED_DIALOGS]*/;
	DWORD mn_DialogAllFlags;
	// Far Manager's UnicodeCharMap plugin
	SMALL_RECT mrc_UCharMap;
	// Drawing parameters below
	uint TextWidth;
	// Full redraw was requested
	bool isForce;
	// What we are parsing now
	const wchar_t* ConCharLine/*[TextWidth]*/;
	const CharAttr* ConAttrLine/*[TextWidth]*/;
	// Temp buffer to return parsed parts to draw
	wchar_t* wcTempDraw/*[TextWidth]*/;
	char* cTempDraw/*[TextWidth]*/;
};

bool isCharAltFont(wchar_t inChar);
bool isCharPseudographics(wchar_t inChar);
bool isCharBorderVertical(wchar_t inChar);
bool isCharProgress(wchar_t inChar);
bool isCharScroll(wchar_t inChar);
bool isCharSeparate(wchar_t inChar);
bool isCharSpace(wchar_t inChar);
bool isCharRTL(wchar_t inChar);
