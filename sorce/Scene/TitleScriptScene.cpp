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
	
	bgChange = new Texture[2];
	bgChange[0] = (TextureHolder::GetTexture("Sprite/dialogueBG_abyss_s.png"));
	bgChange[1] = (TextureHolder::GetTexture("Sprite/background.png"));

	Texture& tex = TextureHolder::GetTexture("Sprite/dialogueBG_abyss_s.png");
	tex.setRepeated(true);
	bgchange_s.setTexture(tex);
	FloatRect transRect = bgchange_s.getLocalBounds();
	bgchange_s.setOrigin((transRect.left + transRect.width) * 0.5, (transRect.top + transRect.height) * 0.5f);
	bgchange_s.setPosition(resolution.x * 0.5f, resolution.y * 0.4f);

	beelFire.setOrigin((transRect.left + transRect.width) * 0.5, (transRect.top + transRect.height) * 0.5f);
	beelFire.setPosition(resolution.x / 1.3, resolution.y * 0.4f);


	img = new Texture[9];
	img[0] = (TextureHolder::GetTexture("Sprite/cutscene_0002_Group-2.png")); 
	img[1] = (TextureHolder::GetTexture("Sprite/cutscene_0003_Group-3-copy-2.png")); 
	img[2] = (TextureHolder::GetTexture("Sprite/cutscene_0004_Layer-273-copy.png")); 
	img[3] = (TextureHolder::GetTexture("Sprite/cutscene_0005_Layer-196.png")); 
	img[4] = (TextureHolder::GetTexture("Sprite/cutscene_0006_Group-6-copy-3.png")); 

	textintro.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	textintro.setCharacterSize(30);

	script[0] = "Story of the HELLTAKER again ? Interesting...";
	//script[1] = " DO you, by any charce, need a narrator ? ";
	////screen8 
	script[1] = "Why please, allow me. It will be a pleasure.";
	////screen7 showup man
	script[2] = "Why woke up ine day with a dream.";
	//script[4] = "Harem full if demon girls";
	////screen8 showup man
	script[3] = "It was, however,not an easy dream to achieve";
	//script[6] = "It could cost you your life";
	////screen9 showup man
	script[4] = "It could cost you your life.";
	//script[8] = "You said,as you ventured down to hell.";

}



void TitleScriptScene::Update(Time& dt)
{
	IntRect bound = bgchange_s.getTextureRect();
	bound.left += 1;
	bgchange_s.setTextureRect(bound);

	beelFire.setTexture(TextureHolder::GetTexture("Sprite/beel_fly_portal.png"));
	
	Utils::SetOrigin(textintro, Pivots::Center);
	textintro.setPosition(Vector2f(resolution.x/2, resolution.y / 20 + 745));

	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		textselectIndex++;
		soundEffects.dialogueTextEnd();
	}
	if (textselectIndex < MAX_NUMBER_OF_SCRIPT)
	{
		textintro.setString(script[textselectIndex]);

		bgchange_s.setTexture(bgChange[1]);
		Utils::SetOrigin(textintro, Pivots::Center);
		textintro.setPosition(Vector2f(resolution.x / 2, resolution.y / 20 * 1 + 745));

		imgScript.setTexture(img[textselectIndex]);

		imgScript.setTexture(img[textselectIndex]);
		auto size = img[textselectIndex].getSize();
		imgScript.setTextureRect(IntRect(0, 0, size.x, size.y));
		Utils::SetOrigin(imgScript, Pivots::Center);
		imgScript.setPosition(Vector2f(resolution.x / 2, resolution.y / 22 + 400));
	}
	else if(textselectIndex >= MAX_NUMBER_OF_SCRIPT)
	{
		sceneManager.ChangeScene(SceneType::STAGE);
	}
	
	
	

}

void TitleScriptScene::Render()
{
	window.draw(bg);
	window.draw(bgchange_s);
	window.draw(beelFire);
	window.draw(imgScript);

	window.draw(textintro);
}

void TitleScriptScene::Release()
{
}

TitleScriptScene::~TitleScriptScene()
{
}
