#ifndef OBJECT_H_
#define OBJECT_H_

class Object {
public:
  int value;
  int weight;

  Object(int value, int weight);

  int get_value();
  int get_weight();
};

#endif // OBJECT_H_
