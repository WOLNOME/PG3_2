#pragma once
#include "BaseScene.h"
class TitleScene : public BaseScene
{
public:
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

};

