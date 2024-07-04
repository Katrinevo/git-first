#include <string>
#include <regex>
#include <iostream>
using namespace std;

int main()
{
    cout << "1" << endl;
    //1
    string data = "abbafda";

    regex reg1("a..a"); 

    auto pos = data.cbegin();
    auto end = data.cend();
    smatch m;
    for (; regex_search(pos, end, m, reg1); pos = m.suffix().first - 3)
    {
        cout << "match:  " << m.str() << endl;
    }
    cout << "----------------" << endl;
    //2 
    cout << "2" << endl;
    string data2 = "abcaabva aa a";

    regex reg2("a([^b].|.[^c])a");
    auto pos2 = data2.cbegin();
    auto end2 = data2.cend();
    smatch m2;
    for (; regex_search(pos2, end2, m2, reg2); pos2 = m2.suffix().first - 3)
    {
        cout << "match:  " << m2.str() << endl;
    }
    cout << "----------------" << endl;
    //3
    cout << "3" << endl;
    regex reg3("a(b*)a");
    string data3 = " aa abbbaba";
    auto pos3 = data3.cbegin();
    auto end3 = data3.cend();
    smatch m3;
    for (; regex_search(pos3, end3, m3, reg3); pos3 = m3.suffix().first - 1)
    {
        cout << "match:  " << m3.str() << endl;
    }
    cout << "----------------" << endl;
    //4
    cout << "4" << endl;
    regex reg4("(ab)+"); // "+" - ab встрчается 1 или более раз
    string data4 = "abbbababnab";
    auto pos4 = data4.cbegin();
    auto end4 = data4.cend();
    smatch m4;
    for (; regex_search(pos4, end4, m4, reg4); pos4 = m4.suffix().first )
    {
        cout << "match:  " << m4.str() << endl;
    }
    cout << "----------------" << endl;
    //5
    cout << "5" << endl;
    regex reg5("2(\\+)*3");
    string data5 = "2+++3snf232+32++3";
    auto pos5 = data5.cbegin();
    auto end5 = data5.cend();
    smatch m5;
    for (; regex_search(pos5, end5, m5, reg5); pos5 = m5.suffix().first)
    {
        cout << "match:  " << m5.str() << endl;
    }
    cout << "----------------" << endl;
    //6
    cout << "6" << endl;
    regex reg6("(abba)|(abbba)|(abbbba)");
    string data6 = "ababbaabbbbbbabbba";
    auto pos6 = data6.cbegin();
    auto end6 = data6.cend();
    smatch m6;
    for (; regex_search(pos6, end6, m6, reg6); pos6 = m6.suffix().first - 1)
    {
        cout << "match:  " << m6.str() << endl;
    }
    cout << "----------------" << endl;
    //7
    cout << "7" << endl;
    regex reg7("a(b{4,})b");
    string data7 = "abbbbbabbaabbbbbbbbbabb";
    auto pos7 = data7.cbegin();
    auto end7 = data7.cend();
    smatch m7;
    for (; regex_search(pos7, end7, m7, reg7); pos7 = m7.suffix().first)
    {
        cout << "match:  " << m7.str() << endl;
    }
    cout << "----------------" << endl;
    //8 
    cout << "8" << endl;
    regex reg8("a(\\d)a");
    string data8 = "a8avba12a6a";
    auto pos8 = data8.cbegin();
    auto end8 = data8.cend();
    smatch m8;
    for (; regex_search(pos8, end8, m8, reg8); pos8 = m8.suffix().first - 1)
    {
        cout << "match:  " << m8.str() << endl;
    }
    cout << "----------------" << endl;
    //9 ?
    cout << "9" << endl;
    regex reg9("a(\\D)*a");
    string data9 = "a8aavbab2aea";
    auto pos9 = data9.cbegin();
    auto end9 = data9.cend();
    smatch m9;
    for (; regex_search(pos9, end9, m9, reg9); pos9 = m9.suffix().first - 1)
    {
        cout << "match:  " << m9.str() << endl;
    }
    cout << "----------------" << endl;
    //10
    cout << "10" << endl;
    regex reg10("a([a-z]+?)a");
    string data10 = "aabbaaccaa";
    auto pos10 = data10.cbegin();
    auto end10 = data10.cend();
    smatch m10;
    for (; regex_search(pos10, end10, m10, reg10); pos10 = m10.suffix().first - 1)
    {
        cout << "match:  " << m10.str() << endl;
    }
    cout << "----------------" << endl;
    //11-12 в примерах 
    
    //para primer
    cout << "examp para" << endl;
    regex reg11("(\\+|\\-|\\d)\\d*(\\.)\\d+");
    string data11= "a-24.3d4a3.3a+9.877";
    auto pos11 = data11.cbegin();
    auto end11 = data11.cend();
    smatch m11;
    for (; regex_search(pos11, end11, m11, reg11); pos11 = m11.suffix().first)
    {
        cout << "match:  " << m11.str() << endl;
    }
    cout << "----------------" << endl;
}