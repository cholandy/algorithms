// 택시기사인 A씨는 회사에서 쏘나타를 제공받아 한달에 n일간 택시를 운행하고 있습니다.
// 택시에 주입할 휘발유를 구입해야 하는데, 구입 가격은 날짜별로 변화가 있습니다.
// 이에 택시 회사에서는 회발유 구입 비용을 줄이기 위해 n일을 운행하는 데 필요한 최소 비용을 
// 구하려고 합니다. 즉 n일간의 휘발유 가격 변화가 주어질 때, 가장 적은 비용이 드는 경우의 총액을 계산하고자 합니다.
// 택시를 운행할 날의 수 n과 택시를 하루 운행하는 데 소요되는 휘발유의 당일 가격 목록 P가 매개변수로 
// 주어질 때 가장 적은 비용이 드는 경우의 총액을 return하도록 solution함수를 완성하세요. 
// n은 1이상 100,000 이하의 자연수입니다.
// P의 길이는 n이고 P의 원소인 휘발유 가격은 1이상 10,000,000 이하의 자연수입니다.

//
#include <iostream> 
using namespace std; 
class CalcModule { // Overflow를 고려하지 않은 Class 
  private: 
  int nX; 
  int nY; 
  public: 
  CalcModule(const int x, const int y) 
  { 
    this->nX = x; 
    this->nY = y; 
 } 
 ~CalcModule() 
 { 
   // Empty 
} 
int mod() { 
  return nX % nY; 
} 
}; 
int main() 
{ 
  const int nX = 1234567; 
  const int nY = 64; 
  CalcModule *calcModule = new CalcModule(nX, nY); 
  cout << nX << " % " << nY << " = " << calcModule->mod() << endl; 
  delete calcModule; 
  return 0; 
} 