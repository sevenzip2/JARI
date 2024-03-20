#include <iostream>
#include "Partition.h"
using std::cin;
using std::cout;
using std::endl;
#ifdef _WIN32
#include <Windows.h>
#endif
int main(int, char **)
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    int w, h, classnum, sectionnum;
    int ifprefix;
    int prefixnum;
    std::cout << "자리 바꾸기 프로그램 1.0" << std::endl;
    Partition Part;
    while (1)
    {
        try
        {
            cout << "좌석의 행, 열, 반의 인원수, 한 분단의 인원수를 차례대로 입력하시오." << endl;
            cin >> w >> h >> classnum >> sectionnum;
            Part = Partition(w, h, classnum, sectionnum);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
        break;
    }
    cout << "자리의 형상은 다음과 같습니다." << endl;
    printpartition(Part.geta(), Part.getmaxnum(), false);
    cout << "자리 선지정이 필요하십니까? 필요하시다면 1, 아니면 아무 숫자나 입력하시오." << endl;
    cin >> ifprefix;
    if (ifprefix == 1)
    {

        int k;
        while (1)
        {

            cout << "1번부터 몇번까지 선지정 자리로 할지 입력하시오" << endl;
            cin >> prefixnum;
            cout << "선지정할 사람의 수를 입력하시오." << endl;
            cin >> k;
            if (k > prefixnum)
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
        Part.changeRandom(prefixnum, a);
        Part.changeRandom();
        printpartition(Part.geta(), Part.getmaxnum(), true);
    }
    else
    {
        cout << "자리배정을 시작합니다." << endl;
        Part.changeRandom();
        printpartition(Part.geta(), Part.getmaxnum(), true);
    }
    #ifdef Win32 
    system("pause");
    #endif
}
