#pragma once
#include "MyForm1.h" // Убедитесь, что файл MyForm1.h включен
#include "MyForm2.h" // Убедитесь, что файл MyForm1.h включен

namespace internet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class Form : public System::Windows::Forms::Form
	{
	public:
		Form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;



	private: System::Windows::Forms::Button^ button3;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gray;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(96, 101);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(246, 71);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Склад";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Gray;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(96, 260);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(246, 67);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Заказы ";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Gray;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(423, 101);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(246, 226);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Резервное копирование";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form::button3_Click);
			// 
			// Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(763, 499);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Form";
			this->Text = L"Интернет магазин";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Создание и показ новой формы при нажатии на кнопку
		MyForm1^ myForm1 = gcnew MyForm1();
		myForm1->Show();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm2^ myForm2 = gcnew MyForm2();
	myForm2->Show();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Создаем уникальное имя файла для резервной копии с использованием временной метки
		System::DateTime now = System::DateTime::Now;
		System::String^ backupFileName = "РезервнаяКопия_" + now.ToString("yyyyMMdd_HHmmss") + ".mdb";

		// Указываем путь для сохранения резервной копии
		System::String^ backupPath = "G:\\internet (1)\\internet\\РезервнаяКопия\\" + backupFileName;

		// Копируем файл базы данных с использованием стабильного метода
		System::IO::File::Copy("G:\\internet (1)\\internet\\x64\\Debug\\Test.mdb", backupPath, true);

		// Добавляем задержку после копирования
		System::Threading::Thread::Sleep(1000);  // Задержка в 1 секунду

		// Выводим сообщение об успешном создании резервной копии
		MessageBox::Show("Резервная копия успешно создана по пути: " + backupPath, "Успех",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		// Выводим сообщение об ошибке, если произошло исключение
		MessageBox::Show("Ошибка при создании резервной копии: " + ex->Message, "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
