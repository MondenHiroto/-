//プレイヤークラスのインクルード
#include "CPlayer.h"
//キー入力クラスのインクルード
#include "CKey.h"
#include "CTaskManager.h"
#include "CUtil.h"

CPlayer::CPlayer()
: mLine(this, &mMatrix, CVector(0.0f, 0.0f, -14.0f), CVector(0.0f, 0.0f, 17.0f))
, mLine2(this, &mMatrix, CVector(0.0f, 5.0f, -8.0f), CVector(0.0f, -3.0f, -8.0f))
, mLine3(this, &mMatrix, CVector(9.0f, 0.0f, -8.0f), CVector(-9.0f, 0.0f, -8.0f))
{//テクスファイの読み込み(1行64列)
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

//更新処理
void CPlayer::Update(){
	if (Time > 0){
		Time--;
	}
	//Aキー入力で回転
	if (CKey::Push('A')){
		//Y軸の回転値を増加
		mRotation.mY += 3;
	}
	if (CKey::Push('D')){
		mRotation.mY += -3; 
	}
	if (CKey::Push(VK_RIGHT)){
		mPosition = CVector(-2.0f, 0.0f, 0.0f) * mMatrix;
	}
	if (CKey::Push(VK_LEFT)){
		mPosition = CVector(2.0f, 0.0f, 0.0f) *mMatrix;
	}
	//上矢印キー入力で前進
	if (CKey::Push(VK_UP)){
		//Z軸方向に1進んだ値を回転移動させる
		mPosition = CVector(0.0f, 0.0f, 2.0f) * mMatrix;
	}

	if (CKey::Push(VK_DOWN)){
		mPosition = CVector(0.0f, 0.0f, -2.0f) * mMatrix;
	}

	if (CKey::Push('W')){
		mPosition = CVector(0.0f, 0.0f, 4.0f) * mMatrix;
	}
	//CCharacterの更新
	CTransform::Update();

}


void CPlayer::Collision(CCollider *m, CCollider *o){
	//自身のコライダタイプの判定
	switch (m->mType){
	case CCollider::ELINE://線分コライダ
		//相手のコライダが三角コライダの時
		if (o->mType == CCollider::ETRIANGlE){
			CVector adjust;//調整用ベクトル
			//三角形と線分の衝突判定
			CCollider::CollisionTriangleLine(o, m, &adjust);
			//位置の更新(mPosition + adjust)
			mPosition = mPosition - adjust * -1;
			//行列の更新
			CTransform::Update();
		}
		break;
	}

}

void CPlayer::Render()
{
	//親の描画処理
	CCharacter::Render();

	//2Dの描画開始
	CUtil::Start2D(-400, 400, -300, 300);
	//描画色の設定(緑色の半透明)
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	//文字列編集エリアの作成
	char buf[64];

	//Y座標の表示
	//文字列の設定
	sprintf(buf, "TIME:%d",Time / 60);
	//文字列の描画
	mText.DrawString(buf, 200, 270, 8, 16);

	//2Dの描画終了
	CUtil::End2D();
}