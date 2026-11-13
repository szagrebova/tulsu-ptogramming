#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute] // обязательно для Windows-form
int main() {
    Application::EnableVisualStyles(); // включает современный вид кнопок, полей ввода и чекбоксов
    Application::SetCompatibleTextRenderingDefault(false); //  настраивает способ отрисовки текста
    // false означает, что будет использоваться современный 
    // движок GDI+ для более четкого и красивого текста на экране.

    DormitoryApp::MyForm form;
    // конструктор формы, который создает все кнопки, текстовые поля и списки, 
    // которые нарисованы в визуальном редакторе

    Application::Run(% form);
    // главный цикл программы (Message Loop)
    // % — оператор взятия дескриптора (handle) в C++/CLI
    // аналог & для классических ссылок
    // Если использовать обычный указатель *, 
    // он бы указывал на старое место, и программа упала бы

    return 0;
}