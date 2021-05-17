#ifndef CBILLBOARD_H
#define CBILLBOARD_H
#include "CCharacter.h"
/*
�r���{�[�h�N���X
��ɃJ�����̂ق��������l�p�`
*/
class CBillBoard : public CCharacter{
public:
	//�O�p�`2��
	CTriangle mT[2];
	//�}�e���A��
	CMaterial mMaterial;
	//�R���X�g���N�^
	CBillBoard();
	//CBillBoard(�ʒu,��,����) 
	CBillBoard(CVector pos, float w, float h);
	//Set(�ʒu�A���A����)
	void Set(CVector pos, float w, float h);
	//�X�V
	void Update();
	//�`��
	void Render();
	void Render(CMaterial *mpMaterial);
};
#endif