#ifndef _json_common_hpp_
#define _json_common_hpp_

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

/// \file common.hpp Common defs needed everywhere and, as far as is possible, platform specific changes.

/// You can change the namespace of the whole library by changing this value.
#ifndef NAMESPACE
#   define NAMESPACE argo
#endif

#include <cstdlib>

#ifdef ARGO_NOTHROW
#   ifndef ARGO_EXIT_CODE
        // the number of crew-mates jason had at the start of his journey for the golden fleece
#       define ARGO_EXIT_CODE 49
#   endif
#   define ARGO_THROW(Type, ...) { printf("ARGO error " #Type "" #__VA_ARGS__); std::exit(ARGO_EXIT_CODE); } 
#endif

#ifndef ARGO_THROW
#   define ARGO_THROW(Type, ...) throw Type(__VA_ARGS__);
#endif

#ifdef _MSC_VER
#define strerror_r(e, b, l) strerror_s(b, l, e)
#define _ARGO_WINDOWS_
#endif

#endif
