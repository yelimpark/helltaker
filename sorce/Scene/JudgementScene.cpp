#include "JudgementScene.h"
#include "../Utils/Utils.h"
#include "../Resource/TextureHolder.h"

JudgementScene::JudgementScene(SceneManager& sceneManager)
	: Scene(sceneManager)
{
}

void JudgementScene::Init()
{
	bgColor.setSize(Vector2f(resolution.x, resolution.y));
	bgColor.setFillColor(Color{ 214, 84, 45 });
	bgColor.setPosition(0, 0);

	sinGearsLAC.SetTarget(&sinGearsL);
	sinGearsLAC.AddClip("sinGears");
	sinGearsLAC.Play("sinGears");
	Utils::SetOrigin(sinGearsL, Pivots::LeftBottom);
	sinGearsL.setPosition(0, resolution.y);
	sinGearsL.setColor(Color{ 255, 255, 200 });

	sinGearsRAC.SetTarget(&sinGearsR);
	sinGearsRAC.AddClip("sinGears");
	sinGearsRAC.Play("sinGears");
	sinGearsR.setScale(-1.f, 1.f);
	Utils::SetOrigin(sinGearsR, Pivots::LeftBottom);
	sinGearsR.setPosition(resolution.x, resolution.y);
	sinGearsR.setColor(Color{ 255, 255, 200 });

	Texture& bridgeTex = TextureHolder::GetTexture("Sprite/bridgeInner.png");
	bridgeTex.setRepeated(true);
	bridge.setTexture(bridgeTex);
	Utils::SetOrigin(bridge, Pivots::Center);
	bridge.setPosition(resolution.x * 0.5, resolution.y * 0.5);

	sinPanelL.setTexture(TextureHolder::GetTexture("Sprite/sinPanel.png"));
	Utils::SetOrigin(sinPanelL, Pivots::RightBottom);
	sinPanelL.setPosition(resolution.x * 0.5, resolution.y);

	sinPanelR.setTexture(TextureHolder::GetTexture("Sprite/sinPanel.png"));
	Utils::SetOrigin(sinPanelR, Pivots::RightBottom);
	sinPanelR.setPosition(resolution.x * 0.5, resolution.y);
	sinPanelR.setScale(-1.f, 1.f);

	int x = 300;
	for (int i = 0; i < 4; i++) {
		sinPyre[i].setTexture(TextureHolder::GetTexture("Sprite/sinPyre0002.png"));
		sinPyre[i].setPosition(x + 300 * i, 800);
	}

	sinEye.setTexture(TextureHolder::GetTexture("Sprite/sinEye.png"));
	Utils::SetOrigin(sinEye, Pivots::CenterBottom);
	sinEye.setPosition(resolution.x * 0.5, resolution.y + 10);

	sinWheel.setTexture(TextureHolder::GetTexture("Sprite/sinWheel.png"));
	Utils::SetOrigin(sinWheel, Pivots::CenterTop);
	sinWheel.setPosition(resolution.x * 0.5, resolution.y);
}

void JudgementScene::Update(Time& dt)
{
	sinGearsLAC.Update(dt.asSeconds());
	Utils::SetOrigin(sinGearsL, Pivots::LeftBottom);

	sinGearsRAC.Update(dt.asSeconds());
	Utils::SetOrigin(sinGearsR, Pivots::LeftBottom);

	IntRect bound = bridge.getTextureRect();
	bound.top += dt.asSeconds() * speedY;
	bridge.setTextureRect(bound);

}

void JudgementScene::Render()
{
	window.draw(bgColor);
	window.draw(sinGearsL);
	window.draw(sinGearsR);
	window.draw(bridge);
	window.draw(sinPanelL);
	window.draw(sinPanelR);
	window.draw(sinWheel);
	window.draw(sinEye);
	for (int i = 0; i < 4; i++) {
		window.draw(sinPyre[i]);
	}

}

void JudgementScene::Release()
{
}

JudgementScene::~JudgementScene()
{
}
