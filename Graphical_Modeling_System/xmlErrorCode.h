#ifndef XMLERRORCODE_H
#define XMLERRORCODE_H

//用來記錄XML開啟檔案的一些code (靜態類別)
class XMLErrorCode
{
public:
    static int OK;
    static int Create_HasExisted;
    static int Create_PathError;
    static int Open_NotExist;
    static int IOError;
};

#endif // XMLERRORCODE_H
