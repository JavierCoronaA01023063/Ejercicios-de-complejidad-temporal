#include <iostream>
using namespace std;
#include <string>

int skylineheight(int a[][6], int numFila, int numCol, int columna = 0, int fila = 0)
{
    if (a[fila][columna] == 0)
        return columna;
    else if(numFila < columna || numCol < fila)
        return -1;
    if (columna == numCol-1)
       return skylineheight(a, numFila, numCol, 0, fila += 1);
    if (a[fila][columna] != 0)
       return skylineheight(a, numFila, numCol, columna += 1, fila);
    return 0;
}

 
int main(int argc, char const *argv[])
{
    int skyline [5][6] = {
        {1, 1, 1, 0, 1, 1},
        {1, 1, 0, 0, 0, 1}, 
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1}
        };
    cout << skylineheight(skyline, 6, 5) << endl;
    return 0;
}

