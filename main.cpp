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
    // Structure to a pointer
    struct Rectangle *p;

    // C++
    // p = new Rectangle(sizeof(struct Rectangle));

    // C
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    *p = {13,14};
    cout<<"Length: "<<p->length<<endl;
    cout<<"Breadth: "<<p->breadth<<endl;
    
    return 0;
}