// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream> // for io operations
#include <fstream> //for archiving data
#include <string> //strings are great
#include <regex> // for file parsing
#include <curl/curl.h> // for web operations


//for parsing the JSON from cme website
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

// TODO: reference additional headers your program requires here
