#include "PlayScene.h"
#include "Engine\\Model.h"
#include"Player.h"
#include"Enemy.h"
#include "Engine\\SceneManager.h"
#include"Engine\\Camera.h"

namespace
{
	int timer = 10;
}
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	//Camera::SetPosition(XMFLOAT3(0.0f, 0.1f, 0.0f));
}

void PlayScene::Update()
{
	new Enemy* =enemy();

	timer -= 1;
	if (timer == 0)
	{
		Instantiate<Enemy>(this);
		timer == 100;
	}
	if (FindObject("Enemy")==nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{

}

void PlayScene::Release()
{
}
