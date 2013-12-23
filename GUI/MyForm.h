#pragma once
#include "ArrayToBeSort.h"

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Button^  button3;
	protected:

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
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->textBox1 = (gcnew System::Windows::Forms::TextBox());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->textBox2 = (gcnew System::Windows::Forms::TextBox());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
		this->button3 = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(12, 89);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(128, 23);
		this->button1->TabIndex = 0;
		this->button1->Text = L"sortuj asemblerem";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
		// 
		// button2
		// 
		this->button2->Location = System::Drawing::Point(154, 89);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(75, 23);
		this->button2->TabIndex = 1;
		this->button2->Text = L"sortuj w C++";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
		// 
		// textBox1
		// 
		this->textBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
		this->textBox1->Location = System::Drawing::Point(110, 41);
		this->textBox1->Name = L"textBox1";
		this->textBox1->Size = System::Drawing::Size(38, 20);
		this->textBox1->TabIndex = 2;
		this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(23, 25);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(125, 13);
		this->label1->TabIndex = 3;
		this->label1->Text = L"ilu w¹tków chcesz u¿yæ\?";
		this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
		// 
		// textBox2
		// 
		this->textBox2->Location = System::Drawing::Point(12, 148);
		this->textBox2->Name = L"textBox2";
		this->textBox2->Size = System::Drawing::Size(100, 20);
		this->textBox2->TabIndex = 4;
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(13, 129);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(86, 13);
		this->label2->TabIndex = 5;
		this->label2->Text = L"czas wykonania:";
		this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
		// 
		// progressBar1
		// 
		this->progressBar1->Location = System::Drawing::Point(12, 193);
		this->progressBar1->Name = L"progressBar1";
		this->progressBar1->Size = System::Drawing::Size(232, 23);
		this->progressBar1->TabIndex = 6;
		// 
		// button3
		// 
		this->button3->Location = System::Drawing::Point(154, 39);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(75, 23);
		this->button3->TabIndex = 7;
		this->button3->Text = L"potwierdŸ";
		this->button3->UseVisualStyleBackColor = true;
		this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
		// 
		// MyForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(275, 255);
		this->Controls->Add(this->button3);
		this->Controls->Add(this->progressBar1);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->textBox2);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->textBox1);
		this->Controls->Add(this->button2);
		this->Controls->Add(this->button1);
		this->Name = L"MyForm";
		this->Text = L"MyForm";
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
				 {}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
				 {}
		private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e)
					 {}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e)
			 {}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
			 {
				
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
			 {}
};
}
