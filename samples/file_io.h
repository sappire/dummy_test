#ifndef FILE_IO_H_
#define FILE_IO_H_

#include <iostream>
#include <fstream>
using namespace std;

class FileIO {
public:
    FileIO(const int buffer_size);
    FileIO(const string ifname, const int buffer_size);
    FileIO(const string ifname, const string ofname,
           const int buffer_size);
    int iopen();
    int iclose();
    int iread(char *buf);
    void iread_words(void);
    size_t ifile_size(void);
private:
    string ifname_;
    string ofname_;
    ifstream ifile_;
    ofstream ofile_;
    int buffer_size_;
};

#endif //FILE_IO_H_
