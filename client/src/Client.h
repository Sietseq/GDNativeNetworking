#ifndef CLIENT_H
#define CLIENT_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {

class Client : public Node2D {
    GODOT_CLASS(Client, Node2D)

private:
    // Variables

public:
    static void _register_methods();

    Client();
    ~Client();

    void _init(); // our initializer called by Godot

};

}

#endif
