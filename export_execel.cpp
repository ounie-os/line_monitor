#include "export_execel.h"
#include "qt_windows.h"

Export_Execel::Export_Execel(QObject *parent)
    :QThread(parent)
{

}

Export_Execel::~Export_Execel()
{

}

void Export_Execel::export_data(int row, QString path, QStringList list_data)
{
    HRESULT r = OleInitialize(0);
    if (r != S_OK && r != S_FALSE)
    {
        qWarning("Qt: Could not initialize OLE (error %x)", (unsigned int)r);
    }
    QAxObject *work_book = 0;
    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    excel.setProperty("DisplayAlerts", false);//不显示任何警告信息
    QAxObject *work_books = excel.querySubObject("WorkBooks");
    QFile xlsFile(path);
    if (xlsFile.exists()) {
        work_book = work_books->querySubObject("Open(const QString &)", path);
    }
    else {
        work_books->dynamicCall("Add");
        work_book = excel.querySubObject("ActiveWorkBook");
    }
    QAxObject *work_sheets = work_book->querySubObject("Sheets");
    QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);
    QAxObject *cell = NULL;
    for(int i=0;i<list_data.length();i++)
    {
        cell = first_sheet->querySubObject("Cells(int,int)",row+1, i+1);
        cell->setProperty("Value", list_data.at(i));
        cell->setProperty("ColumnWidth", 20);  //设置单元格列宽
    }
    work_book->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(path)); //转换路径不可少，否则会崩溃
    work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
    excel.dynamicCall("Quit(void)");  //退出
    OleUninitialize();
}
