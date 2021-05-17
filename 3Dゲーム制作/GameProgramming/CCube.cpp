#include "CCube.h"
#include "CTaskManager.h"

//�R���X�g���N�^
//CEnemy(���f��,�ʒu,��],�g�k)
CCube::CCube(CModel*model, CVector position,
	CVector rotation, CVector scale)
{
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model; //���f���̐ݒ�
	mPosition = position; //�ʒu�̐ݒ�
	mRotation = rotation; //��]�̐ݒ�
	mScale = scale; //�g�k�̐ݒ�
	//�D��x��1�ɕύX����
	mPriority = 1;
	CTaskManager::Get()->Remove(this); //�폜����
	CTaskManager::Get()->Add(this); //�ǉ�����
	ColliderMesh.Set(this, &mMatrix, mpModel);
}


//�X�V����
void CCube::Update(){
	//�s����X�V
	CTransform::Update();
}

