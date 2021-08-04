#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CVector.h"
#include "CModel.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CCollisionManager.h"
#include "CColliderTriangle.h"
#include "CColliderMesh.h"
#include "CCube.h"
/*
ゲームのシーン
*/
class CSceneGame : public CScene {
public:
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	EScene GetNextScene();
	CVector mEye;

	//モデルクラスのインスタンス作成
	CModel mModel;

	CModel mBackGround; //背景モデル
	CModel mModelCube;

	CPlayer mPlayer;

	CCollisionManager CollisionManager;

	//三角コライダの作成
	//削除CColliderTriangle mColliderTriangle;
	//削除CColliderTriangle mColliderTriangle2;

	//モデルからコライダを生成
	CColliderMesh mColliderMesh;
};


#endif
