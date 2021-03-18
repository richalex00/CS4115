#include <fstream>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::stringstream;

#include <math.h>
#include <stdlib.h>
#include <sstream>
#include <list>
#include <string>

// forward declaration
void compressMat();

void compressMat(double epsilon)
{

    int ctr_c = 0;

    int ctr_r = 0;

    string line;

    while (getline(cin, line))
    {
        std::istringstream lstream(line);
        double val;
        while (lstream >> val)
        {
            if (epsilon == NULL)
            {
                if (val == 0)
                {
                }

                else
                {

                    cout << ctr_c + 1 << " " << val << " ";
                }
            }

            else
            {
                if (fabs(val) <= epsilon)
                {
                }
                else
                {
                    cout << ctr_c + 1 << " " << val << " ";
                }
            }
            ctr_c++;
        }
        ctr_c = 0;
        cout << "\n";
        ctr_r++;
    }
}
int main(int argc, char *argv[])
{

    double epsilon;
    if (argc > 1 && string(argv[1]) == "-e")
    {
        epsilon = fabs(strtod(argv[2], 0));
        compressMat(epsilon);
    }
    else
    {
        compressMat(NULL);
    }
}