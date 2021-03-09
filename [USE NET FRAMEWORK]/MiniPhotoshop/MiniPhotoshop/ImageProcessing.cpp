#include "ImageProcessing.h"
#include <cmath>
#include "PrimitiveFunction.h"

using namespace std;
using namespace System::Drawing;

Bitmap^ Image_GrayScale(Bitmap^ bmp_input) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}


	//Update
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

Bitmap^ Image_Translate(Bitmap^ bmp_input, int x_trans, int y_trans) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}


	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			if ((x - x_trans) >= 0 && (y - y_trans) >= 0 && (x - x_trans) < fileWidth && (y - y_trans) < fileHeight) {
				int pxl_Red = arrayRed[x - x_trans][y - y_trans];
				int pxl_Green = arrayGreen[x - x_trans][y - y_trans];
				int pxl_Blue = arrayBlue[x - x_trans][y - y_trans];

				Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
				bitmap->SetPixel(x, y, pxl);
			}
			else {
				Color pxl = Color::FromArgb(255, 255, 255);
				bitmap->SetPixel(x, y, pxl);
			}

		}
	}

	return bitmap;
}

Bitmap^ Image_Rotate90(Bitmap^ bmp_input) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}


	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileHeight, fileWidth );
	int k;
	for (int x = 0; x < fileWidth; x++) {
		k = fileHeight - 1;
		for (int y = 0; y < fileHeight; y++) {
			
			int pxl_Red = arrayRed[x][y];
			int pxl_Green = arrayGreen[x][y];
			int pxl_Blue = arrayBlue[x][y];

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(k, x, pxl);
			k = k - 1;

		}
	}

	return bitmap;
}

