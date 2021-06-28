#include "CEnemy.h"
#include "CTaskManager.h"

//コンストラクタ
//CEnemy(モデル,位置,回転,拡縮)
CEnemy::CEnemy(CModel*model, CVector position,
	CVector rotation, CVector scale)
	:mCollider1(this, &mMatrix, CVector(0.0f, 0.0f, 15.0f), 3.8f)
{
	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	mPosition = position; //位置の設定
	mRotation = rotation; //回転の設定
	mScale = scale; //拡縮の設定
	//優先度を1に変更する
	mPriority = 1;
	CTaskManager::Get()->Remove(this); //削除して
	CTaskManager::Get()->Add(this); //追加する
}


//更新処理
void CEnemy::Update(){
	//行列を更新
	CTransform::Update();
	//位置を移動
	mPosition = CVector(0.0f, -1.5f, 0.0f) * mMatrix;

		CBullet *bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();

		CBullet *bullet2 = new CBullet();
		bullet2->Set(0.1f, 1.5f);
		bullet2->mPosition = CVector(10.0f, 0.0f, 10.0f) * mMatrix;
		bullet2->mRotation = mRotation;
		bullet2->Update();
	
}

//衝突処理
//Collision(コライダ１,コライダ２)
void CEnemy::Collision(CCollider *m, CCollider *o){
	//相手のコライダタイプの判定
	switch (o->mType)
	{
		break;
	case CCollider::ETRIANGlE: //三角コライダの時
		CVector adjust; //調整値
		//三角コライダと球コライダの衝突判定
		if (CCollider::CollisionTrianglesSphere(o, m, &adjust))
		{      //衝突しない位置まで戻す
			mPosition = mPosition + adjust;
			mRotation.mZ++;
		}
		break;
	}
}
	