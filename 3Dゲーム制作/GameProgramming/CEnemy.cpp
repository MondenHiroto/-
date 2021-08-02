#include "CEnemy.h"
#include "CTaskManager.h"
#define VELOCITY 0.11f

//�R���X�g���N�^
//CEnemy(���f��,�ʒu,��],�g�k)
CEnemy::CEnemy(CModel*model, CVector position,
	CVector rotation, CVector scale)
	: mCollider1(this, &mMatrix, CVector(0.0f, 0.0f, 15.0f), 3.8f)
	, mColliderSearch(this, &mMatrix, CVector(0.0f, 0.0f,0.0f),15000.0f)
	, mpPlayer(nullptr)
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
	mColliderSearch.mTag = CCollider::ESEARCH;
	mPoint = mPosition + CVector(0.0f, 0.0f, 100.0f) * mMatrixRotate;
}


//�X�V����
void CEnemy::Update(){
	//�s����X�V
	CTransform::Update();
	//�ʒu���ړ�
	mPosition = CVector(0.0f, 0.0f, 1.5f) * mMatrix;

		/*CBullet *bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();

		CBullet *bullet2 = new CBullet();
		bullet2->Set(0.1f, 1.5f);
		bullet2->mPosition = CVector(10.0f, 0.0f, 10.0f) * mMatrix;
		bullet2->mRotation = mRotation;
		bullet2->Update();
	*/
	CVector vx = CVector(1.0f, 0.0f, 0.0f)* mMatrixRotate;
	CVector vy = CVector(0.0f, 1.0f, 0.0f) *mMatrixRotate;
	CVector vz = CVector(0.0f, 0.0f, 1.0f) * mMatrixRotate;
	CVector vp = mPoint - mPosition;
	float dx = vp.Dot(vx);
	float dy = vp.Dot(vy);
	float margin = 0.1f;
	if (dx > margin)
	{
		mRotation.mY += 10.0f;
	}
	else if (dx < -margin)
	{
		mRotation.mY -= 10.0f;
	}
	if (dy > margin)
	{
		mRotation.mX -= 10.0f;
	}
	else if (dy < -margin)
	{
		mRotation.mX += 10.0f;
	}

	mPosition = mPosition + CVector(0.0f, 0.0f, VELOCITY) * mMatrixRotate;
	CTransform::Update();

	int r = rand() % 180;

}

//�Փˏ���
//Collision(�R���C�_�P,�R���C�_�Q)
void CEnemy::Collision(CCollider *m, CCollider *o){
	switch (m->mTag)
	{
	case CCollider::EBODY:
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
				mRotation.mY++;
			}
			break;
		}
		break;
	case CCollider::ESEARCH:
		if (o->mType == CCollider::ESPHERE){
			if (o->mpParent->mTag == EPLAYER){
				if (CCollider::Collision(m, o)){
					mpPlayer = o->mpParent;
					mPoint = mpPlayer->mPosition;
				}
			}
		}
		break;
	}
}