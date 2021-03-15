#include "PrimitiveFunction.h"

#include <msclr\marshal_cppstd.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <corecrt_math_defines.h>

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
using namespace System::IO;

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

//// std::string to double
double convertToDouble(std::string input) {
	double value = atof(input.c_str());
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

double** GaussianFilterCreate(double sigma, int k_size)
{
	// intialising standard deviation to 1.0 
	double r, s = 2.0 * sigma * sigma;

	double mean = k_size / 2;

	// sum is for normalization 
	double sum = 0.0;

	double** GKernel = new double* [k_size];
	for (int i = 0; i < k_size; i++) {
		GKernel[i] = new double[k_size];
	}

	for (int x = 0; x < k_size; ++x)
		for (int y = 0; y < k_size; ++y) {
			GKernel[x][y] = exp(-0.5 * (pow((x - mean) / sigma, 2.0) + pow((y - mean) / sigma, 2.0)))
				/ (2 * M_PI * sigma * sigma);

			// Accumulate the kernel values
			sum += GKernel[x][y];
		}

	// Normalize the kernel
	for (int x = 0; x < k_size; ++x)
		for (int y = 0; y < k_size; ++y)
			GKernel[x][y] /= sum;

	return GKernel;
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
	long sum = 0;
	double avg;
	int size_n = 0;

	for (int i = 0; i < size; i++) {
		sum += i*arr[i];
		size_n += arr[i];
	}

	avg = double(double(sum) / size_n);
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

//char buffer[100];sprintf_s(buffer, "Size: %d\n", size_n);OutputDebugStringA(buffer);
void SaveArray(int arr[], int size, String^ filename) {
	StreamWriter^ outFile = gcnew StreamWriter("D://" + filename + ".txt");
	for (int i = 0; i < size; i++) {
		outFile->WriteLine(arr[i] + "");
	}
	outFile->Close();
}

void SaveArray(double arr[], int size, String^ filename) {
	StreamWriter^ outFile = gcnew StreamWriter("D://" + filename + ".txt");
	for (int i = 0; i < size; i++) {
		outFile->WriteLine(arr[i] + "");
	}
	outFile->Close();
}

// Histogram Specification
double* Array_Red_CDF(Bitmap^ bmp_input) {
	double* arr = new double[256];
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
			arr[pxlR] += 1;
		}
	}

	// Get Total
	long sum = 0;
	for (int i = 0; i <= 255; ++i) {
		sum += arr[i];
	}

	// Normalize
	for (int i = 0; i <= 255; ++i) {
		arr[i] = 1.0 * arr[i]/sum;
	}

	// Accumulation
	for (int i = 1; i <= 255; ++i) {
		arr[i] = arr[i] + arr[i-1];
	}

	// Multiple By 255
	for (int i = 0; i <= 255; ++i) {
		arr[i] = arr[i]*255;
	}

	return arr;
}
double* Array_Green_CDF(Bitmap^ bmp_input) {
	double* arr = new double[256];
	for (int i = 0; i <= 255; ++i) {
		arr[i] = 0;
	}

	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			int pxlR = pxl.G;
			arr[pxlR] += 1;
		}
	}

	// Get Total
	long sum = 0;
	for (int i = 0; i <= 255; ++i) {
		sum += arr[i];
	}

	// Normalize
	for (int i = 0; i <= 255; ++i) {
		arr[i] = 1.0 * arr[i] / sum;
	}

	// Accumulation
	for (int i = 1; i <= 255; ++i) {
		arr[i] = arr[i] + arr[i - 1];
	}

	// Multiple By 255
	for (int i = 0; i <= 255; ++i) {
		arr[i] = arr[i] * 255;
	}

	return arr;
}
double* Array_Blue_CDF(Bitmap^ bmp_input) {
	double* arr = new double[256];
	for (int i = 0; i <= 255; ++i) {
		arr[i] = 0;
	}

	// SetUp
	double fileWidth = bmp_input->Width;
	double fileHeight = bmp_input->Height;
	for (int x = 0; x < fileWidth; x++) {
		for (int y = 0; y < fileHeight; y++) {
			Color pxl = bmp_input->GetPixel(x, y);
			int pxlR = pxl.B;
			arr[pxlR] += 1;
		}
	}

	// Get Total
	long sum = 0;
	for (int i = 0; i <= 255; ++i) {
		sum += arr[i];
	}

	// Normalize
	for (int i = 0; i <= 255; ++i) {
		arr[i] = 1.0 * arr[i] / sum;
	}

	// Accumulation
	for (int i = 1; i <= 255; ++i) {
		arr[i] = arr[i] + arr[i - 1];
	}

	// Multiple By 255
	for (int i = 0; i <= 255; ++i) {
		arr[i] = arr[i] * 255;
	}

	return arr;
}

double* Array_Map(double arr_original[], double arr_target[],int size) {
	double* arr = new double[size];

	for (int i = 0; i < size; ++i) {
		arr[i] = 0;
	}

	int second_lead = 0;
	for (int idx_original = 0; idx_original < size; idx_original += 1) {
		double val_original = arr_original[idx_original];
		
		for (int idx_target = second_lead; idx_target < size; idx_target += 1) {
			double val_target_1 = arr_target[idx_target];
			double val_target_2 ;
			if (idx_target == 255) {
				arr[idx_original] = idx_target;
				break;
			}
			else {
				val_target_2 = arr_target[idx_target+1];
			}
			double diff_1 = fabs(val_target_1 - val_original);
			double diff_2 = fabs(val_target_2 - val_original);

			if (diff_1 < diff_2) {
				arr[idx_original] = idx_target;
				break;
			}
			else {
				second_lead = idx_target;
			}
			
		}
		
	}

	return arr;
}

