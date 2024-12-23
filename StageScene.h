#pragma once
#include "BaseScene.h"
#include "Vector2.h"

class PlayerBullet
{
public:
	void Initialize(Vector2 pos) {
		pos_ = pos;
		radius_ = 10;
		velocity_ = { 0.0f,-5.0f };
		isDead_ = false;
	}
	void Update() {
		pos_.x += velocity_.x;
		pos_.y += velocity_.y;

		if (pos_.y <= 0.0f) {
			isDead_ = true;
		}
	}
	void Draw() {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, radius_, radius_, 0.0f, 0xffff00ff, kFillModeSolid);
	}

	Vector2 GetPos() { return pos_; }
	int GetRadius() { return radius_; }
	bool GetIsDead() { return isDead_; }

	void SetIsDead(bool isDead) { isDead_ = isDead; }
private:
	Vector2 pos_;
	int radius_;
	Vector2 velocity_;
	bool isDead_;
};


class StageScene : public BaseScene
{
public:
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

private://プレイヤー情報
	Vector2 playerPos;
	int playerRadius;

	PlayerBullet* playerBullet;


private://敵情報
	Vector2 enemyPos;
	int enemyRadius;
	int enemyHP;

};


