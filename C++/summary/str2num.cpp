#include <iostream>
#include <string>
#include <sstream>    //头文件
using namespace std;

stringstream ss;
int n=0,sum=0,d=0;
string k; 

int main(){
  cin>>k;
 
  while(n<k.size()){//求和
   ss<<k[n];        //流入字符
   ss>>d;           //转为数字
   ss.clear();      //清空
   sum=sum+d;
   n++;
  }
  cout<<sum;
 
  return 0;
}
