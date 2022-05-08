#include "Skull.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "./MapCode.h"


void Skull::Init(SkullData info, int tileSize, float moveSecond)
{
	position = info.position;
	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("SkullStand");
	animation.AddClip("SkullPushed");
	animation.AddClip("SkullCrushed");

	animation.Play("SkullStand");

	this->tileSize = tileSize;
	this->moveSecond = moveSecond;
	dir = Direction::None;
}

void Skull::Update(float dt, char** & map)
{
	if (dir == Direction::None) return;

	moveTime -= dt;

	if (moveTime <= 0)
	{
		moveTime = moveSecond;
		dir = Direction::None;
		return;
	}
	
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);

	switch (dir)
	{
	case Direction::Left:
		position.x -= moveDistance * dt / moveSecond;
		break;

	case Direction::Right:
		position.x += moveDistance * dt / moveSecond;
		break;

	case Direction::Up:
		position.y -= moveDistance * dt / moveSecond;
		break;

	case Direction::Down:
		position.y += moveDistance * dt / moveSecond;
		break;

	default:
		break;
	}

	sprite.setPosition(position);
}

void Skull::OnPushed(Direction dir, char**& map)
{
	this->dir = dir;

	char* nextPos = &map[(int)position.y / 100][(int)position.x / 100];

	switch (dir)
	{
	case Direction::Left:
		nextPos = &map[(int)position.y / 100][(int)position.x / 100 - 1];
		animation.Play("SkullPushed");
		animation.PlayQue("SkullStand");
		break;

	case Direction::Right:
		nextPos = &map[(int)position.y / 100][(int)position.x / 100 + 1];
		animation.Play("SkullPushed");
		animation.PlayQue("SkullStand");
		break;

	case Direction::Up:
		nextPos = &map[(int)position.y / 100 - 1][(int)position.x / 100];
		animation.Play("SkullPushed");
		animation.PlayQue("SkullStand");
		break;

	case Direction::Down:
		nextPos = &map[(int)position.y / 100 + 1][(int)position.x / 100];
		animation.Play("SkullPushed");
		animation.PlayQue("SkullStand");
		break;

	default:
		break;
	}

	switch (*nextPos)
	{
	case (char)MapCode::WALL:
	case (char)MapCode::SKULL:
		this->dir = Direction::None;
		return;

	default:
		break;
	}

	map[(int)position.y / 100][(int)position.x / 100] = 'E';
	*nextPos = 'S';
}

void Skull::OnHitted()
{
	int idxY = (int)position.y / tileSize;
	int idxX = (int)position.x / tileSize;

	animation.Play("SkullCrushed");
}

void Skull::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

const Vector2f& Skull::GetPos()
{
	return position;
}

const bool Skull::IsSkullHere(Vector2f pos)
{
	return false;
}
