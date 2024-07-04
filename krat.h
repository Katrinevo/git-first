#pragma once
#ifndef KRatH
#define KRatH
//---------------------------------------------------------------------------
#include <iostream>
#include <exception>
#include <assert.h>
#include <cmath>

using namespace std;

class KRat
{
public:
	friend class KNumProxy;
	explicit KRat(int aNum = 0, int aDenom = 1) : fNum(aNum), fDenom(aDenom)
	{
		if (fDenom == 0)
			throw invalid_argument("Denominator equals zero");
		Normalize();
	}

	//KRat() : fNum(0), fDenom(1) { }
	//explicit KRat(int aNum) : fNum(aNum), fDenom(1) { }
	///*explicit*/ KRat(int aNum, int aDenom) : fNum(aNum), fDenom(aDenom) { Normalize(); }
	~KRat() { }
	// Accessors
	int& Numerator() { return fNum; }
	const int& Numerator() const { return fNum; }
	int& Denominator() { return fDenom; }   // ������� ���������
	const int& Denominator() const { return fDenom; }

	KRat& operator += (const KRat& r);
	KRat& operator += (int a);
	KRat& operator -= (const KRat& r);
	KRat& operator -= (int a);
	KRat& operator *= (const KRat& r);
	KRat& operator *= (int a);
	KRat& operator /= (const KRat& r);
	KRat& operator /= (int a);

	KRat& operator=(int a) {
		fNum = a;
		fDenom = 1;
		return *this;
	}

	inline KRat& operator ++ ();     //prefix
	inline KRat const operator ++ (int);  //postfix
	inline KRat& operator -- ();     //prefix
	inline KRat const operator -- (int);  //postfix

	inline KRat const operator + (KRat const& r) const;   // ������������ const, ����� ����������� r1+r2=r3
	inline KRat const operator + (int a) const;
	friend inline KRat const operator + (int a, KRat const& r2);
	inline KRat const operator - (KRat const& r) const;
	inline KRat const operator - (int a) const;
	friend inline KRat const operator - (int a, KRat const& r2);
	inline KRat const operator * (KRat const& r) const;
	inline KRat const operator * (int a) const;
	friend inline KRat const operator * (int a, KRat const& r2);
	inline KRat const operator / (KRat const& r) const;
	inline KRat const operator / (int a) const;
	friend inline KRat const operator / (int a, KRat const& r2);
	bool operator < (KRat const& r) const;
	bool operator < (int a) const;
	friend bool operator < (int a, KRat const& r2);
	bool operator > (KRat const& r) const;
	bool operator > (int a) const;
	friend bool operator > (int a, KRat const& r2);
	bool operator >= (KRat const& r) const;
	bool operator >= (int a) const;
	friend bool operator >= (int a, KRat const& r2);
	bool operator <= (KRat const& r) const;
	bool operator <= (int a) const;
	friend bool operator <= (int a, KRat const& r2);
	bool operator == (KRat const& r) const;
	bool operator == (int a) const;
	friend bool operator == (int a, KRat const& r2);


	explicit operator double() const { return (double)fNum / fDenom; }   // �� �� ������ ������ ����������

	friend        std::istream& operator >> (std::istream& is, KRat& r);
	friend inline std::ostream& operator << (std::ostream& os, const KRat& r);

private:
	static int GCD(int, int); //���
	void Normalize();

private:
	int fNum;
	int fDenom;
};    // end of KRat

//----------------------------- inline implementation --------------------------


//------------------------------------------------------------------------------

inline KRat& KRat::operator ++ ()     //prefix
{
	fNum += fDenom;
	return *this;
	//return *this+=KRat(1);
}
//------------------------------------------------------------------------------

inline KRat const KRat::operator ++ (int)  //postfix
{
	KRat r = *this;
	++*this;
	return r;
}

//------------------------------------------------------------------------------

inline KRat& KRat::operator -- ()     //prefix
{
	fNum -= fDenom;
	return *this;
	//return *this+=KRat(1);
}
//------------------------------------------------------------------------------

inline KRat const KRat::operator -- (int)  //postfix
{
	KRat r = *this;
	--*this;
	return r;
}

//--------------------------- Friends ------------------------------------------



//------------------------------------------------------------------------------

