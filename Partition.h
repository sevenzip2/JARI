#pragma once
#include "Jari.hpp"
#include <vector>
class Partition
{
public:
    Partition(int w, int h, int classnum, int sectionnum) : a(h)
    {
        int realw = w / sectionnum;
        int modw = w % sectionnum;
    }

private:
    std::vector<std::vector<std::vector<Jari>>> a;
};