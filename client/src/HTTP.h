#ifndef HTTP_H
#define CLIENT_h

#include <Godot.hpp>
#include <HTTPRequest.hpp>
#include <Array.hpp>
#include <PoolArrays.hpp>
#include <JSON.hpp>
#include <JSONParseResult.hpp>

namespace godot {

class HTTP : public HTTPRequest {
    GODOT_CLASS(HTTP, HTTPRequest)

private:

public:
    static void _register_methods();

    HTTP();
    ~HTTP();

    void _init();
    void _ready();
    void _on_request_completed(int result, int response_code, PoolStringArray headers, PoolByteArray body);
};
}

#endif