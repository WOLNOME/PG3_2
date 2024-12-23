#include "ClearScene.h"

void ClearScene::Init()
{
}

void ClearScene::Update(char* keys, char* preKeys)
{
	if (keys[DIK_TAB] && !preKeys[DIK_TAB]) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Here is ClearScene");
	Novice::ScreenPrintf(0, 20, "TAB to TitleScene");
	Novice::ScreenPrintf(640, 360, "CLEAR!");
}
