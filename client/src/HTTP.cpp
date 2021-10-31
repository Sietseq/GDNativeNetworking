#include "HTTP.h"

using namespace godot;

void HTTP::_register_methods(){
    register_method("_ready", &HTTP::_ready);
    register_method("_on_request_completed", &HTTP::_on_request_completed);
}

HTTP::HTTP(){}
HTTP::~HTTP(){}

void HTTP::_init(){}

void HTTP::_ready() {
    this->connect("request_completed", this, "_on_request_completed");
    this->request("http://127.0.0.1:3000/");
}

void HTTP::_on_request_completed(int result, int response_code, PoolStringArray headers, PoolByteArray body){
    Dictionary json = JSON::get_singleton()->parse((char *)body.read().ptr())->get_result();
    String data = JSON::get_singleton()->print(json);

    Godot::print(data);
}