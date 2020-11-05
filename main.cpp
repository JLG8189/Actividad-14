#include <iostream>
#include "arregloDinamico.h"
#include "computadora.h"
using namespace std;

int main()
{
    ArregloDinamico<Computadora> compu;

    Computadora c01("Windows", "Pc01", 750, 8);
    Computadora c02("MacOS", "Pc02", 1000, 12);
    Computadora c03("Windows", "Pc03", 2000, 16);
    Computadora c04("Windows", "Pc04", 250, 2);

    compu << c01 << c02 << c03 << c04;
    Computadora c05("Windows", "Pc05", 500, 4);

    Computadora *ptr = compu.buscar(c02);    

    if (ptr != nullptr)
    {
        cout << *ptr << endl;
    }
    else
    {
        cout << "No existe" << endl;
    }

    ArregloDinamico<Computadora*> ptrs = compu.buscar_todos(c05);

    if (ptrs.size() > 0)
    {
        for (size_t i = 0; i < ptrs.size(); i++)
        {
            Computadora *c = ptrs[i];
            cout << *c << endl;
        }
    }
    else
    {
        cout << "No existen coincidencias" << endl;
    }
    
    
    /*ArregloDinamico<string> arreglo;

    arreglo.insertar_inicio("Dos");
    arreglo.insertar_inicio("Uno");
    arreglo.insertar_final("Tres");
    arreglo.insertar_final("Cuatro");

    for (size_t i = 0; i < arreglo.size(); i++)
    {
        cout << arreglo[i] << " ";
    }

    cout << endl;

    arreglo.insertar("Cinco", 2);

    for (size_t i = 0; i < arreglo.size(); i++)
    {
        cout << arreglo[i] << " ";
    }

    cout << endl;

    arreglo.eliminar_inicio();
    arreglo.eliminar_final();
    arreglo.eliminar(1);

    for (size_t i = 0; i < arreglo.size(); i++)
    {
        cout << arreglo[i] << " ";
    }

    cout << endl;

    string *v = arreglo.buscar("Dos");
    cout << v << " " << *v << endl;
    *v = "Caca";
    for (size_t i = 0; i < arreglo.size(); i++)
    {
        cout << arreglo[i] << " ";
    }

    cout << endl;*/

    return 0;
}