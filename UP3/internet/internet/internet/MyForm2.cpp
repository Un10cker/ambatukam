#include "MyForm2.h"
#include <Windows.h>

namespace internet {
    MyForm2::MyForm2(void)
    {
        InitializeComponent();
        InitializeDatabase();
    }

    void MyForm2::InitializeDatabase()
    {
        // Подключение к базе данных
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\lucky\\Desktop\\internet\\internet\\x64\\Debug\\Test.mdb";
        connection = gcnew OleDbConnection(connectionString);

        // Инициализация объектов
        adapter = gcnew OleDbDataAdapter("SELECT * FROM Orders", connection);
        dataTable = gcnew DataTable();

        // Загрузка данных из базы данных в DataTable
        adapter->Fill(dataTable);

        // Привязка DataTable к DataGridView
        dataGridView1->DataSource = dataTable;
    }

    void MyForm2::UpdateDatabase()
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

    void MyForm2::AddRecord(String^ name, int quantity, double price, double total)
    {
        // Проверка наличия товара на складе
        if (IsProductAvailable(name, quantity))
        {
            if (dataTable)
            {
                DataRow^ newRow = dataTable->NewRow();
                newRow["Название"] = name;
                newRow["Количество"] = quantity;
                newRow["Цена"] = price;
                newRow["Итог"] = total;
                dataTable->Rows->Add(newRow);
                UpdateDatabase();
            }
            else
            {
                MessageBox::Show("Ошибка: Таблица не инициализирована.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        else
        {
            MessageBox::Show("Товара нет на складе.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    // Метод для проверки наличия товара на складе
    bool MyForm2::IsProductAvailable(String^ productName, int quantity)
    {
        // Здесь вам нужно добавить код проверки наличия товара на складе.
        // Вы можете использовать ваш существующий код для получения данных из таблицы "Person".
        // Например, вы можете проверить, достаточно ли товара на складе для выполнения заказа.
        // Если товара достаточно, верните true; в противном случае верните false.
        // Предположим, что у вас есть метод GetProductQuantityInStock, который возвращает количество товара на складе.

        int quantityInStock = GetProductQuantityInStock(productName);

        return quantityInStock >= quantity;
    }

    // Пример метода для получения количества товара на складе (замените его на ваш реальный код)
    int MyForm2::GetProductQuantityInStock(String^ productName)
    {
        // Ваш код для получения количества товара на складе
        // Это просто пример, замените его на ваш реальный код.
        // Например, вы можете использовать запрос к базе данных.
        // Предположим, что у вас есть таблица "Person" с колонкой "Количество".

        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\lucky\\Desktop\\internet\\internet\\x64\\Debug\\Test.mdb";
        OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

        // Предположим, что у вас есть колонка "Количество" в таблице "Person".
        String^ query = "SELECT Количество FROM Person WHERE Название = ?";

        OleDbCommand^ command = gcnew OleDbCommand(query, connection);
        command->Parameters->Add(gcnew OleDbParameter("?", OleDbType::VarWChar))->Value = productName;

        try
        {
            connection->Open();
            Object^ result = command->ExecuteScalar();

            if (result != nullptr)
            {
                return Convert::ToInt32(result);
            }
            else
            {
                return 0; // Если товара с таким названием не найдено, предположим, что его количество на складе равно 0.
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return 0;
        }
        finally
        {
            connection->Close();
        }
    }

    void MyForm2::RemoveRecord(int rowIndex)
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

