#include "BaseScene.h"

//タイトルシーンで初期化
int BaseScene::sceneNo = TITLE;

BaseScene::~BaseScene()
{
}

int BaseScene::GetSceneNo()
{
	return sceneNo;
}
