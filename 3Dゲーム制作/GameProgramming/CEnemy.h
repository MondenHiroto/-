#ifndef CENEMY_H
#define CENEMY_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
#include "CCollider.h"
#include "CEffect.h"
#include "CBullet.h"
/*
エネミークラス
キャラクタクラスを継承
*/
class CEnemy : public CCharacter{
public:
	//コンストラクタ
	//CEnemy(モデル,位置,回転,拡縮)
	CEnemy(CModel*model, CVector position, CVector rotation, CVector scale);
	//更新処理
	void Update();

	//コライダ
	CCollider mCollider1;
	
	//衝突処理
	//Collision(コライダ１,コライダ２)
	void Collision(CCollider *m, CCollider *o);

	int mFx; //X軸方向の移動 -1:左 0:移動しない 1:右へ移動
	int mFy; //Y軸方向の移動 -1:下 0:移動しない 1:上へ移動
	int mFireCount;

	//索敵用コライダ
	CCollider mColliderSearch;

	CVector mPoint;

	CCharacter *mpPlayer;
};

#endif