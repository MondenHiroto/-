#include "CEnemy.h"
#include "CTaskManager.h"

//�R���X�g���N�^
//CEnemy(���f��,�ʒu,��],�g�k)
CEnemy::CEnemy(CModel*model, CVector position,
	CVector rotation, CVector scale)
	:mCollider1(this, &mMatrix, CVector(0.0f, 0.0f, 15.0f), 3.8f)
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
}


//�X�V����
void CEnemy::Update(){
	//�s����X�V
	CTransform::Update();
	//�ʒu���ړ�
	mPosition = CVector(0.0f, -1.5f, 0.0f) * mMatrix;

		CBullet *bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();

		CBullet *bullet2 = new CBullet();
		bullet2->Set(0.1f, 1.5f);
		bullet2->mPosition = CVector(10.0f, 0.0f, 10.0f) * mMatrix;
		bullet2->mRotation = mRotation;
		bullet2->Update();
	
}

//�Փˏ���
//Collision(�R���C�_�P,�R���C�_�Q)
void CEnemy::Collision(CCollider *m, CCollider *o){
	//����̃R���C�_�^�C�v�̔���
	switch (o->mType)
	{
		break;
	case CCollider::ETRIANGlE: //�O�p�R���C�_�̎�
		CVector adjust; //�����l
		//�O�p�R���C�_�Ƌ��R���C�_�̏Փ˔���
		if (CCollider::CollisionTrianglesSphere(o, m, &adjust))
		{      //�Փ˂��Ȃ��ʒu�܂Ŗ߂�
			mPosition = mPosition + adjust;
			mRotation.mZ++;
		}
		break;
	}
}
	