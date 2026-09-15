#pragma once
#include "Engine\\GameObject.h"

class Player :
	public GameObject
{
public:
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

private:
	int hModel_;	//モデルのハンドル
	int hModel_2;

	// --- 以下の変数を追加しました ---
	int leftKeyInterval_ = 0;   // 左キーのダブルタップ判定用タイマー
	int rightKeyInterval_ = 0;  // 右キーのダブルタップ判定用タイマー
	bool isSpinning_ = false;   // 回転移動中かどうか
	int spinTimer_ = 0;         // 回転移動の継続時間
};