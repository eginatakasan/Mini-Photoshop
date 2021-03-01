#include "ExternalFile.h"
#include <msclr\marshal_cppstd.h>
#include <string.h>
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace Microsoft::VisualBasic;
using namespace std;
using namespace msclr::interop;

Bitmap^ Image_BitmapFile(String^ path) {
	Image^ image = Image::FromFile(path);
	
	return gcnew Bitmap(image);
}

Bitmap^ Image_PGMFile(String^ path) {
	//Image^ image = Image::FromFile(path);
	//return gcnew Bitmap(image);

	//[Example Crate Bitmap]
	// Create Array RGB
	double fileWidth = 100;
	double fileHeight = 100;
	int** arrayRed = new int* [fileWidth];
	int** arrayGreen = new int* [fileWidth];
	int** arrayBlue = new int* [fileWidth];
	for (int i = 0; i < fileWidth; i++) {
		arrayRed[i] = new int[fileHeight];
		arrayGreen[i] = new int[fileHeight];
		arrayBlue[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			if (x > 50) {
				arrayRed[x][y] = 40;
				arrayGreen[x][y] = 20;
				arrayBlue[x][y] = 10;
			}
			else if (y < 50) {
				arrayRed[x][y] = 10;
				arrayGreen[x][y] = 20;
				arrayBlue[x][y] = 100;
			}
			else {
				arrayRed[x][y] = 30;
				arrayGreen[x][y] = 80;
				arrayBlue[x][y] = 80;
			}
			
		}
	}

	//Create Bitmap
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y];
			int pxl_Green = arrayGreen[x][y];
			int pxl_Blue = arrayBlue[x][y];
			int pxl_Grey = (pxl_Red + pxl_Green + pxl_Blue) / 3;

			Color pxl = Color::FromArgb(pxl_Grey, pxl_Grey, pxl_Grey);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_PBMFile(String^ path) {
	Image^ image = Image::FromFile(path);

	return gcnew Bitmap(image);
}

Bitmap^ Image_PPMFile(String^ path) {
	Image^ image = Image::FromFile(path);

	return gcnew Bitmap(image);
}

Bitmap^ Image_RawImageFile(String^ path) {
	Image^ image = Image::FromFile(path);

	return gcnew Bitmap(image);
}