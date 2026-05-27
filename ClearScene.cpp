#include "ClearScene.h"
#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"


ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hClearPic_(-1)
{
}

void ClearScene::Initialize()
{
	hClearPic_ = Image::Load("Clear.png");
	assert(hClearPic_ >= 0);
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_T))
	{
		//見つからない場合はnullptrを返すのでnullptr出ないことを確認してから使う
		//SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}

}

void ClearScene::Draw()
{
	Image::SetTransform(hClearPic_, transform_);
	Image::Draw(hClearPic_);
}

void ClearScene::Release()
{
}
