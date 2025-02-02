#include <vector>
#include <functional>
#include <iostream>

#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

//тест 1 'body_contains'
bool test1()
{
    Candle candle{ 3.0, 7.0, 0.0, 4.0 };
    return candle.body_contains(3.5);
}

//тест 2 'body_contains'
bool test2()
{
    Candle candle{ 0.0, 0.0, 0.0, 0.0 };
    candle.open -= INFINITY;
    candle.close = INFINITY;

    return candle.body_contains(INFINITY);
}

//тест 3 'body_contains'
bool test3()
{
    Candle candle{ 8.0, 10.0, 0.0, -15.0 };
    candle.open = NULL;

    return candle.body_contains(-5.0);
}

//тест 1 'contains'
bool test4()
{
    Candle candle{ 3.0, 7.0, 0.0, 4.0 };


    return candle.contains(7.0);
}

//тест 2 'contains'
bool test5()
{
    Candle candle{ 0.0, 0.0, 0.0, 0.0 };

    return candle.contains(3.0) == false;;
}

//тест 3 'contains'
bool test6()
{
    Candle candle(NULL, NULL, NULL, NULL);


    return candle.contains(3.0) == false;
}

//тест 1 'full_size'
bool test7()
{
    Candle candle{ 3.0, 7.0, 0.0, 4.0 };
    return candle.full_size() == 7.0;
}

//тест 2 'full_size'
bool test8()
{
    Candle candle{ 0.0, 0.0, 0.0, 0.0 };

    return candle.full_size() == 0.0;
}

//тест 3 'full_size'
bool test9()
{
    Candle candle{ 0.0, INFINITY, NULL, 0.0 };

    return candle.full_size() == INFINITY;
}

//тест 1 'body_size'
bool test10()
{
    Candle candle{ 3.0, 7.0, 0.0, 4.0 };

    return candle.body_size() == 1.0;
}

//тест 2 'body_size'
bool test11()
{
    Candle candle{ INFINITY, 7.0, 0.0, -INFINITY };

    return candle.body_size() == INFINITY;
}

//тест 3 'body_size'
bool test12()
{
    Candle candle{ NULL, 7.0, 0.0, NULL };

    return candle.body_size() == 0.0;
}

//тест 1 'is_red'
bool test13()
{
    Candle candle{ 3.0, 7.0, 0.0, 2.0 };

    return candle.is_red();
}

//тест 2 'is_red'
bool test14()
{
    Candle candle{ 0.0, 7.0, 0.0, 2.0 };

    return candle.is_red() == false;
}

//тест 3 'is_red'
bool test15()
{
    Candle candle{ 0.0, 7.0, 0.0, 0.0 };

    return candle.is_red() == false;
}




void initTests()
{
  tests.push_back(test1);
  tests.push_back(test2);
  tests.push_back(test3);
  tests.push_back(test4);
  tests.push_back(test5);
  tests.push_back(test6);
  tests.push_back(test7);
  tests.push_back(test8);
  tests.push_back(test9);
  tests.push_back(test10);
  tests.push_back(test11);
  tests.push_back(test12);
  tests.push_back(test13);
  tests.push_back(test14);
  tests.push_back(test15);



}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
