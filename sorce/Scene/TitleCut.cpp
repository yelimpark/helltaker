#include "TitleCut.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"

TitleCut::TitleCut(SceneManager& sceneManager)
	:Scene(sceneManager), window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView())
{
}

void TitleCut::Init()
{
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	cloud.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_abyss.png"));
	beel.setTexture(TextureHolder::GetTexture("Sprite/beel_fly.png"));

	cloud.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);
	bu.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);
	beel.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);

	textintro.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);
	textTop.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);
	
	textintro.setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
	textintro.setString("Greetings little one.Please don't mind me.\n It is just I, good old Breelzebub.");

	textTop.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	textTop.setString("Breelzebub, The Great Fly");
	
	//text 가운데 정렬 필요
	
	//textintro.setPosition(Vector2f(resolution.x / 1.5, resolution.y)); 
	textintro.setPosition(Vector2f(resolution.x / 2, resolution.y));
	textintro.setCharacterSize(25);
	textintro.setFillColor(Color::White);

	textTop.setPosition(Vector2f(resolution.x, resolution.y));
	textTop.setCharacterSize(35);
	textTop.setFillColor(Color{ 230,77,81 }); 


	beel.setPosition(Vector2f(resolution.x /1.5, resolution.y / 2.5));
	bu.setPosition(Vector2f(resolution.x, resolution.y));
	cloud.setPosition(Vector2f(resolution.x / 2, resolution.y / 2.5));
	
	Texture texture;
	texture.loadFromFile("Sprite/title_bu_sprites.png");
	animation.SetTarget(&bu);

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

void TitleCut::Update(Time& dt)
{
	animation.Update(dt.asSeconds());
	if (InputManager::GetKeyDown(Keyboard::Enter) || InputManager::GetKeyDown(Keyboard::A)) {
		sceneManager.ChangeScene(SceneType::TITLEMEMU);
	}
}

void TitleCut::Render()
{
	window.setView(mainView);
	window.draw(bg);
	window.draw(cloud);
	window.draw(beel);
	window.draw(textintro);
	window.draw(textTop);
	window.draw(bu);
}

void TitleCut::Release()
{
}

TitleCut::~TitleCut()
{
}
