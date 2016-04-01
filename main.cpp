#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void parcialito(int arreglo[], int tamanio)
{

}

/*
Leer un archivo con el siguiente formato:
    ejemplo.txt:
    |   N
    |   numero_1 numero_2 ... numero_N

De existir el archivo:
    arreglo = { numero_1, ..., numero_N }
    tamanio = N

IMPORTANTE: No se controla el formato.
*/
bool leer_entrada(string nombre_archivo, int * & arreglo, int & tamanio)
{
    ifstream archivo(nombre_archivo);

    if (!archivo.is_open())
    {
        return false;
    }

    archivo >> tamanio;

    arreglo = new int[tamanio];

    for (int i = 0; i < tamanio; i++)
    {
        archivo >> arreglo[i];
    }

    return true;
}

int main(int argc, char * argv[])
{
    // Si no se pasa un argumento a nuestro programa...
    if (argc != 2)
    {
        // ...explicar como se usa.
        cout << "Uso:" << endl
             << "parcialito.exe <archivo_de_entrada>" << endl;

        return 0;
    }

    string nombre_archivo_entrada = argv[1];
    int * arreglo;
    int tamanio;

    // Leer el archivo de entrada.
    bool error_archivo = !leer_entrada(nombre_archivo_entrada, arreglo, tamanio);
    if (error_archivo)
    {
        cout << "El archivo no se pudo abrir." << endl;
        return 0;
    }

    // Nuestra solucion
    parcialito(arreglo, tamanio);

    return 0;
}
