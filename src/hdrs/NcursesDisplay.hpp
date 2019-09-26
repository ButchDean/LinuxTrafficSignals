#ifndef _NCURSES_DISPLAY_
#define _NCURSES_DISPLAY_

#include <SignalFrames.hpp>

#include <curses.h>

namespace NSNcursesDisplay
{
	class CNcursesDisplay : private NSSignalFrames::CSignalFrames
	{
		public:

			CNcursesDisplay(){}
			~CNcursesDisplay(){}

			void MapAndDisplaySignal()
			{
				auto frameConfig = [this](const std::string frmFile)
				{
					ReadFrameData(frmFile, frameOut);
				};

				frameConfig("simple.frm");
			}

			// Expose retrieved frame data stored in string vector
			std::vector<std::string> GetFrameStringData()
			{
				if(frameOut.empty())
				{
					std::cerr << "Error: Confirm MapAndDisplaySignal() completed successfully." << std::endl;
				}

				return frameOut;
			}

		private:

			std::vector<std::string> frameOut;
	};
}

#endif
