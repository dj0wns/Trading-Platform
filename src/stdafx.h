// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <stdio.h>
#include <iostream> // for io operations
#include <fstream> //for archiving data
#include <string> //strings are great
#include <regex> // for string parsing
#include <curl/curl.h> // for web operations
#include <cassert> // for errors
#include <vector> // for products and orders

#include <thread> //for multithreading
#include <atomic> //prevent race conditions



//for parsing the JSON from cme website
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>

// TODO: reference additional headers your program requires here
