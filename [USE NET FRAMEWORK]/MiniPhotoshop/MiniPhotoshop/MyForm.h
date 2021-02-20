#pragma once
#include <string.h>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "image.h"

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

	protected:

	private: System::Windows::Forms::Label^ lbl_original_img;
	private: System::Windows::Forms::Label^ lbl_edited_image;


	private: System::Windows::Forms::PictureBox^ pic_box_original_img;
	private: System::Windows::Forms::PictureBox^ pic_box_edited_img;
	private: System::Windows::Forms::OpenFileDialog^ ofd;



	private: System::Windows::Forms::MenuStrip^ menu_strip;
	private: System::Windows::Forms::ToolStripMenuItem^ editImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ resetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openSecondImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editImageToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ gray_scale;


	private: System::Windows::Forms::ToolStripMenuItem^ imageBrighteningToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ image_brightening_scalar_addition;
	private: System::Windows::Forms::ToolStripMenuItem^ image_brightening_scalar_multiplication;


	private: System::Windows::Forms::ToolStripMenuItem^ aritmethicToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aritmethic_addition;
	private: System::Windows::Forms::ToolStripMenuItem^ aritmethic_subtraction;
	private: System::Windows::Forms::ToolStripMenuItem^ aritmethic_multiplication;
	private: System::Windows::Forms::ToolStripMenuItem^ aritmethic_division;
	private: System::Windows::Forms::ToolStripMenuItem^ boolean_and;





	private: System::Windows::Forms::ToolStripMenuItem^ aNDToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ boolean_not;
	private: System::Windows::Forms::ToolStripMenuItem^ boolean_or;
	private: System::Windows::Forms::ToolStripMenuItem^ boolean_xor;
	private: System::Windows::Forms::ToolStripMenuItem^ geometry_translation;




	private: System::Windows::Forms::ToolStripMenuItem^ translationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ geometry_rotation;
	private: System::Windows::Forms::ToolStripMenuItem^ geometry_flipping;
	private: System::Windows::Forms::ToolStripMenuItem^ geometry_zooming;



	private: System::Windows::Forms::ToolStripMenuItem^ imageEnhancementToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ image_enhancement_image_brightening;
	private: System::Windows::Forms::ToolStripMenuItem^ image_enhancement_constrast_stretching;
	private: System::Windows::Forms::ToolStripMenuItem^ image_enhancement_log_transformation;
	private: System::Windows::Forms::ToolStripMenuItem^ image_enhancement_inverse_log_transformation;
	private: System::Windows::Forms::ToolStripMenuItem^ image_enhancement_power_transformation;
	private: System::Windows::Forms::ToolStripMenuItem^ image_enhancement_gray_level_slicing;
	private: System::Windows::Forms::ToolStripMenuItem^ image_enhancement_bit_plane_slicing;
	private: System::Windows::Forms::ToolStripMenuItem^ image_enhancement_histogram_equalization;
	private: System::Windows::Forms::ToolStripMenuItem^ image_enhancement_histogram_specification;









	private: System::Windows::Forms::ToolStripMenuItem^ historgramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ show_histogram;

	private: System::Windows::Forms::ToolStripMenuItem^ open_image;
	private: System::Windows::Forms::ToolStripMenuItem^ reset_image;
	private: System::Windows::Forms::ToolStripMenuItem^ save_image;
	private: System::Windows::Forms::ToolStripMenuItem^ change_second_image;
