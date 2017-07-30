#include <QDirIterator>
#include <QStringList>
#include <QFileInfoList>
#include <QSetIterator>
#include <list>
#include <string>
#include <thread>


#include <QString>
#include <QTextStream>
QTextStream cout(stdout);
QTextStream cin(stdin);
//#include <iostream>
#include <fstream>
#include <cstring>

#include <filecollector.h>

#include <ctime>

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
            cout << path1.c_str() << "\t\t" << path2.c_str() << endl;
        }
        //else
        //    cout << "Unequal" << endl;
    }
    else
        cout << "Error opening file!" << endl;
}

void threadFunction(FileCollector &f, string str)
{
     f.collects(str);
}

int main(){
setlocale(LC_CTYPE, "rus");

    string s1 = "C:\\Program Files";
    string s2 = "C:\\Program Files";
    unsigned int start_time =  clock();
    FileCollector f1(s1);
        cout << f1.sizeFileList() << endl;
    FileCollector f2(s2);
        cout << f2.sizeFileList() << endl;
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << search_time << endl;

    FileCollector f3;
    FileCollector f4;
    start_time =  clock();
        std::thread thr(threadFunction, std::ref(f3), s1);
        std::thread thr2(threadFunction, std::ref(f4), s2);

        thr.join();
        cout << f1.sizeFileList() << endl;
        thr2.join();
        cout << f2.sizeFileList() << endl;

        end_time = clock();
        search_time = end_time - start_time;
        cout << search_time << endl;

    //cout << f1.setFilePath(2) << " " << f1.setFileSize(2) << endl;
    bool Substring = false;
    if (strstr (s1.c_str(), s2.c_str()) != NULL || strstr (s2.c_str(), s1.c_str()) != NULL)
        Substring = true;




    if (!Substring){
        for (int i = 0; i < f1.sizeFileList(); i++){
            for(int j = 0; j < f2.sizeFileList(); j++){
                if (f1.setFileSize(i) == f2.setFileSize(j)){
                    comparison(f1.setFilePath(i),f2.setFilePath(j));
                    //cout << f1.setFileSize(i) <<"\t"<< f2.setFileSize(j) << endl;
                }
            }
        }
    }
    else{
        for (int i = 0; i < f1.sizeFileList(); i++){
            for(int j = 0; j < f2.sizeFileList(); j++){
                if (f1.setFileSize(i) == f2.setFileSize(j) && f1.setFilePath(i)!= f1.setFilePath(j)){
                    comparison(f1.setFilePath(i),f2.setFilePath(j));
                    //cout << f1.setFileSize(i) <<"\t"<< f2.setFileSize(j) << endl;
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
