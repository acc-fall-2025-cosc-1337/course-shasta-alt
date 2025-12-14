cmake_minimum_required(VERSION 3.12)
project(portfolio_app CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(portfolio_app
    main.cpp
    bond.cpp
    cash.cpp
    holding.cpp
    investment.cpp
    mutual_fund.cpp
    portfolio.cpp
    stock.cpp
)
target_include_directories(portfolio_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
