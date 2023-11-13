#include <stdio.h>
#define N 4

/*
Búsqueda de una solución
Proc buscar_una_solución(paso : T)
Inicio
    inicializar_alternativas
    Mientras (alternativas ∧ ¬solución_encontrada) Hacer
        backtracking (x+1, y)
        backtracking (x, y+1)
        Si es_alternativa_valida Entonces
            almacenar_paso
            Si es_solución Entonces
                solución_encontrada ß Verdadero
                procesar_solución
            Sino
            buscar_una_solución(nuevo_paso)
                Si ¬ solución_encontrada Entonces
                    borrar_paso
                Fsi
            Fsi
        Fsi
    Fmientras
Finproc
*/

void procesar_solucion(int solucion[N][N])
{
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", solucion[i][j]);
        }
        printf("\n");
    }
}

int es_solucion(int x, int y)
{
    return x == N - 1 && y == N - 1;
}

int es_alternativa_valida(int laberinto[N][N], int x, int y)
{
   return x >= 0 && x < N && y >= 0 && y < N && laberinto[x][y] == 1;
}

void buscar_una_solucion(int laberinto[N][N], int x, int y, int solucion[N][N], int *solucion_encontrada)
{
    // Inicializar alternativas
    int alternativas[2][2];
    alternativas[0][0] = x;
    alternativas[0][1] = y + 1;
    alternativas[1][0] = x + 1;
    alternativas[1][1] = y;

    // mientras haya alternativas
    for (int i = 0; i < 2 && !(*solucion_encontrada); i++)
    {
        int alt_x = alternativas[i][0];
        int alt_y = alternativas[i][1];
        if (es_alternativa_valida(laberinto, alt_x, alt_y))
        {
            solucion[alt_x][alt_y] = 1;
            if (es_solucion(alt_x, alt_y))
            {
                *solucion_encontrada = 1;
                procesar_solucion(solucion);
            }
            else
            {
                buscar_una_solucion(laberinto, alt_x, alt_y, solucion, solucion_encontrada);
                if (!(*solucion_encontrada))
                {
                    solucion[alt_x][alt_y] = 0;
                }
            }
        }
    }
}

int resolver_laberinto(int laberinto[N][N]) {
    int solucion[N][N] = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    int solucion_encontrada = 0;
    buscar_una_solucion(laberinto, 0, 0, solucion, &solucion_encontrada);
}

int main()
{
    int laberinto[N][N] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 1}};

    resolver_laberinto(laberinto);
}
