#include "PauseMenu.h"
#include "../Framework/Framework.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"
#include "../Scene/Scene.h"
#include "../Utils/InputManager.h"
#include "../Utils/SceneManager.h"


PauseMenu::PauseMenu(RenderWindow& window, SceneManager& sceneManager)
	: sceneManager(sceneManager), soundtype(VolumeType::COUNT), levelMove(1)
{

	ContainerInit(window);
	background.setSize(Vector2f(
		static_cast<float>(window.getSize().x),
		static_cast<float>(window.getSize().y))
	);
	background.setFillColor(Color(2, 2, 27, 170));

	//init text
	menuText.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	menuText.setFillColor(Color{ 230,77,81 });
	menuText.setCharacterSize(40);
	menuText.setString("PAUSE MENU"); //fixing text
	Utils::SetOrigin(menuText, Pivots::Center);
	menuText.setPosition(
		container.getPosition().x + container.getSize().x / 2.f,
		container.getPosition().y + 80.f
	);

	addMenuText[0].setString("RESUME");
	addMenuText[1].setString("SKIP PUZZLE");
	addMenuText[2].setString("MUSIC");
	addMenuText[3].setString("SOUND");
	addMenuText[4].setString("MAIN MENU");

	for (int i = 0; i < 5; i++) {

		float xpos, ypos;
		xpos = (container.getPosition().x + container.getSize().x / 2.f);
		ypos = (container.getPosition().y / 0.5);

		addMenuText[i].setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
		addMenuText[i].setFillColor(Color{ 255, 255, 255, 128 });
		addMenuText[i].setCharacterSize(35);
		Utils::SetOrigin(addMenuText[i], Pivots::Center);

		img[i].setTexture(TextureHolder::GetTexture("Sprite/button_small_s.png"));
		img[i].setColor({ 99, 61, 74, 225 });
		Utils::SetOrigin(img[i], Pivots::Center);
		img[i].setPosition(xpos, ypos * i + 216);

		if (i == 3) {
			addMenuText[i].setPosition(xpos, ypos * 4 + 200);
			img[i].setPosition(xpos, ypos * 4 + 216);
		}
		else if (i == 4) {
			addMenuText[i].setPosition(xpos, ypos * 6 + 200);
			img[i].setPosition(xpos, ypos * 6 + 216);
		}
		else {
			addMenuText[i].setPosition(xpos, ypos * i + 200);
			img[i].setTexture(TextureHolder::GetTexture("Sprite/button_small_s.png"));
			img[i].setColor({ 99, 61, 74, 225 });
			Utils::SetOrigin(img[i], Pivots::Center);
			img[i].setPosition(xpos, ypos * i + 216);
		}
	}

	menuline.setTexture(TextureHolder::GetTexture("Sprite/escmenu.png"));
	Utils::SetOrigin(menuline, Pivots::Center);
	menuline.setPosition(
		container.getPosition().x + container.getSize().x / 2.0f,
		container.getPosition().y / 2.0f + 480
	);
	CircleInit();
	soundtype.SideInit();
}

void PauseMenu::CircleInit()
{
	for (int i = 0; i < 2; i++) {
		circle[i].setTexture(TextureHolder::GetTexture("Sprite/whiteCircle.png"));
		circle[i].setColor(Color{ 230,77,81 });
		circle[i].setScale(Vector2f(0.1, 0.1));
		Utils::SetOrigin(circle[i], Pivots::Center);
		circle[i].setPosition(
			menuText.getPosition().x / 3.0f * i + 800,
			menuText.getPosition().y / 0.88f
		);
	}
}

void PauseMenu::ContainerInit(RenderWindow& window)
{
	container.setSize(Vector2f(
		static_cast<float>(window.getSize().x / 2.f),
		static_cast<float>(window.getSize().y))
	);
	container.setFillColor(Color(2, 2, 27, 180));
	container.setPosition(
		static_cast<float>(window.getSize().x) / 2.f - container.getSize().x / 2.f, (window.getSize().y / 30.f)
	);
}

void PauseMenu::UpInit()
{

	MovingMenu();
	selectIndex = 0;
	MovingMenuChange();
}


void PauseMenu::InputButton()
{


	if (InputManager::GetKeyDown(Keyboard::Up)) {
		MoveUp();
	}
	if (InputManager::GetKeyDown(Keyboard::Down)) {
		MoveDown();
	}

	if (selectIndex == 2) {
		if (InputManager::GetKeyDown(Keyboard::Left)) {
			soundtype.MoveLeft();
			soundtype.MusicInputButton();
		}
		if (InputManager::GetKeyDown(Keyboard::Right)) {
			soundtype.MoveRight();
			soundtype.MusicInputButton();
		}
	}

	if (selectIndex == 3) {
		if (InputManager::GetKeyDown(Keyboard::Left)) {
			soundtype.MoveLeft();
			soundtype.EffectInputButton();
		}
		if (InputManager::GetKeyDown(Keyboard::Right)) {
			soundtype.MoveRight();
			soundtype.EffectInputButton();
		}
	}

	if (InputManager::GetKeyDown(Keyboard::Enter)) {
		switch (GetPressedMenu())
		{
		case 0:
			//RESUME
			break;
		case 1:
			//"SKIP PUZZLE"
			break;
		case 2:
			//"MUSIC"
			break;
		case 3:
			//"sound"
			break;
		case 4:
			GameVal::Init();
			sceneManager.ChangeScene(SceneType::TITLE);
			break;
		}
	}
}

int PauseMenu::GetPressedMenu()
{
	return selectIndex;
}


void PauseMenu::MovingMenu()
{
	addMenuText[selectIndex].setCharacterSize(30);
	addMenuText[selectIndex].setFillColor(Color{ 255, 255, 255, 128 });
	img[selectIndex].setColor({ 99, 61, 74, 225 });
	img[selectIndex].setScale(Vector2f(1, 1));
}

void PauseMenu::MovingMenuChange()
{
	addMenuText[selectIndex].setCharacterSize(35);
	addMenuText[selectIndex].setFillColor(Color{ 255, 255, 255, 255 });
	img[selectIndex].setColor({ 230, 77, 81, 225 });
	img[selectIndex].setScale(Vector2f(1.1, 1.1));
}

void PauseMenu::MoveUp()
{
	if (selectIndex - 1 >= 0)
	{
		MovingMenu();
		selectIndex--;
		MovingMenuChange();
	}
}

void PauseMenu::MoveDown()
{
	if (selectIndex + 1 < 5)
	{
		MovingMenu();
		selectIndex++;
		MovingMenuChange();
	}
}

//Functions
void PauseMenu::Update()
{
	InputButton();
}

void PauseMenu::Render(RenderWindow& window)
{
	window.draw(background);
	window.draw(container);
	window.draw(menuText);
	window.draw(circle[0]);
	window.draw(circle[1]);

	for (int i = 0; i < MAX_NUMBER_OF_MENU; i++)
	{
		window.draw(addMenuText[i]);
		window.draw(img[i]);
	}

	window.draw(menuline);
	soundtype.Render(window);

}
PauseMenu::~PauseMenu()
{

}