Bitmap^ Image_NegativeTransformation(Bitmap^ bmp_input) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = 255 - arrayRed[x][y];
			int pxl_Green = 255 - arrayGreen[x][y];
			int pxl_Blue = 255 - arrayBlue[x][y];

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageBrightening_ScalarAddition(Bitmap^ bmp_input, int value) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y] + value;
			int pxl_Green = arrayGreen[x][y] + value;
			int pxl_Blue = arrayBlue[x][y] + value;

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageBrightening_ScalarMultiplication(Bitmap^ bmp_input, int value) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y] * value;
			int pxl_Green = arrayGreen[x][y] * value;
			int pxl_Blue = arrayBlue[x][y] * value;

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageBrightening_LinearFormula(Bitmap^ bmp_input, int multiplier, int constant) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y] * multiplier + constant;
			int pxl_Green = arrayGreen[x][y]  *multiplier + constant;
			int pxl_Blue = arrayBlue[x][y] * multiplier + constant;

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_Arithmethic_Addition(Bitmap^ bmp_input, Bitmap^ bmp_second_input) {
	// SetUp Arr Input
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	// SetUp Arr Second Input
	int** arrayRedSecond = new int* [fileWidth];
	int** arrayGreenSecond = new int* [fileWidth];
	int** arrayBlueSecond = new int* [fileWidth];
	for (int i = 0; i < fileWidth; i++) {
		arrayRedSecond[i] = new int[fileHeight];
		arrayGreenSecond[i] = new int[fileHeight];
		arrayBlueSecond[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_second_input->GetPixel(x, y);
			arrayRedSecond[x][y] = pxl.R;
			arrayGreenSecond[x][y] = pxl.G;
			arrayBlueSecond[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y] + arrayRedSecond[x][y];
			int pxl_Green = arrayGreen[x][y] + arrayGreenSecond[x][y];
			int pxl_Blue = arrayBlue[x][y] + arrayBlueSecond[x][y];

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_Arithmethic_Subtraction(Bitmap^ bmp_input, Bitmap^ bmp_second_input) {
	// SetUp Arr Input
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	// SetUp Arr Second Input
	int** arrayRedSecond = new int* [fileWidth];
	int** arrayGreenSecond = new int* [fileWidth];
	int** arrayBlueSecond = new int* [fileWidth];
	for (int i = 0; i < fileWidth; i++) {
		arrayRedSecond[i] = new int[fileHeight];
		arrayGreenSecond[i] = new int[fileHeight];
		arrayBlueSecond[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_second_input->GetPixel(x, y);
			arrayRedSecond[x][y] = pxl.R;
			arrayGreenSecond[x][y] = pxl.G;
			arrayBlueSecond[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y] - arrayRedSecond[x][y];
			int pxl_Green = arrayGreen[x][y] - arrayGreenSecond[x][y];
			int pxl_Blue = arrayBlue[x][y] - arrayBlueSecond[x][y];

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_Arithmethic_Multiplication(Bitmap^ bmp_input, Bitmap^ bmp_second_input) {
	// SetUp Arr Input
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	// SetUp Arr Second Input
	int** arrayRedSecond = new int* [fileWidth];
	int** arrayGreenSecond = new int* [fileWidth];
	int** arrayBlueSecond = new int* [fileWidth];
	for (int i = 0; i < fileWidth; i++) {
		arrayRedSecond[i] = new int[fileHeight];
		arrayGreenSecond[i] = new int[fileHeight];
		arrayBlueSecond[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_second_input->GetPixel(x, y);
			arrayRedSecond[x][y] = pxl.R;
			arrayGreenSecond[x][y] = pxl.G;
			arrayBlueSecond[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y] * arrayRedSecond[x][y];
			int pxl_Green = arrayGreen[x][y] * arrayGreenSecond[x][y];
			int pxl_Blue = arrayBlue[x][y] * arrayBlueSecond[x][y];

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_Arithmethic_Division(Bitmap^ bmp_input, Bitmap^ bmp_second_input) {
	// SetUp Arr Input
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	// SetUp Arr Second Input
	int** arrayRedSecond = new int* [fileWidth];
	int** arrayGreenSecond = new int* [fileWidth];
	int** arrayBlueSecond = new int* [fileWidth];
	for (int i = 0; i < fileWidth; i++) {
		arrayRedSecond[i] = new int[fileHeight];
		arrayGreenSecond[i] = new int[fileHeight];
		arrayBlueSecond[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_second_input->GetPixel(x, y);
			arrayRedSecond[x][y] = pxl.R;
			arrayGreenSecond[x][y] = pxl.G;
			arrayBlueSecond[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red;
			int pxl_Green;
			int pxl_Blue;
			if (arrayRedSecond[x][y] == 0) {
				pxl_Red = 255;
			}
			else {
				pxl_Red = arrayRed[x][y] / arrayRedSecond[x][y];
			}

			if (arrayGreenSecond[x][y] == 0) {
				pxl_Green = 255;
			}
			else {
				pxl_Green = arrayGreen[x][y] / arrayGreenSecond[x][y];
			}

			if (arrayBlueSecond[x][y] == 0) {
				pxl_Blue = 255;
			}
			else {
				pxl_Blue = arrayBlue[x][y] / arrayBlueSecond[x][y];
			}

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_Boolean_AND(Bitmap^ bmp_input, Bitmap^ bmp_second_input) {
	// SetUp Arr Input
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	// SetUp Arr Second Input
	int** arrayRedSecond = new int* [fileWidth];
	int** arrayGreenSecond = new int* [fileWidth];
	int** arrayBlueSecond = new int* [fileWidth];
	for (int i = 0; i < fileWidth; i++) {
		arrayRedSecond[i] = new int[fileHeight];
		arrayGreenSecond[i] = new int[fileHeight];
		arrayBlueSecond[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_second_input->GetPixel(x, y);
			arrayRedSecond[x][y] = pxl.R;
			arrayGreenSecond[x][y] = pxl.G;
			arrayBlueSecond[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y] & arrayRedSecond[x][y];
			int pxl_Green = arrayGreen[x][y] & arrayGreenSecond[x][y];
			int pxl_Blue = arrayBlue[x][y] & arrayBlueSecond[x][y];

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_Boolean_NOT(Bitmap^ bmp_input) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}


	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = ~arrayRed[x][y];
			int pxl_Green = ~arrayGreen[x][y];
			int pxl_Blue = ~arrayBlue[x][y];

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_Boolean_OR(Bitmap^ bmp_input, Bitmap^ bmp_second_input) {
	// SetUp Arr Input
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	// SetUp Arr Second Input
	int** arrayRedSecond = new int* [fileWidth];
	int** arrayGreenSecond = new int* [fileWidth];
	int** arrayBlueSecond = new int* [fileWidth];
	for (int i = 0; i < fileWidth; i++) {
		arrayRedSecond[i] = new int[fileHeight];
		arrayGreenSecond[i] = new int[fileHeight];
		arrayBlueSecond[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_second_input->GetPixel(x, y);
			arrayRedSecond[x][y] = pxl.R;
			arrayGreenSecond[x][y] = pxl.G;
			arrayBlueSecond[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y] | arrayRedSecond[x][y];
			int pxl_Green = arrayGreen[x][y] | arrayGreenSecond[x][y];
			int pxl_Blue = arrayBlue[x][y] | arrayBlueSecond[x][y];

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_Boolean_XOR(Bitmap^ bmp_input, Bitmap^ bmp_second_input) {
	// SetUp Arr Input
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	// SetUp Arr Second Input
	int** arrayRedSecond = new int* [fileWidth];
	int** arrayGreenSecond = new int* [fileWidth];
	int** arrayBlueSecond = new int* [fileWidth];
	for (int i = 0; i < fileWidth; i++) {
		arrayRedSecond[i] = new int[fileHeight];
		arrayGreenSecond[i] = new int[fileHeight];
		arrayBlueSecond[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_second_input->GetPixel(x, y);
			arrayRedSecond[x][y] = pxl.R;
			arrayGreenSecond[x][y] = pxl.G;
			arrayBlueSecond[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y] ^ arrayRedSecond[x][y];
			int pxl_Green = arrayGreen[x][y] ^ arrayGreenSecond[x][y];
			int pxl_Blue = arrayBlue[x][y] ^ arrayBlueSecond[x][y];

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageEnhancement_ContrastStretching(Bitmap^ bmp_input, int min, int max) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	int** arrayRed = new int* [fileWidth];
	int** arrayGreen = new int* [fileWidth];
	int** arrayBlue = new int* [fileWidth];
	int maxRed = 0, maxGreen = 0, maxBlue = 0;
	int minRed = 255, minGreen = 255, minBlue = 255;

	for (int i = 0; i < fileWidth; i++) {
		arrayRed[i] = new int[fileHeight];
		arrayGreen[i] = new int[fileHeight];
		arrayBlue[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			if (pxl.R < minRed) {
				minRed = pxl.R;
			}
			if (pxl.R > maxRed) {
				maxRed = pxl.R;
			}
			arrayGreen[x][y] = pxl.G;
			if (pxl.G < minGreen) {
				minGreen = pxl.G;
			}
			if (pxl.G > maxGreen) {
				maxGreen = pxl.G;
			}
			arrayBlue[x][y] = pxl.B;
			if (pxl.B < minBlue) {
				minBlue = pxl.B;
			}
			if (pxl.B > maxBlue) {
				maxBlue = pxl.B;
			}
		}
	}


	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y];
			if (pxl_Red <= min) {
				pxl_Red = 0;
			}
			else if (pxl_Red > max) {
				pxl_Red = 255;
			}
			else {
				int b = (maxRed - minRed) <= 0 ? 1 : (maxRed - minRed);
				pxl_Red = 255 * (pxl_Red - minRed) / (maxRed - minRed);
			}
			int pxl_Green = arrayGreen[x][y];
			if (pxl_Green <= min) {
				pxl_Green = 0;
			}
			else if (pxl_Green > max) {
				pxl_Green = 255;
			}
			else {
				int b = (maxGreen - minGreen) <= 0 ? 1 : (maxGreen - minGreen);
				pxl_Green = 255 * (pxl_Green - minGreen) / b;
			}
			int pxl_Blue = arrayBlue[x][y];
			if (pxl_Blue <= min) {
				pxl_Blue = 0;
			}
			else if (pxl_Blue > max) {
				pxl_Blue = 255;
			}
			else {
				int b = (maxBlue - minBlue) <= 0 ? 1 : (maxBlue - minBlue);
				pxl_Blue = 255 * (pxl_Blue - minBlue) / (maxBlue - minBlue);
			}

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageEnhancement_LogTransformation(Bitmap^ bmp_input) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	int** arrayRed = new int* [fileWidth];
	int** arrayGreen = new int* [fileWidth];
	int** arrayBlue = new int* [fileWidth];
	int L = 256;
	for (int i = 0; i < fileWidth; i++) {
		arrayRed[i] = new int[fileHeight];
		arrayGreen[i] = new int[fileHeight];
		arrayBlue[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}


	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = (L-1)/log(L) * log(arrayRed[x][y] + 1);
			int pxl_Green = (L - 1) / log(L) * log(arrayGreen[x][y] + 1);
			int pxl_Blue = (L - 1) / log(L) * log(arrayBlue[x][y] + 1);

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageEnhancement_InverseLogTransformation(Bitmap^ bmp_input) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	int** arrayRed = new int* [fileWidth];
	int** arrayGreen = new int* [fileWidth];
	int** arrayBlue = new int* [fileWidth];
	int L = 256;
	for (int i = 0; i < fileWidth; i++) {
		arrayRed[i] = new int[fileHeight];
		arrayGreen[i] = new int[fileHeight];
		arrayBlue[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}


	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = pow(exp(arrayRed[x][y]), log(L)/(L-1)) - 1;
			int pxl_Green = pow(exp(arrayGreen[x][y]), log(L) / (L - 1)) - 1;
			int pxl_Blue = pow(exp(arrayBlue[x][y]), log(L) / (L - 1)) - 1;

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageEnhancement_PowerTransformation(Bitmap^ bmp_input, double c_input, double pow_input) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = int(c_input * pow(arrayRed[x][y],pow_input)) ;
			int pxl_Green = int(c_input * pow(arrayGreen[x][y], pow_input));
			int pxl_Blue = int(c_input * pow(arrayBlue[x][y], pow_input));

			if (pxl_Red > 255) { pxl_Red = 255; }
			if (pxl_Green > 255) { pxl_Green = 255; }
			if (pxl_Blue > 255) { pxl_Blue = 255; }

			if (pxl_Red < 0) { pxl_Red = 0; }
			if (pxl_Green < 0) { pxl_Green = 0; }
			if (pxl_Blue < 0) { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageEnhancement_BitPlaneSlicing(Bitmap^ bmp_input, int level) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pow_level = pow(2, level);

			int bit_Red = (arrayRed[x][y] & pow_level) / pow_level;
			int bit_Green = (arrayGreen[x][y] & pow_level) / pow_level;
			int bit_Blue = (arrayBlue[x][y] & pow_level) / pow_level;

			int pxl_Red ;
			int pxl_Green ;
			int pxl_Blue ;

			if (bit_Red == 1) { pxl_Red = 255; } else { pxl_Red = 0; }
			if (bit_Green == 1) { pxl_Green = 255; } else { pxl_Green = 0; }
			if (bit_Blue == 1) { pxl_Blue = 255; } else { pxl_Blue = 0; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageEnhancement_GrayLevelSlicing(Bitmap^ bmp_input, int input_1, int input_2) {
	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arrayRed[x][y];
			int pxl_Green = arrayGreen[x][y];
			int pxl_Blue = arrayBlue[x][y];

			if (pxl_Red > input_1 && pxl_Red < input_2) { pxl_Red = 255; }
			if (pxl_Green > input_1 && pxl_Green < input_2) { pxl_Green = 255; }
			if (pxl_Blue > input_1 && pxl_Blue < input_2) { pxl_Blue = 255; }

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageEnhancement_HistogramEqualization(Bitmap^ bmp_input) {
	// SetUp Arr Input
	const int L = 256;
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	// Array CDF Original
	double* arr_red_cdf = Array_Red_CDF(bmp_input);
	double* arr_green_cdf = Array_Green_CDF(bmp_input);
	double* arr_blue_cdf = Array_Blue_CDF(bmp_input);

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arr_red_cdf[arrayRed[x][y]];
			int pxl_Green = arr_green_cdf[arrayGreen[x][y]];
			int pxl_Blue = arr_blue_cdf[arrayBlue[x][y]];

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}

Bitmap^ Image_ImageEnhancement_HistogramSpecification(Bitmap^ bmp_input, Bitmap^ bmp_second_input) {
	// SetUp Arr Input
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
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
			Color pxl = bmp_input->GetPixel(x, y);
			arrayRed[x][y] = pxl.R;
			arrayGreen[x][y] = pxl.G;
			arrayBlue[x][y] = pxl.B;
		}
	}

	// SetUp Arr Second Input
	int** arrayRedSecond = new int* [fileWidth];
	int** arrayGreenSecond = new int* [fileWidth];
	int** arrayBlueSecond = new int* [fileWidth];
	for (int i = 0; i < fileWidth; i++) {
		arrayRedSecond[i] = new int[fileHeight];
		arrayGreenSecond[i] = new int[fileHeight];
		arrayBlueSecond[i] = new int[fileHeight];
	}
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_second_input->GetPixel(x, y);
			arrayRedSecond[x][y] = pxl.R;
			arrayGreenSecond[x][y] = pxl.G;
			arrayBlueSecond[x][y] = pxl.B;
		}
	}

	// Array CDF Original
	double* arr_red_original = Array_Red_CDF(bmp_input);
	double* arr_green_original = Array_Green_CDF(bmp_input);
	double* arr_blue_original = Array_Blue_CDF(bmp_input);

	// Array CDF Target
	double* arr_red_target = Array_Red_CDF(bmp_second_input);
	double* arr_green_target = Array_Green_CDF(bmp_second_input);
	double* arr_blue_target = Array_Blue_CDF(bmp_second_input);

	// Array_Map
	double* arr_red_map = Array_Map(arr_red_original, arr_red_target,256);
	double* arr_green_map = Array_Map(arr_green_original, arr_green_target, 256);
	double* arr_blue_map = Array_Map(arr_blue_original, arr_blue_target, 256);

	//Update
	Bitmap^ bitmap = gcnew Bitmap(fileWidth, fileHeight);
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			int pxl_Red = arr_red_map[arrayRed[x][y]] ;
			int pxl_Green = arr_green_map[arrayGreen[x][y]];
			int pxl_Blue = arr_blue_map[arrayBlue[x][y]] ;

			Color pxl = Color::FromArgb(pxl_Red, pxl_Green, pxl_Blue);
			bitmap->SetPixel(x, y, pxl);
		}
	}

	return bitmap;
}