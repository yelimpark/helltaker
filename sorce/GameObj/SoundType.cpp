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
}

void SoundType::SideInit()
{
	musicSound_s[0] = "high";

	musicSound_s[1] = "medium";

	musicSound_s[2] = "low";

	musicSound_t.setString(musicSound_s[0]);
	musicSound_t.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	musicSound_t.setFillColor(Color{ 255, 255, 255, 128 });
	musicSound_t.setCharacterSize(35);
	Utils::SetOrigin(musicSound_t, Pivots::Center);

	musicSound_t.setPosition(1920 / 2, (1080 / 20) / 0.5 * 2 + 200);

	effectSound_s[0] = "high";

	effectSound_s[1] = "medium";

	effectSound_s[2] = "low";

	effectSound_t.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	effectSound_t.setFillColor(Color{ 255, 255, 255, 128 });
	effectSound_t.setCharacterSize(35);
	effectSound_t.setString(effectSound_s[0]);
	Utils::SetOrigin(effectSound_t, Pivots::Center);
	effectSound_t.setPosition(1920 / 2, (1080 / 20) / 0.5 * 3.35 + 200);
}

void SoundType::MusicInputButton()
{
	musicSound_t.setString(musicSound_s[sideselectIndex]);
	Utils::SetOrigin(musicSound_t, Pivots::Center);
}

void SoundType::EffectInputButton()
{
	effectSound_t.setString(effectSound_s[sideselectIndex]);
	Utils::SetOrigin(effectSound_t, Pivots::Center);
}


void SoundType::MoveRight()
{
	if (sideselectIndex + 1 < MAX_NUMBER_OF_SOUND)
	{
		sideselectIndex++;
		if (sideselectIndex == 3) {
			sideselectIndex = 0;
		}
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
	}
}

void SoundType::Update(VolumeType type)
{

}

void SoundType::Render(RenderWindow& window)
{
	window.draw(musicSound_t);
	window.draw(effectSound_t);
}