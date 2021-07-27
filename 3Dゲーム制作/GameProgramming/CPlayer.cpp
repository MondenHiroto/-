//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"
//�L�[���̓N���X�̃C���N���[�h
#include "CKey.h"
#include "CTaskManager.h"
#include "CUtil.h"

CPlayer::CPlayer()
: mLine(this, &mMatrix, CVector(0.0f, 0.0f, -14.0f), CVector(0.0f, 0.0f, 17.0f))
, mLine2(this, &mMatrix, CVector(0.0f, 5.0f, -8.0f), CVector(0.0f, -3.0f, -8.0f))
, mLine3(this, &mMatrix, CVector(9.0f, 0.0f, -8.0f), CVector(-9.0f, 0.0f, -8.0f))
, Stamina(300)
, mCollider1(this, &mMatrix, CVector(0.0f, 0.0f, 15.0f), 3.8f)
{//�e�N�X�t�@�C�̓ǂݍ���(1�s64��)
	mText.LoadTexture("FontWhite.tga", 1, 64);
	mTag = EPLAYER;
}

//�X�V����
void CPlayer::Update(){
	if (Time > 0){
		Time--;
	}

	if (Stamina < 300 && !CKey::Push('W')){
		Stamina++;
	}
	//A�L�[���͂ŉ�]
	if (CKey::Push('A')){
		//Y���̉�]�l�𑝉�
		mRotation.mY += 3;
	}
	if (CKey::Push('D')){
		mRotation.mY += -3; 
	}
	//�E���L�[���͂ŉE�ړ�
	if (CKey::Push(VK_RIGHT)){
		mPosition = CVector(-3.5f, 0.0f, 0.0f) * mMatrix;
	}
	//�����L�[���͂ō��ړ�
	if (CKey::Push(VK_LEFT)){
		mPosition = CVector(3.5f, 0.0f, 0.0f) *mMatrix;
	}
	//����L�[���͂őO�i
	if (CKey::Push(VK_UP)){
		//Z��������1�i�񂾒l����]�ړ�������
		mPosition = CVector(0.0f, 0.0f, 3.5f) * mMatrix;
	}

	//����L�[�ƉE���L�[�������͂ŉE�΂ߑO�i
	if (CKey::Push(VK_UP) && CKey::Push(VK_RIGHT)){
		//Z��������1�i�񂾒l����]�ړ�������
		mPosition = CVector(-3.5f, 0.0f, 3.5f) * mMatrix;
	}

	//����L�[�ƍ����L�[�������͂ŉE�΂ߑO�i
	if (CKey::Push(VK_UP) && CKey::Push(VK_LEFT)){
		//Z��������1�i�񂾒l����]�ړ�������
		mPosition = CVector(3.5f, 0.0f, 3.5f) * mMatrix;
	}

	//�����L�[���͂Ō��
	if (CKey::Push(VK_DOWN)){
		mPosition = CVector(0.0f, 0.0f, -3.5f) * mMatrix;
	}

	//�����L�[�ƉE���L�[�������͂ŉE�΂ߌ��
	if (CKey::Push(VK_DOWN) && CKey::Push(VK_RIGHT)){
		//Z��������1�i�񂾒l����]�ړ�������
		mPosition = CVector(-3.5f, 0.0f, -3.5f) * mMatrix;
	}

	//�����L�[�ƍ����L�[�������͂ō��΂ߌ��
	if (CKey::Push(VK_DOWN) && CKey::Push(VK_LEFT)){
		//Z��������1�i�񂾒l����]�ړ�������
		mPosition = CVector(3.5f, 0.0f, -3.5f) * mMatrix;
	}

	//�_�b�V��
	if (Stamina > 0 && CKey::Push('W')){
		Stamina--;
		mPosition = CVector(0.0f, 0.0f, 7.0f) * mMatrix;
	}
	//�X�^�~�i��0�ɂȂ����Ƃ�
	if (Stamina == 0 && CKey::Push('W')){
		mPosition = CVector(0.0f, 0.0f, 3.5f) * mMatrix;
	}
	//CCharacter�̍X�V
	CTransform::Update();

}


void CPlayer::Collision(CCollider *m, CCollider *o){
	//���g�̃R���C�_�^�C�v�̔���
	switch (m->mType){
	case CCollider::ELINE://�����R���C�_
		//����̃R���C�_���O�p�R���C�_�̎�
		if (o->mType == CCollider::ETRIANGlE){
			CVector adjust;//�����p�x�N�g��
			//�O�p�`�Ɛ����̏Փ˔���
			CCollider::CollisionTriangleLine(o, m, &adjust);
			//�ʒu�̍X�V(mPosition + adjust)
			mPosition = mPosition - adjust * -1;
			//�s��̍X�V
			CTransform::Update();
		}
		break;
	}

}

void CPlayer::Render()
{
	//�e�̕`�揈��
	CCharacter::Render();

	//2D�̕`��J�n
	CUtil::Start2D(-400, 400, -300, 300);
	//�`��F�̐ݒ�(�ΐF�̔�����)
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	//������ҏW�G���A�̍쐬
	char buf[64];

	//Y���W�̕\��
	//������̐ݒ�
	sprintf(buf, "TIME:%d",Time / 60);
	//������̕`��
	mText.DrawString(buf, 200, 270, 8, 16);

	//Y���W�̕\��
	//������̐ݒ�
	sprintf(buf, "STAMINA:%d", Stamina);
	//������̕`��
	mText.DrawString(buf, 0, 270, 8, 16);

	//2D�̕`��I��
	CUtil::End2D();
}