/* ������������ ������ ��������� ������������ ������.
��������� ������ �����.
������ �������� ��� ���:
.............
Current value is 64894
Current value is
Process returned -1073741571 (0xC00000FD)   execution time : 22.392 s
������ ����� �����?
*/
#include <iostream>

using namespace std;

int count = 0;
void stackOverflow() {
    cout << "Current value is " << count << endl;
    count++;
    stackOverflow();
}

int main() {
    stackOverflow();
    return 0;
}
