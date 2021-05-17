#ifndef CVECTOR_H
#define CVECTOR_H
#include "CMatrix.h"
/*
�x�N�g���N���X
�x�N�g���f�[�^�������܂�
*/
class CVector {
	
public:
	//3D�e���ł̒l��ݒ�
	float mX, mY, mZ;
	//�e���ł̒l�̐ݒ�
	//Set(X���W, Y���W, Z���W)
	void Set(float x, float y, float z);

	//�f�t�H���g�R���X�g���N�^
	CVector();
	//�R���X�g���N�^
	//CVector(X���W,Y���W,Z���W)
	CVector(float x, float y, float z);

	CVector CVector::operator*(const CMatrix &m)
	{
		//�|���Z�̌��ʂ�CVector�^�̒l�ŕԂ�
		return CVector{
		mX * m.mM[0][0] + mY * m.mM[1][0] + mZ * m.mM[2][0] + m.mM[3][0],
		mX * m.mM[0][1] + mY * m.mM[1][1] + mZ * m.mM[2][1] + m.mM[3][1],
		mX * m.mM[0][2] + mY * m.mM[1][2] + mZ * m.mM[2][2] + m.mM[3][2]
	};
	}

	//-���Z�q�̃I�[�o�[���[�h
	//CVector - CVector�@�̉��Z���ʂ�Ԃ�
	CVector operator-(const CVector&v);
	//�x�N�g���̒�����Ԃ�
	float Length();

	//����
	//Dot(�x�N�g��)
	float Dot(const CVector &v);

	//�O��
	//Cross(�x�N�g��)
	CVector Cross(const CVector &v);
	//*���Z�q�̃I�[�o�[���[�h
	//CVector * float�@�̉��Z���ʂ�Ԃ�
	CVector operator*(const float &f);

	//���K��
	//�傫��1�̃x�N�g����Ԃ�
	CVector Normalize();

	//+���Z�q�̃I�[�o�[���[�h
	//CVector + CVector�@�̉��Z���ʂ�Ԃ�
	CVector operator+(const CVector &v);
};

#endif