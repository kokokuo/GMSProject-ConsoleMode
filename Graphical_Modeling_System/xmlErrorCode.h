#ifndef XMLERRORCODE_H
#define XMLERRORCODE_H

//用來記錄XML開啟檔案的一些code (靜態類別)
class XMLErrorCode
{
public:
    static int OK; //XML檔案處理OK
    static int Create_HasExisted; //創建時已有相同路徑
    static int Create_PathError; //創建的路徑不存在
    static int Open_NotExist; //開檔的路徑檔案不存在
    static int IOError; //IO處理時錯誤
};

#endif // XMLERRORCODE_H
