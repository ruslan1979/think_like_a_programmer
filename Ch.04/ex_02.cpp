/* ������������ ������ ��������� ������������ ������.
    ��� ����, ����� ����� ����� ������, ��-
    ���������� ����������, ��� �����������, ���� � ���� ������
    ���� ����������� ��������.
    ��������������: ������ ������������ ����
� ���� ������:
    terminate called after throwing an instance of 'std::bad_alloc'
    what():  std::bad_alloc

    This application has requested the Runtime to terminate it in an unusual way.
    Please contact the application's support team for more information.

    Process returned 3 (0x3)   execution time : 14.332 s
    Press any key to continue.
*/
#include <iostream>

using namespace std;

int main() {
    const int intsPerKilobyte = 1024 / sizeof(int);
    while(true) {
        // ��������� � ����
        int *oneKilobyteArray = new int[intsPerKilobyte];
    }

    return 0;
}
