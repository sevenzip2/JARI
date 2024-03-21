#pragma once
#include "Jari.hpp"
#include "effolkronium/random.hpp"
#include <vector>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <cmath>
#include <algorithm>
using Random = effolkronium::random_static;
unsigned GetNumberOfDigits(unsigned i);
class Partition // 자리들 클래스
{
public:
    Partition()
    {
    }
    Partition(int w, int h, int classnum, int sectionnum,std::vector<int> && classnums) : a(h), b(classnums) // w는 가로 자리 개수, h는 세로 자리 수, classnum은 반의 인원수, sectionnum은 1분단당 인원수를 의미
    {
        int realw = w / sectionnum;                                        // 가로 분단 수
        int modw = w % sectionnum;                                         // 가로 분단 수의 나머지
        if (w * h < classnum || (w * h - classnum) >= w || sectionnum > w) // 주어진 자리수가 너무 적거나 너무 많으면 오류
        {
            throw std::out_of_range("범위 지정 오류");
        }
        else if (w * h == classnum) // 주어진 자리 수와 사람 수가 많다면
        {
            for (int i = 0; i < a.size(); i++)
            {
                for (int j = 0; j < realw; j++) // 일단 분단을 추가
                {
                    a[i].push_back(std::vector<Jari>(sectionnum));
                }
                if (modw != 0) // 그리고 나머지 분단을 추가
                {
                    a[i].push_back(std::vector<Jari>(modw));
                }
            }
        }
        else if (w * h > classnum) // 주어진 사람 수보다 자리 수가 많다면
        {
            for (int i = 0; i < a.size() - 1; i++) // 일단 한 마지막 행을 비워두고 나머지를 추가
            {
                for (int j = 0; j < realw; j++)
                {
                    a[i].push_back(std::vector<Jari>(sectionnum));
                }
                if (modw != 0)
                {
                    a[i].push_back(std::vector<Jari>(modw));
                }
            }
            int newnum = classnum - (w * (h - 1)); // 남은 사람들
            int realnnum = newnum / sectionnum;    // 남은 분단들
            int modnnum = newnum % sectionnum;     // 남은 분단의 나머지
            for (int i = 0; i < realnnum; i++)
            {
                a[a.size() - 1].push_back(std::vector<Jari>(sectionnum)); // 남은 분단들 추가
            }
            if (modnnum != 0)
            {
                a[a.size() - 1].push_back(std::vector<Jari>(modnnum)); // 남은 나머지 추가
            }
        }
        setjarinum();
    }
    const std::vector<std::vector<std::vector<Jari>>> &geta() const
    {
        return a;
    }
    void changeRandom(int presetstart, int presetnum, const std::vector<int> & presetlist ); // 선지정 자리를 랜덤 배열
    void changeRandom();                                           // 선지정되지 않은 모든 자리를 랜덤 좌석 배열
private:
    void setjarinum()
    {
        int num = 1;
        for (auto &x : a) // 자리 번호 지정
        {
            for (auto &y : x)
            {
                for (auto &z : y)
                {
                    z.setnumber(num);
                    num++;
                }
            }
        }
    }
    std::vector<std::vector<std::vector<Jari>>> a; // 자리
    std::vector<int> b;                            // 사람들
};
void printpartition(const std::vector<std::vector<std::vector<Jari>>> &, int, bool); // 자리 출력 함수
