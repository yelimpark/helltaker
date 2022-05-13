#include "SoundType.h"
#include "../Utils/GameVal.h"
#include "SoundEffect.h"
#include "../Utils/SceneManager.h"
#include "../Utils/Utils.h"
#include "../Utils/InputManager.h"
#include "../Resource/ResorceHolder.h"
#include "../Framework/Framework.h"
#include "../Utils/SceneManager.h"

SoundType::SoundType(VolumeType type)
	:type(type), musicSound(GameVal::musicSound), effectSound(GameVal::effectSound), sideselectIndex(0)
{
	musicSound = GameVal::musicSound;
	effectSound = GameVal::effectSound;

	switch (this->type)
	{
	case VolumeType::HIGH:
		musicSound_s[0] = "high";
		effectSound_s[0] = "high";
		break;
	case VolumeType::MEDIUM:
		musicSound_s[1] = "medium";
		effectSound_s[1] = "medium";
		break;

	case VolumeType::LOW:
		musicSound_s[2] = "low";
		effectSound_s[2] = "low";
		break;
	}

	SideInit();
}

void SoundType::SideInit()
{
	musicSound_s[0] = "high";

	musicSound_s[1] = "medium";

	musicSound_s[2] = "low";

	Utils::SetOrigin(musicSound_t, Pivots::Center);
	musicSound_t.setString(musicSound_s[0]);
	musicSound_t.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	musicSound_t.setFillColor(Color{ 255, 255, 255, 128 });
	musicSound_t.setCharacterSize(35);

	musicSound_t.setPosition(1920 / 2, (1080 / 20) / 0.5 * 2 + 200);

	effectSound_s[0] = "high";

	effectSound_s[1] = "medium";

	effectSound_s[2] = "low";

	Utils::SetOrigin(effectSound_t, Pivots::Center);
	effectSound_t.setString(effectSound_s[0]);
	effectSound_t.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	effectSound_t.setFillColor(Color{ 255, 255, 255, 128 });
	effectSound_t.setCharacterSize(35);

	effectSound_t.setPosition(1920 / 2, (1080 / 20) / 0.5 * 3.35 + 200);
}

void SoundType::MovingSideMenu()
{
}

void SoundType::MovingSideMenuChange()
{
}

void SoundType::InputButton()
{
}

void SoundType::MoveRight()
{
	if (sideselectIndex + 1 < MAX_NUMBER_OF_SOUND)
	{

		sideselectIndex++;
		if (sideselectIndex == 3) {
			sideselectIndex = 0;
		}

		Utils::SetOrigin(musicSound_t, Pivots::Center);
		musicSound_t.setString(musicSound_s[sideselectIndex]);
		Utils::SetOrigin(effectSound_t, Pivots::Center);
		effectSound_t.setString(effectSound_s[sideselectIndex]);

	}
}

void SoundType::MoveLeft()
{
	if (sideselectIndex - 1 >= 0)
	{

		sideselectIndex--;
		if (sideselectIndex == -1) {
			sideselectIndex = 2;
		}

		Utils::SetOrigin(musicSound_t, Pivots::Center);
		musicSound_t.setString(musicSound_s[sideselectIndex]);
		Utils::SetOrigin(effectSound_t, Pivots::Center);
		effectSound_t.setString(effectSound_s[sideselectIndex]);
	}
}

int SoundType::GetPressedMenu()
{
	return sideselectIndex;
}

void SoundType::Update(VolumeType type)
{

}

void SoundType::Render(RenderWindow& window)
{
	window.draw(musicSound_t);
	window.draw(effectSound_t);
}