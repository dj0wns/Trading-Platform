#!/bin/bash

g++ -std=c++11 src/*.cpp -o bin/tradingPlatform  -pthread -lcurl -lboost_system -lboost_filesystem -pipe

