#include "Player.h"
#include "Bullet.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("tekki.fbx");
		assert(hModel_ >= 0);
		transform_.position_={ 0.0f,0.0f,0.0f };
		
}

void Player::Update()
{
	int height = 6.8;
	int width = 3.4;
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		transform_.position_.x += -0.8;
		if (transform_.position_.x < -height)
		{
			transform_.position_.x++;
		}
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.8;
		if (transform_.position_.x > height)
		{
			transform_.position_.x--;
		}
	}
	if (Input::IsKey(DIK_UP) || Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.4;
		if (transform_.position_.y > width)
		{
			transform_.position_.y--;
		}
	}
	if (Input::IsKey(DIK_DOWN) || Input::IsKey(DIK_S))
	{
		transform_.position_.y+= -0.4;
		if (transform_.position_.y < -width)
		{
			transform_.position_.y++;
		}
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet* pBullet = Instantiate<Bullet>(this->GetParent());
		pBullet->SetPosition(transform_.position_);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
