#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <type_traits> 
#include <vector>
#include <numbers>
#include <iomanip>

#include <cmath>

#define _USE_MATH_DEFINES // for C++  
 
#include <math.h>  

using namespace std;
using namespace std::numbers;

template <typename _F, typename _G, typename _G2, typename _G1, typename _G11>
class AppFtoG
{
public:
	AppFtoG(_F _f, _G _g, _G2 _g2, _G1 _g1, _G11 _g11) : f(_f), g(_g), g2(_g2), g1(_g1), g11(_g11) { }

	template <typename T>
	auto operator () (T x) { return f(g(g1(x), g2(x)), g11(x)); }

private:
	_F f;
	_G g;
	_G1 g1;
	_G2 g2;
    _G11 g11;

};

class HisFxGx2
{
public:
	template <typename _F, typename _G, typename _G2, typename _G1, typename _G11>
	auto operator () (_F _f, _G _g, _G2 _g2, _G1 _g1, _G11 _g11) { return AppFtoG<_F, _G, _G2, _G1, _G11>(_f, _g, _g2, _g1, _g11); }
};

struct FO_f
{
	template <typename T>
	T operator () (T x, T y) const { return x + y; }
};
struct FO_g
{
	template <typename T>
	T operator () (T x, T y) const { return x * y; }
};

struct FO_g2
{
	template <typename T>
	T operator () (T x) const { return x; }
};
struct FO_g1
{
	template <typename T>
	T operator () (T x) const { return pow(2, x); }
};
struct FO_g11
{
	template <typename T>
	T operator () (T x) const { return 3*x; }
};


int main()
{ 
	// без []
	HisFxGx2 hxx;
	auto result = hxx(FO_f(), FO_g(), FO_g2(), FO_g1(), FO_g11());
	cout << "b) h(x)= " << result(1) << endl << "-----" << endl;
	// с []

	auto composeHisFxGx = [](auto _f, auto _g, auto _g2, auto _g1, auto _g11)->auto
		{ return [_f, _g, _g2, _g1, _g11](auto x) { return _f(_g(_g1(x), _g2(x)), _g11(x)); }; };
	auto f = [](auto x, auto y) { return x + y; };
	auto g = [](auto x, auto y) { return x * y; };
	auto g1 = [](auto x) {return x * x; };
	auto g2 = [](auto x) { return x; };
	auto g11 = [](auto x) {return 3*x; };

	auto result2 = composeHisFxGx(f, g, g1, g2, g11);
	auto a = result2(1.0);
	cout << "a) h(x)= " << result2(1) << endl;
	return 0;
}