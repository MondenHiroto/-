#include "CItem.h"
#include "CTaskManager.h"
#define VELOCITY 0.11f
#include "CPlayer.h"

//�R���X�g���N�^
//CEnemy(���f��,�ʒu,��],�g�k)
CItem::CItem(CModel*model, CVector position,
	CVector rotation, CVector scale)
	: mCollider1(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 4.5f)
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
	mTag = EITEM;
}


//�X�V����
void CItem::Update(){
	//�s����X�V
	CTransform::Update();
	//�ʒu���ړ�
	mPosition = CVector(0.0f, 0.0f, 0.1f) * mMatrix;

}

//�Փˏ���
//Collision(�R���C�_�P,�R���C�_�Q)
void CItem::Collision(CCollider *m, CCollider *o){
	switch (m->mTag)
	{
	case CCollider::EBODY:
		//����̃R���C�_�^�C�v�̔���
		switch (o->mType)
		{
		case CCollider::ESPHERE:
				if (o->mTag == CCollider::EBODY){
					if (o->mpParent->mTag == EPLAYER){
						if (CCollider::Collision(o,m)){
							mEnabled = false;
							CPlayer::spInstance->ItemGet++;
						}
					}
				}
			break;
		case CCollider::ETRIANGlE: //�O�p�R���C�_�̎�
			CVector adjust; //�����l
			//�O�p�R���C�_�Ƌ��R���C�_�̏Փ˔���
			if (CCollider::CollisionTrianglesSphere(o, m, &adjust))
			{      //�Փ˂��Ȃ��ʒu�܂Ŗ߂�
				mPosition = mPosition + adjust;
				mRotation.mY++;
			}
			break;
		}
	break;
	}
}