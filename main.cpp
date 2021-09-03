#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include "Compiler.h"
using namespace std;

string inputParser(string infile);
string strip(string codeline);

int main(int argc, char **argv){
    
    // string code = inputParser("test_files/print7.txt");
    string code = inputParser(argv[1]);
    Compiler cmp(code);
    cmp.compile();
    cmp.run();
    cout << endl;
    return 0;
}

string inputParser(string name){
    string codeline;
    ifstream infile(name.c_str());
    vector<string> codelines;
    while (getline(infile, codeline)){
        codelines.push_back(strip(codeline));
    }
    string code = accumulate(codelines.begin(), codelines.end(), string(""));
    return code;
}

string strip(string codeline){
    vector<char> code;
    vector<char> allowedChars = {'+','-','[',']','<','>','.'};
    for (char ch1 : codeline){
        for (char ch2 : allowedChars){
            if (ch1 == ch2){
                code.push_back(ch1);
                continue;
            }
        }
    }
    string codestring = accumulate(code.begin(), code.end(), string(""));
    return codestring;
}