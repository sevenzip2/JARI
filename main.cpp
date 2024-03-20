#include <iostream>
#include "effolkronium/random.hpp"
#include "Partition.h"
using Random = effolkronium::random_static;
int main(int, char **)
{
    Partition a(7, 3, 16, 3);
    std::cout << "Hello" << std::endl;
}
