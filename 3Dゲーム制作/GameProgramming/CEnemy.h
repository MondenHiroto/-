#ifndef CENEMY_H
#define CENEMY_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
#include "CCollider.h"
#include "CEffect.h"
#include "CBullet.h"
/*
�G�l�~�[�N���X
�L�����N�^�N���X���p��
*/
class CEnemy : public CCharacter{
public:
	//�R���X�g���N�^
	//CEnemy(���f��,�ʒu,��],�g�k)
	CEnemy(CModel*model, CVector position, CVector rotation, CVector scale);
	//�X�V����
	void Update();

	//�R���C�_
	CCollider mCollider1;
	
	//�Փˏ���
	//Collision(�R���C�_�P,�R���C�_�Q)
	void Collision(CCollider *m, CCollider *o);

	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
	int mFireCount;

	//���G�p�R���C�_
	CCollider mColliderSearch;

	CVector mPoint;

	CCharacter *mpPlayer;
};

#endif