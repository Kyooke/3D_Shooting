#include "ClearScene.h"
#include "Engine\\Image.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"CleraScene"),hClearPic_(-1)
{
}

void ClearScene::Initialize()
{
	hClearPic_ = Image::Load("kuria.png");
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
	Image::SetTransform(hClearPic_, transform_);
	Image::Draw(hClearPic_);
}

void ClearScene::Release()
{
}
