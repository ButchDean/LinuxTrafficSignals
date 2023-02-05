#ifndef _SIGNAL_FRAMES_
#define _SIGNAL_FRAMES_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace NSSignalFrames
{

    class CSignalFrames
    {
        public:
            CSignalFrames(){}
            ~CSignalFrames(){}

            void ReadFrameData(const std::string& filename, std::vector<std::string>& asciiFrameOut)
            {
                std::ifstream frameFile("../assets/" + filename);

				line.clear();

                if(frameFile.is_open())
                {
                    while(std::getline(frameFile, line))
                    {
						// Strip out commented lines so they aren't processed.
						if(line.find("#") != std::string::npos)
							continue;

                        asciiFrameOut.push_back(line);
                    }

                    frameFile.close();
                }
                else
                {
                    std::cout << "Failed to open frame data." << std::endl;
                }
            }

            virtual void MapAndDisplaySignal() = 0;

        private:

            std::string line;

    };

}

#endif
