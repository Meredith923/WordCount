/*
程序统计文本文件（纯英文）的字符数或者单词数。
空格，水平制表符，换行符均算字符。
由空格或逗号分割开的都视为单词，且不做单词的有效性校验，
例如：thi#,that视为用逗号隔开的2个单词。
*/
#include <iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int charCnt(vector<string>& x) {//统计字符数
    int cnt = 0;
    for (int i = 0; i < (int)x.size(); i++) {
        for (int j = 0; j < x[i].length(); j++) {
            cnt++;
        }
    }
    return cnt;
}

int wordCnt(vector<string>& x) {//统计单词数
    int cnt = 0;
    for (int i = 0; i < (int)x.size(); i++) {
        for (int j = 0; j < x[i].length(); j++) {
            if (j >= 1 && (x[i][j] == ' ' || x[i][j] == ',')) {
                if (x[i][j - 1] != ' ' || x[i][j - 1] != ',') {
                    cnt++;
                }
            }
        }
    }
    if (x[0][0] != ' ') cnt++;
    return cnt;
}


int main(int argc, char** argv)
{
    string select = argv[1];  //记录选择
    string line;
    vector<string>linestring;
    ifstream inputfile(argv[2], ios::in); //打开文件用于读取
    if (!inputfile) { //如果打开失败
        return -1;
    }
   
    while (getline(inputfile, line)) {
        linestring.push_back(line);
    }
    
    if (select == "-c") {//如果选择-c方式，调用字符计数函数
        cout << charCnt(linestring) << endl;
    }
    
    else if (select == "-w") {//如果选择-w方式，调用单词计数函数
        cout << wordCnt(linestring) << endl;
    }      
    
    else
        cout << "命令错误" << endl;

    inputfile.close();  //关闭文件
    return 0;
}

