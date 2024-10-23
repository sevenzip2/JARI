#include "Partition.h"
void printpartition(const std::vector<std::vector<std::vector<Jari>>> &a, int maxnum, bool prefix) // 자리의 형상 출력
{
    int Jarisu = GetNumberOfDigits(maxnum);

    for (auto &x : a)
    {
        for (auto &y : x)
        {
            std::cout << "|";
            for (auto &z : y)
            {
                int q;
                if (prefix == false)
                {
                    q = z.getnumber();
                }
                else
                {
                    q = z.getclassnum();
                }
                std::cout << q << " ";
                int p = GetNumberOfDigits(q);
                if (p < Jarisu)
                {
                    for (int i = 0; i < (Jarisu - p); i++)
                    {
                        std::cout << " ";
                    }
                }
            }
            std::cout << "| ";
        }
        std::cout << std::endl;
    }
}
void Partition::changeRandom(int presetstart, int presetnum, const std::vector<int> &presetlist) // 선지정 자리를 랜덤 배열
{
    std::vector<int> realpresetlist(presetnum - presetstart + 1); // 선지정 목록
    int i = 0;
    int presize = presetlist.size();
    for (i = 0; i < presize; i++) // 선지정하기로 정한 번호들 추가
    {
        auto it = std::find(b.begin(), b.end(), presetlist[i]);
        if (it == b.end())
        {
            throw std::out_of_range("번호를 찾을 수가 없습니다.");
        }
        realpresetlist[i] = *it;
        b.erase(it);
    }
    for (int j = 0; j < (presetnum - presetstart + 1) - presize; j++) // 나머지는 랜덤으로 추가
    {
        auto it = Random::get(b);
        realpresetlist[i] = *it;
        b.erase(it);
        i++;
    }
    Random::shuffle(realpresetlist);
    int num=0;
    for (auto &x : a) // 랜덤으로 좌석 배열
    {
        for (auto &y : x)
        {
            for (auto &z : y)
            {
                if (z.getclassnum() == 0)
                {

                    if (z.getnumber() > presetnum)
                    {
                        break;
                    }
                    else if (z.getnumber() < presetstart)
                    {
                    }
                    else
                    {
                        z.setclassnum(realpresetlist[num]);
                        num++;
                    }
                }
            }
        }
    }
}
void fprintpartition(const std::vector<std::vector<std::vector<Jari>>> & a, int maxnum, bool prefix) // 자리 출력 함수(File)
{
  int Jarisu = GetNumberOfDigits(maxnum);
 std::ofstream fp("JARI.csv",std::ios_base::out);
    for (auto &x : a)
    {
        for (auto &y : x)
        {
            for (auto &z : y)
            {
                int q;
                if (prefix == false)
                {
                    q = z.getnumber();
                }
                else
                {
                    q = z.getclassnum();
                }
                fp << q << ",";
            }
            fp<<",";
        }
        fp<<"\n";
    }
}
void Partition::changeRandom() // 선지정되지 않은 모든 자리를 랜덤 좌석 배열
{
    Random::shuffle(b);
    int num = 0;
    for (auto &x : a)
    {
        for (auto &y : x)
        {
            for (auto &z : y)
            {
                if (z.getclassnum() == 0)
                {
                    z.setclassnum(b[num]);
                    num++;
                }
            }
        }
    }
}
unsigned GetNumberOfDigits(unsigned i)
{
    return i > 0 ? (int)log10((double)i) + 1 : 1;
}