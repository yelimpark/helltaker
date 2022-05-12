#include "LevelEndScene.h"
#include "../SceneInitializer/LevelEndingSceneInitializer.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

#include "../GameObj/ScriptWithAnimation.h"
#include "../GameObj/ScriptWithChoice.h"

#include <sstream>

LevelEndScene::LevelEndScene(SceneManager& sceneManager)
	: Scene(sceneManager), idx(0), idxMax(0)
{
}

void LevelEndScene::Init()
{
	Release();

	idx = 0;
	stringstream ss;
	ss << GameVal::level;

	std::map<std::string, std::vector<LevelEndngData>> levelEndingDatas;
	Utils::CsvToStructVectorMap<LevelEndngData>(levelEndingDatas, "./LevelInfo/LevelEnding.csv");
	std::vector<LevelEndngData> curLevelEndings = levelEndingDatas[ss.str()];

	background.setTexture(TextureHolder::GetTexture(curLevelEndings[0].backgroundFileName));
	Utils::SetOrigin(background, Pivots::CenterBottom);
	background.setPosition(resolution.x * 0.5, 700);

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
		else {
			ScriptWithChoice* script = new ScriptWithChoice();
			script->Init(levelEndingData, resolution, curLevelOptions[SCidx], curLevelOptions[SCidx + 1]);
			scripts.push_back(script);
			SCidx += 2;
		}
	}
}

void LevelEndScene::Update(Time& dt)
{
	UpdateOutput state = scripts[idx]->Update(dt.asSeconds());

	switch (state)
	{
	case UpdateOutput::SKIP:
		idx++;
		if (idx == idxMax) {
			++ GameVal::level;
			sceneManager.ChangeScene(SceneType::STAGE);
		}
		break;
	case UpdateOutput::BADEND:
		sceneManager.ChangeScene(SceneType::BADENDING);
		break;
	default:
		break;
	}

}

void LevelEndScene::Render()
{
	window.draw(bgColor);
	window.draw(background);
	scripts[idx]->Draw(window);
}

void LevelEndScene::Release()
{
	for (auto& script : scripts) {
		if (script != nullptr)
			delete script;
	}
	scripts.clear();
}

LevelEndScene::~LevelEndScene()
{
}
