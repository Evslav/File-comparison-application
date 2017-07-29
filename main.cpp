#include <QDirIterator>
#include <QStringList>
#include <QFileInfoList>
#include <QSetIterator>
#include <list>

#include <clocale>
#include <QString>
#include <QTextStream>
QTextStream cout(stdout);
QTextStream cin(stdin);

using namespace std;

struct fInfo {
    fInfo(int s, QString p){
        size = s;
        path = p;
    }
    int size;
    QString path;
};


int main(){
    setlocale(LC_CTYPE, "rus");

    QList<fInfo> FileInfoList;
   // cout << FileInfo[0].size << endl;

    int q = 0;
    QDirIterator it("C:\\Users\\evslav\\Pictures", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QFileInfo i = it.next();
        QString fileName = it.fileName();
        //if (fileName != "." && fileName != ".." && fileName.isEmpty())
        if ( i.isFile() ){
            q++;
        fInfo a(i.size(), i.filePath());
        FileInfoList.push_back(a);
        cout << i.size() << "\t\t" ;
        cout << i.filePath() << endl;
        }
        // /etc/.
        // /etc/..
        // /etc/X11
        // /etc/X11/fs
        // ...
    }
    cout << "\n\n" << FileInfoList.size() << endl;
    for (int i = 0; i < FileInfoList.size(); i++){
    cout << FileInfoList[i].size << "\t" << FileInfoList[i].path << endl;
    }
    cout << "\n\n\n" << q << "\n\n";

}
