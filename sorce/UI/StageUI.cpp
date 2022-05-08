#include "StageUI.h"
#include <iostream>
#include <sstream>

#include "../Framework/Framework.h"
#include "../Utils/GameVal.h"
#include "../Resource/FontHolder.h"
#include "../Resource/TextureHolder.h"

bool StageUI::isInitUIFontInfo = false;
bool StageUI::isMovedSide = false;

StageUI::StageUI()
	: side1SpeedX(0), side2SpeedX(0), sideSpeedY(0)
{
}

void StageUI::Init()
{
	if (!isInitUIFontInfo)
	{
		turn.setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
		stageNum.setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
		side1.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_fUI0001.png"));
		side2.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_fUI0001.png"));

		turn.setFillColor(Color::White);
		turn.setCharacterSize(120);
		FloatRect turnRect = turn.getLocalBounds();
		turn.setOrigin(
			turnRect.left + turnRect.width * 0.5f,
			turnRect.top + turnRect.height * 0.5f
		);


		stageNum.setFillColor(Color::White);
		stageNum.setCharacterSize(120);

		//FloatRect side1Rect = side1.getLocalBounds();
		//side1.setOrigin(0, 0);
		//FloatRect side2Rect = side2.getLocalBounds();
		//side2.setOrigin(0, side2Rect.top + side2Rect.height);

		side1.setPosition(0, 392);
		side2.setPosition(1920, 392);
		side2.setScale(-1.f, 1.f);

		side1SpeedX = -2;
		side2SpeedX = 2;
		sideSpeedY = 3;

		isInitUIFontInfo = true;
		isMovedSide = false;
	}
}

void StageUI::Update(int turnTimes)
{

	//----------��Ÿ��
	stringstream st;
	st << turnTimes;
	turn.setString(st.str());
	turn.setPosition(Vector2f((1920 * 0.1f) - 50, (1920 * 0.7f) - 15));

	//----------������������
	//stringstream ss; ���������� ������ �� ������ �� ������ �ȵǴ°�??!?
	//ss<<GameVal::stageNum;


}

void StageUI::MoveSide(float dt)
{
		Vector2f side1Pos = side1.getPosition();
		side1Pos.x += side1SpeedX * dt;
		side1Pos.y += sideSpeedY * dt;
		side1.setPosition(side1Pos);

		Vector2f side2Pos = side2.getPosition();
		side2Pos.x += side2SpeedX * dt;
		side2Pos.y += sideSpeedY * dt;
		side2.setPosition(side2Pos);

		if (side1Pos.x < -100)
		{
			isMovedSide = false;
			side1.setPosition(-200, 1500);
		}

		if (side2Pos.x > 2000) {
			side2.setPosition(2300, 1500);
		}
}

void StageUI::Draw(RenderWindow& window)
{
	window.draw(side1);
	window.draw(side2);
	window.draw(turn);
}

StageUI::~StageUI()
{
}
