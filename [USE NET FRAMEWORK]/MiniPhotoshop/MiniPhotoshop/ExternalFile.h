#pragma once
#include <msclr\marshal_cppstd.h>
#include <string.h>
#include <iostream>

#include "PortableAnymaps/pbm.h"
#include "PortableAnymaps/ppm.h"
#include "PortableAnymaps/pgm.h"
#include "PortableAnymaps/raw.h"

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

Bitmap^ Image_BitmapFile(String^ path);

Bitmap^ Image_PGMFile(String^ path);

Bitmap^ Image_PBMFile(String^ path);

Bitmap^ Image_PPMFile(String^ path);

Bitmap^ Image_RawImageFile(String^ path);

void Write_to_PGM(Bitmap^ bmp, string path);

void Write_to_PPM(Bitmap^ bmp, string path);

void Write_to_PBM(Bitmap^ bmp, string path);

void Write_to_Raw(Bitmap^ bmp, string path);