#include <memory>
#include <cassert>
#include <thread>
#include <chrono>
#include <NcursesDisplay.hpp>
#include <SequenceLogic.hpp>

using namespace SequenceLogic;

#define OFF_LIGHT_PAIR		0
#define FRAME_PAIR 			1
#define RED_LIGHT_PAIR		2
#define AMBER_LIGHT_PAIR	3
#define GREEN_LIGHT_PAIR	4

CLightsStatus* CLightsStatus::ls = nullptr;

void SetUpColors()
{
	start_color();
	init_pair(OFF_LIGHT_PAIR, COLOR_BLACK, COLOR_BLACK);
	init_pair(FRAME_PAIR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(RED_LIGHT_PAIR, COLOR_RED, COLOR_RED);
	init_pair(AMBER_LIGHT_PAIR, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(GREEN_LIGHT_PAIR, COLOR_GREEN, COLOR_GREEN);
}

void RenderColoredChar(const unsigned int row, const unsigned int col, const char ch)
{
	auto setAttrOnStatus = [](const short color, const bool on) 
			{ 
				if(on)
					attron(COLOR_PAIR(color));
				else
					attron(COLOR_PAIR(OFF_LIGHT_PAIR));
			};
	auto setAttrOffStatus = [](const short color, const bool on) 
			{
				if(on) 
					attroff(COLOR_PAIR(color));
				else
					attron(COLOR_PAIR(OFF_LIGHT_PAIR)); 
			};

	switch(ch)
	{
		case '+':
			attron(COLOR_PAIR(FRAME_PAIR));
			mvaddch(row, col, ch);
			attroff(COLOR_PAIR(FRAME_PAIR));
			break;
		case 'r':
			setAttrOnStatus(RED_LIGHT_PAIR, CLightsStatus::LightsStatusInst()->GetStatus(RED));
			mvaddch(row, col, ch);
			setAttrOffStatus(RED_LIGHT_PAIR, CLightsStatus::LightsStatusInst()->GetStatus(RED));
			break;
		case 'a':
			setAttrOnStatus(AMBER_LIGHT_PAIR, CLightsStatus::LightsStatusInst()->GetStatus(AMBER));
			mvaddch(row, col, ch);
			setAttrOffStatus(AMBER_LIGHT_PAIR, CLightsStatus::LightsStatusInst()->GetStatus(AMBER));
			break;
		case 'g':
			setAttrOnStatus(GREEN_LIGHT_PAIR, CLightsStatus::LightsStatusInst()->GetStatus(GREEN));
			mvaddch(row, col, ch);
			setAttrOffStatus(GREEN_LIGHT_PAIR, CLightsStatus::LightsStatusInst()->GetStatus(GREEN));
			break;
		default:
			break;				
	}
}

void StatusSTOP()
{
	CLightsStatus::LightsStatusInst()->ClearSignals();
	CLightsStatus::LightsStatusInst()->SetStatus(RED);
}

void StatusPREPARE_TO_STOP()
{
	CLightsStatus::LightsStatusInst()->ClearSignals();
	CLightsStatus::LightsStatusInst()->SetStatus(AMBER);
}

void StatusGO()
{
	CLightsStatus::LightsStatusInst()->ClearSignals();
	CLightsStatus::LightsStatusInst()->SetStatus(GREEN);
}

int main()
{
    std::unique_ptr<NSNcursesDisplay::CNcursesDisplay> frame(new NSNcursesDisplay::CNcursesDisplay());

    frame->MapAndDisplaySignal();

	std::vector<std::string> constructedFrameData = frame->GetFrameStringData();

    // Curses initialization
    initscr();
    cbreak();
    noecho();

	// Does this terminal support colors?
	if(has_colors() == FALSE)
	{
		endwin();
		assert("Colors not supported in this terminal." && false);
	}

	SetUpColors();

	// Statuses updated here.
	StatusPREPARE_TO_STOP();

	curs_set(0);

    int cycle = 0;

    StatusSTOP();

    while(true)
    {
        clear();

	    for(int idx = 1; idx < constructedFrameData.size(); idx++)
		    for(int jdx = 0; jdx < constructedFrameData[idx].size(); jdx++)
		    {
			    RenderColoredChar(idx, jdx, constructedFrameData[idx][jdx]);
		    }

        if(cycle > 30)
            cycle = 0;

        if(cycle % 3 == 0)
            StatusGO();
        else if(cycle % 3 == 1)
            StatusPREPARE_TO_STOP();
        else if(cycle % 3 == 2)
            StatusSTOP();

	    refresh();

        std::this_thread::sleep_for(std::chrono::seconds(2));

        cycle++;

    }

    // Clean up Curses

    endwin();

    exit(0);
}
