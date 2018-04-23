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
}

#endif // ARRAYLIST_H
