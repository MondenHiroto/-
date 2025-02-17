#include "CCollisionManager.h"
#include "CCollider.h"
//マネージャのインスタンス
CCollisionManager* CCollisionManager::mpInstance = 0;
//マネージャのインスタンス
CCollisionManager* CCollisionManager::Get()
{
	if (mpInstance == 0)
	{
		mpInstance = new CCollisionManager();
	}
	return mpInstance;
}

//衝突処理
void CCollisionManager::Collision(){
	//現在位置を先頭にする
	CCollider *task = (CCollider*)mHead.mpNext;
	//最後まで来たら終了する
	while (task->mpNext){
		//現在位置の次を求める
		CCollider *next = (CCollider*)task->mpNext;
		//次が0になったら終了
		while (next->mpNext){
			//親の衝突処理を呼び出す
			//自分の衝突処理
			if (task->mpParent)
				task->mpParent->Collision(task, next);
			//相手の衝突処理
			if (next->mpParent)
				next->mpParent->Collision(next, task);
			//次を求める
				next = (CCollider*)next->mpNext;
		}
		//現在位置を次にする
		task = (CCollider*)task->mpNext;
	}
}