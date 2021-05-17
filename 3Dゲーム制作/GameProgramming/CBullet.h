#ifndef CBULLET_H
#define CBULLET_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
//三角形クラスのインクルード
#include "CTriangle.h"
#include "CCollider.h"

/*
弾クラス
三角形を飛ばす
*/
class CBullet : public CCharacter{
public:
	CBullet();
	//三角形
	CTriangle mT;
	//幅と奥行きの設定
	//Set(幅、奥行き)
	void Set(float w, float d);
	//更新
	void Update();
	//コライダ
    CCollider mCollider;

	void CBullet::Render();
	
	//生存時間
	int mLife;
	int mFx, mFy;	//移動量
	//衝突処理
	//Collision(コライダ１,コライダ２ )

};
#endif