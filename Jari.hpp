#pragma once
class Jari // 자리 클래스
{
public:
    Jari() : number(0), classnum(0) {}        // 생성자
    Jari(unsigned a) : number(a), classnum(0) // 생성자2
    {
    }
    void setnumber(unsigned a)
    {
        number = a;
    }
    unsigned getnumber() const
    {
        return number;
    }
    void setclassnum(unsigned a)
    {
        classnum = a;
    }
    unsigned getclassnum() const
    {
        return classnum;
    }

private:
    unsigned number;   // 자리번호
    unsigned classnum; // 반번호
};