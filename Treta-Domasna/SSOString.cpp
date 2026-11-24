
#include <iostream>
#include <cstring>
using namespace std;

class SSOString {
private:
    char* array;
    short size;
    short cap;

public:
    SSOString(const char* str = "") {
        size = strlen(str);
        cap = size + 1;

        array = new char[cap];
        strcpy(array, str);
    }

    SSOString(const SSOString& other) {
        size = other.size;
        cap = other.cap;

        array = new char[cap];
        strcpy(array, other.array);
    }

    ~SSOString() {
        delete[] array;
    }

    SSOString& operator=(const SSOString& other) {
        if (this != &other) {
            delete[] array;

            size = other.size;
            cap = other.cap;

            array = new char[cap];
            strcpy(array, other.array);
        }

        return *this;
    }

    char& operator[](int index) {
        return array[index];
    }

    short sizeOf() const {
        return size;
    }

    short capacity() const {
        return cap;
    }

    SSOString operator+(const SSOString& other) const {
        SSOString result;

        result.size = size + other.size;
        result.cap = result.size + 1;

        delete[] result.array;

        result.array = new char[result.cap];

        strcpy(result.array, array);
        strcat(result.array, other.array);

        return result;
    }

    friend ostream& operator<<(ostream& out, const SSOString& str) {
        out << str.array;
        return out;
    }
};

int main() {
    SSOString s1("Hello");
    SSOString s2(" World");

    SSOString s3 = s1 + s2;

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << "Concatenation: " << s3 << endl;

    cout << "Size: " << s3.sizeOf() << endl;
    cout << "Capacity: " << s3.capacity() << endl;

    cout << "First character: " << s3[0] << endl;

    return 0;
}
