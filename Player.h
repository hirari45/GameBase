#pragma once
#include "Engine\\GameObject.h"

class Player :
    public GameObject
{
public:
	Player(GameObject* parent);
	void Initialize() override;	//初期化
	void Update() override;	//更新
	void Draw() override;	//描画
	void Release() override;	//開放
private:
	int hModel_;
	//Transform tr_;//トランスフォーム（アフィン変換のパラメータを保存してるよ！）
};

