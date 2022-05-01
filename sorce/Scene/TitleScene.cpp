#include "./TitleScene.h"
#include "../Framework/Framework.h"

TitleScene::TitleScene(SceneManager& sceneManager)
	:Scene(sceneManager)
{
}

void TitleScene::Init()
{

}

void TitleScene::Update(Time& dt)
{
}

void TitleScene::Render()
{
	window.setView(mainView);
}

void TitleScene::Release()
{
}

TitleScene::~TitleScene()
{
}
