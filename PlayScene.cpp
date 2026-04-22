#include "PlayScene.h"
#include "Engine/Model.h"

PlayScene::PlayScene(GameObject* parent)  //メンバの設定はこっち
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize() //その他はこっち
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
}

void PlayScene::Update()
{
	static float time = 0.0f;

	ot_.position_ = { 0.0f, 0.0f, 0.0f };
	ot_.scale_ = { 1.0f, 1.0f, 1.0f };
	ot_.rotate_.y += 0.1f;
	time += 0.1f;
	float posx = 6.0 * sin(0.2f*time);
	ot_.position_.x = posx;
}

void PlayScene::Draw()
{
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
