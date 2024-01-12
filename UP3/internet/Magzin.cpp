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
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=G:\\internet (1)\\internet\\x64\\Debug\\Test.mdb";
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
        // Проверка наличия нужного количества товара на складе
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
            // Проверка, есть ли уже заказанные товары
            if (dataGridView1->Rows->Count > 0)
            {
                // Проверка, есть ли уже этот товар в заказе
                for (int i = 0; i < dataGridView1->Rows->Count; i++)
                {
                    if (dataGridView1->Rows[i]->Cells["Название"]->Value != nullptr &&
                        dataGridView1->Rows[i]->Cells["Название"]->Value->ToString() == name)
                    {
                        int existingQuantity = Convert::ToInt32(dataGridView1->Rows[i]->Cells["Количество"]->Value);
                        int totalQuantity = existingQuantity + quantity;

                        // Проверка, не превышает ли общее количество товара на складе
                        if (IsProductAvailable(name, totalQuantity))
                        {
                            // Обновление количества в существующей записи
                            dataGridView1->Rows[i]->Cells["Количество"]->Value = totalQuantity;
                            UpdateDatabase();
                            dataGridView1->Refresh(); // Обновление dataGridView1
                            return;
                        }
                        else
                        {
                            MessageBox::Show("Недостаточно товара на складе.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                            return;
                        }
                    }
                }
            }

            
            else
            {
                MessageBox::Show("Товара нет на складе или недостаточно товара на складе.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        else
        {
            MessageBox::Show("Товара нет на складе или недостаточно товара на складе.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    // Метод для проверки наличия товара на складе
    bool MyForm2::IsProductAvailable(String^ productName, int requestedQuantity)
    {
        int quantityInStock = GetProductQuantityInStock(productName);

        return quantityInStock >= requestedQuantity;
    }

    // Получения количества товара на складе 
    int MyForm2::GetProductQuantityInStock(String^ productName)
    {
        

        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\lucky\\Desktop\\internet (1)\\internet\\x64\\Debug\\Test.mdb";
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

