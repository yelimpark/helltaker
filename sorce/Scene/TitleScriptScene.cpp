#include "TitleScriptScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"

using namespace std;
using namespace sf;

TitleScriptScene::TitleScriptScene(SceneManager& sceneManager)
	:Scene(sceneManager), textselectIndex(0),enterCounter(0)
{

}

void TitleScriptScene::Init()
{
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	beelFire.setPosition(resolution.x /4, resolution.y / 9);

	Texture& tex = TextureHolder::GetTexture("Sprite/dialogueBG_abyss_s.png");
	tex.setRepeated(true);
	cloudBackground.setTexture(tex);
	cloudBackground.setPosition(resolution.x * 0.0001f, resolution.y / 9);

	textintro.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	textintro.setCharacterSize(30);

	script[0] = "Story of the HELLTAKER again ? Interesting...";
	script[1] = " DO you, by any charce, need a narrator ? ";
	////screen8 
	script[2] = "Why please, allow me. It will be a pleasure.";
	////screen7 showup man
	script[3] = "Why woke up ine day with a dream.";
	script[4] = "Harem full if demon girls";
	////screen8 showup man
	script[5] = "It was, however,not an easy dream to achieve";
	script[6] = "It could cost you your life";
	////screen9 showup man
	script[7] = "It could cost you your life";
	script[8] = "You said,as you ventured down to hell.";
}



void TitleScriptScene::Update(Time& dt)
{
	IntRect bound = cloudBackground.getTextureRect();
	bound.left += 1;
	cloudBackground.setTextureRect(bound);
	beelFire.setTexture(TextureHolder::GetTexture("Sprite/beel_fly_portal.png"));
	
	Utils::SetOrigin(textintro, Pivots::Center);
	textintro.setPosition(Vector2f(resolution.x/2, resolution.y / 20 + 745));

	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		soundEffects.dialogueTextEnd();
		textselectIndex++;
	}
	if (textselectIndex < MAX_NUMBER_OF_SCRIPT)
	{
		textintro.setString(script[textselectIndex]);
	}
	else if(textselectIndex >= MAX_NUMBER_OF_SCRIPT)
	{
		sceneManager.ChangeScene(SceneType::ENDINGCUTSCENE);
	}
	
	
	

}

void TitleScriptScene::Render()
{
	window.draw(bg);
	window.draw(cloudBackground);
	window.draw(beelFire);

	window.draw(textintro);
}

void TitleScriptScene::Release()
{
}

TitleScriptScene::~TitleScriptScene()
{
}
