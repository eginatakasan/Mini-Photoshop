#include "ImageProcessing.h"

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