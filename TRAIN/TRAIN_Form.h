#pragma once
#include "Train.h";

namespace TRAIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TRAIN_Form
	/// </summary>
	public ref class TRAIN_Form : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	public:
		MyPoezd* locomotiv;// поезд
		int x, y; // и координаты левого верхнего угла паравоза
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	public:
		int count_;// количество вагонов
		TRAIN_Form()
		{
			h = 5;
			InitializeComponent();
			x = 400; y = 200;
			count_ = 3;
			locomotiv = new MyPoezd(x, y);
			locomotiv->push_vagon();
			locomotiv->push_vagon();
			locomotiv->push_vagon();
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TRAIN_Form()
		{
			delete locomotiv;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;









	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox1->Location = System::Drawing::Point(1, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1109, 652);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TRAIN_Form::pictureBox1_Paint);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(991, 94);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 46);
			this->button1->TabIndex = 1;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TRAIN_Form::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &TRAIN_Form::timer1_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(769, 36);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(114, 26);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"5";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(991, 26);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 46);
			this->button2->TabIndex = 3;
			this->button2->Text = L"OK";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TRAIN_Form::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(713, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"scale:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(533, 36);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(114, 26);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(474, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"count:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(298, 36);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(114, 26);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"200";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(268, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Y:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(92, 36);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(114, 26);
			this->textBox4->TabIndex = 9;
			this->textBox4->Text = L"400";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(62, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(24, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"X:";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(110, 129);
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(302, 69);
			this->trackBar1->TabIndex = 11;
			this->trackBar1->Value = 5;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &TRAIN_Form::trackBar1_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(180, 94);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(169, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Текущее значение : 5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(33, 129);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(57, 20);
			this->label6->TabIndex = 13;
			this->label6->Text = L"speed:";
			// 
			// TRAIN_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(1108, 652);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"TRAIN_Form";
			this->Text = L"TRAIN_Form";
			this->Load += gcnew System::EventHandler(this, &TRAIN_Form::TRAIN_Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		locomotiv->Draw(e);
	}
	private: System::Void TRAIN_Form_Load(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Refresh();
	}
	
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	locomotiv->move();
	pictureBox1->Refresh();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (timer1->Enabled)
	{
		timer1->Enabled = false;
		button1->Text = "start";
		locomotiv->relocation();
		pictureBox1->Refresh();
	}
	else
	{
		timer1->Enabled = true;
		button1->Text = "stop";
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Convert::ToInt32(textBox1->Text) > 0 && Convert::ToInt32(textBox1->Text) < 15)
	{
		h = Convert::ToInt32(textBox1->Text);
	}
	if (Convert::ToInt32(textBox2->Text) > 0)
	{
		count_ = Convert::ToInt32(textBox2->Text);
	}
	x = Convert::ToInt32(textBox4->Text);
	y = Convert::ToInt32(textBox3->Text);
	delete locomotiv;
	locomotiv = new MyPoezd(x, y);
	for (int i = 0; i < count_; i++)
	{
		locomotiv->push_vagon();
	}
	pictureBox1->Refresh();
}
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	label5->Text = String::Format("Текущее значение: {0}", trackBar1->Value);
	this->timer1->Interval = abs(trackBar1->Value-11)*10;
}
};
};
