#pragma once
#include <string.h>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "ImageProcessing.h"
#include "PrimitiveFunction.h"
#include "ExternalFile.h"

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
	private: System::Windows::Forms::PictureBox^ pic_box_main_img;
	private: System::Windows::Forms::PictureBox^ pic_box_second_img;

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
	private: System::Windows::Forms::ToolStripMenuItem^ boolean_menu;
	private: System::Windows::Forms::ToolStripMenuItem^ boolean_and_;

	private: System::Windows::Forms::ToolStripMenuItem^ boolean_not;
	private: System::Windows::Forms::ToolStripMenuItem^ boolean_or;
	private: System::Windows::Forms::ToolStripMenuItem^ boolean_xor;
	private: System::Windows::Forms::ToolStripMenuItem^ geometry_menu;
	private: System::Windows::Forms::ToolStripMenuItem^ geometry_translation_;

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ bar_chart;
	private: System::Windows::Forms::Label^ lbl_means;
	private: System::Windows::Forms::Label^ lbl_variance;
	private: System::Windows::Forms::Label^ lbl_standard_deviation;

	private: System::Windows::Forms::Label^ lbl_spec_histogram;
	private: System::Windows::Forms::ToolStripMenuItem^ show_histogram_2;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^ title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->lbl_original_img = (gcnew System::Windows::Forms::Label());
			this->lbl_edited_image = (gcnew System::Windows::Forms::Label());
			this->pic_box_main_img = (gcnew System::Windows::Forms::PictureBox());
			this->pic_box_second_img = (gcnew System::Windows::Forms::PictureBox());
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
			this->boolean_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boolean_and_ = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boolean_not = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boolean_or = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boolean_xor = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aritmethicToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aritmethic_addition = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aritmethic_subtraction = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aritmethic_multiplication = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aritmethic_division = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->geometry_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->geometry_translation_ = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->bar_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->lbl_means = (gcnew System::Windows::Forms::Label());
			this->lbl_variance = (gcnew System::Windows::Forms::Label());
			this->lbl_standard_deviation = (gcnew System::Windows::Forms::Label());
			this->lbl_spec_histogram = (gcnew System::Windows::Forms::Label());
			this->show_histogram_2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_main_img))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_second_img))->BeginInit();
			this->menu_strip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bar_chart))->BeginInit();
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
			// pic_box_main_img
			// 
			this->pic_box_main_img->BackColor = System::Drawing::Color::White;
			this->pic_box_main_img->Location = System::Drawing::Point(26, 69);
			this->pic_box_main_img->Name = L"pic_box_main_img";
			this->pic_box_main_img->Size = System::Drawing::Size(235, 235);
			this->pic_box_main_img->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pic_box_main_img->TabIndex = 6;
			this->pic_box_main_img->TabStop = false;
			// 
			// pic_box_second_img
			// 
			this->pic_box_second_img->BackColor = System::Drawing::Color::White;
			this->pic_box_second_img->Location = System::Drawing::Point(303, 69);
			this->pic_box_second_img->Name = L"pic_box_second_img";
			this->pic_box_second_img->Size = System::Drawing::Size(235, 235);
			this->pic_box_second_img->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pic_box_second_img->TabIndex = 7;
			this->pic_box_second_img->TabStop = false;
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
			this->menu_strip->Size = System::Drawing::Size(769, 24);
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
					this->imageBrighteningToolStripMenuItem, this->boolean_menu, this->aritmethicToolStripMenuItem, this->geometry_menu, this->imageEnhancementToolStripMenuItem,
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
			// boolean_menu
			// 
			this->boolean_menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->boolean_and_,
					this->boolean_not, this->boolean_or, this->boolean_xor
			});
			this->boolean_menu->Name = L"boolean_menu";
			this->boolean_menu->Size = System::Drawing::Size(183, 22);
			this->boolean_menu->Text = L"Boolean";
			// 
			// boolean_and_
			// 
			this->boolean_and_->Name = L"boolean_and_";
			this->boolean_and_->Size = System::Drawing::Size(99, 22);
			this->boolean_and_->Text = L"AND";
			this->boolean_and_->Click += gcnew System::EventHandler(this, &MyForm::boolean_and__Click);
			// 
			// boolean_not
			// 
			this->boolean_not->Name = L"boolean_not";
			this->boolean_not->Size = System::Drawing::Size(99, 22);
			this->boolean_not->Text = L"NOT";
			this->boolean_not->Click += gcnew System::EventHandler(this, &MyForm::boolean_not_Click);
			// 
			// boolean_or
			// 
			this->boolean_or->Name = L"boolean_or";
			this->boolean_or->Size = System::Drawing::Size(99, 22);
			this->boolean_or->Text = L"OR";
			this->boolean_or->Click += gcnew System::EventHandler(this, &MyForm::boolean_or_Click);
			// 
			// boolean_xor
			// 
			this->boolean_xor->Name = L"boolean_xor";
			this->boolean_xor->Size = System::Drawing::Size(99, 22);
			this->boolean_xor->Text = L"XOR";
			this->boolean_xor->Click += gcnew System::EventHandler(this, &MyForm::boolean_xor_Click);
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
			this->aritmethic_addition->Size = System::Drawing::Size(148, 22);
			this->aritmethic_addition->Text = L"Addition";
			this->aritmethic_addition->Click += gcnew System::EventHandler(this, &MyForm::aritmethic_addition_Click);
			// 
			// aritmethic_subtraction
			// 
			this->aritmethic_subtraction->Name = L"aritmethic_subtraction";
			this->aritmethic_subtraction->Size = System::Drawing::Size(148, 22);
			this->aritmethic_subtraction->Text = L"Subtraction";
			this->aritmethic_subtraction->Click += gcnew System::EventHandler(this, &MyForm::aritmethic_subtraction_Click);
			// 
			// aritmethic_multiplication
			// 
			this->aritmethic_multiplication->Name = L"aritmethic_multiplication";
			this->aritmethic_multiplication->Size = System::Drawing::Size(148, 22);
			this->aritmethic_multiplication->Text = L"Multiplication";
			this->aritmethic_multiplication->Click += gcnew System::EventHandler(this, &MyForm::aritmethic_multiplication_Click);
			// 
			// aritmethic_division
			// 
			this->aritmethic_division->Name = L"aritmethic_division";
			this->aritmethic_division->Size = System::Drawing::Size(148, 22);
			this->aritmethic_division->Text = L"Division";
			this->aritmethic_division->Click += gcnew System::EventHandler(this, &MyForm::aritmethic_division_Click);
			// 
			// geometry_menu
			// 
			this->geometry_menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->geometry_translation_,
					this->geometry_rotation, this->geometry_flipping, this->geometry_zooming
			});
			this->geometry_menu->Name = L"geometry_menu";
			this->geometry_menu->Size = System::Drawing::Size(183, 22);
			this->geometry_menu->Text = L"Geometry";
			// 
			// geometry_translation_
			// 
			this->geometry_translation_->Name = L"geometry_translation_";
			this->geometry_translation_->Size = System::Drawing::Size(131, 22);
			this->geometry_translation_->Text = L"Translation";
			this->geometry_translation_->Click += gcnew System::EventHandler(this, &MyForm::geometry_translation__Click);
			// 
			// geometry_rotation
			// 
			this->geometry_rotation->Name = L"geometry_rotation";
			this->geometry_rotation->Size = System::Drawing::Size(131, 22);
			this->geometry_rotation->Text = L"Rotation";
			this->geometry_rotation->Click += gcnew System::EventHandler(this, &MyForm::geometry_rotation_Click);
			// 
			// geometry_flipping
			// 
			this->geometry_flipping->Name = L"geometry_flipping";
			this->geometry_flipping->Size = System::Drawing::Size(131, 22);
			this->geometry_flipping->Text = L"Flipping";
			this->geometry_flipping->Click += gcnew System::EventHandler(this, &MyForm::geometry_flipping_Click);
			// 
			// geometry_zooming
			// 
			this->geometry_zooming->Name = L"geometry_zooming";
			this->geometry_zooming->Size = System::Drawing::Size(131, 22);
			this->geometry_zooming->Text = L"Zooming";
			this->geometry_zooming->Click += gcnew System::EventHandler(this, &MyForm::geometry_zooming_Click);
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
			this->image_enhancement_image_brightening->Click += gcnew System::EventHandler(this, &MyForm::image_enhancement_image_brightening_Click);
			// 
			// image_enhancement_constrast_stretching
			// 
			this->image_enhancement_constrast_stretching->Name = L"image_enhancement_constrast_stretching";
			this->image_enhancement_constrast_stretching->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_constrast_stretching->Text = L"Contrast Stretching";
			this->image_enhancement_constrast_stretching->Click += gcnew System::EventHandler(this, &MyForm::image_enhancement_constrast_stretching_Click);
			// 
			// image_enhancement_log_transformation
			// 
			this->image_enhancement_log_transformation->Name = L"image_enhancement_log_transformation";
			this->image_enhancement_log_transformation->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_log_transformation->Text = L"Log Transformation";
			this->image_enhancement_log_transformation->Click += gcnew System::EventHandler(this, &MyForm::image_enhancement_log_transformation_Click);
			// 
			// image_enhancement_inverse_log_transformation
			// 
			this->image_enhancement_inverse_log_transformation->Name = L"image_enhancement_inverse_log_transformation";
			this->image_enhancement_inverse_log_transformation->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_inverse_log_transformation->Text = L"Inverse Log Transformation";
			this->image_enhancement_inverse_log_transformation->Click += gcnew System::EventHandler(this, &MyForm::image_enhancement_inverse_log_transformation_Click);
			// 
			// image_enhancement_power_transformation
			// 
			this->image_enhancement_power_transformation->Name = L"image_enhancement_power_transformation";
			this->image_enhancement_power_transformation->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_power_transformation->Text = L"Power Transformation";
			this->image_enhancement_power_transformation->Click += gcnew System::EventHandler(this, &MyForm::image_enhancement_power_transformation_Click);
			// 
			// image_enhancement_gray_level_slicing
			// 
			this->image_enhancement_gray_level_slicing->Name = L"image_enhancement_gray_level_slicing";
			this->image_enhancement_gray_level_slicing->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_gray_level_slicing->Text = L"Gray-Level Slicing";
			this->image_enhancement_gray_level_slicing->Click += gcnew System::EventHandler(this, &MyForm::image_enhancement_gray_level_slicing_Click);
			// 
			// image_enhancement_bit_plane_slicing
			// 
			this->image_enhancement_bit_plane_slicing->Name = L"image_enhancement_bit_plane_slicing";
			this->image_enhancement_bit_plane_slicing->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_bit_plane_slicing->Text = L"Bit-Plane Slicing";
			this->image_enhancement_bit_plane_slicing->Click += gcnew System::EventHandler(this, &MyForm::image_enhancement_bit_plane_slicing_Click);
			// 
			// image_enhancement_histogram_equalization
			// 
			this->image_enhancement_histogram_equalization->Name = L"image_enhancement_histogram_equalization";
			this->image_enhancement_histogram_equalization->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_histogram_equalization->Text = L"Histogram Equalization";
			this->image_enhancement_histogram_equalization->Click += gcnew System::EventHandler(this, &MyForm::image_enhancement_histogram_equalization_Click);
			// 
			// image_enhancement_histogram_specification
			// 
			this->image_enhancement_histogram_specification->Name = L"image_enhancement_histogram_specification";
			this->image_enhancement_histogram_specification->Size = System::Drawing::Size(217, 22);
			this->image_enhancement_histogram_specification->Text = L"Histogram Specification";
			this->image_enhancement_histogram_specification->Click += gcnew System::EventHandler(this, &MyForm::image_enhancement_histogram_specification_Click);
			// 
			// negative_transformation
			// 
			this->negative_transformation->Name = L"negative_transformation";
			this->negative_transformation->Size = System::Drawing::Size(183, 22);
			this->negative_transformation->Text = L"Negative";
			this->negative_transformation->Click += gcnew System::EventHandler(this, &MyForm::negative_transformation_Click);
			// 
			// historgramToolStripMenuItem
			// 
			this->historgramToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->show_histogram,
					this->show_histogram_2
			});
			this->historgramToolStripMenuItem->Name = L"historgramToolStripMenuItem";
			this->historgramToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->historgramToolStripMenuItem->Text = L"Historgram";
			// 
			// show_histogram
			// 
			this->show_histogram->Name = L"show_histogram";
			this->show_histogram->Size = System::Drawing::Size(180, 22);
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
			// bar_chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->bar_chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->bar_chart->Legends->Add(legend1);
			this->bar_chart->Location = System::Drawing::Point(26, 310);
			this->bar_chart->Name = L"bar_chart";
			series1->ChartArea = L"ChartArea1";
			series1->Color = System::Drawing::Color::Red;
			series1->Legend = L"Legend1";
			series1->Name = L"Red";
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::Lime;
			series2->Legend = L"Legend1";
			series2->Name = L"Green";
			series3->ChartArea = L"ChartArea1";
			series3->Color = System::Drawing::Color::Blue;
			series3->Legend = L"Legend1";
			series3->Name = L"Blue";
			series4->ChartArea = L"ChartArea1";
			series4->Color = System::Drawing::Color::Black;
			series4->Legend = L"Legend1";
			series4->Name = L"Value";
			this->bar_chart->Series->Add(series1);
			this->bar_chart->Series->Add(series2);
			this->bar_chart->Series->Add(series3);
			this->bar_chart->Series->Add(series4);
			this->bar_chart->Size = System::Drawing::Size(731, 231);
			this->bar_chart->TabIndex = 12;
			this->bar_chart->Text = L"chart1";
			title1->Name = L"Red";
			title2->Name = L"Green";
			this->bar_chart->Titles->Add(title1);
			this->bar_chart->Titles->Add(title2);
			// 
			// lbl_means
			// 
			this->lbl_means->AutoSize = true;
			this->lbl_means->Location = System::Drawing::Point(559, 101);
			this->lbl_means->Name = L"lbl_means";
			this->lbl_means->Size = System::Drawing::Size(42, 13);
			this->lbl_means->TabIndex = 13;
			this->lbl_means->Text = L"Means:";
			// 
			// lbl_variance
			// 
			this->lbl_variance->AutoSize = true;
			this->lbl_variance->Location = System::Drawing::Point(559, 125);
			this->lbl_variance->Name = L"lbl_variance";
			this->lbl_variance->Size = System::Drawing::Size(52, 13);
			this->lbl_variance->TabIndex = 14;
			this->lbl_variance->Text = L"Variance:";
			// 
			// lbl_standard_deviation
			// 
			this->lbl_standard_deviation->AutoSize = true;
			this->lbl_standard_deviation->Location = System::Drawing::Point(559, 149);
			this->lbl_standard_deviation->Name = L"lbl_standard_deviation";
			this->lbl_standard_deviation->Size = System::Drawing::Size(101, 13);
			this->lbl_standard_deviation->TabIndex = 15;
			this->lbl_standard_deviation->Text = L"Standard Deviation:";
			// 
			// lbl_spec_histogram
			// 
			this->lbl_spec_histogram->AutoSize = true;
			this->lbl_spec_histogram->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_spec_histogram->Location = System::Drawing::Point(558, 69);
			this->lbl_spec_histogram->Name = L"lbl_spec_histogram";
			this->lbl_spec_histogram->Size = System::Drawing::Size(82, 20);
			this->lbl_spec_histogram->TabIndex = 16;
			this->lbl_spec_histogram->Text = L"Histogram";
			// 
			// show_histogram_2
			// 
			this->show_histogram_2->Name = L"show_histogram_2";
			this->show_histogram_2->Size = System::Drawing::Size(180, 22);
			this->show_histogram_2->Text = L"Show Histogram 2";
			this->show_histogram_2->Click += gcnew System::EventHandler(this, &MyForm::show_histogram_2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(769, 550);
			this->Controls->Add(this->lbl_spec_histogram);
			this->Controls->Add(this->lbl_standard_deviation);
			this->Controls->Add(this->lbl_variance);
			this->Controls->Add(this->lbl_means);
			this->Controls->Add(this->bar_chart);
			this->Controls->Add(this->pic_box_second_img);
			this->Controls->Add(this->pic_box_main_img);
			this->Controls->Add(this->lbl_edited_image);
			this->Controls->Add(this->lbl_original_img);
			this->Controls->Add(this->menu_strip);
			this->MainMenuStrip = this->menu_strip;
			this->Name = L"MyForm";
			this->Text = L"MiniPhotoshop";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_main_img))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_box_second_img))->EndInit();
			this->menu_strip->ResumeLayout(false);
			this->menu_strip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bar_chart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//[INTERFACE]
	private: System::Void open_image_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenImage();
	}

	private: System::Void show_histogram_Click(System::Object^ sender, System::EventArgs^ e) {
		ShowHistogram();
	}

	private: System::Void show_histogram_2_Click(System::Object^ sender, System::EventArgs^ e) {
		ShowHistogram_2();
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

	// Edit Image
	private: System::Void gray_scale_Click(System::Object^ sender, System::EventArgs^ e) {
		GrayScale();
	}

	private: System::Void image_brightening_scalar_addition_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageBrightening_ScalarAddition();
	}

	private: System::Void image_brightening_scalar_multiplication_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageBrightening_ScalarMultiplication();
	}

	private: System::Void aritmethic_addition_Click(System::Object^ sender, System::EventArgs^ e) {
		Arithmethic_Addition();
	}

	private: System::Void aritmethic_subtraction_Click(System::Object^ sender, System::EventArgs^ e) {
		Arithmethic_Subtraction();
	}

	private: System::Void aritmethic_multiplication_Click(System::Object^ sender, System::EventArgs^ e) {
		Arithmethic_Multiplication();
	}

	private: System::Void aritmethic_division_Click(System::Object^ sender, System::EventArgs^ e) {
		Arithmethic_Division();
	}

	private: System::Void boolean_and__Click(System::Object^ sender, System::EventArgs^ e) {
		Boolean_AND();
	}

	private: System::Void boolean_not_Click(System::Object^ sender, System::EventArgs^ e) {
		Boolean_NOT();
	}
	private: System::Void boolean_or_Click(System::Object^ sender, System::EventArgs^ e) {
		Boolean_OR();
	}
	private: System::Void boolean_xor_Click(System::Object^ sender, System::EventArgs^ e) {
		Boolean_XOR();
	}

	private: System::Void geometry_translation__Click(System::Object^ sender, System::EventArgs^ e) {
		Geometry_Translation();
	}

	private: System::Void geometry_rotation_Click(System::Object^ sender, System::EventArgs^ e) {
		Geometry_Rotation();
	}

	private: System::Void geometry_flipping_Click(System::Object^ sender, System::EventArgs^ e) {
		Geometry_Flipping();
	}

	private: System::Void geometry_zooming_Click(System::Object^ sender, System::EventArgs^ e) {
		Geometry_Zooming();
	}

	private: System::Void image_enhancement_image_brightening_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageEnhancement_ImageBrightening();
	}

	private: System::Void image_enhancement_constrast_stretching_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageEnhancement_ConstrastStretching();
	}

	private: System::Void image_enhancement_log_transformation_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageEnhancement_LogTransformation();
	}

	private: System::Void image_enhancement_inverse_log_transformation_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageEnhancement_InverseLogTransformation();
	}

	private: System::Void image_enhancement_power_transformation_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageEnhancement_PowerTransformation();
	}

	private: System::Void image_enhancement_gray_level_slicing_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageEnhancement_GrayLevelSlicing();
	}

	private: System::Void image_enhancement_bit_plane_slicing_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageEnhancement_BitPlaneSlicing();
	}

	private: System::Void image_enhancement_histogram_equalization_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageEnhancement_HistogramEqualization();
	}

	private: System::Void image_enhancement_histogram_specification_Click(System::Object^ sender, System::EventArgs^ e) {
		ImageEnhancement_HistogramSpecification();
	}

	private: System::Void negative_transformation_Click(System::Object^ sender, System::EventArgs^ e) {
		NegativeTransformation();
	}

	//[MAIN]
	Bitmap^ bitmapMainImage;
	Bitmap^ bitmapMainOriginalImage;
	Bitmap^ bitmapSecondImage;

	//[Function Menu]
	//// Image
	void OpenImage() {
		//ofd->Filter = "|*.jpg; *.jpeg; *.jpe; *.jfif; *.png";
		ofd->Filter = "|*.bmp; *.pgm; *.pbm; *.ppm; *.jpg";
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ extension_file = System::IO::Path::GetExtension(ofd->FileName);
			std::string standardString = convertTostring(extension_file);
			const char* ext_file = standardString.c_str();
		
			if (strcmp(ext_file, ".bmp") == 0) {
				// bmp
				Bitmap^ imageMainImage = Image_BitmapFile(ofd->FileName);
				pic_box_main_img->Image = imageMainImage;
				bitmapMainImage = gcnew Bitmap(imageMainImage);
				bitmapMainOriginalImage = gcnew Bitmap(imageMainImage);
				bitmapSecondImage = nullptr;
				pic_box_second_img->Image = nullptr;
			}
			else if (strcmp(ext_file, ".pgm") == 0) {
				// pgm
				Bitmap^ imageMainImage = Image_PGMFile(ofd->FileName);
				pic_box_main_img->Image = imageMainImage;
				bitmapMainImage = gcnew Bitmap(imageMainImage);
				bitmapMainOriginalImage = gcnew Bitmap(imageMainImage);
				bitmapSecondImage = nullptr;
				pic_box_second_img->Image = nullptr;
			}
			else if (strcmp(ext_file, ".pbm") == 0) {
				// pbm
				Bitmap^ imageMainImage = Image_PBMFile(ofd->FileName);
				pic_box_main_img->Image = imageMainImage;
				bitmapMainImage = gcnew Bitmap(imageMainImage);
				bitmapMainOriginalImage = gcnew Bitmap(imageMainImage);
				bitmapSecondImage = nullptr;
				pic_box_second_img->Image = nullptr;
			}
			else if (strcmp(ext_file, ".ppm") == 0) {
				// ppm
				Bitmap^ imageMainImage = Image_PPMFile(ofd->FileName);
				pic_box_main_img->Image = imageMainImage;
				bitmapMainImage = gcnew Bitmap(imageMainImage);
				bitmapMainOriginalImage = gcnew Bitmap(imageMainImage);
				bitmapSecondImage = nullptr;
				pic_box_second_img->Image = nullptr;
			}
			else {
				// Raw Image
				Bitmap^ imageMainImage = Image_RawImageFile(ofd->FileName);
				pic_box_main_img->Image = imageMainImage;
				bitmapMainImage = gcnew Bitmap(imageMainImage);
				bitmapMainOriginalImage = gcnew Bitmap(imageMainImage);
				bitmapSecondImage = nullptr;
				pic_box_second_img->Image = nullptr;
			}
		
		}
	}

	void ChangeSecondImage() {
		if (bitmapMainImage != nullptr) {
			ofd->Filter = "|*.bmp; *.pgm; *.pbm; *.ppm; *.jpg";
			if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				String^ extension_file = System::IO::Path::GetExtension(ofd->FileName);
				std::string standardString = convertTostring(extension_file);
				const char* ext_file = standardString.c_str();

				if (strcmp(ext_file, ".bmp") == 0) {
					// bmp
					Bitmap^ image = Image_BitmapFile(ofd->FileName);
					bitmapSecondImage = gcnew Bitmap(image);
					if (CheckSizeBitmap(bitmapMainImage, bitmapSecondImage)) {
						pic_box_second_img->Image = image;
					}
					else {
						ShowPlainMessageBox("Image's Size must be same");
						bitmapSecondImage = nullptr;
					}
				}
				else if (strcmp(ext_file, ".pgm") == 0) {
					// pgm
					Bitmap^ image = Image_PGMFile(ofd->FileName);
					bitmapSecondImage = gcnew Bitmap(image);
					if (CheckSizeBitmap(bitmapMainImage, bitmapSecondImage)) {
						pic_box_second_img->Image = image;
					}
					else {
						ShowPlainMessageBox("Image's Size must be same");
						bitmapSecondImage = nullptr;
					}
				}
				else if (strcmp(ext_file, ".pbm") == 0) {
					// pbm
					Bitmap^ image = Image_PBMFile(ofd->FileName);
					bitmapSecondImage = gcnew Bitmap(image);
					if (CheckSizeBitmap(bitmapMainImage, bitmapSecondImage)) {
						pic_box_second_img->Image = image;
					}
					else {
						ShowPlainMessageBox("Image's Size must be same");
						bitmapSecondImage = nullptr;
					}
				}
				else if (strcmp(ext_file, ".ppm") == 0) {
					// ppm
					Bitmap^ image = Image_PPMFile(ofd->FileName);
					bitmapSecondImage = gcnew Bitmap(image);
					if (CheckSizeBitmap(bitmapMainImage, bitmapSecondImage)) {
						pic_box_second_img->Image = image;
					}
					else {
						ShowPlainMessageBox("Image's Size must be same");
						bitmapSecondImage = nullptr;
					}
				}
				else {
					// Raw Image
					Bitmap^ image = Image_RawImageFile(ofd->FileName);
					bitmapSecondImage = gcnew Bitmap(image);
					if (CheckSizeBitmap(bitmapMainImage, bitmapSecondImage)) {
						pic_box_second_img->Image = image;
					}
					else {
						ShowPlainMessageBox("Image's Size must be same");
						bitmapSecondImage = nullptr;
					}
				}

			}
		}
		else {
			ShowPlainMessageBox("Insert Main Image First");
		}

	}

	void SaveImage() {
		if (bitmapMainImage != nullptr) {
			String^ input = Interaction::InputBox("Image Name", "Insert Name", "Untitled", -1, -1);
			std::string standardString = convertTostring(input);
			bitmapMainImage->Save("C:\\Users\\User\\Downloads\\" + input + ".bmp");
		}
		else {
			ShowPlainMessageBox("Please Open Image First");
		}
	}

	void ResetImage() {
		if (bitmapMainImage != nullptr) {
			bitmapMainImage = gcnew Bitmap(bitmapMainOriginalImage);
			pic_box_main_img->Image = bitmapMainImage;
		}
		else {
			ShowPlainMessageBox("Please Open Image First");
		}
	}

	void ShowImageInfo() {
	
	}

	//// [Edit Image Menu]
	void GrayScale() {
		if (bitmapMainImage != nullptr) {
			bitmapMainImage = Image_GrayScale(bitmapMainImage);
			pic_box_main_img->Image = bitmapMainImage;
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void NegativeTransformation() {
		if (bitmapMainImage != nullptr) {
			bitmapMainImage = Image_NegativeTransformation(bitmapMainImage);
			pic_box_main_img->Image = bitmapMainImage;
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ImageBrightening_ScalarAddition() {
		if (bitmapMainImage != nullptr) {
			String^ input = Interaction::InputBox("Scalar Value", "Insert Scalar Value", "0", -1, -1);
			std::string standardString = convertTostring(input);
			try {
				int value = convertToInteger(standardString);
				bitmapMainImage = Image_ImageBrightening_ScalarAddition(bitmapMainImage,value);
				pic_box_main_img->Image = bitmapMainImage;
			}
			catch (std::invalid_argument const& e)
			{
				ShowPlainMessageBox("Input must be numbers");
			}
			catch (std::out_of_range const& e)
			{
				ShowPlainMessageBox("Input must be numbers");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
		
	}

	void ImageBrightening_ScalarMultiplication() {
		if (bitmapMainImage != nullptr) {
			String^ input = Interaction::InputBox("Scalar Value", "Insert Scalar Value", "0", -1, -1);
			std::string standardString = convertTostring(input);
			try {
				int value = convertToInteger(standardString);
				bitmapMainImage = Image_ImageBrightening_ScalarMultiplication(bitmapMainImage, value);
				pic_box_main_img->Image = bitmapMainImage;
			}
			catch (std::invalid_argument const& e)
			{
				ShowPlainMessageBox("Input must be numbers");
			}
			catch (std::out_of_range const& e)
			{
				ShowPlainMessageBox("Input must be numbers");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Arithmethic_Addition() {
		if (bitmapMainImage != nullptr) {
			if (bitmapSecondImage != nullptr) {
				bitmapMainImage = Image_Arithmethic_Addition(bitmapMainImage, bitmapSecondImage);
				pic_box_main_img->Image = bitmapMainImage;
			}
			else {
				ShowPlainMessageBox("Insert The Second Image");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Arithmethic_Subtraction() {
		if (bitmapMainImage != nullptr) {
			if (bitmapSecondImage != nullptr) {
				bitmapMainImage = Image_Arithmethic_Subtraction(bitmapMainImage, bitmapSecondImage);
				pic_box_main_img->Image = bitmapMainImage;
			}
			else {
				ShowPlainMessageBox("Insert The Second Image");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Arithmethic_Multiplication() {
		if (bitmapMainImage != nullptr) {
			if (bitmapSecondImage != nullptr) {
				bitmapMainImage = Image_Arithmethic_Multiplication(bitmapMainImage, bitmapSecondImage);
				pic_box_main_img->Image = bitmapMainImage;
			}
			else {
				ShowPlainMessageBox("Insert The Second Image");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Arithmethic_Division() {
		if (bitmapMainImage != nullptr) {
			if (bitmapSecondImage != nullptr) {
				bitmapMainImage = Image_Arithmethic_Division(bitmapMainImage, bitmapSecondImage);
				pic_box_main_img->Image = bitmapMainImage;
			}
			else {
				ShowPlainMessageBox("Insert The Second Image");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Boolean_AND() {
		if (bitmapMainImage != nullptr) {
			if (bitmapSecondImage != nullptr) {
				bitmapMainImage = Image_Boolean_AND(bitmapMainImage, bitmapSecondImage);
				pic_box_main_img->Image = bitmapMainImage;
			}
			else {
				ShowPlainMessageBox("Insert The Second Image");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Boolean_NOT() {
		if (bitmapMainImage != nullptr) {
			bitmapMainImage = Image_Boolean_NOT(bitmapMainImage);
			pic_box_main_img->Image = bitmapMainImage;
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Boolean_OR() {
		if (bitmapMainImage != nullptr) {
			if (bitmapSecondImage != nullptr) {
				bitmapMainImage = Image_Boolean_OR(bitmapMainImage, bitmapSecondImage);
				pic_box_main_img->Image = bitmapMainImage;
			}
			else {
				ShowPlainMessageBox("Insert The Second Image");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Boolean_XOR() {
		if (bitmapMainImage != nullptr) {
			if (bitmapSecondImage != nullptr) {
				bitmapMainImage = Image_Boolean_XOR(bitmapMainImage, bitmapSecondImage);
				pic_box_main_img->Image = bitmapMainImage;
			}
			else {
				ShowPlainMessageBox("Insert The Second Image");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Geometry_Translation() {
		if (bitmapMainImage != nullptr) {

		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Geometry_Rotation() {
		if (bitmapMainImage != nullptr) {

		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Geometry_Flipping() {
		if (bitmapMainImage != nullptr) {

		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void Geometry_Zooming() {
		if (bitmapMainImage != nullptr) {

		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ImageEnhancement_ImageBrightening() {
		if (bitmapMainImage != nullptr) {

		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ImageEnhancement_ConstrastStretching() {
		if (bitmapMainImage != nullptr) {

		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ImageEnhancement_LogTransformation() {
		if (bitmapMainImage != nullptr) {

		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ImageEnhancement_InverseLogTransformation() {
		if (bitmapMainImage != nullptr) {

		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ImageEnhancement_PowerTransformation() {
		if (bitmapMainImage != nullptr) {
			String^ input_C = Interaction::InputBox("C-Input", "Insert Value of C", "1", -1, -1);
			std::string str_C = convertTostring(input_C);
			try {
				double value_C = convertToDouble(str_C);
				if (value_C < 0) {
					ShowPlainMessageBox("Input must be > 0");
				}
				else {
					String^ input_Y = Interaction::InputBox("Y-Input", "Insert Value of Y", "1", -1, -1);
					std::string str_Y = convertTostring(input_Y);

					try {
						double value_Y = convertToDouble(str_Y);
						if (value_Y < 0) {
							ShowPlainMessageBox("Input must be > 0");
						}
						else {
							bitmapMainImage = Image_ImageEnhancement_PowerTransformation(
								bitmapMainImage, value_C, value_Y);
							pic_box_main_img->Image = bitmapMainImage;
						}						
					}
					catch (std::invalid_argument const& e)
					{
						ShowPlainMessageBox("Input must be numbers");
					}
					catch (std::out_of_range const& e)
					{
						ShowPlainMessageBox("Input must be numbers");
					}
				}
			}
			catch (std::invalid_argument const& e)
			{
				ShowPlainMessageBox("Input must be numbers");
			}
			catch (std::out_of_range const& e)
			{
				ShowPlainMessageBox("Input must be numbers");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ImageEnhancement_GrayLevelSlicing() {
		if (bitmapMainImage != nullptr) {
			String^ input_1 = Interaction::InputBox("Input-1", "Insert Input-1", "1", -1, -1);
			std::string str_1 = convertTostring(input_1);
			try {
				int value_1 = convertToInteger(str_1);
				if (value_1 < 0 || value_1 > 255) {
					ShowPlainMessageBox("Invalid Input");
				}
				else {
					String^ input_2 = Interaction::InputBox("Input-2", "Insert Input-2", "1", -1, -1);
					std::string str_2 = convertTostring(input_2);

					try {
						int value_2 = convertToInteger(str_2);
						if (value_2 < 0 || value_2 > 255) {
							ShowPlainMessageBox("Invalid Input");
						}
						else if (value_1 >= value_2) {
							ShowPlainMessageBox("Value_1 must < Value_2");
						}
						else {
							bitmapMainImage = Image_ImageEnhancement_GrayLevelSlicing(
								bitmapMainImage, value_1, value_2);
							pic_box_main_img->Image = bitmapMainImage;
						}
					}
					catch (std::invalid_argument const& e)
					{
						ShowPlainMessageBox("Input must be numbers");
					}
					catch (std::out_of_range const& e)
					{
						ShowPlainMessageBox("Input must be numbers");
					}
				}
			}
			catch (std::invalid_argument const& e)
			{
				ShowPlainMessageBox("Input must be numbers");
			}
			catch (std::out_of_range const& e)
			{
				ShowPlainMessageBox("Input must be numbers");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ImageEnhancement_BitPlaneSlicing() {
		if (bitmapMainImage != nullptr) {
			String^ input_Y = Interaction::InputBox("Level", "Insert Level 0-7", "1", -1, -1);
			std::string str_Y = convertTostring(input_Y);

			try {
				int level_plane = convertToInteger(str_Y);
				if (level_plane == 0) {
					bitmapMainImage = Image_ImageEnhancement_BitPlaneSlicing(
						bitmapMainImage, level_plane);
					pic_box_main_img->Image = bitmapMainImage;
				}
				else if (level_plane == 1) {
					bitmapMainImage = Image_ImageEnhancement_BitPlaneSlicing(
						bitmapMainImage, level_plane);
					pic_box_main_img->Image = bitmapMainImage;
				}
				else if (level_plane == 2) {
					bitmapMainImage = Image_ImageEnhancement_BitPlaneSlicing(
						bitmapMainImage, level_plane);
					pic_box_main_img->Image = bitmapMainImage;
				}
				else if (level_plane == 3) {
					bitmapMainImage = Image_ImageEnhancement_BitPlaneSlicing(
						bitmapMainImage, level_plane);
					pic_box_main_img->Image = bitmapMainImage;
				}
				else if (level_plane == 4) {
					bitmapMainImage = Image_ImageEnhancement_BitPlaneSlicing(
						bitmapMainImage, level_plane);
					pic_box_main_img->Image = bitmapMainImage;
				}
				else if (level_plane == 5) {
					bitmapMainImage = Image_ImageEnhancement_BitPlaneSlicing(
						bitmapMainImage, level_plane);
					pic_box_main_img->Image = bitmapMainImage;
				}
				else if (level_plane == 6) {
					bitmapMainImage = Image_ImageEnhancement_BitPlaneSlicing(
						bitmapMainImage, level_plane);
					pic_box_main_img->Image = bitmapMainImage;
				}
				else if (level_plane == 7) {
					bitmapMainImage = Image_ImageEnhancement_BitPlaneSlicing(
						bitmapMainImage, level_plane);
					pic_box_main_img->Image = bitmapMainImage;
				}
				else {
					ShowPlainMessageBox("Invalid Input");
				}
			}
			catch (std::invalid_argument const& e)
			{
				ShowPlainMessageBox("Input must be numbers");
			}
			catch (std::out_of_range const& e)
			{
				ShowPlainMessageBox("Input must be numbers");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ImageEnhancement_HistogramEqualization() {
		if (bitmapMainImage != nullptr) {

		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ImageEnhancement_HistogramSpecification() {
		if (bitmapMainImage != nullptr) {
			if (bitmapSecondImage != nullptr) {
				bitmapMainImage = Image_ImageEnhancement_HistogramSpecification(bitmapMainImage, bitmapSecondImage);
				pic_box_main_img->Image = bitmapMainImage;
			}
			else {
				ShowPlainMessageBox("Insert The Second Image");
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	//// Histogram
	void ShowHistogram() {
		if (bitmapMainImage != nullptr) {
			String^ type_image = TypeImage(bitmapMainImage);
			std::string standardString = convertTostring(type_image);
			const char* type_img = standardString.c_str();

			bar_chart->Legends->Clear();
			bar_chart->Series["Red"]->Points->Clear();
			bar_chart->Series["Green"]->Points->Clear();
			bar_chart->Series["Blue"]->Points->Clear();
			bar_chart->Series["Value"]->Points->Clear();

			if (strcmp(type_img, "Biner") == 0) {
				// Biner
				int* arr_biner = Array_Biner(bitmapMainImage);
				double means = Get_Means(arr_biner, 256);
				double variance = Get_Variance(arr_biner, 256);
				double standard_deviation = Get_StandardDeviation(arr_biner, 256);

				lbl_means->Text = "Means: " + means;
				lbl_variance->Text = "Variance: " + variance;
				lbl_standard_deviation->Text = "Standard Deviation: " + standard_deviation;

				for (int i = 0; i < 2; i += 1) {
					bar_chart->Series["Value"]->Points->AddXY(i, arr_biner[i]);
				}
			}else if (strcmp(type_img, "GrayScale") == 0) {
				// GrayScale
				int* arr_grayscale = Array_GrayScale(bitmapMainImage);
				double means = Get_Means(arr_grayscale, 256);
				double variance = Get_Variance(arr_grayscale, 256);
				double standard_deviation = Get_StandardDeviation(arr_grayscale, 256);

				lbl_means->Text = "Means: " + means;
				lbl_variance->Text = "Variance: " + variance;
				lbl_standard_deviation->Text = "Standard Deviation: " + standard_deviation;

				for (int i = 0; i <= 255; i += 1) {
					bar_chart->Series["Value"]->Points->AddXY(i + 1, arr_grayscale[i]);
				}
			}else if (strcmp(type_img, "RGB") == 0) {
				// RGB
				// Check R,G,B
				String^ input = Interaction::InputBox("Choose RGB", "R or G or B", "R", -1, -1);
				std::string input_RGB = convertTostring(input);
				const char* char_RGB = input_RGB.c_str();
				if (strcmp(char_RGB, "R") == 0) {
					int* arr_red = Array_Red(bitmapMainImage);
					double means = Get_Means(arr_red, 256);
					double variance = Get_Variance(arr_red, 256);
					double standard_deviation = Get_StandardDeviation(arr_red, 256);

					lbl_means->Text = "Means: " + means;
					lbl_variance->Text = "Variance: " + variance;
					lbl_standard_deviation->Text = "Standard Deviation: " + standard_deviation;

					for (int i = 0; i <= 255; i += 1) {
						bar_chart->Series["Red"]->Points->AddXY(i + 1, arr_red[i]);
					}
				}
				else if (strcmp(char_RGB, "G") == 0) {
					int* arr_green = Array_Green(bitmapMainImage);
					double means = Get_Means(arr_green, 256);
					double variance = Get_Variance(arr_green, 256);
					double standard_deviation = Get_StandardDeviation(arr_green, 256);

					lbl_means->Text = "Means: " + means;
					lbl_variance->Text = "Variance: " + variance;
					lbl_standard_deviation->Text = "Standard Deviation: " + standard_deviation;

					for (int i = 0; i <= 255; i += 1) {
						bar_chart->Series["Green"]->Points->AddXY(i + 1, arr_green[i]);
					}
				}
				else if (strcmp(char_RGB, "B") == 0) {
					int* arr_blue = Array_Blue(bitmapMainImage);
					double means = Get_Means(arr_blue, 256);
					double variance = Get_Variance(arr_blue, 256);
					double standard_deviation = Get_StandardDeviation(arr_blue, 256);

					lbl_means->Text = "Means: " + means;
					lbl_variance->Text = "Variance: " + variance;
					lbl_standard_deviation->Text = "Standard Deviation: " + standard_deviation;

					for (int i = 0; i <= 255; i += 1) {
						bar_chart->Series["Blue"]->Points->AddXY(i + 1, arr_blue[i]);
					}
				}
				else {
					ShowPlainMessageBox("Invalid Input");
				}			
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	void ShowHistogram_2() {
		if (bitmapSecondImage != nullptr) {
			String^ type_image = TypeImage(bitmapSecondImage);
			std::string standardString = convertTostring(type_image);
			const char* type_img = standardString.c_str();

			bar_chart->Legends->Clear();
			bar_chart->Series["Red"]->Points->Clear();
			bar_chart->Series["Green"]->Points->Clear();
			bar_chart->Series["Blue"]->Points->Clear();
			bar_chart->Series["Value"]->Points->Clear();

			if (strcmp(type_img, "Biner") == 0) {
				// Biner
				int* arr_biner = Array_Biner(bitmapSecondImage);
				double means = Get_Means(arr_biner, 256);
				double variance = Get_Variance(arr_biner, 256);
				double standard_deviation = Get_StandardDeviation(arr_biner, 256);

				lbl_means->Text = "Means: " + means;
				lbl_variance->Text = "Variance: " + variance;
				lbl_standard_deviation->Text = "Standard Deviation: " + standard_deviation;

				for (int i = 0; i < 2; i += 1) {
					bar_chart->Series["Value"]->Points->AddXY(i, arr_biner[i]);
				}
			}
			else if (strcmp(type_img, "GrayScale") == 0) {
				// GrayScale
				int* arr_grayscale = Array_GrayScale(bitmapSecondImage);
				double means = Get_Means(arr_grayscale, 256);
				double variance = Get_Variance(arr_grayscale, 256);
				double standard_deviation = Get_StandardDeviation(arr_grayscale, 256);

				lbl_means->Text = "Means: " + means;
				lbl_variance->Text = "Variance: " + variance;
				lbl_standard_deviation->Text = "Standard Deviation: " + standard_deviation;

				for (int i = 0; i <= 255; i += 1) {
					bar_chart->Series["Value"]->Points->AddXY(i + 1, arr_grayscale[i]);
				}
			}
			else if (strcmp(type_img, "RGB") == 0) {
				// RGB
				// Check R,G,B
				String^ input = Interaction::InputBox("Choose RGB", "R or G or B", "R", -1, -1);
				std::string input_RGB = convertTostring(input);
				const char* char_RGB = input_RGB.c_str();
				if (strcmp(char_RGB, "R") == 0) {
					int* arr_red = Array_Red(bitmapSecondImage);
					double means = Get_Means(arr_red, 256);
					double variance = Get_Variance(arr_red, 256);
					double standard_deviation = Get_StandardDeviation(arr_red, 256);

					lbl_means->Text = "Means: " + means;
					lbl_variance->Text = "Variance: " + variance;
					lbl_standard_deviation->Text = "Standard Deviation: " + standard_deviation;

					for (int i = 0; i <= 255; i += 1) {
						bar_chart->Series["Red"]->Points->AddXY(i + 1, arr_red[i]);
					}
				}
				else if (strcmp(char_RGB, "G") == 0) {
					int* arr_green = Array_Green(bitmapSecondImage);
					double means = Get_Means(arr_green, 256);
					double variance = Get_Variance(arr_green, 256);
					double standard_deviation = Get_StandardDeviation(arr_green, 256);

					lbl_means->Text = "Means: " + means;
					lbl_variance->Text = "Variance: " + variance;
					lbl_standard_deviation->Text = "Standard Deviation: " + standard_deviation;

					for (int i = 0; i <= 255; i += 1) {
						bar_chart->Series["Green"]->Points->AddXY(i + 1, arr_green[i]);
					}
				}
				else if (strcmp(char_RGB, "B") == 0) {
					int* arr_blue = Array_Blue(bitmapSecondImage);
					double means = Get_Means(arr_blue, 256);
					double variance = Get_Variance(arr_blue, 256);
					double standard_deviation = Get_StandardDeviation(arr_blue, 256);

					lbl_means->Text = "Means: " + means;
					lbl_variance->Text = "Variance: " + variance;
					lbl_standard_deviation->Text = "Standard Deviation: " + standard_deviation;

					for (int i = 0; i <= 255; i += 1) {
						bar_chart->Series["Blue"]->Points->AddXY(i + 1, arr_blue[i]);
					}
				}
				else {
					ShowPlainMessageBox("Invalid Input");
				}
			}
		}
		else {
			ShowPlainMessageBox("Insert Image First");
		}
	}

	//[MESSAGE BOX]
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

	

};

}
