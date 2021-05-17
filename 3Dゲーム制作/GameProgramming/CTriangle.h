#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "CVector.h"
/*
�O�p�`�N���X
*/
class CTriangle {
public:
	CVector mV[3]; //���_���W
	CVector mN[3]; //�@��
	//���_���W�ݒ�
	//SetVertex(���_1,���_2,���_3)
	void SetVertex(const CVector &v0, const CVector &v1, const CVector &v2);
	void SetNormal(const CVector &v0, const CVector &v1, const CVector &v2);
		//�@���ݒ�
		//SetNormal(�@���x�N�g��)
		void SetNormal(const CVector &n);
		//�`��
		void Render();
		int mMaterialIdx; //�}�e���A���ԍ�

		CVector mUv[3]; //�e�N�X�`���}�b�s���O

		//�`��
		//Render(�s��)
		void Render(const CMatrix &m);
};
#endif