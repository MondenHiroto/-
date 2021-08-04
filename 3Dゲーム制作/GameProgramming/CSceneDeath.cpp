#include "CSceneDeath.h"
#include "CKey.h"
#include "CUtil.h"

void CSceneDeath::Init() {
	//�e�N�X�`���t�@�C����ǂݍ���
	//�t�H���g�̐ݒ�
	mText.LoadTexture("FontWhite.tga", 1, 64);
	//�V�[���̐ݒ�
	mScene = EDEATH;
}

//�X�V�����̃I�[�o�[���C�h
void CSceneDeath::Update() {
	//������̕`��
	if (CKey::Once(VK_RETURN)) {
		//���̃V�[���̓Q�[��
		mScene = EGAME;
	}
	Render();
}

void CSceneDeath::Render(){

	CUtil::Start2D(-400, 400, -300, 300);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	mText.DrawString("GAMEOVER", -200, 200, 50, 50);
	mText.DrawString("PUSH ENTER KEY", -2000, 200, 16, 16);
	CUtil::End2D();
}

//���̃V�[���̎擾
CScene::EScene CSceneDeath::GetNextScene() {
	return mScene;
}
