#ifndef CCOLLIDERLINE_H
#define CCOLLIDERLINE_H
#include "CCollider.h"
/*
線分コライダの定義
*/
class CColliderLine : public CCollider
{
public:
	CColliderLine(){}
	//コンストラクタ(線分コライダ)
	//CColliderLine(親、親行列、頂点１、頂点２)
	CColliderLine(CCharacter *parent, CMatrix *matrix, const CVector &v0, const CVector &v1);
	//線分コライダの設定
	//Set(親、親行列、頂点１、頂点２)
	void Set(CCharacter  *parent, CMatrix *matrix, const CVector &v0, const CVector &v1);
	//描画
	void Render();

	//優先度の変更
	void CColliderLine::ChangePriority()
	{
		//mV[0]とmV[1]の中心を求める
		CVector pos = (mV[0] * *mpMatrix + mV[1] * *mpMatrix)*(0.5f);
		//ベクトルの長さが優先度
		mPriority = pos.Length();
		CCollisionManager::Get()->Remove(this); //一旦削除
		CCollisionManager::Get()->Add(this); //追加
	}
};
#endif