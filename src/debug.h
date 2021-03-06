/**
 * Multiparty Off-the-Record Messaging library
 * Copyright (C) 2016, eQualit.ie
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of version 3 of the GNU Lesser General
 * Public License as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#pragma once

#include <set>
#include <list>
#include <ostream>
#include <sstream>

template<class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    for (auto i = s.begin(); i != s.end(); ++i) {
        if (i != s.begin()) os << ", ";
        os << *i;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& s) {
    os << "[";
    for (auto i = s.begin(); i != s.end(); ++i) {
        if (i != s.begin()) os << ", ";
        os << *i;
    }
    os << "]";
    return os;
}

namespace np1sec_plugin { namespace util {
    namespace _detail {
        void stringify(std::ostream& os) {
        }

        template<class Arg, class... Args>
        void stringify(std::ostream& os, Arg&& arg, Args&&... args) {
            os << arg;
            stringify(os, std::forward<Args>(args)...);
        }
    }

    template<class... Args>
    std::string str(Args&&... args) {
        std::stringstream ss;
        _detail::stringify(ss, std::forward<Args>(args)...);
        return ss.str();
    }
}}
