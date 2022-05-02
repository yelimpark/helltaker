#include "StageUI.h"
#include <iostream>
#include <sstream>

#include "../Utils/GameVal.h"
#include "../Resource/FontHolder.h"
#include "../Resource/TextureHolder.h"

bool StageUI::isInitUIFontInfo = false;

StageUI::StageUI()
{
	FontHolder::GetFont("Font/Amiri-Regular.ttf");
	FontHolder::GetFont("Font/CrimsonPro-Medium.ttf");

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

		isInitUIFontInfo = true;
	}
}

void StageUI::Update(int turnTimes, Vector2i position)
{
	//----------턴타임
	stringstream st;
	st << turnTimes;
	turn.setString(st.str());
	turn.setPosition((position.x*0.1f)-50, (position.y*0.7f)-15);

	//----------스테이지레벨
	//stringstream ss; 전역변수로 설정한 거 같은데 왜 선언이 안되는가??!?
	//ss<<GameVal::stageNum;

	//----------UI 이미지
	side1.setPosition(0, 392);
	side2.setPosition(1920, 392);
	side2.setScale(-1.f, 1.f);
}

void StageUI::Draw(RenderWindow& window)
{
	window.draw(side1);
	window.draw(side2);
	window.draw(turn);
}
