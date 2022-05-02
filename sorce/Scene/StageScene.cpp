#include "StageScene.h"
#include <SFML/Graphics.hpp>
#include "../Framework/Framework.h"
#include "../Utils/rapidcsv.h"

using namespace sf;

StageScene::StageScene(SceneManager& sceneManager)
	: Scene(sceneManager)
{

}

void StageScene::Init()
{
	sprite.setPosition(0, 0);
	rapidcsv::Document background("data_tables/stage_background_texture.csv");
	std::vector<std::string>colId = background.GetColumn<std::string>("TEXTURE PATH");

}

void StageScene::Update(Time& dt)
{


	//csv ���Ϸ� ����ͼ� �۾� �� �� �ֵ���!!!
}

void StageScene::Render()
{
	window.setView(mainView);


	window.draw(sprite);
}

void StageScene::Release()
{
}

StageScene::~StageScene()
{
}
