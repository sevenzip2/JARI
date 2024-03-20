#include "Partition.h"
void printpartition(const std::vector<std::vector<std::vector<Jari>>> &a, int maxnum, bool prefix)
{
    int Jarisu = GetNumberOfDigits(maxnum);

    for (int i = 0; i < a.size(); i++) 
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            std::cout << "|";
            for (int k = 0; k < a[i][j].size(); k++)
            {
                int q;
                if (prefix == false)
                {
                    q = a[i][j][k].getnumber();
                }
                else
                {
                    q = a[i][j][k].getclassnum();
                }
                std::cout << q;
                int p= GetNumberOfDigits(q);
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
unsigned GetNumberOfDigits (unsigned i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}