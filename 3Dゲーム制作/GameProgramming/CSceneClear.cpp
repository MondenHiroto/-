#include "CSceneClear.h"
#include "CKey.h"


void CSceneClear::Init() {
	//�e�N�X�`���t�@�C����ǂݍ���
	//�t�H���g�̐ݒ�
	mText.LoadTexture("FontWhite.tga", 1, 64);
	//�V�[���̐ݒ�
	mScene = ECLEAR;
}

//�X�V�����̃I�[�o�[���C�h
void CSceneClear::Update() {
	//������̕`��
	if (CKey::Once(VK_RETURN)) {
		//���̃V�[���̓Q�[��
		mScene = EGAME;
	}

}

void CSceneClear::Render(){
	mText.DrawString("GAMECLEAR", -200, 0, 50, 50);
	mText.DrawString("Push ENTER Key", -200, -100, 16, 16);
}

//���̃V�[���̎擾
CScene::EScene CSceneClear::GetNextScene() {
	return mScene;
}
