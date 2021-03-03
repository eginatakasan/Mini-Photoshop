#pragma once
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::Drawing;

bool isNumeric(const std::string& s);

//// String to std::string
std::string convertTostring(String^ input);

//// std::string to int
int convertToInteger(std::string input);

//// std::string to double
double convertToDouble(std::string input);

//// String to int
int convertToInteger(String^ input);

boolean CheckSizeBitmap(Bitmap^ bmp_1, Bitmap^ bmp_2);

// Return Biner, Grayscale, or RGB
String^ TypeImage(Bitmap^ bmp_input);

// Return Array Red
int* Array_Red(Bitmap^ bmp_input);

// Return Array Green
int* Array_Green(Bitmap^ bmp_input);

// Return Array Blue
int* Array_Blue(Bitmap^ bmp_input);

// Return Array GrayScale
int* Array_GrayScale(Bitmap^ bmp_input);

// Return Array Biner
int* Array_Biner(Bitmap^ bmp_input);

// Means
double Get_Means(int arr[], int size);

// Variance
double Get_Variance(int arr[], int size);

// Standard Deviation
double Get_StandardDeviation(int arr[], int size);

// BinaryString
std::string BinaryString(int number);

int Get_Bit(std::string strBinary, int n_th);