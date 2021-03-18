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
#include <sstream>

void printMatrix(double);

int main(int argc, char *argv[])
{
    double e = 0;

    if (argc > 1 && string(argv[1]) == "-e")
    {
        e = fabs(strtod(argv[2], 0));
        printMatrix(e);
    }
    else
    {
        printMatrix(e);
    }
}

void printMatrix(double e)
{
    int c = 0;
    string line;
    while (getline(cin, line))
    {
        std::istringstream lstream(line);
        double val;

        while (lstream >> val)
        {
            if (e == 0 && val != 0)
            {
                cout << c + 1 << " " << val << " ";
            }
            else if (fabs(val) > e)
            {
                cout << c + 1 << " " << val << " ";
            }
            c++;
        }
        c = 0;
        cout << "\n";
    }
}
