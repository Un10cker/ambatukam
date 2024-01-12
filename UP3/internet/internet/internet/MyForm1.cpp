#include "MyForm1.h"
#include <Windows.h>

namespace internet {
    MyForm1::MyForm1(void)
    {
        InitializeComponent();
        InitializeDatabase();
    }
    
    void MyForm1::InitializeDatabase()
    {
        // Подключение к базе данных
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\lucky\\Desktop\\internet\\internet\\x64\\Debug\\Test.mdb";
        connection = gcnew OleDbConnection(connectionString);

        // Инициализация объектов
        adapter = gcnew OleDbDataAdapter("SELECT * FROM Person", connection);
        dataTable = gcnew DataTable();

        // Загрузка данных из базы данных в DataTable
        adapter->Fill(dataTable);

        // Привязка DataTable к DataGridView
        dataGridView1->DataSource = dataTable;
    }

    void MyForm1::UpdateDatabase()
    {
        if (adapter && dataTable) // Проверка, что объекты инициализированы
        {
            // Обновление базы данных
            OleDbCommandBuilder^ builder = gcnew OleDbCommandBuilder(adapter);
            adapter->Update(dataTable);
        }
        else
        {
            // Обработка ошибки: объекты не инициализированы
            MessageBox::Show("Ошибка: Адаптер или таблица не инициализированы.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void MyForm1::AddRecord(String^ name, int quantity, double price)
    {
        if (dataTable)
        {
            DataRow^ newRow = dataTable->NewRow();
            newRow["Название"] = name;
            newRow["Количество"] = quantity;
            newRow["Цена"] = price;
            dataTable->Rows->Add(newRow);
            UpdateDatabase();

            // Получение последнего вставленного идентификатора (ID)
            OleDbCommand^ cmd = gcnew OleDbCommand("SELECT @@Identity", connection);
            connection->Open();
            int lastInsertedId = Convert::ToInt32(cmd->ExecuteScalar());
            connection->Close();

            // Теперь у вас есть lastInsertedId, который содержит значение ID последней вставленной записи.
            // Можете использовать его по вашему усмотрению.
        }
        else
        {
            MessageBox::Show("Ошибка: Таблица не инициализирована.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void MyForm1::RemoveRecord(int rowIndex)
    {
        if (dataTable) // Проверка, что объект инициализирован
        {
            // Удаление записи из базы данных
            dataTable->Rows[rowIndex]->Delete();
            UpdateDatabase();
        }
        else
        {
            // Обработка ошибки: объект не инициализирован
            MessageBox::Show("Ошибка: Таблица не инициализирована.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
}
