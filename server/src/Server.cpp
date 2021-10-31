#include "Server.h"

using namespace godot;

void Server::_register_methods() {
    register_method("_ready", &Server::_ready);
    register_method("_process", &Server::_process);
    register_method("_on_peer_connected", &Server::_on_peer_connected);
    register_method("_on_peer_disconnected", &Server::_on_peer_disconnected);
}

Server::Server() {}
Server::~Server() {}

void Server::_init() {
    network = NetworkedMultiplayerENet()._new();
    api = MultiplayerAPI()._new();
}

void Server::_ready() {
    network->create_server(1900);
    set_custom_multiplayer(api);
    get_custom_multiplayer()->set_root_node(this);
    get_custom_multiplayer()->set_network_peer(network);

    network->connect("peer_connected", this, "_on_peer_connected");
    network->connect("peer_disconnected", this, "_on_peer_disconnected");
}

void Server::_process(float delta){
    if(get_custom_multiplayer() == nullptr){
        return;
    }
    if(get_custom_multiplayer()->has_network_peer() == false){
        return;
    }
    get_custom_multiplayer()->poll();

}

void Server::_on_peer_connected(int player_id){
    Godot::print(godot::String(player_id));
}

void Server::_on_peer_disconnected(int player_id){
    Godot::print("no");
}
