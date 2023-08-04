#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "csf.h"

#define WINDOW_CLOSE -1
#define SCENE_CONTINUE 0
#define SCENE�_MEIN_MENU 1

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
	/// ����������
	/// </summary>
	/// <param name="window">����</param>
	ScenesMainMenu(RenderWindow& window);

	/// <summary>
	/// ����������/��������� ���a
	/// </summary>
	/// <param name="window">����</param>
	/// <returns></returns>
	virtual int Update(RenderWindow& window) override;

	/// <summary>
	/// ��������a �������� �����
	/// </summary>
	/// <param name="window">����</param>
	virtual void Draw(RenderWindow& window) override;

	/// <summary>
	/// �������� �a���� ���a
	/// </summary>
	virtual void Reborn() override;
	/// <summary>
	/// �������� �����
	/// </summary>
	/// <param name="window">����</param>
	/// <returns>������� ����� ������ �� ������ ����� ���� � �� ���� ��� ������� ������������ ������ �� ������ �����</returns>
	static Scene* getScene(RenderWindow& window);
	/// <summary>
	/// �����a� ������a �����
	/// </summary>
	/// <returns>������� ������ �� ������ �����</returns>
	static Scene* getScene();
	/// <summary>
	/// ������� ���������� �� �����
	/// </summary>
	/// <returns>true � ����� ����������, false � ����� �� ����������</returns>
	static bool isScene();
};