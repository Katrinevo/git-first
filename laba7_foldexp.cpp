#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <set>

#include "krat.h"
//1
template<typename R, typename ... Ts>
auto match (const R& range, Ts ... ts)
{
 return (count(begin(range), end(range), ts) + ...); 
}
//3
template <typename T, typename ... Ts>
bool within(T min, T max, Ts ...ts)
{
    return ((min <= ts) || (ts <= max) || ...);
}
//2
template <typename T, typename ... Ts>
bool insert_check(T& set, Ts ... ts)
{
    return (set.insert(ts).second && ...);
}
//4
template <typename T, typename ... Ts>
void insert_all(std::vector<T>& vec, Ts ... ts)
{
    (vec.push_back(ts), ...);
}

int main()
{
    
    vector<KRat> v{ KRat(5), KRat(6,88), KRat(1,32) }; 
    int first = match(v, KRat(2,9), KRat(1, 1), KRat(1, 4));
    cout << first << endl << "------" << endl;

    cout << KRat(1, 1) << " " << KRat(2, 1) << " " << KRat(25, 5) << " " << KRat(12, 4) << endl;
    bool second = within(KRat(1,1), KRat(2,1), KRat(25,5), KRat(12,4)); //min max

    cout << second << endl << "------" << endl;

    set <KRat> s{ KRat(5,4), KRat(1,2) }; //false если уже есть
    bool third = insert_check(s, KRat(0, 4), KRat(1, 3));
    cout << third << endl << "------" << endl;


    insert_all(v, KRat(2, 9), KRat(1, 4), KRat(8, 7));
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";  
    }
     return 0;
}