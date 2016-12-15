#include <sstream>
#include "file_io.h"

FileIO::FileIO(const int buffer_size)
       :buffer_size_(buffer_size) {
    //Nothing
}

FileIO::FileIO(const string ifname, const int buffer_size)
           :ifname_(ifname),
            buffer_size_(buffer_size) {
    //Nothing
}

FileIO::FileIO(const string ifname, const string ofname,
               const int buffer_size)
           :ifname_(ifname), ofname_(ofname),
            buffer_size_(buffer_size) {
    //Nothing
}

int
FileIO::iopen(void) {
    if (!ifile_.is_open()) {
        ifile_.open(ifname_, ios::binary);
    }
    return 0;
}

int
FileIO::iclose(void) {
    if (ifile_.is_open()) ifile_.close();
    return 0;
}

int
FileIO::iread(char *buf) {
    if (buf == NULL) return -1;
    ifile_.read(buf, buffer_size_);
    return ifile_.gcount();
}

size_t
FileIO::ifile_size(void) {
    size_t beg, end;
    ifile_.seekg(0, ios::beg);
    beg = ifile_.tellg();
    ifile_.seekg(0, ios::end);
    end = ifile_.tellg();
    ifile_.seekg(0, ios::beg);
    return end - beg;
}

void
FileIO::iread_words(void) {
    ifile_.seekg(0, ios::beg);
    char *buf = new char[buffer_size_+1];
    int chars_read = iread(buf);
    ostringstream curr_word;
    int start = 0;
    int wc = 0;
    int read_calls = 1;
    while (chars_read > 0) {
        while(start < chars_read) {
            if (buf[start] == ' ') {
                if (curr_word.str().size() > 0) {
                    cout << "WORD-" << wc++ << ":" << curr_word.str() << endl;
                    curr_word.str("");
                    curr_word.clear();
                }
            } else if (buf[start] == '\n') {
                //Ignore
            } else {
                curr_word << buf[start];
            }
            start++;
        }
        start = 0;
        chars_read = iread(buf);
        if (chars_read > 0) {
            read_calls++;
        }
    }

    if (curr_word.str().size() > 0) {
        cout << "WORD-" << wc++ << ":" << curr_word.str() << endl;
    }
    cout << "TOTAL READ CALLS: " << read_calls << endl;
    delete[] buf;
}
