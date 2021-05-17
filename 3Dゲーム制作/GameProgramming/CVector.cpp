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


//-演算子のオーバーロード
//CVector - CVector　の演算結果を返す
CVector CVector::operator-(const CVector&v){
	return CVector(mX - v.mX, mY - v.mY, mZ - v.mZ);
}
//ベクトルの長さを返す
float CVector::Length(){
	//sqrt関数で平方根を返す
	return sqrtf(mX * mX + mY * mY + mZ * mZ);
}

//内積
float CVector::Dot(const CVector &v){
	return mX*v.mX + mY*v.mY + mZ*v.mZ;
}

CVector CVector::Normalize(){
	//ベクトルの大きさで割ったベクトルを返す(長さ１のベクトル)
	return *this *(1.0f / Length());
}

CVector CVector::operator*(const float&f){
	return CVector(mX * f,mY * f,mZ * f);
}

//外積
CVector CVector::Cross(const CVector&v){
	return CVector(mY * v.mZ - mZ * v.mY, mZ * v.mX - mX * v.mZ, mX * v.mY - mY *v.mX);
}

CVector CVector::operator+(const CVector&v){
	return CVector(mX + v.mX, mY + v.mY, mZ + v.mZ);
}
