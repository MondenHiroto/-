#include "CSceneGame.h"

#include "glut.h"

#include "CVector.h"

#include "CTriangle.h"

#include "CKey.h"

#include "CMatrix.h"

#include "CTransform.h"

#include "CTaskManager.h"

#include "CEnemy.h"

#include "CBillBoard.h"

#include "CCamera.h"


//C5モデル
CModel mModelSkull;


void CSceneGame::Init() {
	mEye = CVector(1.0f, 5.0f, 3.0f);
	//モデルファイルの入力
	mBackGround.Load("sky.obj", "sky.mtl");

	CMatrix matrix;
	matrix.Print();
	mPlayer.mpModel = &mModel;
    mPlayer.mPosition = CVector(0.0f, 3.0f, -3.0f); //位置の設定
	mPlayer.mRotation = CVector(0.0f, 180.0f, 0.0f); //回転の設定
	mPlayer.mScale = CVector(0.1f, 0.1f, 0.1f);; //拡大縮小の設定
	//スカルモデルの読み込み
	mModelSkull.Load("Skull.obj", "Skull.mtl");
	//敵機のインスタンス作成
	new CEnemy(&mModelSkull, CVector(0.0f, 1.0f, -100.0f),
		CVector(-90.0f,0.0f,0.0f) , CVector(0.2f, 0.2f, 0.2f));

	mModelCube.Load("cube.obj", "cube.mtl");
	//外壁
	new CCube(&mModelCube, CVector(0.0f, -1.0f, -130.0f),
		CVector(), CVector(140.0f, 10.0f, 5.0f));

	new CCube(&mModelCube, CVector(0.0f, -1.0f, 130.0f),
		CVector(), CVector(140.0f, 10.0f, 5.0f));

	new CCube(&mModelCube, CVector(130.0f, -1.0f, 0.0f),
		CVector(), CVector(5.0f, 10.0f, 140.0f));

	new CCube(&mModelCube, CVector(-130.0f, -1.0f, 0.0f),
		CVector(), CVector(5.0f, 10.0f, 140.0f));
	//障害物
	new CCube(&mModelCube, CVector(-100.0f, -1.0f, 0.0f),
		CVector(), CVector(10.0f, 10.0f, 10.0f));

	new CCube(&mModelCube, CVector(-70.0f, -1.0f, 0.0f),
		CVector(), CVector(10.0f, 10.0f, 30.0f));

	new CCube(&mModelCube, CVector(-70.0f, -1.0f, 50.0f),
		CVector(), CVector(10.0f, 10.0f, 10.0f));

	new CCube(&mModelCube, CVector(-70.0f, -1.0f, -50.0f),
		CVector(), CVector(30.0f, 10.0f, 10.0f));

	new CCube(&mModelCube, CVector(-40.0f, -1.0f, 0.0f),
		CVector(), CVector(10.0f, 10.0f, 10.0f));

	new CCube(&mModelCube, CVector(100.0f, -1.0f, 0.0f),
		CVector(), CVector(10.0f, 10.0f, 30.0f));

	new CCube(&mModelCube, CVector(115.0f, -1.0f, 0.0f),
		CVector(), CVector(20.0f, 10.0f, 10.0f));

	new CCube(&mModelCube, CVector(50.0f, -1.0f, 30.0f),
		CVector(), CVector(10.0f, 10.0f, 10.0f));

	new CCube(&mModelCube, CVector(60.0f, -1.0f, 100.0f),
		CVector(), CVector(20.0f, 10.0f, 10.0f));

	new CCube(&mModelCube, CVector(100.0f, -1.0f, 100.0f),
		CVector(), CVector(10.0f, 10.0f, 10.0f));

	new CCube(&mModelCube, CVector(60.0f, -1.0f, -100.0f),
		CVector(), CVector(20.0f, 10.0f, 10.0f));

	//ビルボードの生成
	new CBillBoard(CVector(-6.0f, 3.0f, -10.0f), 1.0f, 1.0f);
	//三角コライダの確認
	/*mColliderTriangle.Set(NULL, NULL
		, CVector(-50.0f, 0.0f, -50.0f)
		, CVector(-50.0f, 0.0f, 50.0f)
		, CVector(50.0f, 0.0f, -50.0f));
	mColliderTriangle2.Set(NULL, NULL
		, CVector(50.0f, 0.0f, 50.0f)
		, CVector(50.0f, 0.0f, -50.0f)
		, CVector(-50.0f, 0.0f, 50.0f));
		*/

	//背景モデルから三角コライダを生成
	//親インスタンスと親行列はなし
	mColliderMesh.Set(NULL, NULL, &mBackGround);
}

void CSceneGame::Update() {
	//タスクマネージャの更新
	CTaskManager::Get()->Update();
	//コリジョンマネージャの衝突処理
	CCollisionManager::Get()->Collision();
	//頂点1、頂点2、頂点3、法線データの作成
	CVector v0, v1, v2, n;
	//法線を上向きで設定する
	n.mX = 0.0f; n.mY = 1.0f; n.mZ = 0.0f;
	//頂点１の座標を設定する
	v0.mX = 0.0f; v0.mY = 0.0f; v0.mZ = 0.5f;
	//頂点２の座標を設定する
	v1.mX = 1.0f; v1.mY = 0.0f; v1.mZ = 0.0f;
	//頂点３の座標を設定する
	v2.mX = 0.0f; v2.mY = 0.0f; v2.mZ = -0.5f;

	//視点の設定
	//gluLookAt(視点X,視点Y,視点Z,中心X,中心Y,中心Z,上向X,上向Y,上向Z)
	if (CKey::Push('J'))
	{
		mEye.mX -= 0.1f;
	}
	if (CKey::Push('L'))
	{
		mEye.mX += 0.1f;
	}

	if (CKey::Push('I'))
	{
		mEye.mZ -= 0.1f;
	}
	if (CKey::Push('K'))
	{
		mEye.mZ += 0.1f;
	}
	if (CKey::Push('O'))
	{
		mEye.mY += 0.1f;
	}
	if (CKey::Push('M'))
	{
		mEye.mY -= 0.1f;
	}

	

//	mPlayer.Update(); //行列の更新
	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注意点、上方向
	//視点を求める
	e = CVector(0.0f, 0.0f, -0.1f) * mPlayer.mMatrix;
	if (CKey::Push(VK_SPACE))
	{
		e = CVector(0.0f, 0.0f, 0.1f) * mPlayer.mMatrix;
	}
	//注意点を求める
	c = mPlayer.mPosition;
    //上方向を求める
	u = CVector(0,1,0) * mPlayer.mMatrixRotate;
	
	//カメラクラスの設定
	Camera.Set(e, c, u);
	Camera.Render();

	
	mBackGround.Render();
	
	//タスクリストの削除
	CTaskManager::Get()->Delete();
	//タスクマネージャの描画
	CTaskManager::Get()->Render();

	CCollisionManager::Get()->Render();
}
