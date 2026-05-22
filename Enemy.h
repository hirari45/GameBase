#pragma once
#include "Engine\\GameObject.h"

class Enemy :
	public GameObject
{
public:
	Enemy(GameObject* parent);
	~Enemy();
	void Initialize() override;	//初期化
	void Update() override;	//更新
	void Draw() override;	//描画
	void Release() override;	//開放
	void OnCollision(GameObject* pTarget);
private:
	int hModel_;//モデルのハンドル
	//Transform tr_;//一や向きなどを管理するオブジェクト
	float speed_;//弾の速さ
	//Transform ot_;//おでん用のトランスフォーム

};

