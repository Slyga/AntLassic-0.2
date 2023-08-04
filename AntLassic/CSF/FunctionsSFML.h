#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ClassesSFML.h"

using namespace std;
using namespace sf;

namespace ClassesSFML
{	
	/// <summary>
	/// Задержка в 100 мс
	/// </summary>
	void Delay();
	
	/// <summary>
	/// Обновление таймера
	/// </summary>
	/// <returns>Вернуть таймер</returns>
	float getTimer();
}