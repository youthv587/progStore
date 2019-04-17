#include<iostream>
#include<string> 
using namespace std;
//词法分析器

bool isNum(string str);//判断数字
bool isWord(string str);//判断字母
int kyNum(string& str);//返回关键字种别码
int chNum(string& str);//返回字符种别码

string ky[7] = { "?","begin","if","then","while","do","end" }; //关键字，种别码与下标对应 
string ch[16] = { "+","-","*","/",":",":=","?","<","<>","<=",">",">=","=",";","(",")" }; // 运算符和界符,+13
string prog = "begin x:=9;if x>0 then x:=2*x+1/3;end#";
string token;
int i = 0;//i扫描进度
bool isNext;

bool isNum(char str) {
	if ((str >= '0') && (str <= '9'))	return true;
	else	return false;
}

bool isWord(char str) {
	if ((str >= 'a') && (str <= 'z') || (str >= 'A') && (str <= 'Z'))
		return true;
	else
		return false;
}

int kyNum(string& str) {
	isNext = true;
	for (int n = 0; n < 7; n++) {
		if (ky[n] == str) {
			return n; isNext = false; break;
		}//关键字种别码 
		}
	if(isNext)return 10;	//标识符种别码
}

int chNum(string& str) {
	isNext = true;
	for (int j = 0; j < 16; j++) {
		if (ch[j] == str) { 
			return j + 13; isNext = false; break;
		}//运算符及界符 	
	}
	if(isNext)return -1;//无效符号

}

int main()
{

	//string prog , token;
	//cin >> prog;
	while (prog[i] != '#') {
		while (prog[i] == ' ')i++;//忽略空格
		if (isWord(prog[i])) {//字母开头	
			token = { "" };//初始化
			do {
				token += prog[i]; i++;//连接字符
			} while (isWord(prog[i]) || isNum(prog[i]));
			if (kyNum(token) == 10)cout << '(' << 10 << ',' << token << ')' << endl;//标识符 
			else cout << '(' << kyNum(token) << ',' << token << ')' << endl;//关键字 
			while (prog[i] == ' ')i++;//忽略空格
		}

		else if (isNum(prog[i])) {// 数字开头 
			token = { "" };//初始化
			do {
				token += prog[i]; i++;//连接字符
			} while (isNum(prog[i]));
			cout << '(' << 11 << ',' << token << ')' << endl;//数字 
			while (prog[i] == ' ')i++;//忽略空格
		}
		//其它符号 
		else {
			token = { "" };//初始化
			do {
				token += prog[i]; i++;//连接字符 
			} while (isNum(prog[i]) != 1 && isWord(prog[i]) != 1 && prog[i] != ' ');
			if (chNum(token) == -1)cout <<"error"<< endl;
			cout << '(' << chNum(token) << ',' << token << ')' << endl;
		}

	}//大循环扫描 
	return 0;
}

