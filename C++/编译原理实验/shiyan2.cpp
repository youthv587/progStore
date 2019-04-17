#include <iostream>
using namespace std;
//递归下降分析器
int t=0;
char s[100];存放输入的字符串  s[t]表示当前字符 
char vt[7]={'i','+','-','*','/','(',')'};//终结符

void E();
void T();
void G();
void F();
void S();

void match(char ch)
{   
	if(ch==s[t]) {cout<<s[t];t++;}
	else cout <<ch<< "不匹配" << endl;
}

int isVt(char ch){
	for(int i=0;i<=6;i++){
	if(ch==vt[i])return 1;//是终结符
	}
	return 0;//不是终结符
}

void E()
{
	T();
	G();
}

void G()//加减
{
	if (s[t]== '+') {
		match('+');
		T();
		G();
	}
	else if (s[t] == '-') {
		match('-');
		T();
		G();
	}
}

void T()
{
	F();
	S();
}

void S()//乘除
{
	if (s[t]== '*') {
		match('*');
		F();
		S();
	}
	else if (s[t]== '/') {
		match('/');
		F();
		S();
	}
}

void F()
{
	if (s[t]== 'i') {
		match('i');
		}
	else if (s[t] == '(') {
		match('(');
		E();
		if (s[t] == ')') {
			match(')');
		}
		else {
			//错误并退出分析
			cout << "未匹配到右括号')'";
			exit(0);
			}
		}
	else {
		//错误并退出分析
		cout << "第" << t + 1 << "个字符" << s[t] << "匹配错误  ";
		exit(0);
	}
}

int main()
{
		//例：s[100]='i+i*i#'，#为结束符;
		cout<<"在此位置输入符号串例如：";
		cin>>s;
		E();
		cout<<s[t];
		if(s[t]=='#'){
			cout<<"匹配完成"<<endl;
			}
		else if(isVt(s[t])){
			cout<<"语法错误："<<s[t-1]<<"后不能接"<<s[t]<<endl;
			}
		else {
			cout<<s[t]<<"是非法字符"<<endl;
			}
	return 0;
}
