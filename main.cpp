#include "src/ppm.h"
#include "src/pgm.h"
#include "src/pbm.h"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
	if (argc < 1)
	{
		cout << "Input nama file: './main filepath'" << endl;
		return 0;
	}
	char *path = argv[1];
	PBM ppm = PBM(path);

	ppm.ShowDetails(true);

	return 0;
}