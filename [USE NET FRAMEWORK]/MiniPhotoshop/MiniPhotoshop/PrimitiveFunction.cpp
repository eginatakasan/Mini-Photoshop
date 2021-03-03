#include "PrimitiveFunction.h"

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

//[PRIMITIVE FUNCTION]
bool isNumeric(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

//// String to std::string
std::string convertTostring(String^ input) {
	std::string output = marshal_as<std::string>(input);
	return output;
}

//// std::string to int
int convertToInteger(std::string input) {
	int value = std::stoi(input);
	return value;
}

//// String to int
int convertToInteger(String^ input) {
	std::string standardString = convertTostring(input);
	int value = std::stoi(standardString);
	return value;
}

boolean CheckSizeBitmap(Bitmap^ bmp_1, Bitmap^ bmp_2) {
	double bmp1_width = bmp_1->Width;
	double bmp1_height = bmp_1->Height;

	double bmp2_width = bmp_2->Width;
	double bmp2_height = bmp_2->Height;

	if (bmp1_width == bmp2_width && bmp1_height == bmp2_height) {
		return true;
	}
	else {
		return false;
	}
}

// Return Biner, Grayscale, or RGB
String^ TypeImage(Bitmap^ bmp_input) {
	// Biner
	bool isBiner = true;
	bool isGrayScale = true;

	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			int pxlRed = pxl.R;
			int pxlGreen = pxl.G;
			int pxlBlue = pxl.B;

			//Biner
			bool isBlack = (pxlRed == 0 && pxlGreen == 0 && pxlBlue == 0);
			bool isWhite = (pxlRed == 255 && pxlGreen == 255 && pxlBlue == 255);
			if (!isBlack && !isWhite) {
				isBiner = false;
			}

			//GrayScale
			if (pxlRed != pxlGreen || pxlRed != pxlBlue || pxlGreen != pxlBlue) {
				isGrayScale = false;
			}
		}
	}

	if (isBiner) {
		return "Biner";
	}
	else if (isGrayScale) {
		return "GrayScale";
	}
	else {
		return "RGB";
	}
}

// Return Array Red
int* Array_Red(Bitmap^ bmp_input) {
	static int arr[256];
	//int max_value = 10000;
	for (int i = 0; i <= 255; ++i) {
		arr[i] = 0;
	}

	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			int pxlR = pxl.R;
			//if (arr[pxlR] < max_value) {
				arr[pxlR] += 1;
			//}
		}
	}

	return arr;
}

// Return Array Green
int* Array_Green(Bitmap^ bmp_input) {
	static int arr[256];
	//int max_value = 10000;
	for (int i = 0; i <= 255; ++i) {
		arr[i] = 0;
	}

	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			int pxlG = pxl.G;
			//if (arr[pxlG] < max_value) {
				arr[pxlG] += 1;
			//}
		}
	}

	return arr;
}

// Return Array Blue
int* Array_Blue(Bitmap^ bmp_input) {
	static int arr[256];
	//int max_value = 10000;
	for (int i = 0; i <= 255; ++i) {
		arr[i] = 0;
	}

	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			int pxlB = pxl.B;
			//if (arr[pxlB] < max_value) {
				arr[pxlB] += 1;
			//}
		}
	}

	return arr;
}

// Return Array GrayScale
int* Array_GrayScale(Bitmap^ bmp_input) {
	static int arr[256];
	//int max_value = 10000;
	for (int i = 0; i <= 255; ++i) {
		arr[i] = 0;
	}

	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			int pxlGy = pxl.R;
			//if (arr[pxlGy] < max_value) {
				arr[pxlGy] += 1;
			//}
		}
	}

	return arr;
}

// Return Array Biner
int* Array_Biner(Bitmap^ bmp_input) {
	static int arr[2];
	//int max_value = 10000;
	for (int i = 0; i <= 2; ++i) {
		arr[i] = 0;
	}

	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			int pxlRed = pxl.R;
			int pxlGreen = pxl.G;
			int pxlBlue = pxl.B;

			//Biner
			bool isBlack = (pxlRed == 0 && pxlGreen == 0 && pxlBlue == 0);
			bool isWhite = (pxlRed == 255 && pxlGreen == 255 && pxlBlue == 255);

			if (isBlack) {
				//Black
				//if (arr[0] < max_value) {
					arr[0] += 1;
				//}
			}
			else {
				//White
				//if (arr[1] < max_value) {
					arr[1] += 1;
				//}
			}
			
		}
	}

	return arr;
}

// Means
double Get_Means(int arr[], int size) {
	int sum = 0;
	double avg;
	int size_n = 0;

	for (int i = 0; i < size; i++) {
		sum += i*arr[i];
		size_n += arr[i];
	}

	avg = double(sum / size_n);
	return avg;
}

// Variance
double Get_Variance(int arr[], int size)
{
	double mean = Get_Means(arr,size);
	double sqDiff = 0;
	int size_n = 0;

	for (int i = 0; i < size; i++) {
		sqDiff += arr[i]*(i - mean) * (i - mean);
		size_n += arr[i];
	}

	return double(sqDiff / size_n);
}

// Standard Deviation
double Get_StandardDeviation(int arr[],int size)
{
	return sqrt(Get_Variance(arr, size));
}
