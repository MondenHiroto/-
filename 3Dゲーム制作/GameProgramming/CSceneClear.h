#ifndef CSCENECLEAR_H
#define CSCENECLEAR_H
#include "CScene.h"
#include "CText.h"

class CSceneClear : public CScene{
public:
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	void Render();
	//���̃V�[���̎擾
	EScene GetNextScene();
	CText mText;
};
#endif