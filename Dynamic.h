// Seongryul.park Minki.cho.
// Class Project
// CS225, Fall & 2022.

template <typename T, int size>
class Dynamic_Array
{
private:
    T* my_array;

public:
    auto Access(int index) { return my_array[index]; }
    int Length() { return size; }

    Dynamic_Array() { my_array = new T[size]; }

    Dynamic_Array(const Dynamic_Array& array) = delete;
    Dynamic_Array(Dynamic_Array&& array) = delete;
    
    ~Dynamic_Array() 
    { 
        if(my_array != nullptr)
        {
            delete[] my_array;
        }
    }

    auto& operator[](auto index) { return my_array[index]; }
};