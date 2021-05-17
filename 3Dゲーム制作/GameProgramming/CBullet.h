#ifndef CBULLET_H
#define CBULLET_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//�O�p�`�N���X�̃C���N���[�h
#include "CTriangle.h"
#include "CCollider.h"

/*
�e�N���X
�O�p�`���΂�
*/
class CBullet : public CCharacter{
public:
	CBullet();
	//�O�p�`
	CTriangle mT;
	//���Ɖ��s���̐ݒ�
	//Set(���A���s��)
	void Set(float w, float d);
	//�X�V
	void Update();
	//�R���C�_
    CCollider mCollider;

	void CBullet::Render();
	
	//��������
	int mLife;
	int mFx, mFy;	//�ړ���
	//�Փˏ���
	//Collision(�R���C�_�P,�R���C�_�Q )

};
#endif