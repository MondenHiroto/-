#ifndef CMATERIAl_H
#define CMATERIAL_H
#include "CTexture.h"
/*
マテリアルクラス
マテリアルのデータを扱う
*/
class CMaterial{
public:
	//マテリアル名
	char mName[64];
	//拡散光のRGBA
	float mDiffuse[4];
	//デフォルトコンストラクタ
	CMaterial();
	//マテリアルを有効にする
	void Enabled();

	//テクスチャ
	CTexture mTexture;
	//マテリアルを無効にする
	void Disabled();

	//マテリアルごとの頂点数
	int mVertexNum;
};
#endif