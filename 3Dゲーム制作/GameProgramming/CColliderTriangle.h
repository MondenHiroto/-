#ifndef CCOLLIDERTRIANGLE_H
#define CCOLLIDERTRIANGLE_H
#include "CCollider.h"
/*
三角形コライダの定義
*/
class CColliderTriangle : public CCollider
{
public:
	CColliderTriangle(){}
	//コンストラクタ(三角コライダ)
	//CColliderTriangle(親、親行列、頂点1、頂点2、頂点３)
	CColliderTriangle(CCharacter *parent, CMatrix * matrix
		, const CVector &v0, const CVector &v1, const CVector &v2);
	//三角コライダの設定
	//Set(親、親行列、頂点1、頂点２、頂点３)
	void Set(CCharacter *parent, CMatrix *matrix
		, const CVector &v0, const CVector &v1, const CVector &v2);
	//描画
	void Render();

	//優先度の変更
	void CColliderTriangle::ChangePriority()
	{
		//mV[0]とmV[1]とmV[2]の中心を求める
		CVector pos = (mV[0] * *mpMatrix + mV[1] * *mpMatrix
			+ mV[2] * *mpMatrix) * (1.0f / 3.0f);
		//ベクトルの長さが優先度
		mPriority = pos.Length();
		CCollisionManager::Get()->Remove(this); //一旦削除
		CCollisionManager::Get()->Add(this); //追加
	}
};
#endif