inline KRat const KRat::operator + (KRat const& r) const
{
	KRat result(fNum * r.fDenom + r.fNum * fDenom, fDenom * r.fDenom);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const KRat::operator + (int a) const
{
	KRat result(fNum + a * fDenom, fDenom);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const  operator + (int a, KRat const& r2)
{
	KRat result(a * r2.fDenom + r2.fNum, r2.fDenom);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const KRat::operator - (KRat const& r) const
{
	KRat result(fNum * r.fDenom - r.fNum * fDenom, fDenom * r.fDenom);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const KRat::operator - (int a) const
{
	KRat result(fNum - a * fDenom, fDenom);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const  operator - (int a, KRat const& r2)
{
	KRat result(a * r2.fDenom - r2.fNum, r2.fDenom);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const KRat::operator * (KRat const& r) const
{
	KRat result(fNum * r.fNum, fDenom * r.fDenom);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const KRat::operator * (int a) const
{
	KRat result(fNum * a, fDenom);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const  operator * (int a, KRat const& r2)
{
	KRat result(a * r2.fNum, r2.fDenom);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const KRat::operator / (KRat const& r) const
{
	KRat result(fNum * r.fDenom, fDenom * r.fNum);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const KRat::operator / (int a) const
{
	KRat result(fNum, fDenom * a);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline KRat const  operator / (int a, KRat const& r2)
{
	KRat result(a * r2.fDenom, r2.fNum);
	result.Normalize();
	return result;
}
//------------------------------------------------------------------------------

inline std::ostream& operator << (std::ostream& os, const KRat& r)
{
	KRat r1 = r;
	r1.Normalize();
	os << r1.fNum;
	if (1 != r1.fDenom)
		os << '/' << r1.fDenom;
	return os;
}






//------------------------------------------------------------------------------

inline std::istream& operator >> (std::istream& is, KRat& r)
{
	is >> r.fNum >> r.fDenom;
	return is;
}

KRat& KRat::operator += (const KRat& r) {
	*this = *this + r;
	return *this;
}
KRat& KRat::operator += (int a) {
	*this = *this + KRat(a);
	return *this;
}
KRat& KRat::operator -= (const KRat& r) {
	*this = *this - r;
	return *this;
}
KRat& KRat::operator -= (int a) {
	*this = *this - KRat(a);
	return *this;
}
KRat& KRat::operator *= (const KRat& r) {
	*this = *this * r;
	return *this;
}
KRat& KRat::operator *= (int a) {
	*this = *this * KRat(a);
	return *this;
}
KRat& KRat::operator /= (const KRat& r) {
	*this = *this / r;
	return *this;
}
KRat& KRat::operator /= (int a) {
	*this = *this / KRat(a);
	return *this;
}

int KRat::GCD(int a, int b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}


void KRat::Normalize() {
	int k = abs(GCD(fNum, fDenom));
	fNum /= k;
	fDenom /= k;
	if (fDenom < 0) {
		fNum *= -1;
		fDenom *= -1;
	}
}



bool KRat::operator < (KRat const& r) const {
	return fNum * r.fDenom < fDenom * r.fNum;
}
bool KRat::operator < (int a) const {
	return fNum < fDenom * a;
}
bool operator < (int a, KRat const& r2) {
	return a * r2.fDenom < r2.fNum;
}
bool KRat::operator > (KRat const& r) const {
	return fNum * r.fDenom > fDenom * r.fNum;
}
bool KRat::operator > (int a) const {
	return fNum > fDenom * a;
}
bool operator > (int a, KRat const& r2) {
	return a * r2.fDenom > r2.fNum;
}
bool KRat::operator >= (KRat const& r) const {
	return !(*this < r);
}
bool KRat::operator >= (int a) const {
	return !(*this < a);
}
bool operator >= (int a, KRat const& r2) {
	return !(a < r2);
}
bool KRat::operator <= (KRat const& r) const {
	return !(*this > r);
}
bool KRat::operator <= (int a) const {
	return !(*this > a);
}
bool operator <= (int a, KRat const& r2) {
	return !(a > r2);
}
bool KRat::operator == (KRat const& r) const {
	return fNum == r.fNum && fDenom == r.fDenom;
}
bool KRat::operator == (int a) const {
	return a * fDenom == fNum;
}
bool operator == (int a, KRat const& r2) {
	return a * r2.fDenom == r2.fNum;
}

#endif

