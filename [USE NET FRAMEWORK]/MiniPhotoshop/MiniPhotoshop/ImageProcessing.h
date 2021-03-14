#pragma once
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System::Drawing;

Bitmap^ Image_GrayScale(Bitmap^ bmp_input);
Bitmap^ Image_NegativeTransformation(Bitmap^ bmp_input);
Bitmap^ Image_ImageBrightening_ScalarAddition(Bitmap^ bmp_input, int value);
Bitmap^ Image_ImageBrightening_ScalarMultiplication(Bitmap^ bmp_input, int value);
Bitmap^ Image_ImageBrightening_LinearFormula(Bitmap^ bmp_input, int multiplier, int constant);
Bitmap^ Image_Arithmethic_Addition(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Arithmethic_Subtraction(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Arithmethic_Multiplication(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Arithmethic_Division(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Boolean_AND(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Boolean_NOT(Bitmap^ bmp_input);
Bitmap^ Image_Boolean_OR(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Boolean_XOR(Bitmap^ bmp_input, Bitmap^ bmp_second_input);
Bitmap^ Image_Translate(Bitmap^ bmp_input, int x_trans, int y_trans);
Bitmap^ Image_Rotate90(Bitmap^ bmp_input);
Bitmap^ Image_FlipHorizontal(Bitmap^ bmp_input);
Bitmap^ Image_Zooming_In(Bitmap^ bmp_input);
Bitmap^ Image_Zooming_Out(Bitmap^ bmp_input);


Bitmap^ Image_ImageEnhancement_ContrastStretching(Bitmap^ bmp_input, int min, int max);
Bitmap^ Image_ImageEnhancement_LogTransformation(Bitmap^ bmp_input);
Bitmap^ Image_ImageEnhancement_InverseLogTransformation(Bitmap^ bmp_input);
Bitmap^ Image_ImageEnhancement_PowerTransformation(Bitmap^ bmp_input,double c_input,double pow_input);
Bitmap^ Image_ImageEnhancement_BitPlaneSlicing(Bitmap^ bmp_input, int level);
Bitmap^ Image_ImageEnhancement_GrayLevelSlicing(Bitmap^ bmp_input, int input_1, int input_2);
Bitmap^ Image_ImageEnhancement_HistogramEqualization(Bitmap^ bmp_input);
Bitmap^ Image_ImageEnhancement_HistogramSpecification(Bitmap^ bmp_input, Bitmap^ bmp_second_input);