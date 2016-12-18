#ifndef ACTION_H
#define ACTION_H

class event;

class action {
 public:
    virtual void handler(event &ev);
};

#endif // ACTION_H
