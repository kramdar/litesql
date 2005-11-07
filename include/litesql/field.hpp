/* LiteSQL 
 * 
 * By Tero Laitinen 
 * 
 * See LICENSE for copyright information. */

#ifndef __litesql_field_hpp
#define __litesql_field_hpp
#include <iostream>
/** \file field.hpp
    contains FieldType- and Field-classes */
namespace litesql {
using namespace std;

/** holds field name, type and table information */
class In;
class Like;
class SelectQuery;

class FieldType {
    string _name, _type, _table;
public:

    FieldType(const string& n, 
              const string& t, 
              const string& tbl) 
        : _name(n), _type(t), _table(tbl) {}
    string fullName() const { return  table() + "." + name(); }
    string name() const { return _name; }
    string type() const { return _type; }
    string table() const { return _table; }
    /** syntactic sugar to Expr-API, Object::field_.in(set) */
    In in(const string& set) const;
    /** syntactic sugar to Expr-API, Object::field_.in(sel) */
    In in(const SelectQuery& sel) const;
    /** syntactic sugar to Expr-API, Object::field_.like(s) */
    Like like(const string& s);
    bool operator==(const FieldType & fd) const {
        return fd.fullName() == fullName();
    }
    bool operator!=(const FieldType & fd) const {
        return ! (*this == fd);
    }
};

/** convert function */
template <class From, class To>
To convert(From value);

/** holds field value */
template <class T>
class Field {
    const FieldType * field; 
    bool _modified;
    T _value;
public:
    Field(const FieldType & f) : field(&f), _modified(true) {}
    string fullName() const { return field->fullName(); }   
    string name() const { return field->name(); }
    string type() const { return field->type(); }
    string table() const { return field->table(); }
    T value() const { return _value; }
    const FieldType & fieldType() const { return *field; } 
    bool modified() const { return _modified; }
    void setModified(bool state) { _modified = state; }
    const Field & operator=(const string& v) { 
        _value = convert<const string&, T>(v);
        _modified = true;
        return *this;
    }
    const Field & operator=(const T& v) {
        _value = v;
        _modified = true;
        return *this;
    }
    template <class T2>
    const Field & operator=(T2 v) { 
        _modified = true;
        _value = convert<T2, T>(v); 
        return *this;
    }
    template <class T2>
    bool operator==(const T2& v) const {
        return toString(_value) == toString(v);
    }
    template <class T2>
    bool operator!=(const T2& v) const { return !(*this == v); }
    

    operator string() const { return toString(value()); }

    operator T() const { return value(); }
};

template <>
class Field<string> {
    const FieldType * field; 
    bool _modified;
    string _value;
public:
    Field(const FieldType & f) : field(&f), _modified(true) {}
    string fullName() const { return field->fullName(); }   
    string name() const { return field->name(); }
    string type() const { return field->type(); }
    string table() const { return field->table(); }
    string value() const { return _value; }
    const FieldType & fieldType() const { return *field; } 
    bool modified() const { return _modified; }
    void setModified(bool state) { _modified = state; }
    const Field & operator=(string v) { 
        _value = v;
        _modified = true;
        return *this;
    }
    const Field& operator=(const char * v) {
        _value = v;
        _modified = true;
        return *this;
    }
    template <class T2>
    const Field & operator=(T2 v) { 
        _modified = true;
        _value = convert<T2, string>(v); 
        return *this;
    }
    template <class T2>
    bool operator==(const T2& v) const {
        return toString(_value) == toString(v);
    }
    template <class T2>
    bool operator!=(const T2& v) const { return !(*this == v); }

    operator string() const { return value(); }
};


template <class T>
string operator+(string a, Field<T> f) {
    return a + string(f);
}
template <class T>
string operator+(Field<T> f, string a) {
    return string(f) + a;    
}
template <class T>
ostream & operator << (ostream & os, const Field<T> & f) {
    return os << toString(f);
}

}
#endif
