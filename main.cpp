#include "src/image.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	if(argc < 1){
		cout<<"Input nama file: './main filepath'";
		return 0;
	}
	char* path = argv[1];
	Image image(path);
	return 0;
}