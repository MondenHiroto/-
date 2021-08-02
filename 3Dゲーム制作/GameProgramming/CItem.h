#ifndef CITEM_H
#define CEITEM_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
#include "CCollider.h"
#include "CEffect.h"

/*
アイテムクラス
キャラクタクラスを継承
*/
class CItem : public CCharacter{
public:
	//コンストラクタ
	//CItem(モデル,位置,回転,拡縮)
	CItem(CModel*model, CVector position, CVector rotation, CVector scale);
	//更新処理
	void Update();

	//コライダ
	CCollider mCollider1;

	//衝突処理
	//Collision(コライダ１,コライダ２)
	void Collision(CCollider *m, CCollider *o);

	int mFx; //X軸方向の移動 -1:左 0:移動しない 1:右へ移動
	int mFy; //Y軸方向の移動 -1:下 0:移動しない 1:上へ移動

};

#endif