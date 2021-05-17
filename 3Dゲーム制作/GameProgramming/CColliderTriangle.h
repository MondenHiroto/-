#ifndef CCOLLIDERTRIANGLE_H
#define CCOLLIDERTRIANGLE_H
#include "CCollider.h"
/*
�O�p�`�R���C�_�̒�`
*/
class CColliderTriangle : public CCollider
{
public:
	CColliderTriangle(){}
	//�R���X�g���N�^(�O�p�R���C�_)
	//CColliderTriangle(�e�A�e�s��A���_1�A���_2�A���_�R)
	CColliderTriangle(CCharacter *parent, CMatrix * matrix
		, const CVector &v0, const CVector &v1, const CVector &v2);
	//�O�p�R���C�_�̐ݒ�
	//Set(�e�A�e�s��A���_1�A���_�Q�A���_�R)
	void Set(CCharacter *parent, CMatrix *matrix
		, const CVector &v0, const CVector &v1, const CVector &v2);
	//�`��
	void Render();

	//�D��x�̕ύX
	void CColliderTriangle::ChangePriority()
	{
		//mV[0]��mV[1]��mV[2]�̒��S�����߂�
		CVector pos = (mV[0] * *mpMatrix + mV[1] * *mpMatrix
			+ mV[2] * *mpMatrix) * (1.0f / 3.0f);
		//�x�N�g���̒������D��x
		mPriority = pos.Length();
		CCollisionManager::Get()->Remove(this); //��U�폜
		CCollisionManager::Get()->Add(this); //�ǉ�
	}
};
#endif