#include "ExternalFile.h"
#include "PrimitiveFunction.h"
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
using namespace System::Diagnostics;
using namespace Microsoft::VisualBasic;
using namespace std;
using namespace msclr::interop;

int MagicNumber = 0;
int MaxVal = 0;

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
	MagicNumber = pgm.GetMagicNumber();
	MaxVal = pgm.GetMaxVal();

	Bitmap^ bmp = gcnew Bitmap(width, height);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int _color = pgm.GetPixel(j, i) * 255 / pgm.GetMaxVal();
			Color color = Color::FromArgb(_color, _color, _color);
			bmp->SetPixel(i, j, color);
		}
	}

	Debug::WriteLine("PGM Image");
	Debug::WriteLine("Width: " + pgm.GetWidth());
	Debug::WriteLine("Height: " + pgm.GetHeight());
	Debug::WriteLine("Max Val: " + pgm.GetMaxVal());
	Debug::WriteLine("Bit Per Pixel: " + pgm.GetBitPerPixel());
	Debug::WriteLine("File size: " + pgm.GetFileSize() + " B");

	return bmp;
}

Bitmap^ Image_PBMFile(String^ path) {
	int const length = path->Length;
	marshal_context context;
	string s_path = context.marshal_as<std::string>(path);
	PBM pbm = (s_path.c_str());
	int height = pbm.GetHeight();
	int width = pbm.GetWidth();
	MagicNumber = pbm.GetMagicNumber();
	MaxVal = 1;

	Bitmap^ bmp = gcnew Bitmap(width, height);
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int _color = pbm.GetPixel(j,i) == 0 ? 255 : 0;
			Color color = Color::FromArgb(_color, _color, _color);
			bmp->SetPixel(i,j,color);
		}
	}
	Debug::WriteLine("PBM Image");
	Debug::WriteLine("Width: " + pbm.GetWidth() );
	Debug::WriteLine("Height: " + pbm.GetHeight() );
	Debug::WriteLine("Magic Number: " + pbm.GetMagicNumber() );
	Debug::WriteLine("Max Val: " + pbm.GetMaxVal() );
	Debug::WriteLine("Bit Per Pixel: " + pbm.GetBitPerPixel() );
	Debug::WriteLine("File size: " + pbm.GetFileSize() + " B" );

	return bmp;
}

Bitmap^ Image_PPMFile(String^ path) {
	int const length = path->Length;
	marshal_context context;
	string s_path = context.marshal_as<std::string>(path);
	PPM ppm = (s_path.c_str());
	int height = ppm.GetHeight();
	int width = ppm.GetWidth();
	MagicNumber = ppm.GetMagicNumber();
	MaxVal = ppm.GetMaxVal();

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
	Debug::WriteLine("PPM Image");
	Debug::WriteLine("Width: " + ppm.GetWidth() );
	Debug::WriteLine("Height: " + ppm.GetHeight() );
	Debug::WriteLine("Magic Number: " + ppm.GetMagicNumber() );
	Debug::WriteLine("Max Val: " + ppm.GetMaxVal() );
	Debug::WriteLine("Bit Per Pixel: " + ppm.GetBitPerPixel() );
	Debug::WriteLine("File size: " + ppm.GetFileSize() + " B" );

	return bmp;
}

Bitmap^ Image_RawImageFile(String^ path) {
	int const length = path->Length;
	marshal_context context;
	string s_path = context.marshal_as<std::string>(path);
	Raw raw = Raw(s_path.c_str());
	int height = raw.GetHeight();
	int width = raw.GetWidth();
	MaxVal = raw.GetMaxVal();

	Bitmap^ bmp = gcnew Bitmap(width, height);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int pixel = raw.GetPixel(j,i) * 255 / raw.GetMaxVal();
			Color color = Color::FromArgb(pixel, pixel, pixel);
			bmp->SetPixel(i, j, color);
		}
	}
	Debug::WriteLine("Raw Image");
	Debug::WriteLine("Width: " + raw.GetWidth() );
	Debug::WriteLine("Height: " + raw.GetHeight() );
	Debug::WriteLine("Max Val: " + raw.GetMaxVal() );
	Debug::WriteLine("Bit Per Pixel: " + raw.GetBitPerPixel() );
	Debug::WriteLine("File size: " + raw.GetFileSize() + " B" );

	return bmp;
}

void Write_to_PGM(Bitmap^ bmp, string path) {
	int width = bmp->Width;
	int height = bmp->Height;
	int magicNum = MagicNumber;
	int maxVal = MaxVal;

	PGM pgm = PGM(width, height, magicNum, maxVal);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int pixel = bmp->GetPixel(i, j).R * maxVal / 255;
			pgm.SetPixel(j, i, pixel);
		}
	}
	string out = "C:\\Users\\User\\Downloads\\" + path + ".pgm";
	pgm.Write(out.c_str());
}

void Write_to_PBM(Bitmap^ bmp, string path) {
	int width = bmp->Width;
	int height = bmp->Height;
	int magicNum = MagicNumber;
	int maxVal = MaxVal;

	PBM pbm = PBM(width, height, magicNum);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int pixel = bmp->GetPixel(i, j).R == 0 ? 1 : 0;
			pbm.SetPixel(j, i, pixel);
		}
	}
	string out = "C:\\Users\\User\\Downloads\\" + path + ".pbm";
	pbm.Write(out.c_str());
}

void Write_to_PPM(Bitmap^ bmp, string path) {
	int width = bmp->Width;
	int height = bmp->Height;
	int magicNum = MagicNumber;
	int maxVal = MaxVal;
	
	PPM ppm = PPM(width, height, magicNum, maxVal);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int R = bmp->GetPixel(i, j).R * maxVal / 255;
			int G = bmp->GetPixel(i, j).G * maxVal / 255;
			int B = bmp->GetPixel(i, j).B * maxVal / 255;
			_Color color = _Color(R, G, B);
			ppm.SetPixel(j, i, color);
		}
	}
	string out = "C:\\Users\\User\\Downloads\\" + path + ".ppm";
	ppm.Write(out.c_str());
}

void Write_to_Raw(Bitmap^ bmp, string path) {
	int width = bmp->Width;
	int height = bmp->Height;

	Raw raw = Raw(width, height);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int pixel = bmp->GetPixel(i, j).R * MaxVal / 255;
			raw.SetPixel(j, i, pixel);
		}
	}
	string out = "C:\\Users\\egina\\Downloads\\" + path + ".raw";
	raw.Write(out.c_str());
}