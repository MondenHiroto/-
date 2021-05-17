#ifndef CCOLLIDERLINE_H
#define CCOLLIDERLINE_H
#include "CCollider.h"
/*
�����R���C�_�̒�`
*/
class CColliderLine : public CCollider
{
public:
	CColliderLine(){}
	//�R���X�g���N�^(�����R���C�_)
	//CColliderLine(�e�A�e�s��A���_�P�A���_�Q)
	CColliderLine(CCharacter *parent, CMatrix *matrix, const CVector &v0, const CVector &v1);
	//�����R���C�_�̐ݒ�
	//Set(�e�A�e�s��A���_�P�A���_�Q)
	void Set(CCharacter  *parent, CMatrix *matrix, const CVector &v0, const CVector &v1);
	//�`��
	void Render();

	//�D��x�̕ύX
	void CColliderLine::ChangePriority()
	{
		//mV[0]��mV[1]�̒��S�����߂�
		CVector pos = (mV[0] * *mpMatrix + mV[1] * *mpMatrix)*(0.5f);
		//�x�N�g���̒������D��x
		mPriority = pos.Length();
		CCollisionManager::Get()->Remove(this); //��U�폜
		CCollisionManager::Get()->Add(this); //�ǉ�
	}
};
#endif