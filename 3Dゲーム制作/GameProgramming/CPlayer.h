#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
#include "CBullet.h"
#include "CColliderLine.h"
#include "CText.h"
#include "CCollider.h"
/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/
class CPlayer : public CCharacter{
public:
	//�X�V����
	void Update();

	CColliderLine mLine; //�����R���C�_
	CColliderLine mLine2;
	CColliderLine mLine3;
	CCollider mCollider1;
	CPlayer();

	//�Փˏ���
	void Collision(CCollider *m, CCollider * o);

	CText mText;
	//�`�揈��
	void Render(); 

	int Stamina;

	int Time = 301 * 60;
};

#endif