#include "ScriptWithCG.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

ScriptWithCG::ScriptWithCG()
	:effectTime(0)
{
}

void ScriptWithCG::Init(LevelEndngData& data, Vector2i resolution)
{
	effectTime = 0;
	ScriptWithAnimation::Init(data, resolution);
	cg.setTexture(TextureHolder::GetTexture(data.CGFileName));
	Utils::SetOrigin(cg, Pivots::Center);
	cg.setPosition(resolution.x * 0.5, 400);

	FloatRect size = cg.getGlobalBounds();
	redRect.setSize(Vector2f(size.width, size.height));
	redRect.setFillColor(Color{ 135, 57, 51 });
	Utils::SetOrigin(redRect, Pivots::Center);
	redRect.setRotation(3.f);
	redRect.setPosition(resolution.x * 0.5, 400);
}

UpdateOutput ScriptWithCG::Update(float dt)
{
	if (effectTime < EFFECT_TIME_MAX) {
		redRect.setScale(effectTime / EFFECT_TIME_MAX, effectTime / EFFECT_TIME_MAX);
		effectTime += dt;
	}

	return ScriptWithAnimation::Update(dt);
}

void ScriptWithCG::Draw(RenderWindow& window)
{
	window.draw(redRect);
	if (effectTime >= EFFECT_TIME_MAX) {
		window.draw(cg);
		ScriptWithAnimation::Draw(window);
	}

}

ScriptWithCG::~ScriptWithCG()
{
}
