#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//�g�����X�t�H�[���N���X�̃C���N���[�h
#include "CTransform.h"
#include "CCollisionManager.h"
/*
�R���C�_�N���X
�Փ˔���f�[�^
*/
class CCollider : public CTransform,public CTask{
public:
	CCharacter *mpParent;//�e
	CMatrix *mpMatrix;//�e�s��
	float mRadius; //���a
	//�R���X�g���N�^
	//CCollider(�e,�e�s��,�ʒu,��],�g�k,���a)
	CCollider(CCharacter *parent, CMatrix *matrix,
		CVector position, float radius);
	~CCollider();

	//�`��
	void Render();

	//�Փ˔���
	//CCollision(�R���C�_1,�R���C�_2)
	//return:true(�Փ˂��Ă���)false(�Փ˂��Ă��Ȃ�)
	static bool Collision(CCollider *m, CCollider * o);

	//�R���C�_�^�C�v
	enum EType{
		ESPHERE,//���R���C�_
		ETRIANGlE,//�O�p�R���C�_
		ELINE,//�����R���C�_
	};
	EType mType;//�R���C�_�^�C�v
	//���_
	CVector mV[3];
	//�f�t�H���g�R���X�g���N�^
	CCollider();

	//CollisionTriangleLine(�O�p�R���C�_�A�����R���C�_�A�����l)
	//return:true(�Փ˂��Ă���)false(�Փ˂��Ă��Ȃ�)
	//�����r:�Փ˂��Ȃ��ʒu�܂Ŗ߂��l
	static bool CollisionTriangleLine(CCollider *triangle, CCollider *line, CVector *adjust);

	//CollisionTriangleSphere(�O�p�R���C�_�C���R���C�_, �����l)
	//return:true(�Փ˂��Ă���)false(�Փ˂��Ă��Ȃ�)
	//�����l:�Փ˂��Ȃ��ʒu�܂Ŗ߂��l
	static bool CollisionTrianglesSphere(CCollider *triangle, CCollider *sphere, CVector *adjust);

	//�D��x�̕ύX
	void CCollider::ChangePriority()
	{
		//�����̍��W*�e�̕ϊ��s����|���ă��[���h���W�����߂�
		CVector pos = mPosition * *mpMatrix;
		//�x�N�g���̒������D��x
		mPriority = pos.Length();
		CCollisionManager::Get()->Remove(this); //��U�폜
		CCollisionManager::Get()->Add(this); //�ǉ�
	}

	enum ETag
	{
		EBODY,
		ESEARCH,
	};
	ETag mTag;
};
#endif