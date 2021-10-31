#ifndef SERVER_H
#define SERVER_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {

class Server : public Node2D {
    GODOT_CLASS(Server, Node2D)

private:
    // Variables

public:
    static void _register_methods();

    Server();
    ~Server();

    void _init(); // our initializer called by Godot
};

}

#endif
