#include "StageScene.h"
#include <cmath>

void StageScene::Init()
{
	//プレイヤーの初期化
	playerPos = { 640,460 };
	playerRadius = 30;

	//敵の初期化
	enemyPos = { 640,160 };
	enemyRadius = 50;
	enemyHP = 10;

}

void StageScene::Update(char* keys, char* preKeys)
{
	if (keys[DIK_TAB] && !preKeys[DIK_TAB]) {
		sceneNo = CLEAR;
	}
	if (enemyHP <= 0) {
		sceneNo = CLEAR;
	}

	//弾の死亡処理
	if (playerBullet) {
		if (playerBullet->GetIsDead()) {
			delete playerBullet;
			playerBullet = nullptr;
		}
	}

	//プレイヤーの移動
	if (keys[DIK_W]) {
		playerPos.y += (-2);
	}
	if (keys[DIK_A]) {
		playerPos.x += (-2);
	}
	if (keys[DIK_S]) {
		playerPos.y += (2);
	}
	if (keys[DIK_D]) {
		playerPos.x += (2);
	}

	//弾発射
	if (!playerBullet) {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			playerBullet = new PlayerBullet();
			playerBullet->Initialize(playerPos);
		}
	}

	//弾の更新
	if (playerBullet) {
		playerBullet->Update();
	}

	//当たり判定
	if (playerBullet) {
		float dx = enemyPos.x - playerBullet->GetPos().x;
		float dy = enemyPos.y - playerBullet->GetPos().y;
		if (sqrtf(dx * dx + dy * dy) < enemyRadius + playerBullet->GetRadius()) {
			playerBullet->SetIsDead(true);
			enemyHP--;
		}
	}


}

void StageScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Here is StageScene");
	Novice::ScreenPrintf(0, 20, "TAB to ClearScene");
	Novice::ScreenPrintf(0, 40, "WASD : Move");
	Novice::ScreenPrintf(0, 60, "Space : Shot");
	Novice::ScreenPrintf(600, 80, "EnemyHP : %d", enemyHP);

	//プレイヤーの描画
	Novice::DrawEllipse((int)playerPos.x, (int)playerPos.y, playerRadius, playerRadius, 0.0f, 0xff0000ff, kFillModeSolid);

	//弾の描画
	if (playerBullet) {
		playerBullet->Draw();
	}

	//敵の描画
	Novice::DrawEllipse((int)enemyPos.x, (int)enemyPos.y, enemyRadius, enemyRadius, 0.0f, 0x0000ffff, kFillModeSolid);


}
