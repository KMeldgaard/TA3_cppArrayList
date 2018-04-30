#include <iostream>

#include "arraylist.h"

using namespace std;

int main()
{
    std::system("color 0A"); //Matrix color theme
    std::cout << "-----ArrayList implementation - TA3------" << std::endl;

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
    std::cout << "Basic array of sub array contains: " << std::endl;
    for (int i = 0; i < subArray.size()-7; i++){
        std::cout << sArray[i] << ", ";
    }
    std::cout << "\b\b" << std::endl << std::endl;

    //The new elemets in subArray
    std::cout << "Sub array with 7 elements added: " << std::endl;
    for (int i = 0; i < subArray.size(); i++){
        std::cout << subArray[i] << ", ";
    }
    std::cout << "\b\b" << std::endl << std::endl;

    //original array
    std::cout << "Original arraylist: " << std::endl;
    for (int i = 0; i < array.size(); i++){
        std::cout << array[i] << ", ";
    }
    std::cout << "\b\b" << std::endl << std::endl;

    //Copy constructor & copy assignment
    ArrayList<double> array2 = array;
    ArrayList<double> subArray2;
    subArray2 = subArray;

    std::cout << "array2 = ";
    for (int i = 0; i < array2.size(); i++) {
        std::cout << array2[i] << ", ";
    }
    std::cout << "\b\b  " << std::endl << std::endl;

    std::cout << "subArray2 = ";
    for (int i = 0; i < subArray2.size(); ++i) {
        std::cout << subArray2[i] << ", ";
    }
    std::cout << "\b\b  " << std::endl << std::endl;

    //Move assignment operator
    ArrayList<double> subArray3 = std::move(subArray2);
    array2 = std::move(subArray2);

    std::cout << "subArray2 = ";
    for (int i = 0; i < subArray2.size(); ++i) {
        std::cout << subArray2[i] << ", ";
    }
    std::cout << "\b\b  " << std::endl << std::endl;

    std::cout << "subArray3 = ";
    for (int i = 0; i < subArray3.size(); ++i) {
        std::cout << subArray3[i] << ", ";
    }
    std::cout << "\b\b  " << std::endl << std::endl;

    subArray3.sort();

    std::cout << "Sorting subArray3..." << std::endl;
    std::cout << "subArray3 = ";
    for (int i = 0; i < subArray3.size(); ++i) {
        std::cout << subArray3[i] << ", ";
    }

    std::cout << "\b\b  " << std::endl << std::endl;

    std::cout << "Sorting array..." << std::endl;
    array.sort();
    std::cout << "array2 = ";
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << "\b\b  " << std::endl << std::endl;

    return 0;
}
