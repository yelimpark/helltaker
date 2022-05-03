#include "TitleScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"

TitleScene::TitleScene(SceneManager& sceneManager)
	:Scene(sceneManager),window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView())
{
}

void TitleScene::Init()
{
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	cloud.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_abyss.png"));
	

	cloud.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);

	Texture texture;
	texture.loadFromFile("Sprite/title_bu_sprites.png");
	animation.SetTarget(&bu);

	textintro.setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
	textintro.setString("You find yourself surrounded by the void.\nPress [ENTER or A]to continue.");
	textintro2.setString("Press [ENTER or A]to continue.");


	FloatRect textRect = textintro.getLocalBounds();
	textintro.setOrigin(
		textRect.left + textRect.width * 0.5f,
		textRect.top + textRect.height * 0.5f
	);


	textintro.setCharacterSize(25);
	textintro.setFillColor(Color::White);

	bu.setPosition((resolution.x * 0.5f) + 5, resolution.y * 0.75);
	cloud.setPosition(Vector2f(resolution.x / 2, resolution.y / 2.5));

	clip.id = "Idle";
	clip.fps = 5;
	clip.loopType = AmimationLoopTypes::Loop;

	clip.frames.push_back(AnimationFrame(texture, IntRect(0, 0, 50, 50)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(120, 0, 50, 50)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(240, 0, 50, 50)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(360, 0, 50, 50)));
	//animation more add
	animation.AddClip(clip);
	animation.Play("Idle");
	clip.frames.clear();

	mainView.setCenter(resolution.x * 0.5f, resolution.y * 0.5f);
}

void TitleScene::Update(Time& dt)
{
	textintro.setPosition(resolution.x * 0.5, resolution.y * 0.5);
	textintro2.setPosition(resolution.x * 0.5, resolution.y * 0.5);


	bu.setPosition((resolution.x * 0.5f) + 5, resolution.y * 0.75);
	cloud.setPosition(Vector2f(resolution.x / 2, resolution.y / 2.5));

	animation.Update(dt.asSeconds());
	if (InputManager::GetKeyDown(Keyboard::Enter) || InputManager::GetKeyDown(Keyboard::A)) {
		sceneManager.ChangeScene(SceneType::TITLECUT);
	}
}

void TitleScene::Render()
{
	window.setView(mainView);
	window.draw(bg);
	window.draw(cloud);
	window.draw(textintro);
	window.draw(bu);
}

void TitleScene::Release()
{
}

TitleScene::~TitleScene()
{
}
