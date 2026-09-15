#include "Player.h"
#include "Bullet.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"

Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), hModel_2(-1),
	leftKeyInterval_(0), rightKeyInterval_(0), isSpinning_(false), spinTimer_(0)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("tekki.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f, 0.0f, 0.0f };
	transform_.rotate_ = { 0.0f, 0.0f, 0.0f }; 
}

void Player::Update()
{
	float height = 6.8f;
	float width = 3.4f;

	if (leftKeyInterval_ > 0) leftKeyInterval_--;
	if (rightKeyInterval_ > 0) rightKeyInterval_--;

	if (isSpinning_)
	{
		spinTimer_--;
		if (spinTimer_ <= 0)
		{
			isSpinning_ = false;
			transform_.rotate_.z = 0.0f; 
		}
	}


	if (Input::IsKeyDown(DIK_LEFT) || Input::IsKeyDown(DIK_A))
	{
		if (leftKeyInterval_ > 0)
		{
			isSpinning_ = true;
			spinTimer_ = 36; 
			leftKeyInterval_ = 0;
		}
		else
		{
			leftKeyInterval_ = 15;
		}
	}

	if (Input::IsKeyDown(DIK_RIGHT) || Input::IsKeyDown(DIK_D))
	{
		if (rightKeyInterval_ > 0)
		{
			isSpinning_ = true;
			spinTimer_ = 36; 
			rightKeyInterval_ = 0;
		}
		else
		{
			rightKeyInterval_ = 15;
		}
	}


	float moveSpeed = 0.4f;
	if (isSpinning_)
	{
		moveSpeed = 1.2f;
		transform_.rotate_.z += 10.0f;
	}


	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		transform_.position_.x -= moveSpeed;
		if (transform_.position_.x < -height)
		{
			transform_.position_.x = -height;
		}
	}

	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		transform_.position_.x += moveSpeed;
		if (transform_.position_.x > height)
		{
			transform_.position_.x = height;
		}
	}

	if (Input::IsKey(DIK_UP) || Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.2f;
		if (transform_.position_.y > width)
		{
			transform_.position_.y = width;
		}
	}
	if (Input::IsKey(DIK_DOWN) || Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.2f;
		if (transform_.position_.y < -width)
		{
			transform_.position_.y = -width;
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