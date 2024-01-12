#pragma once
#include "MyForm1.h" // Убедитесь, что файл MyForm1.h включен
namespace internet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void);
		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		
		// Добавленные функции
		void InitializeDatabase();
		void UpdateDatabase();
		void AddRecord(String^ name, int quantity, double price);
		void RemoveRecord(int rowIndex);
		OleDbConnection^ connection;
		OleDbDataAdapter^ adapter;
		DataTable^ dataTable;

	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button4;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gray;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(535, 177);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(219, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Обновление списка";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Gray;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(535, 234);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(219, 35);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Добавление привезенного товара";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Gray;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(535, 288);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(219, 35);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Убрать товар";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox1->Location = System::Drawing::Point(535, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(220, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox2->Location = System::Drawing::Point(535, 81);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(220, 20);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox3->Location = System::Drawing::Point(535, 127);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(220, 20);
			this->textBox3->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(531, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 19);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Название товара";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(531, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(148, 19);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Количество товара";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(531, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 19);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Цена";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->GridColor = System::Drawing::Color::Gray;
			this->dataGridView1->Location = System::Drawing::Point(12, 25);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(445, 358);
			this->dataGridView1->TabIndex = 9;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Gray;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Location = System::Drawing::Point(535, 341);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(219, 35);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Сохранить ";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(799, 429);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm1";
			this->Text = L"Склад";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		UpdateDatabase();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Получение значений из текстовых полей
	String^ name = textBox1->Text;
	String^ quantityText = textBox2->Text;
	String^ priceText = textBox3->Text;

	// Проверка наличия значений в текстовых полях
	if (String::IsNullOrWhiteSpace(name) || String::IsNullOrWhiteSpace(quantityText) || String::IsNullOrWhiteSpace(priceText)) {
		MessageBox::Show("Ошибка: Все поля должны быть заполнены.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Проверка корректности ввода количества
	int quantity;
	if (!Int32::TryParse(quantityText, quantity) || quantity <= 0) {
		MessageBox::Show("Ошибка: Некорректное значение для количества товара.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Проверка корректности ввода цены
	double price;
	if (!Double::TryParse(priceText, price) || price <= 0.0) {
		MessageBox::Show("Ошибка: Некорректное значение для цены товара.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Вызов функции для добавления записи
	AddRecord(name, quantity, price);
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	// Проверка наличия выбранной строки
	if (dataGridView1->SelectedRows->Count == 0) {
		MessageBox::Show("Ошибка: Сначала выберите запись для удаления.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Получение выбранной строки
	int selectedRowIndex = dataGridView1->CurrentCell->RowIndex;

	// Подтверждение удаления
	System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите удалить запись?", "Подтверждение удаления", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

	// Проверка результата подтверждения
	if (result == System::Windows::Forms::DialogResult::Yes) {
		// Удаление записи
		RemoveRecord(selectedRowIndex);
	}
	// Иначе, если пользователь выбрал "Нет" или "Отмена", ничего не делаем
}

private: System::Void dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedRows->Count > 0) {
		// Получение выбранной строки
		DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];

		// Заполнение TextBox значениями из выбранной строки
		textBox1->Text = selectedRow->Cells["Название"]->Value->ToString();
		textBox2->Text = selectedRow->Cells["Количество"]->Value->ToString();
		textBox3->Text = selectedRow->Cells["Цена"]->Value->ToString();
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedRows->Count > 0) {
		// Получение выбранной строки
		DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];

		// Обновление значений в выбранной строке
		selectedRow->Cells["Название"]->Value = textBox1->Text;
		selectedRow->Cells["Количество"]->Value = textBox2->Text;
		selectedRow->Cells["Цена"]->Value = textBox3->Text;

		// Обновление базы данных
		UpdateDatabase();
	}
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
