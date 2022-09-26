#include <iostream>

using namespace std;

// Ctrl + k + c (comment)
// Ctrl + k + u (uncomment)

// 변수 선언 방법
// [타입] [이름];
// [타입] [이름] = [초기값];

// 0이 아닌 초기화 값이 있으면 .data영역
int hp = 100;

// 초기값이 0이거나, 초기값이 없는 변수라면 .bss 영역
char a;     // 1바이트 (-128 ~ 127)
short b;    // 2바이트 (-32768 ~ 32767)
int c;      // 4바이트 (-21억 ~ 21억)
_int64 d;   // 8바이트 (long long) (어마어마하게 크다)

unsigned char e;     // 1바이트 (0 ~ 256)
unsigned short f;    // 2바이트 (0 ~ 65536)
unsigned int g;      // 4바이트 (0 ~ 42.9억)
unsigned _int64 h;   // 8바이트 (long long) (어마어마하게 크다)

// 참고) 이론적으로 양수만 존재할 수 있는 데이터 unsigned
// 무조건 unsigned를 사용할지 의견이 갈림
// - 레벨이 음수라는 것은 말이 안된다 -> 그럼 차라리 그 자리에서 프로그램을 크래시 내서 버그를 빨리 찾는게 낫다
// - unsigned / signed 사이의 변환

// 귀찮은데 그냥 대충 4바이트로 가면 안될까?
// -> 콘솔/모바일 게임 -> 메모리가 늘 부족하다
// -> 온라인 게임 -> 4바이트 * 1만명

int main()
{
    // 정수 오버플로우
    b = 32767;
    b = b + 1;
    cout << b << endl;  // -32768 출력

    // 정수 언더플로우
    f = 0;
    f = f - 1;
    cout << f << endl;  // 65355 출력

    cout << "Hello World!\n";
}

