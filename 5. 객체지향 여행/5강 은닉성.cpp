#include <iostream>
using namespace std;

// ������ ���� : ���м�

// ��ü���� (OOP Object Oriented Programming)
// - ��Ӽ�
// - ���м� = ĸ��ȭ
// - ������

// ���м�(Data Hiding) = ĸ��ȭ(Encapsulation)
// ���� �Ǵ� ���� ����ϰ� ����ڴ�!
// ����� ���?
// - 1) ���� �����ϰ� �ǵ帮�� �ȵǴ� ���
// - 2) �ٸ� ��η� �����ϱ� ���ϴ� ���

// �ڵ���
// - �ڵ�
// - ���
// - ����
// - ��
// - ���� ���⼱

// �Ϲ� ������ ���忡�� ����ϴ� ��?
// - �ڵ� / ��� / ��
// ���� �Ǵ� �κ� (�ǵ帮�� ū�ϳ�)
// - ����, ���� ���⼱

// public (����?)	protected (��ȣ�޴�?)	private (������?)
// - public : �������׳� ����, ���� ����ϼ���~
// - protected : ���� �ڼյ����׸� ���
// - private : ���� ����Ұž�!! << class Car ���ο�����!!

// ��� ���� ������ : ���� �������� �θ���� ������ ��� ��������?
// �θ������ �������� ������ �� ���� �ڼյ����׵� �Ȱ��� ������� ������ ����
// - public : ������ ��� -> �θ���� ���� ���� �״��~ (public -> public, protected -> protected)
// - protected : ��ȣ�޴� ��� -> �� �ڼյ����׸� �����ٰž� (public -> protected, protected -> protected)
// - private : �������� ��� -> �������� �� ���� �ڼյ����״� �� �����ٰž�! (���� -> private)

class Car
{
public: // (���) ���� ������
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }

	void TurnKey()
	{
		// ...
		RunEngine();
	}

protected:
	void DisassembleCar() { } // ���� �����Ѵ�
	void RunEngine() { } // ������ ������Ų��
	void ConnectCircuit() { } // ���⼱�� �����Ų��

public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���� ���⼱
};

class SuperCar : private Car // ��� ���� ������
{
public:
	void PushRemoteController() 
	{
		RunEngine();
	}
};

class TestSuperCar : public SuperCar // public �� ���� private�� �⺻
{
public:
	void Test()
	{
		// DisassembleCar();
	}
};

// 'ĸ��ȭ'
// ������ �����Ϳ� �Լ��� �������� ������� ��
class Berserker
{
public:

	int GetHp() { return _hp; }

	// ��� : ü���� 50 ���Ϸ� �������� ����Ŀ ��� �ߵ� (������)
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

private:
	void SetBerserkerMode()
	{
		cout << "�ſ� ������!" << endl;
	}

	int _hp = 100;
};

int main()
{
	Berserker b;

	b.SetHp(20);

	return 0;
}