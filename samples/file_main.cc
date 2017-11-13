#include <iostream>
#include "file_io.h"

static int buffer_size = 4;

void test1() {
    cout << "Started test: " << __func__ << endl; 
    FileIO fio("sample_input_file.txt", buffer_size);
    fio.iopen();
    cout << "FILE SIZE " << fio.ifile_size() << endl;
    char *buf = new char[buffer_size+1];
    int chars_read = fio.iread(buf);
    cout << chars_read << endl;
    cout << buf << endl;
    delete[] buf;
    fio.iclose();
}

void test2() {
    cout << "Started test: " << __func__ << endl; 
    FileIO fio("sample_input_file.txt", buffer_size);
    fio.iopen();
    fio.iread_words();
    fio.iclose();
}

int main() {
    test1();
    test2();
    return 0;
}
