#include <iostream>
#include <iterator>
#include <functional>
#include <vector>

auto lambda= [](int a, int b){
return a<b;
};

void printaj(const std::vector<int>& brojevi){
for(const int& broj: brojevi){
  std::cout<< broj << "\t" ;
};
std::cout<< "\n" <<std::endl;
}

void ucitaj(std::vector<int>& brojevi){
int broj;
std::cout<<"Unesite brojeve: "<<std::endl;
while(std::cin >> broj){
if(broj == 0) break;
brojevi.push_back(broj);
};
}


template <typename iter, typename fja = std::function<bool(int,int)>>
void sort(iter pocetak, iter kraj, fja kriterij = [](int a, int b){return a>b;}){ 
for(; pocetak!=kraj; pocetak++){
for(iter tmp= pocetak; tmp!= kraj; tmp++){
if(kriterij(*pocetak,*tmp)){
int tmp2;
tmp2=*pocetak;
*pocetak=*tmp;
*tmp=tmp2;
};
};
};
}

int main()
{
std::vector<int> brojevi;
ucitaj(brojevi);
printaj(brojevi);
sort(begin(brojevi), end(brojevi), lambda);
printaj(brojevi);
sort(begin(brojevi), end(brojevi));
printaj(brojevi);
}
