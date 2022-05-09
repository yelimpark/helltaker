#include "PauseMenu.h"
#include "../Framework/Framework.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

PauseMenu::PauseMenu(RenderWindow& window)
{
	//init backgound (opacity)
	background.setSize(Vector2f(
		static_cast<float>(window.getSize().x), 
		static_cast<float>(window.getSize().y))
	);
	background.setFillColor(Color(20, 20, 20, 100));

	//init container
	container.setSize(Vector2f(
		static_cast<float>(window.getSize().x/2.f),
		static_cast<float>(window.getSize().y))
	);
	container.setFillColor(Color(20, 20, 20, 100));
	container.setPosition(
		static_cast<float>(window.getSize().x) / 2.f - container.getSize().x / 2.f, (window.getSize().y / 30.f)
	);

	//init text
	menuText.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	menuText.setFillColor(Color{ 230,77,81 });
	menuText.setCharacterSize(50);
	menuText.setString("PAUSE MENU"); //fixing text
	Utils::SetOrigin(menuText, Pivots::Center);
	menuText.setPosition(
		container.getPosition().x + container.getSize().x / 2.f/* - this->menuText.getGlobalBounds().width / 2.f*/,
		container.getPosition().y + 50.f
	);

	addMenuText[0].setString("SKIP PUZZLE");
	addMenuText[1].setString("MUSIC");
	addMenuText[2].setString("high");
	/*addMenuText[3].setString("midiun");
	addMenuText[4].setString("low");
	addMenuText[5].setString("mute");*/
	addMenuText[3].setString("SOUND");
	addMenuText[4].setString("high");
	/*addMenuText[8].setString("midiun");
	addMenuText[9].setString("low");
	addMenuText[10].setString("mute");*/
	addMenuText[5].setString("MAIN MENU");

	for (int i = 0; i < MAX_NUMBER_OF_MENU; i++)
	{
		addMenuText[i].setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
		addMenuText[i].setFillColor(Color::White);
		addMenuText[i].setCharacterSize(40);
		Utils::SetOrigin(addMenuText[i], Pivots::Center);
		addMenuText[i].setPosition(
			container.getPosition().x +container.getSize().x / 2.f,
			container.getPosition().y / 0.3 * i + 200
		);

	}
}

PauseMenu::~PauseMenu()
{
}

//void PauseMenu::Addbutton(const string key, float x, float y, const string text)
//{
//	this->
//}

void PauseMenu::Addbutton()
{
	
}

//functions
void PauseMenu::Update()
{
}

void PauseMenu::Render(RenderWindow& window)
{
	window.draw(background);
	window.draw(this->container);
	window.draw(menuText);
	for (int i = 0; i < MAX_NUMBER_OF_MENU; i++)
	{
		window.draw(addMenuText[i]);
	}

}

