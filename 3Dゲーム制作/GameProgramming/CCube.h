#ifndef CCUBE_H
#define CCUBE_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
#include "CColliderMesh.h"

/*
エネミークラス
キャラクタクラスを継承
*/
class CCube : public CCharacter{
public:
	//三角形の可変長配列
	std::vector<CTriangle> mTriangles;
	//コンストラクタ
	//CEnemy(モデル,位置,回転,拡縮)
	CCube(CModel*model, CVector position, CVector rotation, CVector scale);
	//更新処理
	void Update();

	CColliderMesh ColliderMesh;
};

#endif