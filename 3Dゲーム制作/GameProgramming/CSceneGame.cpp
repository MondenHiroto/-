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


//C5���f��
CModel mModelSkull;


void CSceneGame::Init() {
	mEye = CVector(1.0f, 5.0f, 3.0f);
	//���f���t�@�C���̓���
	mBackGround.Load("sky.obj", "sky.mtl");

	CMatrix matrix;
	matrix.Print();
	mPlayer.mpModel = &mModel;
    mPlayer.mPosition = CVector(0.0f, 3.0f, -3.0f); //�ʒu�̐ݒ�
	mPlayer.mRotation = CVector(0.0f, 180.0f, 0.0f); //��]�̐ݒ�
	mPlayer.mScale = CVector(0.1f, 0.1f, 0.1f);; //�g��k���̐ݒ�
	//�X�J�����f���̓ǂݍ���
	mModelSkull.Load("Skull.obj", "Skull.mtl");
	//�G�@�̃C���X�^���X�쐬
	new CEnemy(&mModelSkull, CVector(0.0f, 1.0f, -100.0f),
		CVector(-90.0f,0.0f,0.0f) , CVector(0.2f, 0.2f, 0.2f));

	mModelCube.Load("cube.obj", "cube.mtl");
	//�O��
	new CCube(&mModelCube, CVector(0.0f, -1.0f, -130.0f),
		CVector(), CVector(140.0f, 10.0f, 5.0f));

	new CCube(&mModelCube, CVector(0.0f, -1.0f, 130.0f),
		CVector(), CVector(140.0f, 10.0f, 5.0f));

	new CCube(&mModelCube, CVector(130.0f, -1.0f, 0.0f),
		CVector(), CVector(5.0f, 10.0f, 140.0f));

	new CCube(&mModelCube, CVector(-130.0f, -1.0f, 0.0f),
		CVector(), CVector(5.0f, 10.0f, 140.0f));
	//��Q��
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

	//�r���{�[�h�̐���
	new CBillBoard(CVector(-6.0f, 3.0f, -10.0f), 1.0f, 1.0f);
	//�O�p�R���C�_�̊m�F
	/*mColliderTriangle.Set(NULL, NULL
		, CVector(-50.0f, 0.0f, -50.0f)
		, CVector(-50.0f, 0.0f, 50.0f)
		, CVector(50.0f, 0.0f, -50.0f));
	mColliderTriangle2.Set(NULL, NULL
		, CVector(50.0f, 0.0f, 50.0f)
		, CVector(50.0f, 0.0f, -50.0f)
		, CVector(-50.0f, 0.0f, 50.0f));
		*/

	//�w�i���f������O�p�R���C�_�𐶐�
	//�e�C���X�^���X�Ɛe�s��͂Ȃ�
	mColliderMesh.Set(NULL, NULL, &mBackGround);
}

void CSceneGame::Update() {
	//�^�X�N�}�l�[�W���̍X�V
	CTaskManager::Get()->Update();
	//�R���W�����}�l�[�W���̏Փˏ���
	CCollisionManager::Get()->Collision();
	//���_1�A���_2�A���_3�A�@���f�[�^�̍쐬
	CVector v0, v1, v2, n;
	//�@����������Őݒ肷��
	n.mX = 0.0f; n.mY = 1.0f; n.mZ = 0.0f;
	//���_�P�̍��W��ݒ肷��
	v0.mX = 0.0f; v0.mY = 0.0f; v0.mZ = 0.5f;
	//���_�Q�̍��W��ݒ肷��
	v1.mX = 1.0f; v1.mY = 0.0f; v1.mZ = 0.0f;
	//���_�R�̍��W��ݒ肷��
	v2.mX = 0.0f; v2.mY = 0.0f; v2.mZ = -0.5f;

	//���_�̐ݒ�
	//gluLookAt(���_X,���_Y,���_Z,���SX,���SY,���SZ,���X,���Y,���Z)
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

	

//	mPlayer.Update(); //�s��̍X�V
	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A���ӓ_�A�����
	//���_�����߂�
	e = CVector(0.0f, 0.0f, -0.1f) * mPlayer.mMatrix;
	if (CKey::Push(VK_SPACE))
	{
		e = CVector(0.0f, 0.0f, 0.1f) * mPlayer.mMatrix;
	}
	//���ӓ_�����߂�
	c = mPlayer.mPosition;
    //����������߂�
	u = CVector(0,1,0) * mPlayer.mMatrixRotate;
	
	//�J�����N���X�̐ݒ�
	Camera.Set(e, c, u);
	Camera.Render();

	
	mBackGround.Render();
	
	//�^�X�N���X�g�̍폜
	CTaskManager::Get()->Delete();
	//�^�X�N�}�l�[�W���̕`��
	CTaskManager::Get()->Render();

	CCollisionManager::Get()->Render();
}
