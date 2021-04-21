#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;
namespace ariel
{

    class NumberWithUnits
    {

    private:
        double amount;
        string unit;

    public:
        NumberWithUnits(double amount, string unit)
        {
            this->amount = amount;
            this->unit = unit;
        }

        NumberWithUnits() {
            amount = 0;
            unit = " ";
        }

        static void read_units(ifstream &file);

        //Operators +, (+), +=, -, (-), -= .
        NumberWithUnits operator+(const NumberWithUnits &n1) const;
        NumberWithUnits operator+() const;
        NumberWithUnits &operator+=(const NumberWithUnits &n1);
        NumberWithUnits operator-() const;
        NumberWithUnits operator-(const NumberWithUnits &n) const;
        NumberWithUnits &operator-=(const NumberWithUnits &n1);
        
        //Operators ++, -- .
        const NumberWithUnits& operator++(); //prefix
        NumberWithUnits operator++(int); //postfix
        const NumberWithUnits& operator--(); //prefix
        NumberWithUnits operator--(int); //postfix


        //Operators >, <, >=, <=, ==, != .
        bool operator>(const NumberWithUnits &num1) const;
        bool operator<(const NumberWithUnits &num1) const;
        bool operator>=(const NumberWithUnits &num1) const;
        bool operator<=(const NumberWithUnits &num1) const;
        bool operator==(const NumberWithUnits &num1) const;
        bool operator!=(const NumberWithUnits &num1) const;

        //Operators *, *= --> We write twice this operators so we can multiple from each side (because of the double).
        friend NumberWithUnits operator*(double num, const NumberWithUnits &num1);
        friend NumberWithUnits operator*(const NumberWithUnits &num1, double num);
        friend NumberWithUnits operator*=(double num, const NumberWithUnits &num1);
        friend NumberWithUnits operator*=(const NumberWithUnits &num1, double num);

        //Input & Output operations.
        friend ostream& operator<<(ostream &os, const NumberWithUnits &num);
        friend istream& operator>>(istream &is, NumberWithUnits &num);
    };

}