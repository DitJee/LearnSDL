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

	// set scale
	mScale = VEC2_ONE;

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

	Vector2 parentScale = mParent->Scale(SPACE::world);

	// account for parent's rotation
	Vector2 parentPos = mParent->Pos(SPACE::world);
	Vector2 newRotation = RotateVector(mPos, mParent->Rotation(SPACE::local));

	Vector2 newPos = parentPos + Vector2(newRotation.x * parentScale.x, newRotation.y * parentScale.y);

	return  newPos;
	
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

void GameEntity::Scale(Vector2 scale)
{
	mScale = scale;
}

Vector2 GameEntity::Scale(SPACE space)
{
	if (space == SPACE::local || mParent == NULL)
	{
		return mScale;
	}

	Vector2 parentScale = mParent->Scale(SPACE::world);

	Vector2 newScale = Vector2(parentScale.x * mScale.x, parentScale.y * mScale.y);

	return newScale;
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
	mPos = Pos(SPACE::world) - parent->Pos(SPACE::world);
	mParent = parent;
}

GameEntity* GameEntity::Parent()
{
	return mParent;
}

void GameEntity::Translate(Vector2 vec)
{
	mPos += vec;
}

void GameEntity::Rotate(float angle)
{
	mRotation += angle;
}

void GameEntity::Update()
{

}

void GameEntity::Render()
{

}