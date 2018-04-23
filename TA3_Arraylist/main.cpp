#include <iostream>

#include "arraylist.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    ArrayList<double> array;

    for (int i = 0; i < 33; i++){
        array.add(i*1.1);
    }

    array.add(4, -5);
    array.remove(1);

    for (int i = 0; i < array.size(); i++){
        std::cout << array[i] << ", ";
    }

    std::cout << "\b\b" << std::endl << std::endl;

    std::cout << "Arraylist have reserved space for " << array.reserved()
              << " elements, and stores " << array.size() << " elements" << std::endl;

    array.trimToSize();

    std::cout << "Arraylist now trimmed to size and have reserved space for "
              << array.reserved() << " elements and stores "
              << array.size() << " elements." << std::endl << std::endl;

    /*------------------------------------------------------*/
    ArrayList<double> subArray = array.subArrayList(1, 10);

    std::cout << "Arraylist have reserved space for " << subArray.reserved()
              << " elements, and stores " << subArray.size() << " elements" << std::endl;

    for (int i = 0; i < subArray.size(); i++){
        std::cout << subArray[i] << ", ";
    }
    std::cout << "\b\b" << std::endl << std::endl;

    double *sArray = subArray.toArray();

    for (int i = 0; i < 7; i++){
        subArray.add(i+1);
    }

    //The basic array prints after adding elements to subArray
    //for (int i = 0; )

    return 0;
}
