#include "TitleScene.h"

void TitleScene::Init()
{
}

void TitleScene::Update(char* keys, char* preKeys)
{
	if (keys[DIK_TAB] && !preKeys[DIK_TAB]) {
		sceneNo = STAGE;
	}

}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Here is TitleScene");
	Novice::ScreenPrintf(0, 20, "TAB to StageScene");
	Novice::ScreenPrintf(640, 360, "TITLE!");
}
