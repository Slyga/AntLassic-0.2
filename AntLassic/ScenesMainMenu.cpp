#include "ScenesMainMenu.h"

Scene* ScenesMainMenu::scene;


ScenesMainMenu::ScenesMainMenu(RenderWindow& window)
{
	status = Start;
	SP_Background.Reload("SP_Background");
	BT_Exit.Reload("BT_Exit");
	BT_Options.Reload("BT_Options");
	BT_Load.Reload("BT_Load");
	BT_Start.Reload("BT_Start");
}

int ScenesMainMenu::Update(RenderWindow& window)
{
	if (BT_Exit.Pressed(event, window)) { window.close(); }
	if (BT_Options.Pressed(event, window)) {}
	if (BT_Load.Pressed(event, window)) {}
	if (BT_Start.Pressed(event, window)) {}

	switch (status)
	{
	case ScenesMainMenu::Start:

		break;

	case ScenesMainMenu::Game:

		break;

	case ScenesMainMenu::Final:

		break;
	}

	return SCENE_CONTINUE;
}

void ScenesMainMenu::Draw(RenderWindow& window)
{
	window.clear(); {

		SP_Background >> window;
		BT_Exit >> window;
		BT_Options >> window;
		BT_Load >> window;
		BT_Start >> window;

		switch (status)
		{
		case ScenesMainMenu::Start:

			break;
		case ScenesMainMenu::Game:
 1reak;
		}
	} window.display();
}

void ScenesMainMenu::Reborn()
{
	BT_Exit.Delete();
	BT_Options.Delete();
	BT_Load.Delete();
	BT_Start.Delete();
}

Scene* ScenesMainMenu::getScene(RenderWindow& window)
{
	if (scene == NULL) scene = new ScenesMainMenu(window);
	return scene;
}

Scene* ScenesMainMenu::getScene()
{
	return scene;
}

bool ScenesMainMenu::isScene()
{
	if (scene == NULL) return false;
	return true;
}
