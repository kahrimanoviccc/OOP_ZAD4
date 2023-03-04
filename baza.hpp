#pragma once
#include <list>
#include <iostream>
#include "radnik.hpp"

class BazaRadnika {
  private:
    std::list<Radnik> radnici;
  public:
  std::istream& ucitaj(std::istream&);
  bool izbrisi_radnika(std::string);
  std::ostream& ispisi(std::ostream&);
  double prosjek_plata();
  double prosjek_godina();
};

std::istream& BazaRadnika::ucitaj(std::istream& ulaz){
std::cout<<"Unesi radnik(ime,prezime,plata,godine)"<<std::endl;
Radnik novi;
ulaz>>novi.ime>>novi.prezime>>novi.plata>>novi.godine;
for(Radnik el: radnici){
if (novi.ime == el.ime){
throw std::domain_error{"Radnik u bazi!!"};
};
};
radnici.push_back(novi);
return ulaz;
}


bool BazaRadnika::izbrisi_radnika(std::string ime_radnika){
auto it = begin(radnici);
while (it != end(radnici)){
if(ime_radnika == it->ime){
it = radnici.erase(it);
return true;
};
it++;
};
return false;
}

std::ostream& BazaRadnika::ispisi(std::ostream& izlaz){
for(Radnik el : radnici){

  izlaz<<el.ime<<"\n";
};
return izlaz;
}

double BazaRadnika::prosjek_plata(){
double suma_plata{0};
for(Radnik el : radnici){
suma_plata+=el.plata;
};
return suma_plata/radnici.size();
}

double BazaRadnika::prosjek_godina(){
double suma_godina{0};
for(Radnik el : radnici){
suma_godina+=el.godine;
};
return suma_godina/radnici.size();
}

