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
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	EScene GetNextScene();
	CVector mEye;

	//���f���N���X�̃C���X�^���X�쐬
	CModel mModel;

	CModel mBackGround; //�w�i���f��
	CModel mModelCube;

	CPlayer mPlayer;

	CCollisionManager CollisionManager;

	//�O�p�R���C�_�̍쐬
	//�폜CColliderTriangle mColliderTriangle;
	//�폜CColliderTriangle mColliderTriangle2;

	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;
};


#endif
