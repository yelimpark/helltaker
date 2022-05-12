#include "CutScene.h"
#include "../SceneInitializer/LevelEndingSceneInitializer.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

#include "../GameObj/ScriptWithAnimation.h"
#include "../GameObj/ScriptWithChoice.h"
#include "../GameObj/ScriptWithCG.h"

#include <sstream>

CutScene::CutScene(SceneManager& sceneManager)
	: Scene(sceneManager), idx(0), idxMax(0)
{
}

void CutScene::Init()
{
	Release();

	idx = 0;
	stringstream ss;
	ss << GameVal::level;

	std::map<std::string, std::vector<LevelEndngData>> levelEndingDatas;
	Utils::CsvToStructVectorMap<LevelEndngData>(levelEndingDatas, "./LevelInfo/cutInfo.csv");
	std::vector<LevelEndngData> curLevelEndings = levelEndingDatas[ss.str()];

	bgColor.setSize(Vector2f(resolution.x, resolution.y));
	bgColor.setFillColor(Color{2, 2, 27});
	bgColor.setPosition(0, 0);

	std::map<std::string, std::vector<OptionData>> optionDatas;
	Utils::CsvToStructVectorMap<OptionData>(optionDatas, "./LevelInfo/choiceInfo.csv");
	std::vector<OptionData> curLevelOptions = optionDatas[ss.str()];

	idxMax = curLevelEndings.size();

	int SCidx = 0;
	for (auto& levelEndingData : curLevelEndings)
	{
		if (levelEndingData.type == 'A') {
			ScriptWithAnimation* script = new ScriptWithAnimation();
			script->Init(levelEndingData, resolution);
			scripts.push_back(script);
		}
		else if (levelEndingData.type == 'C') {
			ScriptWithChoice* script = new ScriptWithChoice();
			script->Init(levelEndingData, resolution, curLevelOptions[SCidx], curLevelOptions[SCidx + 1]);
			scripts.push_back(script);
			SCidx += 2;
		}
		else {
			ScriptWithCG* script = new ScriptWithCG();
			script->Init(levelEndingData, resolution);
			scripts.push_back(script);
		}
	}
}

void CutScene::Update(Time& dt)
{
	UpdateOutput state = scripts[idx]->Update(dt.asSeconds());

	switch (state)
	{
	case UpdateOutput::SKIP:
		idx++;
		if (idx == idxMax) {
			++ GameVal::level;
			sceneManager.InitScene(SceneType::STAGE);
			sceneManager.ChangeScene(SceneType::STAGE);
		}
		break;
	case UpdateOutput::BADEND:
		sceneManager.InitScene(SceneType::BADENDING);
		sceneManager.ChangeScene(SceneType::BADENDING);
		break;
	default:
		break;
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
