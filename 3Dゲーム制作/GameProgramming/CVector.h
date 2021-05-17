#ifndef CVECTOR_H
#define CVECTOR_H
#include "CMatrix.h"
/*
ベクトルクラス
ベクトルデータを扱います
*/
class CVector {
	
public:
	//3D各軸での値を設定
	float mX, mY, mZ;
	//各軸での値の設定
	//Set(X座標, Y座標, Z座標)
	void Set(float x, float y, float z);

	//デフォルトコンストラクタ
	CVector();
	//コンストラクタ
	//CVector(X座標,Y座標,Z座標)
	CVector(float x, float y, float z);

	CVector CVector::operator*(const CMatrix &m)
	{
		//掛け算の結果をCVector型の値で返す
		return CVector{
		mX * m.mM[0][0] + mY * m.mM[1][0] + mZ * m.mM[2][0] + m.mM[3][0],
		mX * m.mM[0][1] + mY * m.mM[1][1] + mZ * m.mM[2][1] + m.mM[3][1],
		mX * m.mM[0][2] + mY * m.mM[1][2] + mZ * m.mM[2][2] + m.mM[3][2]
	};
	}

	//-演算子のオーバーロード
	//CVector - CVector　の演算結果を返す
	CVector operator-(const CVector&v);
	//ベクトルの長さを返す
	float Length();

	//内積
	//Dot(ベクトル)
	float Dot(const CVector &v);

	//外積
	//Cross(ベクトル)
	CVector Cross(const CVector &v);
	//*演算子のオーバーロード
	//CVector * float　の演算結果を返す
	CVector operator*(const float &f);

	//正規化
	//大きさ1のベクトルを返す
	CVector Normalize();

	//+演算子のオーバーロード
	//CVector + CVector　の演算結果を返す
	CVector operator+(const CVector &v);
};

#endif