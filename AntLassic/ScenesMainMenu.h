#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "csf.h"

#define WINDOW_CLOSE -1
#define SCENE_CONTINUE 0
#define SCENEЫ_MEIN_MENU 1

using namespace sf;
using namespace std;
using namespace csf;

class ScenesMainMenu :
    public Scene
{
	enum Status { Start, Game, Final } status;

	static Scene* scene;

	mySprite SP_Background;
	Button BT_Exit, BT_Options, BT_Load, BT_Start;

public:
	/// <summary>
	/// Констуктор
	/// </summary>
	/// <param name="window">Окно</param>
	ScenesMainMenu(RenderWindow& window);

	/// <summary>
	/// Обновление/Оживление окнa
	/// </summary>
	/// <param name="window">Окно</param>
	/// <returns></returns>
	virtual int Update(RenderWindow& window) override;

	/// <summary>
	/// Отрисовкa объектов сцены
	/// </summary>
	/// <param name="window">Окно</param>
	virtual void Draw(RenderWindow& window) override;

	/// <summary>
	/// Удаление дaнных окнa
	/// </summary>
	virtual void Reborn() override;
	/// <summary>
	/// Создание сцены
	/// </summary>
	/// <param name="window">Окно</param>
	/// <returns>Возврат новой ссылки на объект сцены если её не было или возврат существующей ссылки на объект сцены</returns>
	static Scene* getScene(RenderWindow& window);
	/// <summary>
	/// Возврaт объектa сцены
	/// </summary>
	/// <returns>Возврат ссылки на объект сцены</returns>
	static Scene* getScene();
	/// <summary>
	/// Возврат существует ли сцена
	/// </summary>
	/// <returns>true — сцена существует, false — сцена не существует</returns>
	static bool isScene();
};