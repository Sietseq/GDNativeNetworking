#include "Client.h"

using namespace godot;

void Client::_register_methods() {
    register_method("_ready", &Client::_ready);
    register_method("_process", &Client::_process);
    register_method("_on_connection_succeeded", &Client::_on_connection_succeeded);
    register_method("_on_connection_failed", &Client::_on_connection_failed);
}

Client::Client() {}
Client::~Client() {}

void Client::_init() {
    network = NetworkedMultiplayerENet()._new();
    api = MultiplayerAPI()._new();
}

void Client::_ready(){
    network->create_client("127.0.0.1", 1900);
    set_custom_multiplayer(api);
    get_custom_multiplayer()->set_root_node(this);
    get_custom_multiplayer()->set_network_peer(network);

    network->connect("connection_succeeded", this, "_on_connection_succeeded");
    network->connect("connection_failed", this, "_on_connection_failed");
}

void Client::_process(float delta){
    if (get_custom_multiplayer() == nullptr){
        return;
    } 
    if (get_custom_multiplayer()->has_network_peer() == false){
        return;
    }

    get_custom_multiplayer()->poll();
}

void Client::_on_connection_succeeded(){
    Godot::print("Connected to server");
}

void Client::_on_connection_failed(){
    Godot::print("Failed to connect to the server");
}