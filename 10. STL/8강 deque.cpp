#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>

// ������ ���� : deque

// vector : ���� �迭
// [         ]

// list : ���� ���� ����Ʈ
// [ ] <-> [ ] <-> [ ] <-> [ ] <->

// deque : double-ended queue ��ũ
// [     ]
// [     ]
// [     ]

int main()
{
	// ������ �����̳� (Sequence Container)
	// �����Ͱ� ���� ������� �����Ǵ� ����
	// vector, list, deque(��ũ) -> dequeue�� �ٸ� ��!!!

	// deque<int> dq;

	// dq.push_back(1);
	// dq.capacity(); // �ʿ��� ������ ���� ���� ���� capacity �ʿ� X
	// dq.push_front(2);
	// cout << dq[0] << endl;

	// vector�� ���������� �迭 ������� ����
	// �ٸ� �޸� �Ҵ� ��å�� �ٸ���

	// vector
	// [        ] ������ 50% �ø� ���ο� ���� ����
	// [               ] ���ο� ������ ���� ������ �����ϰ� ���� �迭 ����

	// deque
	// [    3 3] push_front���� ��
	// [1 1 1 2] �� ó�� ��
	// [2      ] ������ ���� �ϳ� �� �߰�

	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);

	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	// - deque�� ���� ����
	// - �߰� ����/���� (BAD / BAD) -> �߰��� �����ϸ� �ڿ� �� ��ĭ�� ��ܾ���
	// - ó��/�� ����/���� (GOOD / GOOD) -> �� �߰� ������ ������
	// - ���� ���� (GOOD)

	dq[3] = 10;
	cout << dq[3] << endl;

	deque<int>::iterator it;

	// * ���� ���
	// _Size_type _Block = _Mycont->_Getblock(_Myoff);	// � ��� �Ҽ�����
	// _Size_type _Off = _Myoff % _Block_size;			// �׽�Ʈ������ _Block_size�� 4����
	// return _Mycont->_Map[_Block][_Off];				// �� ��° ����� �� ��° �������̱�
	// ���� ���� ȣ�� �������� �������� ��ȣ���� �Ű����� ����
	// -> ���� �����Ͱ� �߰��� �� ���� ������ �ȵ�!! -> �׷��� �߰� ����/������ ��Ʊ�

	return 0;
}