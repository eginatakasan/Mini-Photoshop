#include "ExternalFile.h"
#include <msclr\marshal_cppstd.h>
#include <string.h>
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
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
	int const length = path->Length;
	marshal_context context;
	string s_path = context.marshal_as<std::string>(path);
	PGM pgm = (s_path.c_str());
	int height = pgm.GetHeight();
	int width = pgm.GetWidth();
	Bitmap^ bmp = gcnew Bitmap(width, height);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int _color = pgm.GetPixel(j, i) * 255 / pgm.GetMaxVal();
			Color color = Color::FromArgb(_color, _color, _color);
			bmp->SetPixel(i, j, color);
		}
	}
	return bmp;
}

Bitmap^ Image_PBMFile(String^ path) {
	int const length = path->Length;
	marshal_context context;
	string s_path = context.marshal_as<std::string>(path);
	PBM pbm = (s_path.c_str());
	int height = pbm.GetHeight();
	int width = pbm.GetWidth();
	Bitmap^ bmp = gcnew Bitmap(width, height);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int _color = pbm.GetPixel(j,i) == 0 ? 255 : 0;
			Color color = Color::FromArgb(_color, _color, _color);
			bmp->SetPixel(i,j,color);
		}
	}
	return bmp;
}

Bitmap^ Image_PPMFile(String^ path) {
	int const length = path->Length;
	marshal_context context;
	string s_path = context.marshal_as<std::string>(path);
	PPM ppm = (s_path.c_str());
	int height = ppm.GetHeight();
	int width = ppm.GetWidth();

	Bitmap^ bmp = gcnew Bitmap(width, height);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			_Color _color = ppm.GetPixel(j, i);
			int R = _color.R * 255 / ppm.GetMaxVal();
			int G = _color.G * 255 / ppm.GetMaxVal();
			int B = _color.B * 255 / ppm.GetMaxVal();
			Color color = Color::FromArgb(R, G, B);
			bmp->SetPixel(i, j, color);
		}
	}
	return bmp;
}

Bitmap^ Image_RawImageFile(String^ path) {
	Image^ image = Image::FromFile(path);

	return gcnew Bitmap(image);
}