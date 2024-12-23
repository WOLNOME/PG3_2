#pragma once
#include <memory>
#include "BaseScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include "ClearScene.h"

class SceneManager
{
private:
	//シーンを保持するメンバ変数
	std::unique_ptr<BaseScene> sceneArr_[3];

	//どのステージを呼び出すかを管理する変数
	int currentSceneNo_;
	int prevSceneNo_;

	//キー入力
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

public:
	SceneManager();
	~SceneManager();

	int Run();


};

