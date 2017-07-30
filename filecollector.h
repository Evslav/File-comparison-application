#include <QString>
#include <QDirIterator>

class FileCollector {
private:
    struct fInfo {
        fInfo(int s, QString p){
            size = s;
            path = p;
        }
        int size;
        QString path;
    };
    QList<fInfo> FileInfoList;

    void collect(QString str){
        QDirIterator it(str, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QFileInfo i = it.next();
            QString fileName = it.fileName();
            //if (fileName != "." && fileName != ".." && fileName.isEmpty())
            if ( i.isFile() ){
            fInfo a(i.size(), i.filePath());
            FileInfoList << a;
            }
        }
    }

public:

    FileCollector(std::string str){
        QString qstr = str.c_str();
        collect(qstr);
    }

    FileCollector(){

    }

    void collects(std::string str){
        QString qstr = str.c_str();
        collect(qstr);
    }

    QList<fInfo> FileIfoList(){
        return FileInfoList;
    }

    int setFileSize(int i){
        return FileInfoList[i].size;
    }

    std::string setFilePath(int i){
        return FileInfoList[i].path.toStdString();
    }

    int sizeFileList (){
        return FileInfoList.size();
    }

};
