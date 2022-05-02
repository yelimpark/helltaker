#include "./TitleScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"

TitleScene::TitleScene(SceneManager& sceneManager)
	:Scene(sceneManager),window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView())
{
}

void TitleScene::Init()
{
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));

	Texture texture;
	texture.loadFromFile("Sprite/title_bu_sprites.png");
	animation.SetTarget(&bu);

	textintro.setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
	textintro.setString("You find yourself surrounded by the void.\n       Press [ENTER or A]to continue.");

	textintro.setPosition(resolution.x * 0.4f, resolution.y * 0.58f);
	textintro.setCharacterSize(25);
	textintro.setFillColor(Color::White);

	
	bu.setPosition(resolution.x * 0.53f, resolution.y * 0.75f);
	bu.setOrigin(60, 60);

	clip.id = "Idle";
	clip.fps = 5;
	clip.loopTypes = AnimationLoopTypes::Loop;

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
	animation.Update(dt.asSeconds());
}

void TitleScene::Render()
{
	window.setView(mainView);
	window.draw(bg);
	window.draw(bu);
	window.draw(textintro);
	window.draw(bu);
}

void TitleScene::Release()
{
}

TitleScene::~TitleScene()
{
}
