#include "StageScene.h"
#include <SFML/Graphics.hpp>
#include "../Framework/Framework.h"

using namespace sf;

StageScene::StageScene(SceneManager& sceneManager)
	: Scene(sceneManager)
{

}

void StageScene::Init()
{
}

void StageScene::Update()
{
	Texture textureBackground;
	textureBackground.loadFromFile("Sprite/chapterBG0001.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	window.setView(mainView);
	window.draw(spriteBackground);
	window.display();


	//csv 파일로 끌어와서 작업 할 수 있도록!!!
}

void StageScene::Render()
{


}
