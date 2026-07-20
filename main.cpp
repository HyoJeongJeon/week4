#include "preciseTime.h"
#include <memory>
#include <vector>

int main()
{
    using namespace Jeonhyojeong2593270;

    preciseTime p{2,16,17}; p.print();
    std::cout << "-silicing problem\n";
    timeOfDay t{p}; t.print(); std::cout << '\n';

    std::cout << "-silicing problems defeated (pointer)\n";
    preciseTime* pp{&p}; pp->print();
    timeOfDay* pt(pp); pt->print();

    std::cout << "-silicing problems defeated {dynamic}\n";
    timeOfDay* pd{new preciseTime(2,26,39)}; pd->print();
    delete pd;

    std::cout << "silicing problems defeated {smart pointer}\n";
    std::unique_ptr<timeOfDay> pu{std::make_unique<preciseTime>(2,31,32)};
    pu->print();

    std::cout << "\nstd::vector로도 테스트\n";
    std::vector<timeOfDay> v;
    v.push_back(t); v[0].print(); std::cout << '\n';
    v.push_back(p); v[1].print(); std::cout << '\n';

    std::cout << "`silicing problems defeated (pointer)\n";
    std::vector<timeOfDay*> vp;
    vp.push_back(pt); vp[0]->print();
    vp.push_back(pp); vp[1]->print();
    vp.push_back(pd); vp[2]->print();


    std::cout << "스마트포인터 vector\n";
    std::vector<std::unique_ptr<timeOfDay>> vu;
    vu.push_back(std::move(pu)); vu[0]->print(); 


    delete pd;

    return 0;





}

























// [실습13]

// 1. 본인이름학번의 네임스페이스

// -본인이름학번 네임스페이스 예: 이름이 김프로이고 학번이 3727500일 경우 KimPro3727500

// using 지시자는 cpp파일에서는 영역 { block } 안에서 사용, 헤더파일엔 using 지시자는 사용하지 않고 네임스페이스 지정자를 사용합니다.

// -using 지시자 예: { using namespace std; cout << "Enter your id: "; }

// -네임스페이스 지정자 예: std::cout << "Enter your id: ";

// 2. timeOfDay.h: 지난 실습에서 만든 클래스에 다음을 추가

// -print함수를 가상으로 

// -가상소멸자

// 3. preciseTime.h: 지날 실습에서 만든 클래스를 이용

// -print함수를 가상으로 

// 4. main.cpp: 테스트

// -slicing problem

// preciseTime 객체를 원하는 값으로 초기화하여 선언한 후 print함수 호출

// timeOfDay 객체를 preciseTime 객체로 초기화하여 선언한 후 print함수 호출

// -slicing problem defeated (pointer)

// preciseTime 객체을 가리키는 포인터변수 선언한 후 print함수 호출

// timeOfDay를 가리키는 포인터변수를 선언, preciseTime 객체을 가리키는 포인터변수를 할당 후 print함수 호출

// -slicing problem defeated (dynamic)

// timeOfDay를 가리키는 포인터변수를 선언, preciseTime으로 동적할당, print함수 호출, 동적할당 해제

// -slicing problem defeated (smart pointer)

// 스마트포인터로도 테스트



// std::vector로도 테스트

// timeOfDay 객체형 std::vector를 선언하고 첫번째에는 timeOfDay형, 두번째에는 preciseTime형을 넣어준 후 각각 print함수 호출

// 포인터변수, 동적할당, 스마트포인터