private: System::Windows::Forms::ToolStripMenuItem^ negative_transformation;





	private: System::Windows::Forms::ToolStripMenuItem^ show_image_info;












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
			this->lbl_original_img = (gcnew System::Windows::Forms::Label());
			this->lbl_edited_image = (gcnew System::Windows::Forms::Label());
			this->pic_box_original_img = (gcnew System::Windows::Forms::PictureBox());
			this->pic_box_edited_img = (gcnew System::Windows::Forms::PictureBox());
			this->ofd = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menu_strip = (gcnew System::Windows::Forms::MenuStrip());
			this->editImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->open_image = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reset_image = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->save_image = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->change_second_image = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->show_image_info = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editImageToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gray_scale = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imageBrighteningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_brightening_scalar_addition = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_brightening_scalar_multiplication = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aritmethicToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aritmethic_addition = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aritmethic_subtraction = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aritmethic_multiplication = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aritmethic_division = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boolean_and = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aNDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boolean_not = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boolean_or = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boolean_xor = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->geometry_translation = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->translationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->geometry_rotation = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->geometry_flipping = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->geometry_zooming = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imageEnhancementToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_enhancement_image_brightening = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_enhancement_constrast_stretching = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_enhancement_log_transformation = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_enhancement_inverse_log_transformation = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_enhancement_power_transformation = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_enhancement_gray_level_slicing = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_enhancement_bit_plane_slicing = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_enhancement_histogram_equalization = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->image_enhancement_histogram_specification = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->negative_transformation = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->historgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->show_histogram = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openSecondImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_original_img))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_edited_img))->BeginInit();
			this->menu_strip->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbl_original_img
			// 
			this->lbl_original_img->AutoSize = true;
			this->lbl_original_img->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_original_img->Location = System::Drawing::Point(22, 42);
			this->lbl_original_img->Margin = System::Windows::Forms::Padding(0);
			this->lbl_original_img->Name = L"lbl_original_img";
			this->lbl_original_img->Size = System::Drawing::Size(108, 24);
			this->lbl_original_img->TabIndex = 2;
			this->lbl_original_img->Text = L"Main Image";
			// 
			// lbl_edited_image
			// 
			this->lbl_edited_image->AutoSize = true;
			this->lbl_edited_image->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_edited_image->Location = System::Drawing::Point(299, 42);
			this->lbl_edited_image->Name = L"lbl_edited_image";
			this->lbl_edited_image->Size = System::Drawing::Size(133, 24);
			this->lbl_edited_image->TabIndex = 3;
			this->lbl_edited_image->Text = L"Second Image";
			// 
			// pic_box_original_img
			// 
			this->pic_box_original_img->BackColor = System::Drawing::Color::White;
			this->pic_box_original_img->Location = System::Drawing::Point(26, 69);
			this->pic_box_original_img->Name = L"pic_box_original_img";
			this->pic_box_original_img->Size = System::Drawing::Size(235, 235);
			this->pic_box_original_img->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pic_box_original_img->TabIndex = 6;
			this->pic_box_original_img->TabStop = false;
			// 
			// pic_box_edited_img
			// 
			this->pic_box_edited_img->BackColor = System::Drawing::Color::White;
			this->pic_box_edited_img->Location = System::Drawing::Point(303, 69);
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
			// menu_strip
			// 
			this->menu_strip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->editImageToolStripMenuItem,
					this->editImageToolStripMenuItem1, this->historgramToolStripMenuItem
			});
			this->menu_strip->Location = System::Drawing::Point(0, 0);
			this->menu_strip->Name = L"menu_strip";
			this->menu_strip->Size = System::Drawing::Size(597, 24);
			this->menu_strip->TabIndex = 11;
			this->menu_strip->Text = L"menuStrip1";
			// 
			// editImageToolStripMenuItem
			// 
			this->editImageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->open_image,
					this->reset_image, this->save_image, this->change_second_image, this->show_image_info
			});
			this->editImageToolStripMenuItem->Name = L"editImageToolStripMenuItem";
			this->editImageToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->editImageToolStripMenuItem->Text = L"Image";
			// 
			// open_image
			// 
			this->open_image->Name = L"open_image";
			this->open_image->Size = System::Drawing::Size(193, 22);
			this->open_image->Text = L"Open Image";
			this->open_image->Click += gcnew System::EventHandler(this, &MyForm::open_image_Click);
			// 
			// reset_image
			// 
			this->reset_image->Name = L"reset_image";
			this->reset_image->Size = System::Drawing::Size(193, 22);
			this->reset_image->Text = L"Reset Image";
			this->reset_image->Click += gcnew System::EventHandler(this, &MyForm::reset_image_Click);
			// 
			// save_image
			// 
			this->save_image->Name = L"save_image";
			this->save_image->Size = System::Drawing::Size(193, 22);
			this->save_image->Text = L"Save Image";
			this->save_image->Click += gcnew System::EventHandler(this, &MyForm::save_image_Click);
			// 
			// change_second_image
			// 
			this->change_second_image->Name = L"change_second_image";
			this->change_second_image->Size = System::Drawing::Size(193, 22);
			this->change_second_image->Text = L"Change Second Image";
			this->change_second_image->Click += gcnew System::EventHandler(this, &MyForm::change_second_image_Click);
			// 
			// show_image_info
			// 
			this->show_image_info->Name = L"show_image_info";
			this->show_image_info->Size = System::Drawing::Size(193, 22);
			this->show_image_info->Text = L"Show Image Info";
			this->show_image_info->Click += gcnew System::EventHandler(this, &MyForm::show_image_info_Click);
			// 
			// editImageToolStripMenuItem1
			// 
			this->editImageToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->gray_scale,
					this->imageBrighteningToolStripMenuItem, this->aritmethicToolStripMenuItem, this->boolean_and, this->geometry_translation, this->imageEnhancementToolStripMenuItem,
					this->negative_transformation
			});
			this->editImageToolStripMenuItem1->Name = L"editImageToolStripMenuItem1";
			this->editImageToolStripMenuItem1->Size = System::Drawing::Size(75, 20);
			this->editImageToolStripMenuItem1->Text = L"Edit Image";
			// 
			// gray_scale
			// 
			this->gray_scale->Name = L"gray_scale";
			this->gray_scale->Size = System::Drawing::Size(183, 22);
			this->gray_scale->Text = L"GrasyScale";
			this->gray_scale->Click += gcnew System::EventHandler(this, &MyForm::gray_scale_Click);
			// 
			// imageBrighteningToolStripMenuItem
			// 
			this->imageBrighteningToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->image_brightening_scalar_addition,
					this->image_brightening_scalar_multiplication
			});
			this->imageBrighteningToolStripMenuItem->Name = L"imageBrighteningToolStripMenuItem";
			this->imageBrighteningToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->imageBrighteningToolStripMenuItem->Text = L"Image Brightening";
			// 
			// image_brightening_scalar_addition
			// 
			this->image_brightening_scalar_addition->Name = L"image_brightening_scalar_addition";
			this->image_brightening_scalar_addition->Size = System::Drawing::Size(182, 22);
			this->image_brightening_scalar_addition->Text = L"Scalar Addition";
			this->image_brightening_scalar_addition->Click += gcnew System::EventHandler(this, &MyForm::image_brightening_scalar_addition_Click);
			// 
			// image_brightening_scalar_multiplication
			// 
			this->image_brightening_scalar_multiplication->Name = L"image_brightening_scalar_multiplication";
			this->image_brightening_scalar_multiplication->Size = System::Drawing::Size(182, 22);
			this->image_brightening_scalar_multiplication->Text = L"Scalar Multiplication";
			this->image_brightening_scalar_multiplication->Click += gcnew System::EventHandler(this, &MyForm::image_brightening_scalar_multiplication_Click);
			// 
			// aritmethicToolStripMenuItem
			// 
			this->aritmethicToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->aritmethic_addition,
					this->aritmethic_subtraction, this->aritmethic_multiplication, this->aritmethic_division
			});
			this->aritmethicToolStripMenuItem->Name = L"aritmethicToolStripMenuItem";
			this->aritmethicToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->aritmethicToolStripMenuItem->Text = L"Aritmethic";
			// 
			// aritmethic_addition
			// 
			this->aritmethic_addition->Name = L"aritmethic_addition";
			this->aritmethic_addition->Size = System::Drawing::Size(180, 22);
			this->aritmethic_addition->Text = L"Addition";
			// 
			// aritmethic_subtraction
			// 
			this->aritmethic_subtraction->Name = L"aritmethic_subtraction";
			this->aritmethic_subtraction->Size = System::Drawing::Size(180, 22);
			this->aritmethic_subtraction->Text = L"Subtraction";
			// 
			// aritmethic_multiplication
			// 
			this->aritmethic_multiplication->Name = L"aritmethic_multiplication";
			this->aritmethic_multiplication->Size = System::Drawing::Size(180, 22);
			this->aritmethic_multiplication->Text = L"Multiplication";
			// 
			// aritmethic_division
			// 
			this->aritmethic_division->Name = L"aritmethic_division";
			this->aritmethic_division->Size = System::Drawing::Size(180, 22);
			this->aritmethic_division->Text = L"Division";
			// 
			// boolean_and
			// 
			this->boolean_and->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->aNDToolStripMenuItem,
					this->boolean_not, this->boolean_or, this->boolean_xor
			});
			this->boolean_and->Name = L"boolean_and";
			this->boolean_and->Size = System::Drawing::Size(183, 22);
			this->boolean_and->Text = L"Boolean";
			// 
			// aNDToolStripMenuItem
			// 
			this->aNDToolStripMenuItem->Name = L"aNDToolStripMenuItem";
			this->aNDToolStripMenuItem->Size = System::Drawing::Size(99, 22);
			this->aNDToolStripMenuItem->Text = L"AND";
			// 
			// boolean_not
			// 
			this->boolean_not->Name = L"boolean_not";
			this->boolean_not->Size = System::Drawing::Size(99, 22);
			this->boolean_not->Text = L"NOT";
			// 
			// boolean_or
			// 
			this->boolean_or->Name = L"boolean_or";
			this->boolean_or->Size = System::Drawing::Size(99, 22);
			this->boolean_or->Text = L"OR";
			// 
			// boolean_xor
			// 
			this->boolean_xor->Name = L"boolean_xor";
			this->boolean_xor->Size = System::Drawing::Size(99, 22);
			this->boolean_xor->Text = L"XOR";
			// 
			// geometry_translation
			// 
			this->geometry_translation->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->translationToolStripMenuItem,
					this->geometry_rotation, this->geometry_flipping, this->geometry_zooming
			});
			this->geometry_translation->Name = L"geometry_translation";
			this->geometry_translation->Size = System::Drawing::Size(183, 22);
			this->geometry_translation->Text = L"Geometry";
			// 
			// translationToolStripMenuItem
			// 
			this->translationToolStripMenuItem->Name = L"translationToolStripMenuItem";
			this->translationToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->translationToolStripMenuItem->Text = L"Translation";
			// 
			// geometry_rotation
			// 
			this->geometry_rotation->Name = L"geometry_rotation";
			this->geometry_rotation->Size = System::Drawing::Size(131, 22);
			this->geometry_rotation->Text = L"Rotation";
			// 
			// geometry_flipping
			// 
			this->geometry_flipping->Name = L"geometry_flipping";
			this->geometry_flipping->Size = System::Drawing::Size(131, 22);
			this->geometry_flipping->Text = L"Flipping";
			// 
			// geometry_zooming
			// 
			this->geometry_zooming->Name = L"geometry_zooming";
			this->geometry_zooming->Size = System::Drawing::Size(131, 22);
			this->geometry_zooming->Text = L"Zooming";
			// 
			// imageEnhancementToolStripMenuItem
			// 
			this->imageEnhancementToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->image_enhancement_image_brightening,
					this->image_enhancement_constrast_stretching, this->image_enhancement_log_transformation, this->image_enhancement_inverse_log_transformation,
					this->image_enhancement_power_transformation, this->image_enhancement_gray_level_slicing, this->image_enhancement_bit_plane_slicing,
					this->image_enhancement_histogram_equalization, this->image_enhancement_histogram_specification
			});
			this->imageEnhancementToolStripMenuItem->Name = L"imageEnhancementToolStripMenuItem";
			this->imageEnhancementToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->imageEnhancementToolStripMenuItem->Text = L"Image Enhancement";
			// 
			// image_enhancement_image_brightening
			// 
			this->image_enhancement_image_brightening->Name = L"image_enhancement_image_brightening";
			this->image_enhancement_image_brightening->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_image_brightening->Text = L"Image Brightening";
			// 
			// image_enhancement_constrast_stretching
			// 
			this->image_enhancement_constrast_stretching->Name = L"image_enhancement_constrast_stretching";
			this->image_enhancement_constrast_stretching->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_constrast_stretching->Text = L"Contrast Stretching";
			// 
			// image_enhancement_log_transformation
			// 
			this->image_enhancement_log_transformation->Name = L"image_enhancement_log_transformation";
			this->image_enhancement_log_transformation->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_log_transformation->Text = L"Log Transformation";
			// 
			// image_enhancement_inverse_log_transformation
			// 
			this->image_enhancement_inverse_log_transformation->Name = L"image_enhancement_inverse_log_transformation";
			this->image_enhancement_inverse_log_transformation->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_inverse_log_transformation->Text = L"Inverse Log Transformation";
			// 
			// image_enhancement_power_transformation
			// 
			this->image_enhancement_power_transformation->Name = L"image_enhancement_power_transformation";
			this->image_enhancement_power_transformation->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_power_transformation->Text = L"Power Transformation";
			// 
			// image_enhancement_gray_level_slicing
			// 
			this->image_enhancement_gray_level_slicing->Name = L"image_enhancement_gray_level_slicing";
			this->image_enhancement_gray_level_slicing->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_gray_level_slicing->Text = L"Gray-Level Slicing";
			// 
			// image_enhancement_bit_plane_slicing
			// 
			this->image_enhancement_bit_plane_slicing->Name = L"image_enhancement_bit_plane_slicing";
			this->image_enhancement_bit_plane_slicing->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_bit_plane_slicing->Text = L"Bit-Plane Slicing";
			// 
			// image_enhancement_histogram_equalization
			// 
			this->image_enhancement_histogram_equalization->Name = L"image_enhancement_histogram_equalization";
			this->image_enhancement_histogram_equalization->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_histogram_equalization->Text = L"Histogram Equalization";
			// 
			// image_enhancement_histogram_specification
			// 
			this->image_enhancement_histogram_specification->Name = L"image_enhancement_histogram_specification";
			this->image_enhancement_histogram_specification->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_histogram_specification->Text = L"Histogram Specification";
			// 
			// negative_transformation
			// 
			this->negative_transformation->Name = L"negative_transformation";
			this->negative_transformation->Size = System::Drawing::Size(183, 22);
			this->negative_transformation->Text = L"Negative";
			// 
			// historgramToolStripMenuItem
			// 
			this->historgramToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->show_histogram });
			this->historgramToolStripMenuItem->Name = L"historgramToolStripMenuItem";
			this->historgramToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->historgramToolStripMenuItem->Text = L"Historgram";
			// 
			// show_histogram
			// 
			this->show_histogram->Name = L"show_histogram";
			this->show_histogram->Size = System::Drawing::Size(162, 22);
			this->show_histogram->Text = L"Show Histogram";
			this->show_histogram->Click += gcnew System::EventHandler(this, &MyForm::show_histogram_Click);
			// 
			// openImageToolStripMenuItem
			// 
			this->openImageToolStripMenuItem->Name = L"openImageToolStripMenuItem";
			this->openImageToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->openImageToolStripMenuItem->Text = L"Open Image";
			// 
			// resetToolStripMenuItem
			// 
			this->resetToolStripMenuItem->Name = L"resetToolStripMenuItem";
			this->resetToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->resetToolStripMenuItem->Text = L"Reset";
			// 
			// saveImageToolStripMenuItem
			// 
			this->saveImageToolStripMenuItem->Name = L"saveImageToolStripMenuItem";
			this->saveImageToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->saveImageToolStripMenuItem->Text = L"Save Image";
			// 
			// openSecondImageToolStripMenuItem
			// 
			this->openSecondImageToolStripMenuItem->Name = L"openSecondImageToolStripMenuItem";
			this->openSecondImageToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->openSecondImageToolStripMenuItem->Text = L"Open Second Image";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(597, 310);
			this->Controls->Add(this->pic_box_edited_img);
			this->Controls->Add(this->pic_box_original_img);
			this->Controls->Add(this->lbl_edited_image);
			this->Controls->Add(this->lbl_original_img);
			this->Controls->Add(this->menu_strip);
			this->MainMenuStrip = this->menu_strip;
			this->Name = L"MyForm";
			this->Text = L"MiniPhotoshop";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_original_img))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_edited_img))->EndInit();
			this->menu_strip->ResumeLayout(false);
			this->menu_strip->PerformLayout();
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

	//Function Menu
	//// Image
	void OpenImage() {
		//ofd->Filter = "|*.jpg; *.jpeg; *.jpe; *.jfif; *.png";
		ofd->Filter = "|*.bmp; *.pgm; *.pbm; *.ppm";
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {


			//img_original = Image::FromFile(ofd->FileName);
			//img_edited = Image::FromFile(ofd->FileName);
			//Image2Array_Original();
			//Image2Array_Edited();
			//String^ extension_file = System::IO::Path::GetExtension(ofd->FileName);

			//pic_box_original_img->Image = img_original;
			//pic_box_edited_img->Image = img_edited;


			ShowPlainMessageBox(ofd->FileName);
		}
	}

	void SaveImage() {
		Bitmap^ bmp_edited = gcnew Bitmap(img_edited);
		bmp_edited->Save("C:\\Users\\User\\Downloads\\Save_Edited.jpg");
	}

	void ResetImage() {
		img_edited = img_original;
		pic_box_edited_img->Image = img_original;
		Image2Array_Edited();
	}

	void ChangeSecondImage() {

	}

	void ShowImageInfo() {
		if (img_original != nullptr) {
			double fileWidth = img_original->Width;
			double fileHeight = img_original->Height;
			ShowPlainMessageBox("Width: " + fileWidth + "\n" + "Height: " + fileHeight);
		}
	}

	//// Edit Image
	void GrayScale() {
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

	void NegativeTransformation() {

	}

	void ImageBrightening_ScalarAddition() {

	}

	void ImageBrightening_ScalarMultiplication() {

	}

	void Arithmethic_Addition() {

	}

	void Arithmethic_Subtraction() {

	}

	void Arithmethic_Multiplication() {

	}

	void Arithmethic_Division() {

	}

	void Boolean_AND() {

	}

	void Boolean_NOT() {

	}

	void Boolean_OR() {

	}

	void Boolean_XOR() {

	}

	void Geometry_Translation() {

	}

	void Geometry_Rotation() {

	}

	void Geometry_Flipping() {

	}

	void Geometry_Zooming() {

	}

	void ImageEnhancement_ImageBrightening() {

	}

	void ImageEnhancement_ConstrastStretching() {

	}

	void ImageEnhancement_LogTransformation() {

	}

	void ImageEnhancement_InverseLogTransformation() {

	}

	void ImageEnhancement_PowerTransformation() {

	}

	void ImageEnhancement_GrayLevelSlicing() {

	}

	void ImageEnhancement_BitPlaneSlicing() {

	}

	void ImageEnhancement_HistogramEqualization() {

	}

	void ImageEnhancement_HistogramSpecification() {

	}

	//// Histogram
	void ShowHistogram() {
		
	}

	//Example Message Box
	void ShowInputMessageBox() {
		String^ input = Interaction::InputBox("Brightness", "Title", "0", -1, -1);
		std::string standardString = convertTostring(input);
		if (isNumeric(standardString)) {
			try {
				int value = convertToInteger(standardString) + 10;
				ShowPlainMessageBox("Finish: " + value);
			}
			catch (std::invalid_argument const& e)
			{

			}
			catch (std::out_of_range const& e)
			{

			}

		}
		else {
			ShowPlainMessageBox("Input haruslah angka");
		}
	}

	void ShowPlainMessageBox(String^ str) {
		MessageBox::Show(str);
	}

	//Primitive Function
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

	//// Recent
	void TestStringIf() {
		//String^ strInput = txt_name_input->Text;
		//std::string standardString = marshal_as<std::string>(strInput);
		//const char* converted = standardString.c_str();

		//if (strcmp(converted, "gray_scale") == 0) {
		//	Edit_GrayScale();
		//}
		//else {
		//	ShowPlainMessageBox("Wrong Argument");
		//}
	}

	//[INTERFACE]
	private: System::Void open_image_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenImage();
	}

	private: System::Void show_histogram_Click(System::Object^ sender, System::EventArgs^ e) {
		ShowHistogram();
	}

	private: System::Void reset_image_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetImage();
	}

	private: System::Void save_image_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveImage();
	}

	private: System::Void change_second_image_Click(System::Object^ sender, System::EventArgs^ e) {
		ChangeSecondImage();
	}

	private: System::Void show_image_info_Click(System::Object^ sender, System::EventArgs^ e) {
		ShowImageInfo();
	}

	private: System::Void gray_scale_Click(System::Object^ sender, System::EventArgs^ e) {
		GrayScale();
	}


	private: System::Void image_brightening_scalar_addition_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageBrightening_ScalarAddition();
	}

	private: System::Void image_brightening_scalar_multiplication_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageBrightening_ScalarMultiplication();
	}


};

}
