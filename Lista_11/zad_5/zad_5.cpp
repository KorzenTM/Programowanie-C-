#include <iostream>
#include <vector>

template<typename T>
class SymmetricArray
{
private:
    int _size;
    std::vector<std::vector<T>> array;
public:
    SymmetricArray(int size):_size(size)
    {
        std::cout << "Tworzenie macierzy kwadratowej o rozmiarze " << _size << "\n";
        array.resize(_size);
        zeros(); //domyślnie wypełniona zerami
    }
    void zeros()
    {
        for (unsigned i = 0; i < array.size(); ++i)
            array[i].resize(_size);

        for (unsigned i = 0; i < array.size(); ++i)
            for (unsigned j = 0; j < array[i].size(); ++j)
                array[i][j] = static_cast<T>(0);
    }
    void ones()
    {
        int index = 1;
        for (unsigned i = 0; i < array.size(); ++i)
        {
            for (unsigned j = 0; j < index and index <= array[i].size(); ++j)
                array[i][j] = static_cast<T>(1);
            index++;
        }
    }
    void fun()
    {
        int index = 1;
        for (unsigned i = 0; i < array.size(); ++i)
        {
            for (unsigned j = 0; j < index and index <= array[i].size(); ++j)
                array[i][j] = static_cast<T>((i * j) / 100.0);
            index++;
        }
    }
    void print()
    {
        for (unsigned i = 0; i < array.size(); ++i)
        {
            std::cout << "| ";
            for (unsigned j = 0; j < array[i].size(); ++j)
                std::cout<< array[i][j] << " ";
            std::cout << "|\n";
        }
    }
    T & operator() (int x, int y)   {return array[x][y];}
    T operator() (int x, int y) const {return array[x][y];}


    ~SymmetricArray() {}

};




int main()
{
    SymmetricArray<double> arr(10);
    arr.fun();
    arr.print();

}

