#include "PlayScene.h"
#include "Engine/Model.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)  //メンバの設定はこっち
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize() //その他はこっち
{
	//hModel_ = Model::Load("Oden.fbx");
	//assert(hModel_ >= 0);
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);

	Camera::SetPosition(XMFLOAT3(0.0f, 5.0f, -10.0f));
	Camera::SetTarget(XMFLOAT3(0.0f, 0.0f, 10.0f));
}

void PlayScene::Update()
{
	//static float time = 0.0f;
	//ot_.position_ = { 0.0f, 0.0f, 10.0f };
	//ot_.scale_ = { 0.5f, 0.5f, 0.5f };
	//ot_.rotate_.y += 0.1f;
	//time += 0.025f;
	//ot_.position_.x = 6.0f * sin(time);
	////float posx = 6.0 * sin(0.2f*time);
	////ot_.position_.x = posx;
	if (FindObject("Enemy") == nullptr) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
	//Model::SetTransform(hModel_, ot_);
	//Model::Draw(hModel_);
}

void PlayScene::Release()
{
}