/** Задача :
Создайте свою собственную фигуру: Придумайте свою собственную симметричную фигуру из символов # и проверьте, сможете
ли вы написать программу, которая следует правилам программ с фигурами.
###########
#         #
# ####### #
# #     # # 
# # # # # #
# # # # # #
# # # # # #
# #     # #
# ####### #
#         #
###########


*/

#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i != 11; ++i) {
        if ((i == 0) || (i == 10)) {
           for (int j = 0; j != 11; ++j)
                cout << "#";
        }

        else if ((i == 2) || (i == 8)) {
           for (int j = 0; j != 11; ++j){
                if ((j == 1) || (j == 9))               
                    cout << " ";
                else
                    cout << "#";
           }
        }

        else if ((i == 3) || (i == 7))  {
           for (int j = 0; j != 11; ++j){
                if ((j == 0) || (j == 10) || (j == 2) || (j == 8))              
                    cout << "#";
                else
                    cout << " ";
           }
		}

        else if ((i > 3) && (i < 7))  {
           for (int j = 0; j != 11; ++j){
                if (j % 2 == 0)             
                    cout << "#";
                else
                    cout << " ";
           }
		}

        else if ((i == 1) || (i == 9))  {
           for (int j = 0; j != 11; ++j){
                if ((j == 0) || (j == 10))             
                    cout << "#";
                else
                    cout << " ";
           }
		}
        
        cout << endl;
    }
}