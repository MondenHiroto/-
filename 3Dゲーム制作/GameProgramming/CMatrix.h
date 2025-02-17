#ifndef CMATRIX_H
#define CMATRIX_H

/*
}gNXNX
4s4ñÌsñf[^ðµ¢Ü·
*/
class CMatrix{
public:
	//4~4Ìsñf[^ðÝè
	float mM[4][4];
	//\¦mFp
	//4~4ÌsñðæÊoÍ
	void Print();
	//ftHgRXgN^
	CMatrix();
	//PÊsñÌì¬
	CMatrix Identity();
	//gåk¬sñÌì¬
	//Scale({¦X, {¦Y, {¦Z)
	CMatrix Scale(float sx, float sy, float sz);
	//ñ]sñ(Y²)Ìì¬
	//RotateY(px)
	CMatrix RotateY(float degree);
	//ñ]sñ(Z²)Ìì¬
	//RotateZ(px)
	CMatrix RotateZ(float degree);
	//ñ]sñ(X²)Ìì¬
	//RotateX(px)
	CMatrix RotateX(float degree);
	//Ú®sñÌì¬
	//Translate(Ú®ÊX, Ú®ÊY, Ú®ÊZ)
	CMatrix Translate(float mx, float my, float mz);
	//*ZqÌI[o[[h
	//CMatrix * CMatrixÌZÊðÔ·
	CMatrix operator*(const CMatrix &m);

};
#endif