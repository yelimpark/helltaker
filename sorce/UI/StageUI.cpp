#include "StageUI.h"
#include <iostream>
#include <sstream>

#include "../Framework/Framework.h"
#include "../Utils/GameVal.h"
#include "../Resource/FontHolder.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

StageUI::StageUI()
	: lastTurn(0)
{

}

void StageUI::Init(int lastTurn)
{
	turn.setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
	stageNum.setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
	sideLeft.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_fUI0001.png"));
	sideRight.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_fUI0001.png"));

	this->lastTurn = lastTurn;
	turn.setFillColor(Color::White);
	turn.setCharacterSize(120);
	turn.setPosition(Vector2f(200, 780));

	stringstream ss;
	ss << lastTurn;
	turn.setString(ss.str());
	Utils::SetOrigin(turn, Pivots::Center);

	ss.str("");
	ss << GameVal::level;
	stageNum.setFillColor(Color::White);
	stageNum.setCharacterSize(120);
	stageNum.setPosition(Vector2f(1700, 780));
	stageNum.setString(ss.str());
	Utils::SetOrigin(stageNum, Pivots::Center); 

	sideLeft.setPosition(0, 392);
	sideRight.setPosition(1920, 392);
	sideRight.setScale(-1.f, 1.f);
}

void StageUI::UseTurn()
{
	//----------еое╦юс
	stringstream st;
	st << --lastTurn;
	turn.setString(st.str());
	Utils::SetOrigin(turn, Pivots::Center);
}

void StageUI::MoveObj(float x, float y, Transformable& obj)
{
	Vector2f pos = obj.getPosition();
	pos.x += x;
	pos.y += y;
	obj.setPosition(pos);
}

void StageUI::OnClear(float dt)
{
	Vector2f sideLeftPos = sideLeft.getPosition();
	if (sideLeftPos.x < (-1) * SIDE_WIDTH) return;

	MoveObj((-1) * SIDE_WIDTH * dt, SIDE_HEIGHT * dt, sideLeft);
	MoveObj((-1) * SIDE_WIDTH * dt, SIDE_HEIGHT * dt, turn);

	MoveObj(SIDE_WIDTH * dt, SIDE_HEIGHT * dt, sideRight);
	MoveObj(SIDE_WIDTH * dt, SIDE_HEIGHT * dt, stageNum);
}

void StageUI::Draw(RenderWindow& window)
{
	window.draw(sideLeft);
	window.draw(sideRight);
	window.draw(turn);
	window.draw(stageNum);
}

StageUI::~StageUI()
{
}
