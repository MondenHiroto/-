#include "CSceneClear.h"
#include "CKey.h"


void CSceneClear::Init() {
	//テクスチャファイルを読み込む
	//フォントの設定
	mText.LoadTexture("FontWhite.tga", 1, 64);
	//シーンの設定
	mScene = ECLEAR;
}

//更新処理のオーバーライド
void CSceneClear::Update() {
	//文字列の描画
	if (CKey::Once(VK_RETURN)) {
		//次のシーンはゲーム
		mScene = EGAME;
	}

}

void CSceneClear::Render(){
	mText.DrawString("GAMECLEAR", -200, 0, 50, 50);
	mText.DrawString("Push ENTER Key", -200, -100, 16, 16);
}

//次のシーンの取得
CScene::EScene CSceneClear::GetNextScene() {
	return mScene;
}
