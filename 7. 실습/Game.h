#pragma once

// ���漱��
class Player;

// is - a
// has - a
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	// Player _player;		// ũ�Ⱑ ũ�� Game ũ�⵵ �þ, ��û�� ������, �ٸ� PT�� ������ �� ���� ��
	Player* _player;		// �ּҰ��� ����
};

