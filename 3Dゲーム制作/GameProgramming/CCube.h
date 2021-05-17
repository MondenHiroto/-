#ifndef CCUBE_H
#define CCUBE_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
#include "CColliderMesh.h"

/*
�G�l�~�[�N���X
�L�����N�^�N���X���p��
*/
class CCube : public CCharacter{
public:
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle> mTriangles;
	//�R���X�g���N�^
	//CEnemy(���f��,�ʒu,��],�g�k)
	CCube(CModel*model, CVector position, CVector rotation, CVector scale);
	//�X�V����
	void Update();

	CColliderMesh ColliderMesh;
};

#endif