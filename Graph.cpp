#include "Graph.h"

Graph::Graph()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    mCount = 0;
}
void Graph::addMember(Member *member)
{
    member->setId(mCount);
    members[mCount] = member;
    membersId[mCount] = member->getId();
    mCount++;
}
void Graph::addHandshake(Member *m1, Member *m2)
{
    matrix[m1->getId()][m2->getId()] = 1;
    matrix[m2->getId()][m1->getId()] = 1;
}

Member *Graph::getMemberById(int id)
{
    return members[id];
}

void Graph::getAllThreeHandshakes(Member *member, int depth)
{
    std::cout << "Все знакомые " << member->getName() << ":" << std::endl;
    int count = 0;
    int start = member->getId();
    int queue_to_visit[SIZE]; // очередь вершин для обхода
    int queueCount = 0;

    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;

    queue_to_visit[queueCount++] = start; // кладем в очередь начальную вершину
    while (queueCount > 0)
    {
        // взятие из очереди вершины
        int current = queue_to_visit[0];
        queueCount--;
        for (int i = 0; i < queueCount; i++)
        {
            queue_to_visit[i] = queue_to_visit[i + 1];
        }
        visited[current] = true;

        if (queueCount == 0)
        {
            count++;
        }

        std::cout << getMemberById(current)->getName();

        if (count == depth)
        {
            std::cout << std::endl;
            return;
        }
        std::cout << " -> ";
        // поиск смежных вершин и добавление их в очередь
        for (int i = 0; i < SIZE; i++)
        {

            bool alreadyAdded = false;
            for (int j = 0; j < queueCount; j++)
                if (queue_to_visit[j] == i)
                {
                    alreadyAdded = true;
                    break;
                }
            if (!alreadyAdded && handshakeExists(current, i) && !visited[i])
                queue_to_visit[queueCount++] = i;
        }
    }
}

void Graph::getPairThreeHandshakes(Member *m1, Member *m2, int depth)
{
    int count = 0;
    int start = m1->getId();
    int end = m2->getId();
    int queue_to_visit[SIZE]; // очередь вершин для обхода
    int queueCount = 0;

    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;

    queue_to_visit[queueCount++] = start; // кладем в очередь начальную вершину
    while (queueCount > 0)
    {
        // взятие из очереди вершины
        int current = queue_to_visit[0];
        queueCount--;
        for (int i = 0; i < queueCount; i++)
        {
            queue_to_visit[i] = queue_to_visit[i + 1];
        }
        visited[current] = true;

        if (queueCount == 0)
        {
            count++;
        }
        if (current == end)
        {
            std::cout << m1->getName() << " и " << m2->getName() << " знакомы" << std::endl;
            return;
        }

        if (count == depth)
        {
            std::cout << m1->getName() << " и " << m2->getName() << " не знакомы" << std::endl;
            return;
        }

        // поиск смежных вершин и добавление их в очередь
        for (int i = 0; i < SIZE; i++)
        {

            bool alreadyAdded = false;
            for (int j = 0; j < queueCount; j++)
                if (queue_to_visit[j] == i)
                {
                    alreadyAdded = true;
                    break;
                }
            if (!alreadyAdded && handshakeExists(current, i) && !visited[i])
                queue_to_visit[queueCount++] = i;
        }
    }
    std::cout << std::endl;
}

bool Graph::handshakeExists(Member *m1, Member *m2)
{
    return matrix[m1->getId()][m2->getId()] > 0;
}

bool Graph::handshakeExists(int m1Id, int m2Id)
{
    return matrix[m1Id][m2Id] > 0;
}

bool Graph::memberExists(Member *member)
{
    for (int i = 0; i < mCount; i++)
        if (members[i]->getId() == member->getId())
            return true;
    return false;
}