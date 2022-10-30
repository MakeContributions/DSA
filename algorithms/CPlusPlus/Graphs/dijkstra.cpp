#include <cstddef>
#include <limits>

//I highly recommend to create matrix class
template <typename T>
inline T& getMatrixElement( T* matrix, size_t size, 
                            size_t row, size_t column)
{
    return *(matrix + row * size + column);
}

template <typename T>
inline void setMatrixElement ( T* matrix, size_t size,
                               size_t row, size_t column, T element)
{
    *(matrix + row * size + column) = element;
}

template <typename T>
size_t minDistance(T* vector, bool* states, size_t size)
{
    size_t index;
    T min = std::numeric_limits<T>::max();

    for(size_t i = 0; i < size; i++)
    {
        if (states[i] == false && vector[i] <= min)
        {
            min = vector[i];
            index = i;
        }
    }

    return index;
}

template <typename T>
T* dijkstra (T* matrix, size_t matrix_size, size_t start_pos)
{
    T* result = new T [matrix_size];
    // I recoment use dynamic bitset from boost library
    bool* states = new bool[matrix_size];

    //Set All elements to max value and all state to False
    for(size_t i = 0; i < matrix_size; i++)
    {
        result[i] = std::numeric_limits<T>::max();
        states[i] = false;
    }
    
    result[0] = 0;

    for(size_t i = 0; i < matrix_size; i++)
    {
        size_t index = minDistance(result, states, matrix_size);
        states[index] = true;

        for(size_t j = 0; j < matrix_size; j++)
        {
            if (
                !states[j] &&
                getMatrixElement(matrix, matrix_size, index, j) &&
                result[index] +  getMatrixElement(matrix, matrix_size, index, j) < result[j]
                //result.get(index) != std::numeric_limits<T>::max()
                )
            {
                T new_val = result[index] + getMatrixElement(matrix, matrix_size, index, j);
                result[j] = new_val;
            }
        }
    }

    return result;
}

#include <iostream>


//function declaration below
//Generate and std::cout << matrix
void getExampleMatrix(int*& matrix_out, size_t& size_out);

int main()
{
    //I highly recommend to create matrix class

    size_t size;
    std::cout << "Graph Size: ";
    std::cin >> size; 

    int* user_graph_matrix = new int [size*size];

    for(size_t i = 0; i < size; i++)    
    {
        for(size_t j = 0; j < size; j++)    
        {
            int temp;
            std::cout << "(" << j << ", " << i << ") = ";
            std::cin >> temp;

            setMatrixElement(user_graph_matrix, size, i, j, temp);
        }
    }


    size_t start_element = std::numeric_limits<size_t>::max();
    while (true)
    {
        std::cout << "Choose First Element: ";
        std::cin >> start_element;

        if(start_element < size)
            break;
        
        std::cout << "[Warning] Number of element is greater that matrix size\n";
    }

    auto ex_result = dijkstra(user_graph_matrix, size, start_element);
    for(size_t i = 0; i < size; i++)
    {
        std::cout << ex_result[i] << " ";
    }
    std::cout << "\n";

    // !!! Unkoment for example matrix

    // size_t ex_size;
    // int* ex_matrix;
    
    // getExampleMatrix(ex_matrix, ex_size);

    // auto ex_result = dijkstra(ex_matrix, ex_size, 0);
    // for(size_t i = 0; i < ex_size; i++)
    // {
    //     std::cout << ex_result[i] << " ";
    // }
    // std::cout << "\n";
}

void getExampleMatrix(int*& matrix_out, size_t& size_out)
{
    size_t size = 4;
    int* graph_matrix = new int[size*size];

    setMatrixElement(graph_matrix, size, 0, 0, 0);
    setMatrixElement(graph_matrix, size, 0, 1, 0);
    setMatrixElement(graph_matrix, size, 0, 2, 3);
    setMatrixElement(graph_matrix, size, 0, 3, 1);

    setMatrixElement(graph_matrix, size, 1, 0, 0);
    setMatrixElement(graph_matrix, size, 1, 1, 0);
    setMatrixElement(graph_matrix, size, 1, 2, 0);
    setMatrixElement(graph_matrix, size, 1, 3, 5);

    setMatrixElement(graph_matrix, size, 2, 0, 3);
    setMatrixElement(graph_matrix, size, 2, 1, 0);
    setMatrixElement(graph_matrix, size, 2, 2, 0);
    setMatrixElement(graph_matrix, size, 2, 3, 1);

    setMatrixElement(graph_matrix, size, 3, 0, 1);
    setMatrixElement(graph_matrix, size, 3, 1, 5);
    setMatrixElement(graph_matrix, size, 3, 2, 1);
    setMatrixElement(graph_matrix, size, 3, 3, 0);

    for(size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << getMatrixElement(graph_matrix, size, i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    size_out = size;
    matrix_out = graph_matrix;
}