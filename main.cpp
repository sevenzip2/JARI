#include <iostream>
#include "effolkronium/random.hpp"
#include "Partition.h"
using Random = effolkronium::random_static;
using std::cin;
using std::cout;
using std::endl;
int main(int, char **)
{
    int w, h, classnum, sectionnum;
    std::cout << "자리 바꾸기 프로그램 1.0" << std::endl;
    cout << "좌석의 행, 열, 반의 인원수, 한 분단의 인원수를 차례대로 입력하시오." << endl;
    cin >> w >> h >> classnum >> sectionnum;
    Partition Part(w, h, classnum, sectionnum);
    cout << "자리의 형상은 다음과 같습니다." << endl;
    printpartition(Part.geta(), Part.getmaxnum(), false);
}
