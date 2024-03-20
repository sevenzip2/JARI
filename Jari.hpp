#pragma once
class Jari
{
public:
    Jari():number(0),classnum(0){}
    Jari(unsigned a) : number(a),classnum(0)
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