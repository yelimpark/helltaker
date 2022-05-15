#include "CutScene.h"
#include "../SceneInitializer/CutSceneInitializer.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

#include "../GameObj/ScriptWithAnimation.h"
#include "../GameObj/ScriptWithChoice.h"
#include "../GameObj/ScriptWithCG.h"

#include<string>

CutScene::CutScene(SceneManager& sceneManager)
	: Scene(sceneManager), idx(0)
{

}

std::string ToFullFilePath(const char* filePath) {
	std::string path = "";
	path += filePath;
	path += GameVal::language;
	path += ".csv";
	return path;
}

void CutScene::Init()
{
	Release();

	idx = 0;

	std::map<std::string, std::vector<CutSceneData>> cutSceneDatas;
	Utils::CsvToStructVectorMap<CutSceneData>(cutSceneDatas, ToFullFilePath("./LevelInfo/cutInfo").c_str());
	std::vector<CutSceneData> curSceneDatas = cutSceneDatas[to_string(GameVal::cutSceneIdx)];

	bgColor.setSize(Vector2f(resolution.x, resolution.y));
	bgColor.setFillColor(Color{2, 2, 27});
	bgColor.setPosition(0, 0);

	std::map<std::string, std::vector<OptionData>> optionDatas;
	Utils::CsvToStructVectorMap<OptionData>(optionDatas, ToFullFilePath("./LevelInfo/choiceInfo").c_str());
	std::vector<OptionData> curLevelOptions = optionDatas[to_string(GameVal::cutSceneIdx)];

	int SCidx = 0;

	for (auto& curSceneData : curSceneDatas)
	{
		if (curSceneData.type == 'A') {
			ScriptWithAnimation* script = new ScriptWithAnimation();
			script->Init(curSceneData, resolution);
			scripts.push_back(script);
		}
		else if (curSceneData.type == 'C') {
			ScriptWithChoice* script = new ScriptWithChoice();
			script->Init(curSceneData, resolution, curLevelOptions[SCidx], curLevelOptions[SCidx + 1]);
			scripts.push_back(script);
			SCidx += 2;
		}
		else {
			ScriptWithCG* script = new ScriptWithCG();
			script->Init(curSceneData, resolution);
			scripts.push_back(script);
		}
	}
}

void CutScene::Update(Time& dt)
{
	if (scripts[idx]->Update(dt.asSeconds())) {
		std::string& nextNode = scripts[idx]->GetNextNode();
		if (nextNode.compare("B") == 0) {
			sceneManager.ChangeScene(SceneType::BADENDING);
		}
		else if (nextNode.compare("S") == 0) {
			GameVal::level = GameVal::cutSceneIdx + 1;
			sceneManager.ChangeScene(SceneType::STAGE, true);
		}
		else if (nextNode.compare("T") == 0) {
			sceneManager.ChangeScene(SceneType::TITLE);
		}
		else {
			idx += stoi(nextNode);
		}
	}
}

void CutScene::Render()
{
	window.draw(bgColor);
	scripts[idx]->Draw(window);
}

void CutScene::Release()
{
	for (auto& script : scripts) {
		if (script != nullptr)
			delete script;
	}
	scripts.clear();
}

CutScene::~CutScene()
{
}
