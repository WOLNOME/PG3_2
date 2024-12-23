#include "SceneManager.h"
#include "Novice.h"

SceneManager::SceneManager()
{
	//各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();
	//初期シーンの設定
	currentSceneNo_ = TITLE;
	prevSceneNo_ = TITLE;

}

SceneManager::~SceneManager()
{
}

int SceneManager::Run()
{
	while (Novice::ProcessMessage() == 0)
	{
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		//シーン切り替えチェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		//更新処理
		sceneArr_[currentSceneNo_]->Update(keys, preKeys);

		//描画処理
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();

		if (keys[DIK_ESCAPE] && !preKeys[DIK_ESCAPE]) {
			break;
		}
	}
	return 0;
}
