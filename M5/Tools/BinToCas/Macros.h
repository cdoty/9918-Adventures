#pragma once

#include <map>
#include <memory>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

// Define a namespace
#define NAMESPACE(name) namespace name {
#define ENDNAMESPACE }

#ifndef SAFE_DELETE
#define SAFE_DELETE(x) {delete x; x = NULL;}
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x) {delete[] x; x = NULL;}
#endif

// Create a shared pointer function parameter
#define SHAREDTYPE(type) std::shared_ptr<type>
 
 // Create class name+"Ptr" shared pointer typedef
#define CLASSPTR(name) class name; typedef std::shared_ptr<name> name ## Ptr;

 // Create data+"Ptr" shared pointer typedef
#define DATAPTR(name, type) typedef std::shared_ptr<type> name ## Ptr;

// Create a pointer typedef
#define PTR(type) typedef std::shared_ptr<type> Ptr;

// Define a super class
#define SUPER(name) typedef name super;

// Create instance
#define INSTANCE(object, constructor) Ptr object(new (std::nothrow) constructor); if (nullptr == object) return object;

// Define instance
#define DEFINEINSTANCE(object, constructor) object	= Ptr(new (std::nothrow) constructor); if (nullptr == object) return object;

// Shared functions
#define SHAREDPTR(type, ptr) std::shared_ptr<type>(ptr)
#define SHAREDOBJECT(object, type) object = std::shared_ptr<type>(new (std::nothrow) type); //-V554
#define SHAREDINSTANCE(object, type, constructor) object = std::shared_ptr<type>(new (std::nothrow) constructor); //-V554
#define SHAREDCREATEDINSTANCE(object, type, constructor) object = std::shared_ptr<type>(constructor); //-V554
#define DEFINESHAREDINSTANCE(object, type, constructor) auto object = std::shared_ptr<type>(constructor); //-V554
#define SHAREDBUFFER(object, type, size) object = std::shared_ptr<type>(new (std::nothrow) type[(size_t)(size)], [](type *p){delete [] p;}); //-V554
#define DEFINESHAREDBUFFER(object, type, size) auto object = std::shared_ptr<type>(new (std::nothrow) type[(size_t)(size)], [](type *p){delete [] p;}); //-V554
#define WRAPBUFFER(object, type, buffer) object = std::shared_ptr<type>(buffer, [](type *p){delete [] p;}); //-V554
#define DEFINEWRAPBUFFER(object, type, buffer) auto object = std::shared_ptr<type>(buffer, [](type *p){delete [] p;}); //-V554

// Create a map, pair and iterator
#define MAPTYPE(key, value, name) typedef std::map<key, value> name ## Map; typedef std::pair<key, value> name ## Pair; typedef std::map<key, value>::iterator name ## Iterator;  typedef std::map<key, value>::const_iterator name ## ConstIterator;
#define WEAKPTR_MAPTYPE(key, value, name) typedef std::map<key, value, std::owner_less<key>> name ## Map; typedef std::pair<key, value> name ## Pair; typedef std::map<key, value>::iterator name ## Iterator;  typedef std::map<key, value>::const_iterator name ## ConstIterator;
#define UNORDERED_MAPTYPE(key, value, name) typedef std::unordered_map<key, value> name ## Map; typedef std::pair<key, value> name ## Pair; typedef std::unordered_map<key, value>::iterator name ## Iterator; typedef std::unordered_map<key, value>::const_iterator name ## ConstIterator;
#define SETTYPE(key, value, name) typedef std::set<key, value> name ## Set; typedef std::pair<key, value> name ## Pair; typedef std::set<key, value>::iterator name ## Iterator;  typedef std::set<key, value>::const_iterator name ## ConstIterator;
#define UNORDERED_SETTYPE(key, value, name) typedef std::unordered_set<key, value> name ## Set; typedef std::pair<key, value> name ## Pair; typedef std::unordered_set<key, value>::iterator name ## Iterator;  typedef std::unordered_set<key, value>::const_iterator name ## ConstIterator;
#define LISTTYPE(value, name) typedef std::list<value> name ## List; typedef std::list<value>::iterator name ## Iterator;
#define QUEUETYPE(value, name) typedef std::queue<value> name ## Queue;
