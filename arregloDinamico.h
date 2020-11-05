#ifndef ARREGLODINAMICO_H
#define ARREGLODINAMICO_H

#include <iostream>
using namespace std;

template <class T>
class ArregloDinamico
{
    T *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX = 6;

public:
    ArregloDinamico();
    ~ArregloDinamico();
    void insertar_final(const T& v);
    void insertar_inicio(const T& v);
    void insertar(const T& v, size_t p);

    void eliminar_final();
    void eliminar_inicio();
    void eliminar(size_t p);

    T* buscar(const T& v);
    ArregloDinamico<T*> buscar_todos(const T& v);

    size_t size();
    T operator[](size_t p)
    {
        return arreglo[p];
    }

    friend ArregloDinamico<T>& operator<<(ArregloDinamico<T> &a, const T& v)
    {
        a.insertar_final(v);
        return a;
    }

private:
    void expandir();
};

template <class T>
ArregloDinamico<T>::ArregloDinamico()
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template <class T>
ArregloDinamico<T>::~ArregloDinamico()
{
    delete[] arreglo;
}

template <class T>
void ArregloDinamico<T>::insertar_final(const T& v)
{
    if (cont == tam)
    {
        expandir();
    }
    arreglo[cont] = v;
    cont++;
}

template <class T>
void ArregloDinamico<T>::insertar_inicio(const T& v)
{
    if (cont == tam)
    {
        expandir();
    }
    for(size_t i = cont; i > 0; i--)
    {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[0] = v;
    cont++;
}

template <class T>
void ArregloDinamico<T>::insertar(const T& v, size_t p)
{
    if (p >= cont)
    {
        cout << "Posición no valida" << endl;
        return;
    }
    if (cont == tam)
    {
        expandir();
    }
    for (size_t i = cont; i > p; i--)
    {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[p] = v;
    cont++;
}

template <class T>
void ArregloDinamico<T>::eliminar_final()
{
    if (cont == 0)
    {
        cout << "Arreglo vacio" << endl;
        return;
    }
    cont--;
}

template <class T>
void ArregloDinamico<T>::eliminar_inicio()
{
    if (cont == 0)
    {
        cout << "Arreglo vacío" << endl;
        return;
    }
    for (size_t i = 0; i < cont-1; i++)
    {
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template <class T>
void ArregloDinamico<T>::eliminar(size_t p)
{
    if (cont == 0)
    {
        cout << "Arreglo vacío" << endl;
        return;
    }
    for (size_t i = p; i < cont - 1; i++)
    {
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template <class T>
T* ArregloDinamico<T>::buscar(const T& v)
{
    for (size_t i = 0; i < cont; i++)
    {
        if (v == arreglo[i])
        {
            return &arreglo[i];
        }   
    }
    return nullptr;
}

template <class T>
ArregloDinamico<T*> ArregloDinamico<T>::buscar_todos(const T& v)
{
    ArregloDinamico<T*> ptrs;
    for (size_t i = 0; i < cont; i++)
    {
        if (v == arreglo[i])
        {
            ptrs.insertar_final(&arreglo[i]);
        }
    }
    return ptrs;
}

template <class T>
size_t ArregloDinamico<T>::size()
{
    return cont;
}

template <class T>
void ArregloDinamico<T>::expandir()
{
    T *nuevo = new T[tam + MAX];

    for (size_t i = 0; i < cont; i++)
    {
        nuevo[i] = arreglo[i];
    }

    delete[] arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

#endif