#pragma once
#include "Logic.h"
#include <msclr\marshal_cppstd.h>

std::vector<Student*> studentList; // Глобальный вектор студентов

namespace DormitoryApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtName;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtGroup;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtGpa;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtIncome;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnRun;
	private: System::Windows::Forms::ListBox^ lstDisplay;
	private: System::Windows::Forms::TextBox^ txtMinSalary;
	private: System::Windows::Forms::Label^ label5;




	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtGroup = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtGpa = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtIncome = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->lstDisplay = (gcnew System::Windows::Forms::ListBox());
			this->txtMinSalary = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(55, 85);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ФИО:";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(126, 82);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(328, 26);
			this->txtName->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(55, 134);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Группа:";
			// 
			// txtGroup
			// 
			this->txtGroup->Location = System::Drawing::Point(126, 131);
			this->txtGroup->Name = L"txtGroup";
			this->txtGroup->Size = System::Drawing::Size(328, 26);
			this->txtGroup->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(55, 181);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Балл:";
			// 
			// txtGpa
			// 
			this->txtGpa->Location = System::Drawing::Point(126, 178);
			this->txtGpa->Name = L"txtGpa";
			this->txtGpa->Size = System::Drawing::Size(328, 26);
			this->txtGpa->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(55, 228);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Доход";
			// 
			// txtIncome
			// 
			this->txtIncome->Location = System::Drawing::Point(126, 225);
			this->txtIncome->Name = L"txtIncome";
			this->txtIncome->Size = System::Drawing::Size(328, 26);
			this->txtIncome->TabIndex = 7;
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(126, 270);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(328, 30);
			this->btnAdd->TabIndex = 8;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// btnRun
			// 
			this->btnRun->Location = System::Drawing::Point(59, 318);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(395, 58);
			this->btnRun->TabIndex = 9;
			this->btnRun->Text = L"Сформировать очередь";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &MyForm::btnRun_Click);
			// 
			// lstDisplay
			// 
			this->lstDisplay->FormattingEnabled = true;
			this->lstDisplay->HorizontalScrollbar = true;
			this->lstDisplay->ItemHeight = 20;
			this->lstDisplay->Location = System::Drawing::Point(59, 394);
			this->lstDisplay->Name = L"lstDisplay";
			this->lstDisplay->Size = System::Drawing::Size(395, 324);
			this->lstDisplay->TabIndex = 10;
			// 
			// txtMinSalary
			// 
			this->txtMinSalary->Location = System::Drawing::Point(126, 37);
			this->txtMinSalary->Name = L"txtMinSalary";
			this->txtMinSalary->Size = System::Drawing::Size(328, 26);
			this->txtMinSalary->TabIndex = 11;
			this->txtMinSalary->Text = L"27093";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(55, 40);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"МРОТ:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 745);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtMinSalary);
			this->Controls->Add(this->lstDisplay);
			this->Controls->Add(this->btnRun);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->txtIncome);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtGpa);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtGroup);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Получаем текст из полей ввода (перевод из String^ в std::string)
			string name = msclr::interop::marshal_as<std::string>(txtName->Text);
			string group = msclr::interop::marshal_as<std::string>(txtGroup->Text);

			if (name.empty()) throw invalid_argument("Введите ФИО!");

			// Переводим текст в числа
			double gpa = Convert::ToDouble(txtGpa->Text);
			double income = Convert::ToDouble(txtIncome->Text);

			// Создаем объект (тут сработают проверки из DormitoryData)
			Student* newStudent = new Student(name, group, gpa, income);
			studentList.push_back(newStudent);

			MessageBox::Show("Студент успешно добавлен!");

			// Очищаем поля
			txtName->Clear(); txtGroup->Clear(); txtGpa->Clear(); txtIncome->Clear();
		}
		catch (System::FormatException^) {
			MessageBox::Show("Ошибка: Балл и Доход должны быть числами!", "Ошибка");
		}
		catch (const std::exception& ex) {
			MessageBox::Show(gcnew String(ex.what()), "Ошибка");
		}
	}
private: System::Void btnRun_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1. Проверяем, есть ли вообще студенты в списке
		if (studentList.empty()) {
			throw std::runtime_error("Список студентов пуст! Добавьте студентов перед формированием очереди.");
		}

		lstDisplay->Items->Clear(); // Очищаем список на экране

		// 2. Читаем МРОТ из текстового поля на форме (а не жестко заданное число)
		double minSalary = Convert::ToDouble(txtMinSalary->Text);

		// 3. Проверяем, что МРОТ положительный
		if (minSalary <= 0) {
			throw std::invalid_argument("МРОТ должен быть больше нуля!");
		}

		// 4. Вызываем friend-функцию, передавая ей МРОТ и имя файла
		Run(studentList, "dormitory_queue.txt", minSalary);

		// 5. Выводим результат в ListBox в красивом формате
		for (Student* s : studentList) {
			// Первая строка: только ФИО
			lstDisplay->Items->Add(gcnew String(("ФИО: " + s->getName()).c_str()));

			// Форматируем числа, чтобы не было лишних нулей (5.000000 -> 5.0)
			std::string gpaStr = std::to_string(s->getGpa());
			gpaStr = gpaStr.substr(0, gpaStr.find('.') + 2);

			std::string incomeStr = std::to_string(s->getIncome());
			incomeStr = incomeStr.substr(0, incomeStr.find('.'));

			// Вторая строка: группа, балл и доход вместе
			std::string restData = "   Группа: " + s->getGroup() +
				" | Балл: " + gpaStr +
				" | Доход: " + incomeStr + " руб.";

			lstDisplay->Items->Add(gcnew String(restData.c_str()));

			// Разделитель между студентами
			lstDisplay->Items->Add("-------------------------");
		}

		MessageBox::Show("Очередь сформирована и сохранена в файл 'dormitory_queue.txt'!", "Успех");
	}
	// Ловим ошибки логики C++ (пустой список, отрицательный МРОТ, ошибки файла)
	catch (const std::exception& ex) {
		MessageBox::Show(gcnew String(ex.what()), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// Ловим ошибки .NET (если пользователь ввел буквы или символы в поле МРОТ)
	catch (System::FormatException^) {
		MessageBox::Show("Ошибка: МРОТ должен быть числом! Проверьте ввод.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
};
}
