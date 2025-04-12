#include <iostream>
#include <fstream>
#include <stack>

void printAr(uint16_t** const ar, int N);

void getGraph(uint16_t**& ar, int& N);

void deleteArr(uint16_t**& ar, int N);

void dfs(uint16_t** const ar, int vertix, uint16_t* visited, std::stack<int>* order, int N);

int main()
{
    setlocale(LC_ALL, "RU");

    int N{ 0 };
    uint16_t** grafAr = nullptr;
    getGraph(grafAr, N);
    std::stack<int> order;
    uint16_t* visited = new uint16_t[N]{ 0 };

    for (int l = 0; l < N; l++)
    {
        if (!visited[l]) {
            dfs(grafAr, l, visited, &order, N);
        }
    };

    while (!order.empty()) {
        std::cout << order.top() << " ";
        order.pop();
    }

     //printAr(grafAr, N);
    deleteArr(grafAr, N);
    delete[] visited;
}

void printAr(uint16_t** const ar, int N) {

    for (size_t i = 0; i < N; i++)
    {
        for (size_t k = 0; k < N; k++)
        {
            std::cout << ar[i][k] << " ";
        }

        std::cout << std::endl;
    }
}

void getGraph(uint16_t**& ar, int& N) {

    std::string data;
    std::ifstream file("input.txt");
    file >> N;
    ar = new uint16_t* [N];
    for (size_t i = 0; i < N; i++)
    {
        ar[i] = new uint16_t[N]{ 0 };
        for (size_t k = 0; k < N; k++)
        {
            file >> ar[i][k];
        }
    };

    file.close();
}


void deleteArr(uint16_t**& ar, int N) {
    for (size_t i = 0; i < N; i++)
    {
        delete[] ar[i];
    }

    delete[] ar;
}

void dfs(uint16_t** const ar, int vertix, uint16_t* visited, std::stack<int>* order, int N) {
    visited[vertix] = 1;
    for (int i = vertix; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            if (ar[i][k] == 1) {
                if (!visited[k]) {
                    dfs(ar, k, visited, order, N);
                }
            }
        }
    }
    order->push(vertix + 1);
}