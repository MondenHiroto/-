#ifndef CSCENEDEATH_H
#define CSCENEDEATH_H
#include "CScene.h"
#include "CText.h"

class CSceneDeath : public CScene{
public:
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	void Render();
	//次のシーンの取得
	EScene GetNextScene();
	CText mText;
};
#endif