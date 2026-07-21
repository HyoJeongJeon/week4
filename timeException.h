#pragma once
#include <exception>
#include <string>

namespace Jeonhyojeong2593270
{
    class timeException : public std::exception  // 예외클래스는 std::exception을 공개적으로 상속합니다. 
    {
        timeException(const std::string& m = "no message yet")   //생성자: std::string형 멤버변수를 초기화 (초기값도 넣어주기)
            : message{m}{}
        const std::string getMessage() const { return message; }   //const get 접근함수: std::string형 멤버변수를 리턴
   
    
        private:
            std::string message;    //private 멤버변수 std::string형

}



//  2. 예외클래스.h: 예외클래스를 인라인으로 정의합니다.

// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의합니다. 

// 예외클래스는 std::exception을 공개적으로 상속합니다. 

// private 멤버변수 std::string형

// public

// -생성자: std::string형 멤버변수를 초기화 (초기값도 넣어주기)

// -const get 접근함수: std::string형 멤버변수를 리턴