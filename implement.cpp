#include "mojNiz.hpp"

MojNizInt::MojNizInt() : p_niz{new int [size_]}, size_{1}{
*p_niz=0;
}

MojNizInt::MojNizInt(std::initializer_list<int> lista) : p_niz{new int [size_]}, size_{lista.size()}{
  std::copy(begin(lista), end(lista), p_niz);
}

int MojNizInt::size() {
  return size_;
}

int& MojNizInt::at(const int& indeks){
if(indeks > size_){
throw std::invalid_argument{"Van granica"};
};
return p_niz[indeks];
}

MojNizInt::MojNizInt(const MojNizInt& other) : p_niz{new int [size_]}, size_{other.size_}{
std::copy(other.p_niz, other.p_niz+other.size_, p_niz);
}

MojNizInt::MojNizInt(MojNizInt&& drugi) : p_niz{drugi.p_niz}, size_{drugi.size_}{
drugi.p_niz= nullptr;
drugi.size_= 0;
};

MojNizInt& MojNizInt::operator=(const MojNizInt& other){
  delete [] p_niz;
  size_=other.size_;
  p_niz= new int[size_];
  std::copy(other.p_niz,other.p_niz+other.size_, p_niz);
  return *this;
}

MojNizInt& MojNizInt::operator=(MojNizInt&& other){
delete [] p_niz;
size_=other.size_;
p_niz=other.p_niz;
other.p_niz=0;
other.size_=0;
return *this;
}

MojNizInt& MojNizInt::operator*(const int& broj){
for (int i =0; i< size_; i++){
p_niz[i]=p_niz[i]*broj;
};
return *this;
}

