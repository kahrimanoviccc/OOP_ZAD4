#include "mojNiz.hpp"

int main()
{
MojNizInt noviNiz{6, 9 , 3235, 88};
noviNiz.printaj();
std::cout << noviNiz.size() << std::endl;
std::cout << noviNiz.at(2) << std::endl ;
MojNizInt drugi{3, 6, 9, 12, 7, 8};
drugi*2;
drugi.printaj();
drugi*3;
drugi.printaj();
}
