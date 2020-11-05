#include "computadora.h"

Computadora::Computadora()
{

}

Computadora::Computadora(const string &sistema, const string &nombre, int almac, int ram)
{
    this->sistema = sistema;
    this->nombre = nombre;
    this->almac = almac;
    this->ram = ram;
}

void Computadora::setSistema(const string &v)
{
    sistema = v;
}

string Computadora::getSistema()
{
    return sistema;
}

void Computadora::setNombre(const string &v)
{
    nombre = v;
}

string Computadora::getNombre()
{
    return nombre;
}

void Computadora::setAlmac(int v)
{
    almac = v;
}

float Computadora::getAlmac()
{
    return almac;
}

void Computadora::setRam(int v)
{
    ram = v;
}

int Computadora::getRam()
{
    return ram;
}