#include "CText.h"

/*
DrawChar
������`�悷��
ch:�����f�[�^ x:X���W y:Y���W w:�� h:����
*/
void CText::DrawChar(char ch, int x, int y, int w, int h) {
	int u = (ch - ' ') % mFont.mCol * mFont.mHeader.width / mFont.mCol;
	int v = (ch - ' ') / mFont.mCol * mFont.mHeader.height / mFont.mRow;
	mFont.DrawImage(x - w, x + w, y - h, y + h,
		u, u + mFont.mHeader.width / mFont.mCol,
		v + mFont.mHeader.height / mFont.mRow, v);
}
// s:������f�[�^ x:�擪����X���W y:�擪����Y���W
void CText::DrawString(const char *s, int x, int y, int w, int h) {
	//1�������`�悵�܂�
	for (int i = 0; s[i] != '\0'; i++) {
		//������`�悷��
		DrawChar(s[i], x, y, w, h);
		//�E�ֈړ�
		x += w * 2;
	}
}
//�e�N�X�`���̃��[�h
//LoadTexture(�e�N�X�`���t�@�C����, �s��, ��)
void CText::LoadTexture(const char *tga, int row, int col)
{
	mFont.Load(tga);
	mFont.SetRowCol(row, col);
}
