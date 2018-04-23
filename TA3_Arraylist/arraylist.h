#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <typename T>
class ArrayList
{
public:
    ArrayList();

    //Copy constructor
    ArrayList(const ArrayList<T>& c);

    //Move constructor
    ArrayList(ArrayList<T>&& c);

    /*
     * Constructor with initialisation of "initialized" elements
     */
    ArrayList(int initialized);

    virtual ~ArrayList();

    /*
     * Copy assignment operator
     */
    ArrayList<T>& operator=(const ArrayList<T>& a);

    /*
     * Move assignment operator
     */
    ArrayList<T>& operator=(ArrayList<T>&& a);

    /*
     * Add element to dynamic array
     */
    void add(const T& element) {
        if (_size == _reserved)
            extendStorage();

        _elems[_size] = element;
        ++_size;
    }

    /*
     * Inserts the element at placement "idx" in array and moves the remaining
     * items by one place, restoring the old element at "idx"
     * check whether it is needed to extend the storage.
     * mov all elements from _size to idx (reverse) one element to the right in the array
     * set elems[idx] equal to the element to be inserted
     */
    void add(int idx, const T& element);

    /*
     * Get const reference to the element at idx
     */
    const T& operator[](int idx) const;

    /*
     * Get a reference to the element at idx
     */
    T& operator [](int idx);

    /*
     * Removes the element at placement "idx" by moving all the remaining elements
     * by one place to the left in the array
     */
    void remove(int idx);

    /*
     * Returns the number of elements stored
     */
    int size() const;

    /*
     * Returns the number of items currently reserved in memory
     */
    int reserved() const;

    /*
     * Returns true if number of elements in array is zero
     */
    bool isEmpty() const;

    /*
     * Trims the storage array to the exact number of elements stored.
     */
    void trimToSize();

    /*
     * Sorts the array using insertion sort (or another algorithm)
     */
    void sort();

    /*
     * Returns a new ArrayList with elements from "fromIdx" index to "toIdx"
     */
    ArrayList<T> subArrayList(int fromIdx, int toIdx) const;

    /*
     * Returns a new C++ style array (copy created with new) with all elements
     */
    T* toArray();

private:
    /*
     * extendStorage();
     *      create new array with size 2*_reserved
     *      copy old data to the new array
     *      delete old aray
     *      update pointer _elems to point to the new array
     * (Since the method is private, the method will only be used internally,
     * but the functionality is needed)
     */
    void extendStorage();

    /*
     * Member variables
     */
    int _reserved;  // The current capacity of "_elems" array
    int _size;      // The number of elements stored
    T* _elems;      // Array for soring the elements
};

template<class T>
ArrayList<T>::ArrayList()
{

}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T> &c)
{
    _size = c.size();
    _reserved = c.reserved();
    _elems= new T [_reserved];
    for (int i =0; i<_size;i++) {
       _elems[i]=c[i];
    }
}


template<class T>
ArrayList<T>::ArrayList(ArrayList<T> &&c)
{
    _size = c.size();
    _reserved = c.reserved();
    _elems = c._elems;

    c._size = 0;
    c._reserved = 0;
    c._elems = nullptr;
}

template<class T>
ArrayList<T>::ArrayList(int initialized)
{

}

template<class T>
ArrayList<T>::~ArrayList()
{

}

template<class T>
ArrayList<T>::operator=(const ArrayList<T>& a)
{
    if (this != a) {
        delete [] _elems;
        _elems = new T[a._size];
        for (int i = 0; i < a._elems; i++)
            _elems[i] = a._elems[i];
        _size = a._size;
    }
    return *this;
}

template<class T>
ArrayList<T>::operator=(ArrayList<T>&& a)
{
    if (this != &a) {
        delete [] _elems;
        _elems = a._elems;
        _size = a._size;

        a._elems = nullptr;
        a._size = 0;
    }
    return *this;
}

template<class T>
void ArrayList<T>::add(int idx, const T &element)
{
    if (idx > _size) {
        return;
    }
    if (_size == _reserved){
        extendStorage();
    }

    for (unsigned int i = _size; i > idx; i--){ //shuffle right
        _elems[i+1] = _elems[i];
    }
    _elems[idx] = element;
    _size++;
}

template<class T>
T& ArrayList<T>::operator [](int idx) const
{
    return _elems[idx];
}

template<class T>
T& ArrayList<T>::operator [](int idx)
{
    return _elems[idx];
}

template<class T>
void ArrayList<T>::remove(int idx)
{
    if (idx > _size){
        return;
    }
    for (unsigned int i = idx; i < _size; i++){ //shuffle right
        _elems[i]=_elems[i+1];
    }
    _size--;
}

template<class T>
int ArrayList<T>::size()
{
    return _size;
}

template<class T>
int ArrayList<T>::reserved()
{
    return _reserved;
}

template<class T>
bool ArrayList<T>::isEmpty()
{
    return _size;
}

template<class T>
ArrayList<T>::trimToSize()
{

}

template<class T>
void ArrayList<T>::sort()
{

}

template<class T>
ArrayList<T> ArrayList<T>::subArrayList(int fromIdx, int toIdx) const
{

}

template<class T>
T* ArrayList<T>::toArray()
{
    T* res = T[_size];
    for (unsigned int i = 0; i < _size; i++){
        res[i] = _elems[i];
    }

    return res;
}

template<class T>
void ArrayList<T>::extendStorage()
{
    T* temp = new T[size * 2]; //make new array 2x larger
    for (unsigned int i = 0; i < _size; i++){
        _elems[i] = temp[i]; //copy values from elems to new array
    }
    _reserved *= 2;
    delete [] _elems; //delete data at _elems
    _elems = temp; //point _elems at new array
}

#endif // ARRAYLIST_H
