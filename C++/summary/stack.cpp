//堆栈
/*

.push(val)//将()里的内容压栈
.top() // 返回栈顶
.pop() // 弹出栈顶,没有返回值

*/
/*示例  求和并转为D进制（PAT乙级1022） */
#include<iostream>
#include <stack>
using namespace std;

int main(){
	int A,B,D,num;
	stack<int>S;//定义栈S
	cin>>A>>B>>D;
	num=A+B;
	
	if(num==0)cout<<0;
	while(num){//取余放入堆栈
	S.push(num%D);
	num=num/D;	
	}
	
	while(!S.empty()){//将堆栈中的数字依次取出
	cout<<S.top();
	S.pop();
	}
return 0;
} 
