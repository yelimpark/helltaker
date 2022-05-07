#include "Skull.h"
#include "../Utils/InputManager.h"


void Skull::Init(float x, float y)
{
	position.x = x;
	position.y = y;

	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("SkullStand");
	animation.AddClip("SkullPushed");

	animation.Play("SkullStand");
}

void Skull::Update(float dt)
{
	animation.Update(dt);
	sprite.setOrigin(sprite.getGlobalBounds().width * 0.5f, sprite.getGlobalBounds().height * 0.5f);

	
	if (InputManager::GetKeyDown(Keyboard::Left))
	{
		sprite.setScale(-1.f, 1.f);
		dir = Direction::Left;
	}

	else if (InputManager::GetKeyDown(Keyboard::Right))
	{
		sprite.setScale(1.f, 1.f);
		dir = Direction::Right;
	}

	else if (InputManager::GetKeyDown(Keyboard::Up))
	{
		dir = Direction::Up;
	}

	else if (InputManager::GetKeyDown(Keyboard::Down))
	{
		dir = Direction::Down;
	}
}

void Skull::OnPushed()
{

	if (InputManager::GetKeyDown(Keyboard::Left))
	{
		dir = Direction::Left;
		sprite.setScale(-1.f, 1.f);
		animation.Play("SkullPushed");
		animation.PlayQue("SkullStand");
	}

	else if (InputManager::GetKeyDown(Keyboard::Right))
	{
		dir = Direction::Right;
		sprite.setScale(1.f, 1.f);
		animation.Play("SkullPushed");
		animation.PlayQue("SkullStand");
	}

	else if (InputManager::GetKeyDown(Keyboard::Up))
	{
		dir = Direction::Up;
		animation.Play("SkullPushed");
		animation.PlayQue("SkullStand");
	}

	else if (InputManager::GetKeyDown(Keyboard::Down))
	{
		dir = Direction::Down;
		animation.Play("SkullPushed");
		animation.PlayQue("SkullStand");
	}
}

void Skull::OnHitted()
{
	//particle
}

void Skull::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
