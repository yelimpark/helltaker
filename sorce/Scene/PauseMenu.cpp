#include "PauseMenu.h"
#include "../Framework/Framework.h"
#include "../Resource/TextureHolder.h"

PauseMenu::PauseMenu(RenderWindow& window)
{
	//init backgound
	this->background.setSize(Vector2f(
		static_cast<float>(window.getSize().x), 
		static_cast<float>(window.getSize().y))
	);
	this->background.setFillColor(Color(20, 20, 20, 100));

	//init container
	this->container.setSize(Vector2f(
		static_cast<float>(window.getSize().x),
		static_cast<float>(window.getSize().y))
	);
	this->container.setFillColor(Color(20, 20, 20, 100));
	this->container.setPosition(
		static_cast<float>(window.getSize().x)/ 2.f - this->container.getSize().x / 2.f, 0.f
	);

	//init text
	menuText.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	menuText.setFillColor(Color(255,255,255,200));
	menuText.setCharacterSize(30);
	menuText.setString("PAUSE MENU"); //fixing text
	menuText.setPosition(this->container.getPosition()); //fixing text
}

PauseMenu::~PauseMenu()
{
}


//functions
void PauseMenu::Update()
{
}

void PauseMenu::Render(RenderWindow& window)
{
	window.draw(background);
	window.draw(container);
	window.draw(this->menuText);


}

