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




void initTests()
{
  tests.push_back(test1);
  tests.push_back(test2);
  tests.push_back(test3);
  tests.push_back(test4);
  tests.push_back(test5);
  tests.push_back(test6);
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
