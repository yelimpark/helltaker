#include "./Scene.h"
#include "../Framework/Framework.h"

Scene::Scene(SceneManager& sceneManager)
	:sceneManager(sceneManager),
	resolution(Framework::GetResolution()),
	window(Framework::Getwindow()),
	mainView(Framework::GetMainView())
{
}

Scene::~Scene()
{
}
