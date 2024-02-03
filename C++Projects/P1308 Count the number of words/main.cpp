#include <iostream>
#include <cctype>
#include <cstring>
//状态机法
const int SPACE = 0;//空格状态
const int LETTER = -1;//非目标单词状态
const int WORD = 1;//要查找的单词的状态

//将字符串转化为小写
void strLower(char *a) {
    for (int i = 0; a[i]; ++i) {
        if (isupper(a[i])) {
            a[i] = tolower(a[i]);
        }
    }
}


int main() {
    char str[1000001], word[20];
    int freq = 0;//出现频次
    int pos = -1;//首次出现位置
    int state = 0;//当前状态（上一个字符）

    fgets(word, sizeof (word),stdin);
    if(strlen(word)!=sizeof(word)-1) //需要考虑要读的数据行太长没读完的情况.
        word[strlen(word)-1]='\0';
    fgets(str, sizeof (str),stdin);
    if(strlen(str)!=sizeof(str)-1) //需要考虑要读的数据行太长没读完的情况.
        str[strlen(str)-1]='\0';
//    gets(word);
//    gets(str);
    strLower(word);
    strLower(str);
    int len = strlen(word);//单词长度
    int i;

    for (i = 0; str[i]; ++i) {
        switch (state) {
            case SPACE:
                if (str[i] == word[0]) {//在上一个字符为空格的情况下，若当前字母匹配单词的的一个字母
                    state = WORD;//则切换至WORD状态
                } else if (str[i] == ' ') {
                    //不执行任何操作
                } else {
                    state = LETTER;//更改为非目标单词状态
                }
                break;
            case LETTER:
                if (str[i] == ' ') {
                    state = SPACE;//若访问到空格则切换状态为空格
                }
                break;
            default:
                if (state < len) {//若未达到单词长度（未完全匹配）
                    if (str[i] == ' ') {//遇到空格则切换到SPACE状态
                        state = SPACE;
                    } else if (str[i] == word[state]) {//匹配则增加一单位匹配长度
                        state++;
                    } else {//不匹配则切换为非目标单词状态
                        state = LETTER;
                    }
                } else if (state == len) {//达到单词长度（即完全匹配）
                    if (str[i] == ' ') {//遇到空格，更改状态为SPACE
                        state = SPACE;
                        if (pos == -1) {//若还未出现目的单词
                            pos = i - len;//记录首次出现位置
                        }
                        freq++;//频次加一
                    } else {//达到长度后仍未结束则切换到非目标单词
                        state = LETTER;
                    }
                }
        }
    }

    if (state == len) {//考虑文末最后一个单词匹配的情况
        freq++;
        if (pos == -1) {
            pos = i - 1 - len;
        }
    }
    if (pos == -1) {//按题目要求的两种情况输出
        printf("-1");
    } else {
        printf("%d %d", freq, pos);
    }

    return 0;
}
