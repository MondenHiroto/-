#ifndef CMODEL_H
#define CMODEL_H
//vector�̃C���N���[�h
#include <vector>
#include "CTriangle.h"
#include "CMaterial.h"
/*
���f���N���X
���f���f�[�^�̓��͂�\��
*/
class CModel {
public:
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle> mTriangles;
	//���f���t�@�C���̓���
	//Load(���f���t�@�C����,�}�e���A���t�@�C����)
	void Load(char *obj, char *mtl);

	//�`��
	void Render();

	//�}�e���A���|�C���^�̉ϒ��z��
	std::vector<CMaterial*>mpMaterials;

	~CModel();

	//�`��
	//Render(�s��)
	void Render(const CMatrix &m);

	//���_�z��
	float *mpVertex; //���_���W
	float *mpNormal; //�@��
	float *mpTextureCoord; //�e�N�X�`���}�b�s���O
	//�f�t�H���g�R���X�g���N�^
	CModel();
};

#endif