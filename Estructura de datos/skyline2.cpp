#include <iostream>
#include <string>

using namespace std;

int skylineheight(int a[5][6], int fila, int columna, int end = 0, int start = 0, int regresaColumna = 0)
{
    int siguenteColumna;

    if (start > end)
    {
        return -1;
    }
    if (end == 0)
    {
        end = 5;
    }
    
    int enmedio = ((start + end) / 2);
    bool existe = false;

    for(int i = 0; i < columna; i++)
    {
        if (a[enmedio][i] == 0)
        {
            existe = true;
            if (enmedio == 0)
            {
                return i;
            }
            int siguenteColumna = skylineheight(a, fila, columna, enmedio, start, regresaColumna);
            if (siguenteColumna < 0)
            {
                regresaColumna = i;
            }
            else
            {
                regresaColumna = siguenteColumna;
                break;
            }
        }
    }
    if (!existe && ((enmedio + end) / 2) == enmedio)
    {
        return -1;
    }
    if (existe)
    {
        return regresaColumna;
    }
    return skylineheight(a, fila, columna, end, enmedio, regresaColumna);
}


int main()
{
    int skyline[5][6] = {
        {1, 1, 1, 0, 1, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1}
    };
    cout << skylineheight(skyline, 5, 6) << endl;
}