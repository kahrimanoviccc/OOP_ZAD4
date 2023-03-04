#include "mojNiz.hpp"

MojNizInt::MojNizInt() : p_niz{new int [size_]}, size_{1} {
}

MojNizInt::MojNizInt(const MojNizInt& other) : p_niz{new int [size_]}, size_{other.size_}{
  std::copy(other.p_niz, other.p_niz+other.size_, p_niz);
}

MojNizInt::MojNizInt(MojNizInt&& other) : p_niz{other.p_niz}, size_{other.size_} {
other.p_niz= nullptr;
other.p_niz= 0;
} 

MojNizInt::MojNizInt(std::initializer_list<int> lista):  p_niz{new int [size_]}, size_{lista.size()} {
  std::copy(lista.begin(), lista.end(), p_niz);
}

void MojNizInt::printaj(){
for(int i=0; i<size_ ; i++){
  std::cout<<*(p_niz+i)<<std::endl;
};
}

int MojNizInt::size(){
return size_;
}

MojNizInt::~MojNizInt(){
delete [] p_niz;
size_ = 0;
}

int& MojNizInt::at(const int& indeks){
if(indeks> size_) {throw std::invalid_argument("Nevalidan argument");};
return (p_niz[indeks]);

}
MojNizInt& MojNizInt::operator=(const MojNizInt& other){
if (this != &other){
delete [] p_niz;
size_ = other.size_;
p_niz = new int [size_];
std::copy(other.p_niz , other.p_niz+size_, p_niz);
};
return *this;
}

MojNizInt& MojNizInt::operator*(const int& a){
for(size_t i=0; i<size_ ; i++){
p_niz[i] = p_niz[i]*a;
}
return *this;
}

/*MojNizInt& MojNizInt::operator+(const MojNizInt& other){
int* tmp = p_niz;
size_t tmp_size= size_;
p_niz = new [size_] 
}*/
