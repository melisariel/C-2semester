#pragma once

#include "Rect.h"

namespace Project2
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class MyForm : public Form
	{
	public:

		MyForm()
		{
			InitializeComponent();
		}

	private:

		TextBox^ textBox1;
		TextBox^ textBox2;
		TextBox^ textBox3;
		TextBox^ textBox4;

		Label^ label1;
		Label^ label2;
		Label^ label3;
		Label^ label4;

		Button^ button1;
		Button^ button2;

		void InitializeComponent(void)
		{
			this->textBox1 = gcnew TextBox();
			this->textBox2 = gcnew TextBox();
			this->textBox3 = gcnew TextBox();
			this->textBox4 = gcnew TextBox();

			this->label1 = gcnew Label();
			this->label2 = gcnew Label();
			this->label3 = gcnew Label();
			this->label4 = gcnew Label();

			this->button1 = gcnew Button();
			this->button2 = gcnew Button();

			// textBox1
			this->textBox1->Location = Point(20, 20);

			// textBox2
			this->textBox2->Location = Point(20, 50);

			// textBox3
			this->textBox3->Location = Point(20, 80);

			// textBox4
			this->textBox4->Location = Point(20, 110);

			// label1
			this->label1->Location = Point(130, 20);
			this->label1->Text = L"X";

			// label2
			this->label2->Location = Point(130, 50);
			this->label2->Text = L"Y";

			// label3
			this->label3->Location = Point(130, 80);
			this->label3->Text = L"Width";

			// label4
			this->label4->Location = Point(130, 110);
			this->label4->Text = L"Height";

			// button1
			this->button1->Location = Point(20, 150);
			this->button1->Size = Drawing::Size(100, 30);
			this->button1->Text = L"Draw";
			this->button1->Click += gcnew EventHandler(this, &MyForm::button1_Click);

			// button2
			this->button2->Location = Point(20, 190);
			this->button2->Size = Drawing::Size(100, 30);
			this->button2->Text = L"Clear";
			this->button2->Click += gcnew EventHandler(this, &MyForm::button2_Click);

			// Form
			this->ClientSize = Drawing::Size(600, 400);

			this->Controls->Add(textBox1);
			this->Controls->Add(textBox2);
			this->Controls->Add(textBox3);
			this->Controls->Add(textBox4);

			this->Controls->Add(label1);
			this->Controls->Add(label2);
			this->Controls->Add(label3);
			this->Controls->Add(label4);

			this->Controls->Add(button1);
			this->Controls->Add(button2);
		}

		void button1_Click(Object^ sender, EventArgs^ e)
		{
			int x = Convert::ToInt32(textBox1->Text);
			int y = Convert::ToInt32(textBox2->Text);
			int w = Convert::ToInt32(textBox3->Text);
			int h = Convert::ToInt32(textBox4->Text);

			Graphics^ g = this->CreateGraphics();

			Rect r(x, y, w, h);

			r.Draw(g);
		}

		void button2_Click(Object^ sender, EventArgs^ e)
		{
			this->Refresh();
		}
	};
}