#include "GameEntity.h"

GameEntity::GameEntity(float x, float y)
{
	// set transform
	mPos.x = x;
	mPos.y = y;

	// set rotation
	mRotation = 0.0f;

	// set active
	mActive = true;

	// set parent
	mParent = NULL;
}

GameEntity::~GameEntity()
{
	mParent = NULL;

}

void GameEntity::Pos(Vector2 pos)
{
	mPos = pos;
}

Vector2 GameEntity::Pos(SPACE space)
{
	if (space == SPACE::local || mParent == NULL)
	{
		return mPos;
	}

	// account for parent's rotation
	Vector2 parentPos = mParent->Pos(SPACE::world);
	Vector2 newRotation = RotateVector(mPos, mParent->Rotation(SPACE::local));

	return  parentPos + newRotation;
	
}

void GameEntity::Rotation(float rotation)
{
	mRotation = rotation;

	int wholeNumber = (int)rotation % 360;
	float fraction = rotation - (int)rotation;
	rotation = wholeNumber + fraction;

	if (rotation < 0)
	{
		mRotation = 360.0f + rotation;
	}
	else
	{
		mRotation = rotation;
	}

}

float GameEntity::Rotation(SPACE space)
{
	if (space == SPACE::local || mParent == NULL)
	{
		return mRotation;
	}

	return mParent->Rotation(SPACE::world) + mRotation;
}

void GameEntity::Active(bool active)
{
	mActive = active;
}

bool GameEntity::Active()
{
	return mActive;
}

void GameEntity::Parent(GameEntity* parent)
{
	mPos = this->Pos(SPACE::world) - parent->Pos(SPACE::world);
	mParent = parent;
}

GameEntity* GameEntity::Parent()
{
	return mParent;
}

void GameEntity::Update()
{

}

void GameEntity::Render()
{

}