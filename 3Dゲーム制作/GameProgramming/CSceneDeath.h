#ifndef CSCENEDEATH_H
#define CSCENEDEATH_H
#include "CScene.h"
#include "CText.h"

class CSceneDeath : public CScene{
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