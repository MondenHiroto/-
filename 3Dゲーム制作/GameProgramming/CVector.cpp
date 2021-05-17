#include "CVector.h"
#include <math.h>


CVector::CVector()
: mX(0.0f)
, mY(0.0f)
, mZ(0.0f)
{}

CVector::CVector(float x, float y, float z)
: mX(x)
, mY(y)
, mZ(z)
{}

void CVector::Set(float x, float y, float z){
	mX = x;
    mY = y;
	mZ = z;
}


//-���Z�q�̃I�[�o�[���[�h
//CVector - CVector�@�̉��Z���ʂ�Ԃ�
CVector CVector::operator-(const CVector&v){
	return CVector(mX - v.mX, mY - v.mY, mZ - v.mZ);
}
//�x�N�g���̒�����Ԃ�
float CVector::Length(){
	//sqrt�֐��ŕ�������Ԃ�
	return sqrtf(mX * mX + mY * mY + mZ * mZ);
}

//����
float CVector::Dot(const CVector &v){
	return mX*v.mX + mY*v.mY + mZ*v.mZ;
}

CVector CVector::Normalize(){
	//�x�N�g���̑傫���Ŋ������x�N�g����Ԃ�(�����P�̃x�N�g��)
	return *this *(1.0f / Length());
}

CVector CVector::operator*(const float&f){
	return CVector(mX * f,mY * f,mZ * f);
}

//�O��
CVector CVector::Cross(const CVector&v){
	return CVector(mY * v.mZ - mZ * v.mY, mZ * v.mX - mX * v.mZ, mX * v.mY - mY *v.mX);
}

CVector CVector::operator+(const CVector&v){
	return CVector(mX + v.mX, mY + v.mY, mZ + v.mZ);
}
