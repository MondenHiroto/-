#ifndef CMATERIAl_H
#define CMATERIAL_H
#include "CTexture.h"
/*
�}�e���A���N���X
�}�e���A���̃f�[�^������
*/
class CMaterial{
public:
	//�}�e���A����
	char mName[64];
	//�g�U����RGBA
	float mDiffuse[4];
	//�f�t�H���g�R���X�g���N�^
	CMaterial();
	//�}�e���A����L���ɂ���
	void Enabled();

	//�e�N�X�`��
	CTexture mTexture;
	//�}�e���A���𖳌��ɂ���
	void Disabled();

	//�}�e���A�����Ƃ̒��_��
	int mVertexNum;
};
#endif