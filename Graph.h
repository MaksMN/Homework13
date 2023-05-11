#define SIZE 100
#include "Member.h"
#include <iostream>
class Graph
{
public:
    Graph();
    /// @brief Добавление пользователя в граф
    /// @param member
    void addMember(Member *member);

    /// @brief Добавление рукопожатия
    /// @param member1
    /// @param member2
    void addHandshake(Member *member1, Member *member2);

    /// @brief Получить все рукопожатия пользователя
    /// @param member
    /// @param depth - глубина рукопожатий
    void getAllThreeHandshakes(Member *member, int depth);

    /// @brief Проверка рукопожатий между двумя пользователями
    /// @param m1
    /// @param m2
    /// @param depth - глубина рукопожатий
    void getPairThreeHandshakes(Member *m1, Member *m2, int depth);

private:
    /// @brief Получить указательна пользователя по ID
    /// @param id
    /// @return
    Member *getMemberById(int id);
    int mCount = 0;        // счетчик добавленных пользователей
    Member *members[SIZE]; // Хранилище пользователей
    int membersId[SIZE];   // вершины в графе

    /// @brief Есть ли одно рукопожатие между пользователями (по указателям)
    /// @param m1
    /// @param m2
    /// @return
    bool handshakeExists(Member *m1, Member *m2);

    /// @brief Есть ли одно рукопожатие между пользователями (по ID)
    /// @param m1Id
    /// @param m2Id
    /// @return
    bool handshakeExists(int m1Id, int m2Id);

    /// @brief Проверка пользователя в матрице.
    /// @param member
    /// @return
    bool memberExists(Member *member);

    int matrix[SIZE][SIZE]; // матрица смежности
};