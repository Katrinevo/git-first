#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <regex>

using namespace std;

void out(bool b)
{
    cout << (b ? "Вся строка удовлетворяет регулярному выражению" : "Вся строка НЕ удовлетворяет регулярному выражению") << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    //ifstream inputFile("text1.txt"); // text1 full true, text2 full falce, text3 substring
    //string data1;
    //if (inputFile.is_open()) {
    //    //string data1;
    //    locale::global(locale("ru_RU.UTF-8")); // для текста на русском
    //    getline(inputFile, data1); 
    //    
    //    cout << data1 << endl;
    //    inputFile.close();
    //}
    //else {
    //    cout << "Error with oppening file" << endl;
    //}
    //cout << "Изначальная строка: " << data1 << endl << endl;
    //

    string data1; //full true
    string data2; //full falce
    string data3; //substring
    string data4; //not right temp
    data1 = "В прогнозе говорилось, что весна будет холодной, максимальная температура не превысит +10° градусов.";
    data2 = "зима, средняя температура -4";
    data3 = "Осень была холодная,лето было жарким, средняя температура превышала +20°градусов";
    data4 = "В прогнозе говорилось, что зима будет жаркой, максимальная температура не превысит +50° градусов.";

    cout << "Изначальная строка: " << data1 << endl << endl;
    
    regex reg("(((.*)(\\s)+)|(\\s*))((весна)|(лето)|(осень)|(зима))((\\s(.*?)\\s)|(\\s))((максимальная)|(средняя))\\s(температура)((\\s(.*?)\\s)|(\\s)+)((\\+)|(\\-)|(\\s)*)\\d+(°)((\\s+(.*))|(\\s*))");

    //temp
    //regex regtemp1("зима((\\s(.*?)\\s)|(\\s))((максимальная)|(средняя))\\s(температура)((\\s(.*?)\\s)|(\\s)+)((\\+)|(\\s)*)[15-50](°)");
    //bool foundtemp1 = regex_search(data4, regtemp1);
    //if (foundtemp1) {
    //    cout << "Ошибка в температуре";
    //    return 0;
    //}
    //regex regtemp2("весна((\\s(.*?)\\s)|(\\s))((максимальная)|(средняя))\\s(температура)((\\s(.*?)\\s)|(\\s)+)(\\-)[15-50](°)");
    //bool foundtemp2 = regex_search(data1, regtemp2);
    //if (foundtemp2) {
    //    cout << "Ошибка в температуре";
    //    return 0;
    //}
    //regex regtemp3("лето((\\s(.*?)\\s)|(\\s))((максимальная)|(средняя))\\s(температура)((\\s(.*?)\\s)|(\\s)+)(\\-)[0-50](°)");
    //bool foundtemp3 = regex_search(data1, regtemp3);
    //if (foundtemp3) {
    //    cout << "Ошибка в температуре";
    //    return 0;
    //}
    //regex regtemp4("осень((\\s(.*?)\\s)|(\\s))((максимальная)|(средняя))\\s(температура)((\\s(.*?)\\s)|(\\s)+)((\\+)|(\\s)*)[20-50](°)");
    //bool foundtemp4 = regex_search(data1, regtemp4);
    //if (foundtemp4) {
    //    cout << "Ошибка в температуре";
    //    return 0;
    //}
    //
    //search
    auto pos = data1.cbegin();
    auto end = data1.cend();
    smatch m;
    bool found = regex_search(data1, reg);
    cout << "Результат search: ";
    if (found) {
        for (; regex_search(pos, end, m, reg); pos = m.suffix().first)
        {
            cout << m.str() << endl;
        }
    }
    else cout << "Нет такой подстроки" << endl;
    //match
    bool found1 = regex_match(data1, reg);
    cout << "Результат match: ";
    out(found1);
    //

    return 0;
}
