#include "CColliderTriangle.h"
#include "CCollisionManager.h"

CColliderTriangle::CColliderTriangle(CCharacter *parent, CMatrix *matrix
	, const CVector &v0, const CVector &v1, const CVector &v2)
{
	Set(parent, matrix, v0, v1, v2);
}

void CColliderTriangle::Set(CCharacter *parent, CMatrix *matrix
	, const CVector &v0, const CVector &v1, const CVector &v2){
	mType = ETRIANGlE;//三角コライダ
	mpParent = parent;//親設定
	if (matrix)
		mpMatrix = matrix;//親行列あれば設定
	//三角形頂点設定
	mV[0] = v0;
	mV[1] = v1;
	mV[2] = v2;
}
void CColliderTriangle::Render()
{
	//行列退避
	glPushMatrix(); 
	//行列適用
	glMultMatrixf(mpMatrix->mM[0]);

	//アルファブレンドを有効にする
	glEnable(GL_BLEND);
	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//ライトオフ
	glDisable(GL_LIGHTING);
	//DIFFUSE赤色設定
	float c[] = { 1.0f, 0.0f, 0.0f, 0.2f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	glColor4fv(c);

	//三角形描画
	glBegin(GL_TRIANGLES);
	glVertex3f(mV[0].mX, mV[0].mY, mV[0].mZ);
	glVertex3f(mV[1].mX, mV[1].mY, mV[1].mZ);
	glVertex3f(mV[2].mX, mV[2].mY, mV[2].mZ);
	glEnd();

	//ライトオン
	glEnable(GL_LIGHTING);
	//アルファブレンドを無効
	glDisable(GL_BLEND);
	//行列復帰
	glPopMatrix();
}