#pragma once

// 전방선언
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
	// Player _player;		// 크기가 크면 Game 크기도 늘어남, 엄청난 의존성, 다른 PT를 저장할 수 없게 됨
	Player* _player;		// 주소값만 저장
};

