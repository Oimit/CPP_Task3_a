#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"
using namespace std;
namespace ariel
{

    void NumberWithUnits::read_units(ifstream &file)
    {
        ifstream units_file{"units.txt"};
        
    }

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &n1) const
    {
        return n1;
    }

    NumberWithUnits NumberWithUnits::operator+() const
    {
        return *this;
    }

    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits &a)
    {
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &n1) const
    {
        return n1;
    }

    NumberWithUnits NumberWithUnits::operator-() const
    {
        NumberWithUnits res = *this;
        res.amount = -res.amount;
        
        return res;
    }

    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits &a)
    {
        return *this;
    }

     const NumberWithUnits &NumberWithUnits:: operator++()
    {
        amount += 1;
        return *this;
    }
    
   NumberWithUnits NumberWithUnits::operator++(int)
    {
        NumberWithUnits temp(*this);
        amount = amount +1;
        return temp;
    }

     const NumberWithUnits &NumberWithUnits:: operator--()
    {
        amount -= 1;
        return *this;
    }

   NumberWithUnits NumberWithUnits::operator--(int)
    {
        NumberWithUnits temp(*this);
        amount = amount -1;
        return temp;
    }

    bool NumberWithUnits::operator>(const NumberWithUnits &a) const
    {
        return true;
    }

    bool NumberWithUnits::operator<(const NumberWithUnits &num1) const
    {
        return true;
    }

    bool NumberWithUnits::operator>=(const NumberWithUnits &num1) const
    {
        return true;
    }

    bool NumberWithUnits::operator<=(const NumberWithUnits &num1) const
    {
        return true;
    }

    bool NumberWithUnits::operator==(const NumberWithUnits &num1) const
    {
        return true;
    }

    bool NumberWithUnits::operator!=(const NumberWithUnits &num1) const
    {
        return true;
    }

    NumberWithUnits operator*(double num, const NumberWithUnits &num1)
    {
        NumberWithUnits res = num1;
        res.amount = num*res.amount;
        return res;
    }

    NumberWithUnits operator*(const NumberWithUnits &num1, double num)
    {
        return num1;
    }

    NumberWithUnits operator*=(double num, const NumberWithUnits &num1)
    {
        return num1;
    }

    NumberWithUnits operator*=(const NumberWithUnits &num1, double num)
    {
        return num1;
    }

    ostream &operator<<(ostream &os, const NumberWithUnits &num)
    {
        return os << num.amount << "[" << num.unit << "]";
    }

    istream &operator>>(istream &is, NumberWithUnits &num)
    {
        return is;
    }
}