/* Стр 96
    Нахождение самого высокого уровня ежемесячных продаж у любого агента
*/
#include <iostream>

using namespace std;

int main() {
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}        
    };

    int highestSales = sales[0][0];
    for (int agent = 0; agent < NUM_AGENTS; agent++)
        for (int month = 0; month < NUM_MONTHS; month++)
            if (sales[agent][month] > highestSales)
                highestSales = sales[agent][month];            
    
    cout << "Highest sales: " << highestSales << endl;

}
