#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
//トランスフォームクラスのインクルード
#include "CTransform.h"
#include "CCollisionManager.h"
/*
コライダクラス
衝突判定データ
*/
class CCollider : public CTransform,public CTask{
public:
	CCharacter *mpParent;//親
	CMatrix *mpMatrix;//親行列
	float mRadius; //半径
	//コンストラクタ
	//CCollider(親,親行列,位置,回転,拡縮,半径)
	CCollider(CCharacter *parent, CMatrix *matrix,
		CVector position, float radius);
	~CCollider();

	//描画
	void Render();

	//衝突判定
	//CCollision(コライダ1,コライダ2)
	//return:true(衝突している)false(衝突していない)
	static bool Collision(CCollider *m, CCollider * o);

	//コライダタイプ
	enum EType{
		ESPHERE,//球コライダ
		ETRIANGlE,//三角コライダ
		ELINE,//線分コライダ
	};
	EType mType;//コライダタイプ
	//頂点
	CVector mV[3];
	//デフォルトコンストラクタ
	CCollider();

	//CollisionTriangleLine(三角コライダ、線分コライダ、調整値)
	//return:true(衝突している)false(衝突していない)
	//調整池:衝突しない位置まで戻す値
	static bool CollisionTriangleLine(CCollider *triangle, CCollider *line, CVector *adjust);

	//CollisionTriangleSphere(三角コライダ，球コライダ, 調整値)
	//return:true(衝突している)false(衝突していない)
	//調整値:衝突しない位置まで戻す値
	static bool CollisionTrianglesSphere(CCollider *triangle, CCollider *sphere, CVector *adjust);

	//優先度の変更
	void CCollider::ChangePriority()
	{
		//自分の座標*親の変換行列を掛けてワールド座標を求める
		CVector pos = mPosition * *mpMatrix;
		//ベクトルの長さが優先度
		mPriority = pos.Length();
		CCollisionManager::Get()->Remove(this); //一旦削除
		CCollisionManager::Get()->Add(this); //追加
	}

	enum ETag
	{
		EBODY,
		ESEARCH,
	};
	ETag mTag;
};
#endif