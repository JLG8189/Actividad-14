#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
#include <iomanip>
using namespace std;

class Computadora
{
    string sistema;
    string nombre;
    int almac;
    int ram;

public:
    Computadora();
    Computadora(const string &sistema, const string &nombre, int almac, int ram);
    void setSistema(const string &v);
    string getSistema();
    void setNombre(const string &v);
    string getNombre();
    void setAlmac(int v);
    float getAlmac();
    void setRam(int v);
    int getRam();

    friend ostream& operator<< (ostream &out, const Computadora &c)
    {
        out << left;
        out << setw(10) << c.sistema;
        out << setw(10) << c.nombre;
        out << setw(17) << c.almac;
        out << setw(6) << c.ram;
        out << endl;
        return out;
    }

    friend istream& operator>>(istream &in, Computadora &c)
    {
        cout << "Sistema: ";
        getline(cin, c.sistema);

        cout << "Nombre: ";
        getline(cin, c.nombre);
        
        cout << "Almacenamiento: ";
        cin >> c.almac;

        cout << "Ram: ";
        cin >> c.ram;
        return in;
    }

    bool operator==(const Computadora& c)
    {
        return sistema == c.sistema;
    }
    bool operator==(const Computadora& c) const
    {
        return sistema == c.sistema;
    }

};

#endif