#pragma once

#include "Vec2.h"

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int handle) { m_handle = handle; }

	// �G�̏�����
	void init();

	// ����
	void update();
	// �`��
	void draw();

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

private:
	int m_handle;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
};