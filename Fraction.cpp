#include "Fraction.h"

using namespace std;

Fraction::Fraction(int numerateur, int denominateur)
{
    if (denominateur ==0)
    {
        cout << "Error!!! Le denominateur doit étre non nul." << endl;
    }
    else
    {
        if (denominateur > 0)
        {
            m_numerateur = numerateur;
            m_denominateur = denominateur;
        }
        else
        {
            m_numerateur = - numerateur;
            m_denominateur = - denominateur;
        }
    }

    simplifier();
}

Fraction& Fraction::operator+=(Fraction const& f)
{
    m_numerateur = f.m_denominateur * m_numerateur + m_denominateur * f.m_numerateur;
    m_denominateur = m_denominateur * f.m_denominateur;

    simplifier();

    return *this;
}

Fraction& Fraction::operator-=(Fraction const& f)
{
    m_numerateur = f.m_denominateur * m_numerateur - m_denominateur * f.m_numerateur;
    m_denominateur = m_denominateur * f.m_denominateur;

    simplifier();

    return *this;
}

Fraction& Fraction::operator*=(Fraction const& f)
{
    m_numerateur *= f.m_numerateur;
    m_denominateur *= f.m_denominateur;
    simplifier();

    return *this;
}

Fraction& Fraction::operator/=(Fraction const& f)
{
    m_numerateur *= f.m_denominateur;
    m_denominateur *= f.m_numerateur;
    simplifier();

    return *this;
}

ostream& Fraction::afficher(ostream& flux)
{
    flux << m_numerateur << "/" << m_denominateur ;
}

bool Fraction::estEgalA(Fraction const& f) const
{
    return ((m_numerateur*f.m_denominateur - f.m_numerateur* m_denominateur) == 0);
}

bool Fraction::eststrictInferieurA(Fraction const& f) const
{
    return (m_numerateur*f.m_denominateur < f.m_numerateur* m_denominateur);
}

void Fraction::simplifier()
{
    int pgcd = calculerPGCD(m_numerateur, m_denominateur);
    m_numerateur /= pgcd;
    m_denominateur /= pgcd;
}

int Fraction::numerateur() const
{
    return m_numerateur;
}

int Fraction::denominateur() const
{
    return m_denominateur;
}

double Fraction::nombreReel() const
{
    double n = m_numerateur;
    double d = m_denominateur ;

    return n/d;
}

ostream& operator<<(ostream& flux, Fraction f)
{
    f.afficher(flux);
    return flux;
}

Fraction operator+(Fraction const& a, Fraction const& b)
{
    Fraction copie(a);
    copie += b;
    return copie;
}

Fraction operator-(Fraction const& a, Fraction const& b)
{
    Fraction copie(a);
    copie -= b;
    return copie;
}

Fraction operator-(Fraction const& a)
{
    Fraction fractionNulle(0, 1);
    fractionNulle -= a;
    return fractionNulle;
}

Fraction operator*(Fraction const& a, Fraction const& b)
{
    Fraction copie(a);
    copie *= b;
    return copie;
}

Fraction operator/(Fraction const& a, Fraction const& b)
{
    Fraction copie(a);
    copie /= b;
    return copie;
}

bool operator==(Fraction const& a, Fraction const& b)
{
    return a.estEgalA(b);
}

bool operator!=(Fraction const& a, Fraction const& b)
{
    return !(a==b);
}

bool operator<(Fraction const& a, Fraction const& b)
{
    return a.eststrictInferieurA(b);
}

bool operator<=(Fraction const& a, Fraction const& b)
{
    return (a<b || a==b);
}

bool operator>=(Fraction const& a, Fraction const& b)
{
    return !(a<b);
}

bool operator>(Fraction const& a, Fraction const& b)
{
    return !(a<=b);
}

Fraction abs(Fraction const& f)
{
    Fraction fractionNulle, copie(f), fractionMoinsUn(-1);
    if (f < fractionNulle)
        copie *= fractionMoinsUn;

    return copie;
}

Fraction sqrt(Fraction const& f)
{
    double reel = sqrt(f.nombreReel());

    return Fraction(reelToFraction(reel));
}

Fraction reelToFraction(double reel)
{
    int const precision = 1000000000;

    int partieEntiere = reel;
    int partieDecimale = (reel - partieEntiere)*precision;

    Fraction fraction1(partieEntiere);
    Fraction fraction2(partieDecimale, precision);

    return fraction1 + fraction2;
}

Fraction pow(Fraction const& f, int puissance)
{
    return Fraction(pow(f.numerateur(), puissance), pow(f.denominateur(), puissance));
}

// Fonctions annexes -------------------------------------------

int calculerPGCD(int a, int b)
{
    a = fabs(a);
    b = fabs(b);

    int x, r;
    if (b<=a)
    {
        x = a;
        r = b;
    }
    else
    {
        x = b;
        r = a;
    }

    // Récursivité
    if (r==0)
        return x;
    else
        return calculerPGCD(r, x%r);
}
