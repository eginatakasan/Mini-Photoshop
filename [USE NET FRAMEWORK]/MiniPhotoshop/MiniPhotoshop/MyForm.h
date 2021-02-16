#pragma once
#include <string.h>
#include <iostream>
#include <msclr\marshal_cppstd.h>

namespace MiniPhotoshop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;
	using namespace std;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_open;
	protected:
	private: System::Windows::Forms::Button^ btn_show_info;
	private: System::Windows::Forms::Label^ lbl_original_img;
	private: System::Windows::Forms::Label^ lbl_edited_image;
	private: System::Windows::Forms::Button^ btn_edit_image;
	private: System::Windows::Forms::Button^ btn_save_image;
	private: System::Windows::Forms::PictureBox^ pic_box_original_img;
	private: System::Windows::Forms::PictureBox^ pic_box_edited_img;
	private: System::Windows::Forms::OpenFileDialog^ ofd;
	private: System::Windows::Forms::Button^ btn_reset;
	private: System::Windows::Forms::TextBox^ txt_name_input;
	private: System::Windows::Forms::Label^ lbl_name_edit;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_open = (gcnew System::Windows::Forms::Button());
			this->btn_show_info = (gcnew System::Windows::Forms::Button());
			this->lbl_original_img = (gcnew System::Windows::Forms::Label());
			this->lbl_edited_image = (gcnew System::Windows::Forms::Label());
			this->btn_edit_image = (gcnew System::Windows::Forms::Button());
			this->btn_save_image = (gcnew System::Windows::Forms::Button());
			this->pic_box_original_img = (gcnew System::Windows::Forms::PictureBox());
			this->pic_box_edited_img = (gcnew System::Windows::Forms::PictureBox());
			this->ofd = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->txt_name_input = (gcnew System::Windows::Forms::TextBox());
			this->lbl_name_edit = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_original_img))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_edited_img))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_open
			// 
			this->btn_open->Location = System::Drawing::Point(28, 24);
			this->btn_open->Name = L"btn_open";
			this->btn_open->Size = System::Drawing::Size(109, 36);
			this->btn_open->TabIndex = 0;
			this->btn_open->Text = L"Open Image";
			this->btn_open->UseVisualStyleBackColor = true;
			this->btn_open->Click += gcnew System::EventHandler(this, &MyForm::btn_open_Click);
			// 
			// btn_show_info
			// 
			this->btn_show_info->Enabled = false;
			this->btn_show_info->Location = System::Drawing::Point(154, 24);
			this->btn_show_info->Name = L"btn_show_info";
			this->btn_show_info->Size = System::Drawing::Size(109, 36);
			this->btn_show_info->TabIndex = 1;
			this->btn_show_info->Text = L"Show Info";
			this->btn_show_info->UseVisualStyleBackColor = true;
			this->btn_show_info->Click += gcnew System::EventHandler(this, &MyForm::btn_show_info_Click);
			// 
			// lbl_original_img
			// 
			this->lbl_original_img->AutoSize = true;
			this->lbl_original_img->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_original_img->Location = System::Drawing::Point(24, 63);
			this->lbl_original_img->Margin = System::Windows::Forms::Padding(0);
			this->lbl_original_img->Name = L"lbl_original_img";
			this->lbl_original_img->Size = System::Drawing::Size(132, 24);
			this->lbl_original_img->TabIndex = 2;
			this->lbl_original_img->Text = L"Original Image";
			// 
			// lbl_edited_image
			// 
			this->lbl_edited_image->AutoSize = true;
			this->lbl_edited_image->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_edited_image->Location = System::Drawing::Point(301, 63);
			this->lbl_edited_image->Name = L"lbl_edited_image";
			this->lbl_edited_image->Size = System::Drawing::Size(121, 24);
			this->lbl_edited_image->TabIndex = 3;
			this->lbl_edited_image->Text = L"Edited Image";
			// 
			// btn_edit_image
			// 
			this->btn_edit_image->Enabled = false;
			this->btn_edit_image->Location = System::Drawing::Point(546, 90);
			this->btn_edit_image->Name = L"btn_edit_image";
			this->btn_edit_image->Size = System::Drawing::Size(109, 36);
			this->btn_edit_image->TabIndex = 4;
			this->btn_edit_image->Text = L"Edit Image";
			this->btn_edit_image->UseVisualStyleBackColor = true;
			this->btn_edit_image->Click += gcnew System::EventHandler(this, &MyForm::btn_edit_image_Click);
			// 
			// btn_save_image
			// 
			this->btn_save_image->Enabled = false;
			this->btn_save_image->Location = System::Drawing::Point(305, 24);
			this->btn_save_image->Name = L"btn_save_image";
			this->btn_save_image->Size = System::Drawing::Size(109, 36);
			this->btn_save_image->TabIndex = 5;
			this->btn_save_image->Text = L"Save Image";
			this->btn_save_image->UseVisualStyleBackColor = true;
			this->btn_save_image->Click += gcnew System::EventHandler(this, &MyForm::btn_save_image_Click);
			// 
			// pic_box_original_img
			// 
			this->pic_box_original_img->BackColor = System::Drawing::Color::White;
			this->pic_box_original_img->Location = System::Drawing::Point(28, 90);
			this->pic_box_original_img->Name = L"pic_box_original_img";
			this->pic_box_original_img->Size = System::Drawing::Size(235, 235);
			this->pic_box_original_img->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pic_box_original_img->TabIndex = 6;
			this->pic_box_original_img->TabStop = false;
			// 
			// pic_box_edited_img
			// 
			this->pic_box_edited_img->BackColor = System::Drawing::Color::White;
			this->pic_box_edited_img->Location = System::Drawing::Point(305, 90);
			this->pic_box_edited_img->Name = L"pic_box_edited_img";
			this->pic_box_edited_img->Size = System::Drawing::Size(235, 235);
			this->pic_box_edited_img->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pic_box_edited_img->TabIndex = 7;
			this->pic_box_edited_img->TabStop = false;
			// 
			// ofd
			// 
			this->ofd->FileName = L"image";
			this->ofd->Title = L"Select an image";
			// 
			// btn_reset
			// 
			this->btn_reset->Enabled = false;
			this->btn_reset->Location = System::Drawing::Point(420, 24);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(109, 36);
			this->btn_reset->TabIndex = 8;
			this->btn_reset->Text = L"Reset";
			this->btn_reset->UseVisualStyleBackColor = true;
			this->btn_reset->Click += gcnew System::EventHandler(this, &MyForm::btn_reset_Click);
			// 
			// txt_name_input
			// 
			this->txt_name_input->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_name_input->Location = System::Drawing::Point(546, 62);
			this->txt_name_input->Name = L"txt_name_input";
			this->txt_name_input->Size = System::Drawing::Size(178, 22);
			this->txt_name_input->TabIndex = 9;
			this->txt_name_input->Text = L"gray_scale";
			// 
			// lbl_name_edit
			// 
			this->lbl_name_edit->AutoSize = true;
			this->lbl_name_edit->Location = System::Drawing::Point(543, 46);
			this->lbl_name_edit->Name = L"lbl_name_edit";
			this->lbl_name_edit->Size = System::Drawing::Size(56, 13);
			this->lbl_name_edit->TabIndex = 10;
			this->lbl_name_edit->Text = L"Name Edit";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(732, 331);
			this->Controls->Add(this->lbl_name_edit);
			this->Controls->Add(this->txt_name_input);
			this->Controls->Add(this->btn_reset);
			this->Controls->Add(this->pic_box_edited_img);
			this->Controls->Add(this->pic_box_original_img);
			this->Controls->Add(this->btn_save_image);
			this->Controls->Add(this->btn_edit_image);
			this->Controls->Add(this->lbl_edited_image);
			this->Controls->Add(this->lbl_original_img);
			this->Controls->Add(this->btn_show_info);
			this->Controls->Add(this->btn_open);
			this->Name = L"MyForm";
			this->Text = L"MiniPhotoshop";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_original_img))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_edited_img))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	Image^ img_original;
	int** arrayRedOriginal;
	int** arrayGreenOriginal;
	int** arrayBlueOriginal;

	Image^ img_edited;
	int** arrayRedEdited;
	int** arrayGreenEdited;
	int** arrayBlueEdited;

	private: System::Void btn_open_Click(System::Object^ sender, System::EventArgs^ e) {
		//ofd->Filter = "|*.jpg; *.jpeg; *.jpe; *.jfif; *.png";
		ofd->Filter = "|*.bmp";
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			img_original = Image::FromFile(ofd->FileName);
			img_edited = Image::FromFile(ofd->FileName);
			Image2Array_Original();
			Image2Array_Edited();
			String^ extension_file = System::IO::Path::GetExtension(ofd->FileName);

			pic_box_original_img->Image = img_original;
			pic_box_edited_img->Image = img_edited;

			SetButtonEnabled();
		}
	}

	void Image2Array_Original() {
		double fileWidth = img_original->Width;
		double fileHeight = img_original->Height;
		arrayRedOriginal = new int* [fileWidth];
		arrayGreenOriginal = new int* [fileWidth];
		arrayBlueOriginal = new int* [fileWidth];
		for (int i = 0; i < fileWidth; i++) {
			arrayRedOriginal[i] = new int[fileHeight];
			arrayGreenOriginal[i] = new int[fileHeight];
			arrayBlueOriginal[i] = new int[fileHeight];
		}

		Bitmap^ bmp = gcnew Bitmap(img_original);
		for (int x = 0; x < fileWidth; x++) {
			for (int y = 0; y < fileHeight; y++) {
				Color pxl = bmp->GetPixel(x, y);

				int pxl_Red = pxl.R;
				int pxl_Green = pxl.G;
				int pxl_Blue = pxl.B;

				arrayRedOriginal[x][y] = pxl_Red;
				arrayGreenOriginal[x][y] = pxl_Green;
				arrayBlueOriginal[x][y] = pxl_Blue;
			}
		}
	}

	void Image2Array_Edited() {
		double fileWidth = img_edited->Width;
		double fileHeight = img_edited->Height;
		arrayRedEdited = new int* [fileWidth];
		arrayGreenEdited = new int* [fileWidth];
		arrayBlueEdited = new int* [fileWidth];
		for (int i = 0; i < fileWidth; i++) {
			arrayRedEdited[i] = new int[fileHeight];
			arrayGreenEdited[i] = new int[fileHeight];
			arrayBlueEdited[i] = new int[fileHeight];
		}

		Bitmap^ bmp = gcnew Bitmap(img_edited);
		for (int x = 0; x < fileWidth; x++) {
			for (int y = 0; y < fileHeight; y++) {
				Color pxl = bmp->GetPixel(x, y);

				int pxl_Red = pxl.R;
				int pxl_Green = pxl.G;
				int pxl_Blue = pxl.B;

				arrayRedEdited[x][y] = pxl_Red;
				arrayGreenEdited[x][y] = pxl_Green;
				arrayBlueEdited[x][y] = pxl_Blue;
			}
		}
	}

	void ShowPlainMessageBox(String^ str) {
		MessageBox::Show(str);
	}

	void SetButtonEnabled() {
		if (img_original != nullptr) {
			btn_show_info->Enabled = true;
			btn_edit_image->Enabled = true;
			btn_save_image->Enabled = true;
			btn_reset->Enabled = true;
		}
		else {
			btn_show_info->Enabled = false;
			btn_edit_image->Enabled = false;
			btn_save_image->Enabled = false;
			btn_reset->Enabled = false;
		}
	}

	private: System::Void btn_show_info_Click(System::Object^ sender, System::EventArgs^ e) {
		if (img_original != nullptr) {
			double fileWidth = img_original->Width;
			double fileHeight = img_original->Height;
			ShowPlainMessageBox("Width: " + fileWidth + "\n" + "Height: " + fileHeight);
		}
	}

	private: System::Void btn_save_image_Click(System::Object^ sender, System::EventArgs^ e) {
		Bitmap^ bmp_edited = gcnew Bitmap(img_edited);
		bmp_edited->Save("C:\\Users\\User\\Downloads\\Save_Edited.jpg");
	}

	private: System::Void btn_reset_Click(System::Object^ sender, System::EventArgs^ e) {
		img_edited = img_original;
		pic_box_edited_img->Image = img_original;
		Image2Array_Edited();
	}

	private: System::Void btn_edit_image_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ strInput = txt_name_input->Text;
		std::string standardString = marshal_as<std::string>(strInput);
		const char* converted = standardString.c_str();

		if (strcmp(converted, "gray_scale") == 0) {
			Edit_GrayScale();
		}
		else {
			ShowPlainMessageBox("Wrong Argument");
		}
	}

	void Edit_GrayScale() {
		double fileWidth = img_edited->Width;
		double fileHeight = img_edited->Height;
		Bitmap^ bmp_edited = gcnew Bitmap(fileWidth, fileHeight);

		for (int x = 0; x < fileWidth; x++) {
			for (int y = 0; y < fileHeight; y++) {
				int pxl_Red = arrayRedEdited[x][y];
				int pxl_Green = arrayGreenEdited[x][y];
				int pxl_Blue = arrayBlueEdited[x][y];
				int pxl_Grey = (pxl_Red + pxl_Green + pxl_Blue) / 3;

				Color pxl = Color::FromArgb(pxl_Grey, pxl_Grey, pxl_Grey);
				bmp_edited->SetPixel(x, y, pxl);
			}
		}

		pic_box_edited_img->Image = bmp_edited;
		img_edited = bmp_edited;
		Image2Array_Edited();
	}
};

}
