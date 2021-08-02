#ifndef CITEM_H
#define CEITEM_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
#include "CCollider.h"
#include "CEffect.h"

/*
�A�C�e���N���X
�L�����N�^�N���X���p��
*/
class CItem : public CCharacter{
public:
	//�R���X�g���N�^
	//CItem(���f��,�ʒu,��],�g�k)
	CItem(CModel*model, CVector position, CVector rotation, CVector scale);
	//�X�V����
	void Update();

	//�R���C�_
	CCollider mCollider1;

	//�Փˏ���
	//Collision(�R���C�_�P,�R���C�_�Q)
	void Collision(CCollider *m, CCollider *o);

	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�

};

#endif