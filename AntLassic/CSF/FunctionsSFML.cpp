#include "FunctionsSFML.h"

namespace ClassesSFML
{
	Clock clockMenu;

	void Delay()
	{
		sleep(milliseconds(100));
	}

	float getTimer()
	{
		float timeMenu = (float)clockMenu.getElapsedTime().asMicroseconds();
		clockMenu.restart();
		return timeMenu / 1200;
	}
}