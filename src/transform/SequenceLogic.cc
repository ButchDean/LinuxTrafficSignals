#include <SequenceLogic.h>

#define SHIFTLEFT(n) (1 << n)

namespace SequenceLogic
{
	void CLightsStatus::SetStatus(const SignalColor color)
	{
		// Bit 2 Red. Bit 1 Amber. Bit 0 Green.
		switch(color)
		{
			case RED:
				systemStatus |= SHIFTLEFT(2);
				break;
			case AMBER:
				systemStatus |= SHIFTLEFT(1);
				break;
			case GREEN:
				systemStatus |= SHIFTLEFT(0);
				break;
			default:
				break;
		}
	}

	void CLightsStatus::ClearSignals()
	{
		systemStatus &= ~SHIFTLEFT(2);
		systemStatus &= ~SHIFTLEFT(1);
		systemStatus &= ~SHIFTLEFT(0);
	}

	bool CLightsStatus::GetStatus(const SignalColor color) const 
	{
		// Bit 2 Red. Bit 1 Amber. Bit 0 Green.
		switch(color)
		{
			case RED:
				if(systemStatus & SHIFTLEFT(2))
					return true;
				break;
			case AMBER:
				if(systemStatus & SHIFTLEFT(1))
					return true;
				break;
			case GREEN:
				if(systemStatus & SHIFTLEFT(0))
					return true;
				break;
			default:
				break;
		}
		
		return false;
	}

}
