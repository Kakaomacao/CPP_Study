#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"

// [Bug Report #8]
// 펫을 궁수의 생성자에서 만드는 것이
// 깔끔하지 않다는 사장님의 지적에 따라
// 일단 밖으로 빼서 펫을 생성하게 수정했습니다.

// 그런데 막상 밖으로 빼니 또 크래시가 납니다.
// 가만히 있으면 중간은 간다던데...
// 뭐가 문제일까요?

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	while (true)
	{
		// 나중엔 궁수, 법사 등 추가 예정
		Player* p = nullptr;

		switch (rand() % 3)
		{
			case 0:
			{
				p = new Knight();
				p->_hp = 100;
				p->_attack = 100;
				break;
			}	
			case 1:
			{
				// 여기서 같이 만들어준다
				// 이런 저런 펫 정보 추가될 예정
				// Pet pet; 
				// 자동으로 알아서 소멸되고 생성되는데 직접적으로 Archer에 넘겨서 문제 발생
				// 즉 new로 만든게 아닌 애를 Archer의 소멸자에서 지워주려고 했기 때문에 문제가 발생했군!
				Pet* pet = new Pet();

				// Archer를 만들 때 pet 정보도 넘겨준다
				p = new Archer(pet);
				p->_hp = 100;
				p->_attack = 100;

				break;
			}		
			case 2:
			{
				p = new Mage();
				p->_hp = 100;
				p->_attack = 100;
				break;
			}			
		}

		// Archer를 삭제하면서 이상해졌군!!
		// 유효하지 않은 메모리를 지우려고 했군!!
		delete p;
	}

}
