// Copyright (c) 2007, Niels Martin Hansen
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of the Aegisub Group nor the names of its contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Aegisub Project http://www.aegisub.org/
//
// $Id$

/// @file video_provider_dummy.h
/// @see video_provider_dummy.cpp
/// @ingroup video_input
///

// The dummy video provider needs a header, since it needs to be created directly as a special case

#ifndef _VIDEO_PROVIDER_DUMMY_H

/// DOCME
#define _VIDEO_PROVIDER_DUMMY_H


///////////
// Headers
#include "include/aegisub/video_provider.h"
#include <wx/colour.h>
#include "vfr.h"



/// DOCME
/// @class DummyVideoProvider
/// @brief DOCME
///
/// DOCME
class DummyVideoProvider : public VideoProvider {
private:

	/// DOCME
	int lastFrame;

	/// DOCME
	int framecount;

	/// DOCME
	double fps;

	/// DOCME
	int width;

	/// DOCME
	int height;

	/// DOCME
	AegiVideoFrame frame;

	void Create(double fps, int frames, int _width, int _height, const wxColour &colour, bool pattern);

public:
	DummyVideoProvider(wxString filename);
	DummyVideoProvider(double fps, int frames, int _width, int _height, const wxColour &colour, bool pattern);
	~DummyVideoProvider();

	const AegiVideoFrame GetFrame(int n);
	static wxString MakeFilename(double fps, int frames, int _width, int _height, const wxColour &colour, bool pattern);

	int GetPosition();
	int GetFrameCount();

	int GetWidth();
	int GetHeight();
	double GetFPS();


	/// @brief DOCME
	/// @return 
	///
	bool AreKeyFramesLoaded() { return false; };

	/// @brief DOCME
	/// @return 
	///
	wxArrayInt GetKeyFrames() { return wxArrayInt(); };

	/// @brief DOCME
	/// @return 
	///
	bool IsVFR() { return false; };

	/// @brief DOCME
	/// @return 
	///
	bool NeedsVFRHack() { return true; }

	/// @brief DOCME
	///
	FrameRate GetTrueFrameRate() { return FrameRate(); };

	wxString GetDecoderName();
};

#endif

