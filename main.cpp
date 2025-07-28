#include<iostream>
using namespace std;

/* Memory Section
 * Heap: |
 * Stack:| main(): length [2 bytes], breadth [2 bytes], area [2 bytes]
 * Code: | main()
 */

struct  Rectangle
{
    int length;
    int breadth;
    int area;
};

int main()
{
    struct Rectangle rect = {10,5};
    rect.area = rect.length * rect.breadth;

    printf("Area: %d\n", rect.area);


    // Structure can also be declared as an array.
    struct Rectangle rectArr[2] = { {1,2}, {2,3}};

    return 0;
}