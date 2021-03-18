#include <fstream>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using namespace std;

#include <math.h>
#include <stdlib.h>

void readArr(int, int, double **);
void multArrs(int, double **, int, double **, int, double **);
int nonZerosTotal(int r, int c, double **arr);
int nonZerosRow(int r, int c, double **arr);

int main(int argc, char *argv[])
{
    int ar = atoi(argv[1]); // ar is array A row size
    int ac = atoi(argv[2]); // ac is array A column size
    int nz = 0;
    // reserve space for the three arrays
    double **A = new double *[ar]; // each el. of this points to a row of A
    for (int i = 0; i < ar; i++)
        A[i] = new double[ac]; // a row of 'ac' floats

    readArr(ar, ac, A);
    int col = 0;
    cout << ar << "\n";
    for (int i = 0; i < ar; i++)
    {
        cout << nonZerosRow(i, ac, A);

        for (int j = 0; j < ac; j++)
        {
            if (A[i][j] != 0)
            {
                cout << " " << j + 1 << " " << A[i][j];
                nz++;
            }

            if (j == ac - 1)
            {
                cout << "\n";
            }
        }
    }
    cout << nz << "\n";
}

void readArr(int r, int c, double **arr)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int nonZerosRow(int r, int c, double **arr)
{
    int nonZerosRowCounter = 0;
    for (int j = 0; j < c; j++)
    {
        if (arr[r][j] != 0)
        {
            nonZerosRowCounter++;
        }
    }
    return nonZerosRowCounter;
}
