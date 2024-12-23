#pragma once
#include <Novice.h>

//シーン名を列挙型(Enum)で定義
enum SCENE {
	TITLE,
	STAGE,
	CLEAR
};

class BaseScene
{
protected:
	//シーン番号を管理する変数
	static int sceneNo;

public:
	virtual void Init() = 0;
	virtual void Update(char* keys, char* preKeys) = 0;
	virtual void Draw() = 0;

	virtual ~BaseScene();

	int GetSceneNo();
};

