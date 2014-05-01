#include "object.h"

Object::Object(int value, int weight) {
  this->value = value;
  this->weight = weight;
}

int Object::get_value() {
  return value;
}

int Object::get_weight() {
  return weight;
}
