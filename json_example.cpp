/*
 * Copyright (c) 2017 Andrew Haisley
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/// \file json_example.cpp Argonaut example code.

#include <iostream>
#include <fstream>
#include "argonaut.hpp"

void hello_world()
{
    std::string s = "{ \"one\" : \"hello world\"}";
    auto j = argonaut::parser::parse(s);
    std::cout << (*j)["one"] << std::endl;
}

void parse_file()
{
    auto j = argonaut::parser::load("test_files/test2.json");
    argonaut::unparser::save(*j, "test_files/tmp.json");
}

void construct()
{
    // create an object
    argonaut::json j(argonaut::json::object_e);

    // add some values
    j["one"] = 1;
    j["two"] = 2.0;
    j["three"] = "three";
    j["four"] = true;
    j["five"] = false;
    j["six"] = argonaut::json(); // null
    
    // print it
    std::cout << j << std::endl;
}

int main(int argc, char *argv[])
{
    try
    {
        hello_world();
        parse_file();
        construct();
    }
    catch (argonaut::json_exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
