#pragma once
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System::Drawing;

Bitmap^ Image_GrayScale(Bitmap^ bmp_input);
Bitmap^ Image_NegativeTransformation(Bitmap^ bmp_input);
Bitmap^ Image_ImageBrightening_ScalarAddition(Bitmap^ bmp_input, int value);
Bitmap^ Image_ImageBrightening_ScalarMultiplication(Bitmap^ bmp_input, int value);
Bitmap^ Image_Arithmethic_Addition(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Arithmethic_Subtraction(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Arithmethic_Multiplication(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Arithmethic_Division(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Boolean_AND(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Boolean_NOT(Bitmap^ bmp_input);
Bitmap^ Image_Boolean_OR(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Boolean_XOR(Bitmap^ bmp_input, Bitmap^ bmp_second_input);