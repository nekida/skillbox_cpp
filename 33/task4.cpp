#include <iostream>
#include <string>
#include <vector>

static constexpr size_t sizeArray = 8;

template <typename T>
void addValue(T* array, size_t len)
{
    T value;
    for (size_t i = 0; i < len; i++) {
        std::cin >> value;
        array[i] = value;
    }
}

template <typename T>
T average(T *array, size_t len)
{
    T sum = 0;
    for (size_t i = 0; i < len; i++)
        sum += array[i];
    return sum / len;
}

int main ()
{
    std::string type;
    std::cin >> type;

    if (type == "int") {
        int arrayInt[sizeArray];
        std::cout << "Input new \"int\" values for array " << std::endl;
        addValue(arrayInt, sizeof (arrayInt) / sizeof (arrayInt[0]));
        std::cout << "Average: " << average(arrayInt, sizeof (arrayInt) / sizeof (arrayInt[0])) << std::endl;
    } else if (type == "double") {
        double arrayDouble[sizeArray];
        std::cout << "Input new \"double\" values for array " << std::endl;
        addValue(arrayDouble, sizeof (arrayDouble) / sizeof (arrayDouble[0]));
        std::cout << "Average: " << average(arrayDouble, sizeof (arrayDouble) / sizeof (arrayDouble[0])) << std::endl;
    }  else if (type == "float") {
        float arrayFloat[sizeArray];
        std::cout << "Input new \"float\" values for array " << std::endl;
        addValue(arrayFloat, sizeof (arrayFloat) / sizeof (arrayFloat[0]));
        std::cout << "Average: " << average(arrayFloat, sizeof (arrayFloat) / sizeof (arrayFloat[0])) << std::endl;
    }

    return 0;
}
