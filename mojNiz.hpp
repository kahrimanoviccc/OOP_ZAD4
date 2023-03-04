#pragma once 
#include<initializer_list>
#include<algorithm>
#include<iostream>
#include<exception>
class MojNizInt {
  public:
    MojNizInt();
    int size();
    int& at(const int&); //bez const konteksta
    MojNizInt(std::initializer_list<int>);
    MojNizInt(const MojNizInt&);
    MojNizInt(MojNizInt&&);
    MojNizInt& operator=(const MojNizInt&);
    MojNizInt& operator=(MojNizInt&&);
    ~MojNizInt();
    //
    int& operator[](int);
    MojNizInt& operator*(const int&);
    MojNizInt& operator+(const MojNizInt&);
    MojNizInt& operator++();
    MojNizInt& operator++(int);
    MojNizInt& push_back(int);
    void printaj(void);
  private:
    size_t size_{0};
    int* p_niz{nullptr};
};

