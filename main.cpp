#include <QDirIterator>
#include <QStringList>
#include <QFileInfoList>
#include <QSetIterator>
#include <list>
#include <string>

//#include <QString>
//#include <QTextStream>
//QTextStream cout(stdout);
//QTextStream cin(stdin);
#include <iostream>
#include <fstream>
#include <cstring>

#include <filecollector.h>


using namespace std;

void comparison(string path1, string path2){
    ifstream fin1(path1, ios::binary);
    ifstream fin2(path2, ios::binary);
    if (fin2 && fin2)
    {
        char ch1, ch2;
        bool result = true;
        while (fin1.get(ch1) && fin2.get(ch2))
        {
            if (ch1 != ch2)
            {
                result = false;
                break;
            }
        }
        if (result){
        //    cout << "Equal" << endl;
            cout << path1 << "\t\t" << path2 << endl;
        }
        //else
        //    cout << "Unequal" << endl;
    }
    else
        cout << "Error opening file!" << endl;
}


int main(){

    string s1 = "/home/evslav/Documents/Pictures/";
    string s2 = "/home/evslav/Documents/Pictures/";
    FileCollector f1(s1);
    FileCollector f2(s2);
    //cout << f1.setFilePath(2) << " " << f1.setFileSize(2) << endl;
    bool Substring = false;
    if (strstr (s1.c_str(), s2.c_str()) != NULL || strstr (s2.c_str(), s1.c_str()) != NULL)
        Substring = true;




    if (!Substring){
        for (int i = 0; i < f1.sizeFileList(); i++){
            for(int j = 0; j < f2.sizeFileList(); j++){
                if (f1.setFileSize(i) == f2.setFileSize(j)){
                    comparison(f1.setFilePath(i),f2.setFilePath(j));
                }
            }
        }
    }
    else{
        for (int i = 0; i < f1.sizeFileList(); i++){
            for(int j = 0; j < f2.sizeFileList(); j++){
                if (f1.setFileSize(i) == f2.setFileSize(j) && f1.setFilePath(i)!= f1.setFilePath(j)){
                    comparison(f1.setFilePath(i),f2.setFilePath(j));
                }
            }
        }
    }

    //setlocale(LC_CTYPE, "rus");
    //
    //QList<fInfo> FileInfoList;
    //
    //QString patch1 = "Вветите путь к первой папке:";
    //QString patch2 = "Вветите путь ко второй папке:";
    //
    //cout << patch1;
    //cin >> patch1;
    //cout << endl << patch2;
    //cin >> patch2;
    //cout << endl;
    //
    //int q = 0;
    //QDirIterator it("/home/evslav/Documents/Pictures/", QDirIterator::Subdirectories);
    //while (it.hasNext()) {
    //    QFileInfo i = it.next();
    //    QString fileName = it.fileName();
    //    //if (fileName != "." && fileName != ".." && fileName.isEmpty())
    //    if ( i.isFile() ){
    //        q++;
    //    fInfo a(i.size(), i.filePath());
    //    FileInfoList.push_back(a);
    //    cout << i.size() << "\t\t" ;
    //    cout << i.filePath() << endl;
    //    }
    //    // /etc/.
    //    // /etc/..
    //    // /etc/X11
    //    // /etc/X11/fs
    //    // ...
    //}
    //cout << "\n\n" << FileInfoList.size() << endl;
    //for (int i = 0; i < FileInfoList.size(); i++){
    //cout << FileInfoList[i].size << "\t" << FileInfoList[i].path << endl;
    //}
    //cout << "\n\n\n" << q << "\n\n";

}
