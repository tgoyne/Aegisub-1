// Copyright (c) 2008-2009, Karl Blomster
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

/// @file video_provider_ffmpegsource.h
/// @see video_provider_ffmpegsource.cpp
/// @ingroup video_input ffms
///

#ifdef WITH_FFMS2
#ifndef AGI_PRE
#include <vector>
#endif

#include "ffmpegsource_common.h"
#include "include/aegisub/video_provider.h"
#include "video_frame.h"

/// @class FFmpegSourceVideoProvider
/// @brief Implements video loading through the FFMS library.
class FFmpegSourceVideoProvider : public VideoProvider, FFmpegSourceProvider {
	/// video source object
	agi::scoped_holder<FFMS_VideoSource*, void (FFMS_CC*)(FFMS_VideoSource*)> VideoSource;
	const FFMS_VideoProperties *VideoInfo; ///< video properties

	int Width;                      ///< width in pixels
	int Height;                     ///< height in pixels
	double DAR;                     ///< display aspect ratio
	int FrameNumber;                ///< current framenumber
	std::vector<int> KeyFramesList; ///< list of keyframes
	agi::vfr::Framerate Timecodes;  ///< vfr object
	wxString ColorSpace;            ///< Colorspace name

	AegiVideoFrame CurFrame;        ///< current video frame

	char FFMSErrMsg[1024];          ///< FFMS error message
	FFMS_ErrorInfo ErrInfo;         ///< FFMS error codes/messages

	void LoadVideo(wxString filename);

public:
	FFmpegSourceVideoProvider(wxString filename);

	const AegiVideoFrame GetFrame(int n);

	int GetFrameCount() const { return VideoInfo->NumFrames; }
	int GetWidth() const { return Width; }
	int GetHeight() const { return Height; }
	double GetDAR() const { return DAR; }
	agi::vfr::Framerate GetFPS() const { return Timecodes; }

	wxString GetColorSpace() const { return ColorSpace; }

	/// @brief Gets a list of keyframes
	/// @return	Returns a wxArrayInt of keyframes.
	std::vector<int> GetKeyFrames() const { return KeyFramesList; };
	wxString GetDecoderName() const { return "FFmpegSource"; }
	/// @brief Gets the desired cache behavior.
	/// @return Returns true.
	bool WantsCaching() const { return true; }
};
#endif /* WITH_FFMS2 */
