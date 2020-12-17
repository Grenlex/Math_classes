#include <iostream>

using namespace std;
template <int n>
class FibonaciNumber {
private:
  int data[n];
public:
FibonaciNumber(){
  data[0] = 0;
  data[1] = 1;
  for (int i = 2; i < n; i++) data[i] = data[i-1] + data[i-2];
}
int* begin(){
  return data;
}
int* end(){
  int* datax = data + n -1;
  return datax;
}
class iterator{
  private:
  int* num;
  public:
  iterator(int* pointer){
    num = pointer;
  }
  iterator(){}
  iterator& operator++ (){
    num += 1;
    return *this;
    }
  iterator& operator-- (){
    num -= 1;
    return *this;
    }
  iterator operator++ (int){
    iterator prev = *this;
    ++*this;
    return prev;
    }
  iterator operator-- (int){
    iterator prev = *this;
    --*this;
    return prev;
    }
  bool operator <= (int* c2){
    return (*this).num <= c2;
    }
  bool operator >= (int* c2){
    return (*this).num >= c2;
    }
  bool operator < (int* c2){
    return (*this).num < c2;
    }
  bool operator > (int* c2){
    return (*this).num > c2;
    }
  int operator* (){return *(*this).num;}
};
};

int main(){
  FibonaciNumber<10> test;
  FibonaciNumber<10>::iterator it;
  for (it = test.begin(); it <= test.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  for (it = test.end(); it >= test.begin(); it--) {
    cout << *it << " ";
  }
  return 0;
}