#pragma once
class Jari
{
public:
    Jari(unsigned a) : number(a)
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
    unsigned number;
    unsigned classnum;
};