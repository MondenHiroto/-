#ifndef CPLAYER_H
#define CPLAYER_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
#include "CBullet.h"
#include "CColliderLine.h"
#include "CText.h"
#include "CCollider.h"
/*
プレイヤークラス
キャラクタクラスを継承
*/
class CPlayer : public CCharacter{
public:
	//更新処理
	void Update();

	CColliderLine mLine; //線分コライダ
	CColliderLine mLine2;
	CColliderLine mLine3;
	CCollider mCollider1;
	CPlayer();

	//衝突処理
	void Collision(CCollider *m, CCollider * o);

	CText mText;
	//描画処理
	void Render(); 

	int Stamina;

	int Time = 301 * 60;
};

#endif