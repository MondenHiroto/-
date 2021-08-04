#include "CSceneDeath.h"
#include "CKey.h"
#include "CUtil.h"

void CSceneDeath::Init() {
	//テクスチャファイルを読み込む
	//フォントの設定
	mText.LoadTexture("FontWhite.tga", 1, 64);
	//シーンの設定
	mScene = EDEATH;
}

//更新処理のオーバーライド
void CSceneDeath::Update() {
	//文字列の描画
	if (CKey::Once(VK_RETURN)) {
		//次のシーンはゲーム
		mScene = EGAME;
	}
	Render();
}

void CSceneDeath::Render(){

	CUtil::Start2D(-400, 400, -300, 300);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	mText.DrawString("GAMEOVER", -200, 200, 50, 50);
	mText.DrawString("PUSH ENTER KEY", -2000, 200, 16, 16);
	CUtil::End2D();
}

//次のシーンの取得
CScene::EScene CSceneDeath::GetNextScene() {
	return mScene;
}
