#include <iostream>
#include <string>
#include "Graph.h"

int main(int argc, const char *argv[])
{
    // Создание участников соцсети
    Member *vasya = new Member("Вася");
    Member *petya = new Member("Петя");
    Member *maria = new Member("Мария");
    Member *andrew = new Member("Андрей");
    Member *vitaly = new Member("Вася");
    Member *anna = new Member("Анна");
    Member *nataly = new Member("Наталья");
    Member *nastya = new Member("Настя");
    Member *eugeny = new Member("Евгений");
    Member *stas = new Member("Стас");
    Member *ivan = new Member("Иван");

    // Добавление участников в граф
    Graph g;
    g.addMember(vasya);
    g.addMember(petya);
    g.addMember(maria);
    g.addMember(andrew);
    g.addMember(vitaly);
    g.addMember(anna);
    g.addMember(nataly);
    g.addMember(nastya);
    g.addMember(eugeny);
    g.addMember(stas);
    g.addMember(ivan);

    // Создание рукопожатий
    // В этой схеме Вася не знаком с Настей
    g.addHandshake(vasya, maria);
    g.addHandshake(maria, petya);
    g.addHandshake(maria, eugeny);
    g.addHandshake(eugeny, ivan);
    g.addHandshake(maria, stas);
    g.addHandshake(ivan, nataly);
    // g.addHandshake(vasya, ivan); // эта строка познакомит Васю с Настей через Ивана
    g.addHandshake(nataly, nastya);

    // Все с кем знаком вася
    g.getAllThreeHandshakes(vasya, 3);

    // Проверить знаком ли Вася с Настей
    g.getPairThreeHandshakes(vasya, nastya, 3);

    // Знаком ли Вася со Стасом
    g.getPairThreeHandshakes(vasya, stas, 3);

    delete vasya;
    delete petya;
    delete maria;
    delete andrew;
    delete vitaly;
    delete anna;
    delete nataly;
    delete nastya;
    delete eugeny;
    delete stas;
    delete ivan;

    return 0;
}