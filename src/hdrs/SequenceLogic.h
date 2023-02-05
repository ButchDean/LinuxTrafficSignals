#ifndef _SEQUENCE_LOGIC_
#define _SEQUENCE_LOGIC_

// Code that deals with light sequence flipping.

namespace SequenceLogic
{
	enum SignalColor {RED, AMBER, GREEN};

	class CLightsStatus
	{
		public:
			
			~CLightsStatus(){}

			static CLightsStatus* LightsStatusInst()
			{
				if(!ls)
					ls = new CLightsStatus();

				return ls;
			}

			void SetStatus(const SignalColor color);

			void ClearSignals();

			bool GetStatus(const SignalColor color) const;

		private:

			CLightsStatus(){}

			static CLightsStatus* ls;

			unsigned char systemStatus; // Bit 2 Red. Bit 1 Amber. Bit 0 Green.
	};
}

#endif
