#include "CEnemy.h"
#include "CTaskManager.h"
#define VELOCITY 0.11f

//コンストラクタ
//CEnemy(モデル,位置,回転,拡縮)
CEnemy::CEnemy(CModel*model, CVector position,
	CVector rotation, CVector scale)
	: mCollider1(this, &mMatrix, CVector(0.0f, 0.0f, 15.0f), 3.8f)
	, mColliderSearch(this, &mMatrix, CVector(0.0f, 0.0f,0.0f),15000.0f)
	, mpPlayer(nullptr)
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
	mColliderSearch.mTag = CCollider::ESEARCH;
	mPoint = mPosition + CVector(0.0f, 0.0f, 100.0f) * mMatrixRotate;
}


//更新処理
void CEnemy::Update(){
	//行列を更新
	CTransform::Update();
	//位置を移動
	mPosition = CVector(0.0f, 0.0f, 1.5f) * mMatrix;

		/*CBullet *bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();

		CBullet *bullet2 = new CBullet();
		bullet2->Set(0.1f, 1.5f);
		bullet2->mPosition = CVector(10.0f, 0.0f, 10.0f) * mMatrix;
		bullet2->mRotation = mRotation;
		bullet2->Update();
	*/
	CVector vx = CVector(1.0f, 0.0f, 0.0f)* mMatrixRotate;
	CVector vy = CVector(0.0f, 1.0f, 0.0f) *mMatrixRotate;
	CVector vz = CVector(0.0f, 0.0f, 1.0f) * mMatrixRotate;
	CVector vp = mPoint - mPosition;
	float dx = vp.Dot(vx);
	float dy = vp.Dot(vy);
	float margin = 0.1f;
	if (dx > margin)
	{
		mRotation.mY += 10.0f;
	}
	else if (dx < -margin)
	{
		mRotation.mY -= 10.0f;
	}
	if (dy > margin)
	{
		mRotation.mX -= 10.0f;
	}
	else if (dy < -margin)
	{
		mRotation.mX += 10.0f;
	}

	mPosition = mPosition + CVector(0.0f, 0.0f, VELOCITY) * mMatrixRotate;
	CTransform::Update();

	int r = rand() % 180;

}

//衝突処理
//Collision(コライダ１,コライダ２)
void CEnemy::Collision(CCollider *m, CCollider *o){
	switch (m->mTag)
	{
	case CCollider::EBODY:
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
				mRotation.mY++;
			}
			break;
		}
		break;
	case CCollider::ESEARCH:
		if (o->mType == CCollider::ESPHERE){
			if (o->mpParent->mTag == EPLAYER){
				if (CCollider::Collision(m, o)){
					mpPlayer = o->mpParent;
					mPoint = mpPlayer->mPosition;
				}
			}
		}
		break;
	}
}