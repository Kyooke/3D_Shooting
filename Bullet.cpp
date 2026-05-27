#include "Bullet.h"
#include"Player.h"
#include "Engine\\Model.h"
#include "Engine\\SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1),spped_(0.5f)
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.5f,0.5f,0.5f };
	//Player* player = static_cast<Player*>(FindObject("Player"));
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.5f);
	AddCollider(collider);
}

void Bullet::Update()
{
	transform_.position_.z = transform_.position_.z + spped_;
	if (transform_.position_.z > 50.0f)
	{
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
