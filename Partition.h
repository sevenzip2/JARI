#pragma once
#include "Jari.hpp"
#include <vector>
#include <exception>
class Partition
{
public:
    Partition(int w, int h, int classnum, int sectionnum) : a(h)
    {
        int realw = w / sectionnum;
        int modw = w % sectionnum;
        if (w * h < classnum)
        {
            throw std::out_of_range("지정된 자리보다 좌석 수 많음");
        }
        if (w * h == classnum)
        {
            for (int i = 0; i < a.size(); i++)
            {
                for (int j = 0; j < realw; j++)
                {
                    a[i].push_back(std::vector<Jari>(sectionnum));
                }
                a[i].push_back(std::vector<Jari>(modw));
            }
        }
    }

private:
    std::vector<std::vector<std::vector<Jari>>> a;
};