#ifndef SEMANT_H_
#define SEMANT_H_

#include <assert.h>
#include <iostream>  
#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

class ClassTable;
typedef ClassTable *ClassTableP;

// This is a structure that may be used to contain the semantic
// information such as the inheritance graph.  You may use it or not as
// you like: it is only here to provide a container for the supplied
// methods.

class ClassTable {
private:
  std::map<Symbol, Class_> *class_table;
  int semant_errors;
  void install_basic_classes();
  ostream& error_stream;

public:
  ClassTable();
  int errors() { return semant_errors; }
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
  Class_ lookup(Symbol name);
  Class_ lookup_parent(Class_ class_);
  Feature lookup_method(Symbol class_name, Symbol method_name);
  int install_classes(Classes classes);
  int install_class(Symbol name, Class_ class_);
  int generate_tree();
  int get_environment();
  int check_cycle();
};

#endif

