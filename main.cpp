#include <iostream>
#include "Partition.h"
using std::cin;
using std::cout;
using std::endl;
#ifdef _WIN32
#include <Windows.h>
#endif
void run()
{
    int w, h, classnum, sectionnum;
    int ifprefix;
    int prefixstart, prefixend;
    std::vector<int> classnums;
    std::cout << "자리 바꾸기 프로그램 1.2.0" << std::endl;
    Partition Part;
    while (1)
    {
        try
        {
            cout << "좌석의 행, 열, 반의 인원수, 한 분단의 인원수를 차례대로 입력하시오." << endl;
            cin >> w >> h >> classnum >> sectionnum;
            int start, absen, end;
            cout << "반의 시작번호는?" << endl;
            cin >> start;
            cout << "반의 끝 번호는?" << endl;
            cin >> end;
            absen = ((end - start) + 1) - classnum;
            classnums = std::vector<int>(end - start + 1);
            std::ranges::iota(std::begin(classnums), std::end(classnums), start);
            cout << "결번된 번호들을 입력하시오." << endl;
            for (int i = 0; i < absen; i++)
            {
                int pk;
                cin >> pk;
                auto it = std::find(classnums.begin(), classnums.end(), pk);
                if (it == classnums.end())
                {
                    throw std::out_of_range("오류 발생");
                }
                classnums.erase(it);
            }
            cout << "학급의 인원 현황은 다음과 같습니다." << endl;
            for (auto it = classnums.begin(); it != classnums.end(); it++)
            {
                cout << *it;
                if (it != (classnums.end() - 1))
                    cout << ",";
            }
            cout << endl;
            Part = Partition(w, h, classnum, sectionnum, std::move(classnums));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
        break;
    }
    cout << "자리의 형상은 다음과 같습니다." << endl;
    printpartition(Part.geta(), classnum, false);
    cout << "자리 선지정이 필요하십니까? 필요하시다면 1, 아니면 아무 숫자나 입력하시오." << endl;
    cin >> ifprefix;
    if (ifprefix == 1)
    {

        while (1)
        {
            try
            {
                int k;
                while (1)
                {

                    cout << "몇번부터 선지정 자리로 합니까?" << endl;
                    cin >> prefixstart;
                    cout << "몇번까지 선지정 자리로 합니까?" << endl;
                    cin >> prefixend;
                    cout << "선지정할 사람의 수를 입력하시오." << endl;
                    cin >> k;
                    if (k > (prefixend - prefixstart + 1))
                    {
                        cout << "잘못된, 다시 입력이 필요한." << endl;
                        continue;
                    }
                    break;
                }
                cout << "선지정할 사람들의 번호를 입력하시오." << endl;
                std::vector<int> a(k);
                for (int i = 0; i < k; i++)
                {
                    int q;
                    cin >> q;
                    a[i] = q;
                }
                cout << "자리배정을 시작합니다." << endl;
                Part.changeRandom(prefixstart, prefixend, a);
                Part.changeRandom();
                printpartition(Part.geta(), classnum, true);
                fprintpartition(Part.geta(),classnum,true);

            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                continue;
            }
            break;
        }
    }
    else
    {
        cout << "자리배정을 시작합니다." << endl;
        Part.changeRandom();
        printpartition(Part.geta(), classnum, true);
        fprintpartition(Part.geta(),classnum,true);
    }
}
int main(int, char **)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    run();
#ifdef _WIN32
    system("pause");
#endif
}
