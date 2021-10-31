#ifndef SERVER_H
#define SERVER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <NetworkedMultiplayerENet.hpp>
#include <MultiplayerAPI.hpp>

namespace godot {

class Server : public Node2D {
    GODOT_CLASS(Server, Node2D)

private:
    NetworkedMultiplayerENet* network;
    MultiplayerAPI* api;

public:
    static void _register_methods();

    Server();
    ~Server();

    void _init(); // our initializer called by Godot
    void _ready();
    void _process(float delta);

    void _on_peer_connected(int player_id);
    void _on_peer_disconnected(int player_id);
};

}

#endif
