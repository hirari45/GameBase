#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	tr_.rotate_.y = 180.0f;
	tr_.scale_ = { 0.5f, 0.5f, 0.5 };
	tr_.position_ = { 0.0f, -3.0f, 5.0f };
}

void Bullet::Update()
{
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
