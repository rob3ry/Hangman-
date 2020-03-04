#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

//char hangy[4][4] = {' '};

typedef void(*VoidFuncPointers)(char hangy[][4]);
void f1(char[][4]);
void f2(char[][4]);
void f3(char[][4]);
void f4(char[][4]);
void f5(char[][4]);
void f6(char[][4]);
void f7(char[][4]);
void f8(char[][4]);
void f9(char[][4]);
void f10(char[][4]);
void f11(char[][4]);
void f12(char[][4]);

bool solved(char hid[],int len)
{
    int count = 0;
    for(int i=0;i<len;i++)
    {
        if(hid[i] == '_') {count++;}
    }
    if(count > 0) {return false;}
    else {return true;}
}
void printHangy(char hangy[][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << hangy[i][j];
        }
        cout << endl;
    }
}

class Set
{
public:
    Set() : n(0) {}
    void push(const string &s)
    {
        words.push_back(s);
        /*else{
            for(int i=0;i<n;i++)
            {
                if(s < words[i]) {words[i] = s;}
            }
        }*/
        n++;
    }
    void pop()
    {
        words.pop_back();
    }
    int getSize()
    {
        return n;
    }
    bool isEmpty()
    {
        return n == 0;
    }
    void print()
    {
        for(int i=0;i<n;i++) {cout << words[i] << endl;}
    }
    string get_randElem()
    {
        srand(time(0));
        int index = rand();
        return words[index];
    }
private:
    vector<string> words;
    int n;
};


int main()
{
    VoidFuncPointers functions[] = {f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12};
    string word;
    Set wordlist;
    ifstream infile;
    infile.open("words.txt");
    if(infile.fail()) {cout << "Error opening fail!" << endl;}

    while(!(infile.eof()))
    {
        getline(infile,word);
        wordlist.push(word);
    }

    char hangy[4][4] = {' '};
    string rnd = wordlist.get_randElem();
    int len = rnd.length(),error = 0;
    //cout << rnd << " " << len << endl;
    char alphabet[26];
    for(int i= 0; i < 26;i++) {alphabet[i] = 'a'+i;}
    char hidden[len];
    char inp;
    //bool gameover = false;
    for(int i=0;i<len;i++) {hidden[i] = '_';}

    while(error <= 12)
    {
        //cout << hidden;
        for(int i=0;i<len;i++)
            cout << hidden[i];
        cout << endl << "Guess the word! Enter a letter: ";
        cin >> inp;
        for(int i=0;i<26;i++)
        {
            if(inp == alphabet[i]) {alphabet[i] = '-';}
            cout << alphabet[i] << " ";
        }
        cout << endl;
        bool match = false;

        for(int i=0;i<len;i++)
        {
            if(rnd[i] == inp)
            {
                hidden[i] = inp;
                match = true;
            }
        }
        if(solved(hidden,len)) {cout << endl << "CONGRATS!" << endl << "Word solved: " << rnd; break;}
        if(match == false)
        {
            functions[error](hangy);
            printHangy(hangy);
            if(error == 11)
            {
                cout << endl << "GAMEOVER! You're hanged :(" << endl;
                cout << "The word is: " << rnd <<endl;
                break;
            }
            error++;
        }
    }

    return 0;
}

void f1(char hangy[][4]) {hangy[3][3] = '|';} /// 1
void f2(char hangy[][4]) {hangy[2][3] = '|';}/// 2
void f3(char hangy[][4]) {hangy[1][3] = '|';} /// 3
void f4(char hangy[][4]) {hangy[0][3] = '_';} /// 4}
void f5(char hangy[][4]) {hangy[0][2] = '_';} /// 5}
void f6(char hangy[][4]) {hangy[0][1] = '_';} /// 6}
void f7(char hangy[][4]) {hangy[1][1] = 'O';} /// 7}
void f8(char hangy[][4]) {hangy[2][1] = '|';} /// 8}
void f9(char hangy[][4]) {hangy[3][0] = '/';} /// 9}
void f10(char hangy[][4]){hangy[3][2] = '\\';}///10}
void f11(char hangy[][4]){hangy[2][0] = '/';} ///11}
void f12(char hangy[][4]){hangy[2][2] = '\\';}///12}

