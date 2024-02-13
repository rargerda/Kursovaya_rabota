#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <windows.h>
#include <fstream>
#include "safe_input.h"

SafeInput sf;

class Graph
{
public:
    Graph(int vertices) : V(vertices), chromaticNumber(0)
    {
        adjacencyMatrix.resize(V, std::vector<int>(V, 0)); // Матрица смежности, заполненая 0 
    }

    // Функция добавления ребра 
    bool addEdge(int v, int w)
    {
        // Проверка на границы 
        if (v < 0 || v >= V || w < 0 || w >= V) return 1; 
        // Устанавливаем ребра 
        adjacencyMatrix[v][w] = 1;
        adjacencyMatrix[w][v] = 1;
        return 0;
    }

    // Функция вывода графа в консоли 
    void printGraph()
    {
        for (int i = 0; i < V; ++i)
        {
            // Вывод текущей вершины 
            std::cout << "Вершина " << i << ": ";
            for (int j = 0; j < V; ++j)
            {
                // Если вершины смежны 
                if (adjacencyMatrix[i][j] == 1)
                {
                    std::cout << j << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    // Функция сохранения результатов в файле 
    void printGraphToFile()
    {
        // Ввод имени файла 
        std::string fileName;
        std::cout << std::endl << "Введите имя файла для сохранения графа: ";
        std::cin >> fileName;
        std::ofstream file(fileName);
        for (int i = 0; i < V; ++i)
        {
            // Ввод связей в файл 
            file << "Вершина " << i << ": "; // Вывод текущей вершины 
            for (int j = 0; j < V; ++j)
            {
                // Если вершины смежны 
                if (adjacencyMatrix[i][j] == 1)
                {
                    file << j << " "; 
                }
            }
            file << std::endl;
        }
        file.close();
    }

    // Функция раскраски графа и получения хроматического числа 
    void colorGraph()
    {
        colors.resize(V, -1); // Помечаем все вершины нераскрашенными 
        chromaticNumber = 0; // Хроматическое число 

        for (int i = 0; i < V; ++i)
        {
            // Если вершина не раскрашена
            if (colors[i] == -1) 
            {
                dfsColoring(i); // Вызов функции обхода и поиска цвета 
                ++chromaticNumber; // Увеличиваем хроматическое число 
            }
        }

        std::cout << std::endl << "Хроматическое число: " << chromaticNumber << std::endl;
        printColors();
    }

private:
    int V; // Вершины
    int chromaticNumber; // Для поиска нового цвета
    std::vector<std::vector<int>> adjacencyMatrix; // Матрица 
    std::vector<int> colors; // Уникальные цвета 

    // Поиск в глубину 
    void dfsColoring(int vertex)
    {
        static std::set<int> availableColors; // Множество цветов 

        for (int i = 0; i < V; ++i)
        {
            // Если вершина смежна и нераскрашенна 
            if (adjacencyMatrix[vertex][i] == 1 && colors[i] != -1)
            {
                availableColors.insert(colors[i]); // Добавляем в множество 
            }
        }

        int chosenColor = 0;

        // Находим новый цвет для вершины 
        while (availableColors.count(chosenColor))
        {
            ++chosenColor;
        }

        colors[vertex] = chosenColor; // Сохранение цвета 
        availableColors.clear(); // Очищение множества 

        // Рекурсивный вызов для всех смежных вершин 
        for (int i = 0; i < V; ++i)
        {
            if (adjacencyMatrix[vertex][i] == 1 && colors[i] == -1)
            {
                dfsColoring(i);
            }
        }
    }

 public:
     // Функция вывода цветов в консоль 
    void printColors()
    {
        for (int i = 0; i < V; ++i)
        {
            std::cout << "Вершина " << i << " раскрашена цветом " << colors[i] << std::endl; // Вывод цвет расскраски соответсвующей вершины 
        }
    }
    // Функция вввода цветов в файл
    void printColorsToFile()
    {
        // Ввод имени файла
        std::cout << std::endl << "Введите имя файла для сохранения цветов графа: ";
        std::string fileName;
        std::cin >> fileName;
        std::ofstream file(fileName);
        for (int i = 0; i < V; ++i)
        {
            file << "Вершина " << i << " раскрашена цветом " << colors[i] << std::endl; // Ввод цвет расскраски соответсвующей вершины 
        }
        file.close();
    }
};

// Функция добавления ребра между вершинами 
void AddFromKeyBoard(Graph& g)
{
    bool resume = 1; // Для продолжения заполнения, изначально в режиме добавления 
    while (resume) // Пока добовляем 
    {
        int input;
        int output;
        sf.safe_input("Добавление ребра.\nВведите начало ребра(откуда): ", input); // Начальная вершина для ребра 
        sf.safe_input("Добавление ребра.\nВведите конец ребра(куда): ", output); // Конечная вершина для ребра 

        // Если добавление не удалось 
        if (g.addEdge(input, output))
        {
            std::cout << "Введены некорректные данные, попробуйте снова." << std::endl;
            //resume = true;
            //continue;
        }
        else // Иначе 
        {
            std::cout << "Ребро успешно добавлено!" << std::endl;
        }
        resume = sf.end_request("Продолжить? (да|нет)\n > "); // Проверка на продолжение 
    }
    std::cout << std::endl << std::endl;
}

// Основная функция 
int main()
{
    // Ввод и вывод на русском 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Вывод титульника 
    std::cout << "Пензенский государственный университет" << std::endl;
    std::cout << "\"Кафедра \"Вычислительная техника\"" << std::endl;
    std::cout << "Курсовая работа" << std::endl;
    std::cout << "По курсу \"Логика и основы алгоритмизации в инженерных задачах\"" << std::endl;
    std::cout << "На тему \"Реализация алгоритма раскрашивания графа\"" << std::endl;
    std::cout << "Приняли: Юрова О.В. и Акифьев И.В." << std::endl;
    std::cout << "Выполнила: Гераськина Дарья Андреевна, учебная группа 22ВВВ3(22ВВП2)" << std::endl << std::endl;
    //

    int numVertices;
    sf.safe_input("Введите количество вершин графа: ", numVertices); // Ввод кол-ва вершин 
    while (numVertices < 1) // Если вершин меньше 1, входим в цикл 
    {
        std::cout << std::endl << "Вы задали число вершин меньше 1. Граф пустой, его невозможно раскрасить. Повторите попытку." << std::endl << std::endl;
        sf.safe_input("Введите количество вершин графа: ", numVertices); // Ввод кол-ва вершин 
    }

    Graph g(numVertices); // Создаем граф в соответствие с введенным числом вершинам 

    bool automatical = sf.end_request("\nЗаполнить граф автоматически? (да|нет)\n > "); // Как будет происходить заполнение графа 

    std::cout << std::endl;

    // Автоматическое заполнение - инициализируем циклический граф
    if (automatical)
    {
        for (int i = 0; i < numVertices-1; ++i)
        {
            g.addEdge(i, i + 1); // Соеденяем текущию и следущаю вершину 
        }
        g.addEdge(numVertices - 1, 0); // Соеденение первой и последней вершины, для зацикливания 
    }
    else // Иначе ручное заполнение - берем данные с клавиатуры
    {
        AddFromKeyBoard(g);
    }

    std::cout << "Граф:" << std::endl;

    g.printGraph(); // Выводим связи между вершинами

    g.colorGraph(); // Выводим цвет расскраски 

    std::cout << std::endl;

    bool save = sf.end_request("Сохранить результат? (да|нет)\n > "); // Хочет ли пользователь сохранить результат в файле 

    // Если пользователь выбрал "да"
    if (save)
    {
        g.printGraphToFile(); // Выводим связи между вершинами
        g.printColorsToFile(); // Выводим цвет расскраски 
    }

    return 0;
}