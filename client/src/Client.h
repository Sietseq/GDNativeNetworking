#ifndef CLIENT_H
#define CLIENT_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <NetworkedMultiplayerENet.hpp>
#include <MultiplayerAPI.hpp>

namespace godot {

class Client : public Node2D {
    GODOT_CLASS(Client, Node2D)

private:
    NetworkedMultiplayerENet* network;
    MultiplayerAPI* api;

public:
    static void _register_methods();

    Client();
    ~Client();

    void _init(); // our initializer called by Godot
    void _ready();
    void _process(float delta);
    void _on_connection_succeeded();
    void _on_connection_failed();

};

}

#endif
