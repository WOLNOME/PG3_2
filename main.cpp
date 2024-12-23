#include <Novice.h>
#include "SceneManager.h"

const char kWindowTitle[] = "PG3_04_01_確認課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	SceneManager* sceneManager = new SceneManager();

	sceneManager->Run();

	delete sceneManager;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
