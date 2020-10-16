#ifndef DEF_FRACTION
#define DEF_FRACTION

#include <iostream>
#include <cmath>

class Fraction
{
    private:
    int m_numerateur;
    int m_denominateur;
    void simplifier();

    public:
    Fraction(int numerateur=0, int denominateur=1);

    std::ostream& afficher(std::ostream& flux);

    Fraction& operator+=(Fraction const& f);
    Fraction& operator-=(Fraction const& f);
    Fraction& operator*=(Fraction const& f);
    Fraction& operator/=(Fraction const& f);

    bool estEgalA(Fraction const& f) const;
    bool eststrictInferieurA(Fraction const& f) const;

    int numerateur() const;
    int denominateur() const;

    double nombreReel() const;
};

std::ostream& operator<<(std::ostream& flux, Fraction f);

Fraction operator+(Fraction const& a, Fraction const& b);
Fraction operator-(Fraction const& a, Fraction const& b);
Fraction operator-(Fraction const& a);
Fraction operator*(Fraction const& a, Fraction const& b);
Fraction operator/(Fraction const& a, Fraction const& b);

bool operator==(Fraction const& a, Fraction const& b);
bool operator!=(Fraction const& a, Fraction const& b);
bool operator<(Fraction const& a, Fraction const& b);
bool operator<=(Fraction const& a, Fraction const& b);
bool operator>(Fraction const& a, Fraction const& b);
bool operator>=(Fraction const& a, Fraction const& b);


Fraction abs(Fraction const& f);
Fraction sqrt(Fraction const& f);
Fraction pow(Fraction const& f, int puissance);

Fraction reelToFraction(double reel);

int calculerPGCD(int a, int b);

#endif // DEF_FRACTION
